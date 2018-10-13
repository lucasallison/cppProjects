#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void coderenFile (int pin, ifstream &invoer, ofstream &uitvoer, int & k, int & r) {

int pincodeFile = 0;
int codePlek = 0;
int karInt; //omzetten char getal naar int getal
char kar;
char prevKar;
char karEncoded;
int digit1 = pin / 1000;
int digit2 = (pin / 100) % 10;
int digit3 = (pin / 10) % 10;
int digit4 = pin % 10;

while (! invoer.eof()) {

    prevKar = kar;
    kar = invoer.get();
    k++;

    if (isdigit(kar)) {
        karInt = kar - 48;
        pincodeFile = pincodeFile * 10 + karInt;
    }


    if (kar != '\n') {
        if (codePlek == 0) {
            karEncoded = (kar + digit1 + 128) % 128;
            uitvoer.put(karEncoded);
        }
        if (codePlek == 1) {
            karEncoded = (kar + digit2 + 128) % 128;
            uitvoer.put(karEncoded);

        }
        if (codePlek == 2) {
            karEncoded = (kar + digit3 + 128) % 128;
            uitvoer.put(karEncoded);
        }
        if (codePlek == 3) {
            karEncoded = (kar + digit4 + 128) % 128;
            uitvoer.put(karEncoded);
        }

        codePlek++;
        codePlek = codePlek % 4;
    }
    else {
        codePlek = 0;
        uitvoer.put(kar);
        r++;

    }


    if (isdigit(prevKar) && ! isdigit(kar)) {
        if (pin >= 0 && pin <= 9999) {

            pin = pincodeFile;
            digit1 = pin / 1000;
            digit2 = (pin / 100) % 10;
            digit3 = (pin / 10) % 10;
            digit4 = pin % 10;

            pincodeFile = 0;
            codePlek = 0;
        }
        else {
            pincodeFile = 0;
        }
    }


}//while
}//void


int main () {

int pincode;
int aantalKar = 0;
int aantalRegelOvergangen = 0;

ifstream fileInv;
ofstream fileUit;


fileInv.open("/home/lucasallison/Documents/cppProjects/invoer.txt");
fileUit.open("/home/lucasallison/Documents/cppProjects/uitvoer.txt");

if (fileInv.fail()) {
cout  << "De file kan niet geopend worden." << endl;
return 1 ;
}


cout << "Voer een pincode in: ";
cin >> pincode;
if (pincode < 0 || pincode > 9999) {
    cout << "Dit is een ongeldige pincode";
    return 1;
}

coderenFile (pincode, fileInv, fileUit, aantalKar, aantalRegelOvergangen);

cout << "Het aantal karakters in de file: " << aantalKar << endl;
cout << "Het aantal regelovergangen in de file " << aantalRegelOvergangen<< endl;

fileInv.close();
fileUit.close();


	return 0;
}//main
