#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void coderenFile (int pin, ifstream &invoer, ofstream &uitvoer) {

int pincodeFile = 0;
int codePlek = 0;
int karInt;
char kar;
char prevKar;

kar = invoer.get();
prevKar = kar;

int digit1 = pin / 1000;
int digit2 = (pin / 100) % 10;
int digit3 = (pin / 10) % 10;
int digit4 = pin % 10;

while (! invoer.eof()) {

    
    if (isdigit(kar)) {
        karInt = kar - 48;
        pincodeFile = pincodeFile * 10 + karInt;
    }


    if (kar != '\n') {
        if (codePlek == 0) {
            kar = (kar + digit1 + 128) % 128;
        }
        if (codePlek == 1) {
            kar = (kar + digit2 + 128) % 128;
        }
        if (codePlek == 2) {
            kar = (kar + digit3 + 128) % 128;
        }
        if (codePlek == 3) {
            kar = (kar + digit4 + 128) % 128;
        }

        codePlek++;
        codePlek = codePlek % 4;
    }
    else {
        codePlek = 0;
    }

 if (isdigit(prevKar) && kar == '\n') {
        if (pin >= 0 && pin <= 9999) {

            pin = pincodeFile;
            digit1 = pin / 1000;
            digit2 = (pin / 100) % 10;
            digit3 = (pin / 10) % 10;
            digit4 = pin % 10;

            codePlek = 0;
        }
        else {
            pincodeFile = 0;
        }
    }


    if (isdigit(prevKar) && ! isdigit(kar)) {
        if (pin >= 0 && pin <= 9999) {

            pin = pincodeFile;
            digit1 = pin / 1000;
            digit2 = (pin / 100) % 10;
            digit3 = (pin / 10) % 10;
            digit4 = pin % 10;

            codePlek = 0;
        }
        else {
            pincodeFile = 0;
        }
    }

    prevKar = kar;
	uitvoer.put(kar);
	kar = invoer.get();
	
}//while
}//void


int main () {

ifstream fileInv;
ofstream fileUit;
int pincode;

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

coderenFile (pincode, fileInv, fileUit);

fileInv.close();
fileUit.close();


	return 0;
}
