#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
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
        if (pincodeFile >= 0 && pincodeFile <= 9999) {

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

void decoderenFile (int pin, ifstream &invoer, ofstream &uitvoer, int & k, int & r) {

    int pincodeFile = 0;
    int codePlek = 0;
    int karInt; //omzetten char getal naar int getal
    char kar;
    char prevKar;
    char karDecoded;
    int digit1 = pin / 1000;
    int digit2 = (pin / 100) % 10;
    int digit3 = (pin / 10) % 10;
    int digit4 = pin % 10;

    while (! invoer.eof()) {

        prevKar = karDecoded;
        kar = invoer.get();
        k++;



        if (kar != '\n') {
            if (codePlek == 0) {
                karDecoded = (kar - digit1 + 128) % 128;
                uitvoer.put(karDecoded);
            }
            if (codePlek == 1) {
                karDecoded = (kar - digit2 + 128) % 128;
                uitvoer.put(karDecoded);

            }
            if (codePlek == 2) {
                karDecoded = (kar - digit3 + 128) % 128;
                uitvoer.put(karDecoded);
            }
            if (codePlek == 3) {
                karDecoded = (kar - digit4 + 128) % 128;
                uitvoer.put(karDecoded);
            }

            codePlek++;
            codePlek = codePlek % 4;
        }
        else {
            codePlek = 0;
            uitvoer.put(kar);
            r++;
            karDecoded = 'a';//om aan de if te doen voor nieuwe pin

        }

        if (isdigit(karDecoded)) {
            karInt = karDecoded - 48;
            pincodeFile = pincodeFile * 10 + karInt;
        }

        if (isdigit(prevKar) && ! isdigit(karDecoded)) {
            if (pincodeFile >= 0 && pincodeFile <= 9999) {

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

void draaiNummer (int a, int & x) {

    int p;

    x=0;
    while (a != 0) {
        p = a%10;
        x = x*10 + p;
        a /=10;
    }//while
}//void

void lychrelGetal (int &nummerInv, int nummerRev, int &her, bool &lychrelPot) {

lychrelPot = false;
draaiNummer(nummerInv, nummerRev);

    while (nummerInv != nummerRev) {

        if (nummerInv > INT_MAX - nummerRev) {
            nummerInv = nummerRev;
            lychrelPot = true;

        }
        else {
            nummerInv = nummerInv + nummerRev;
            draaiNummer(nummerInv, nummerRev);
            her++;

        }//else
    }//while
}//void


int main () {

string invoerFileNaam;
string uitvoerFileNaam;
int pincode;
int aantalKar = 0;
int aantalRegelOvergangen = 0;
int keuze;

ifstream fileInv;
ofstream fileUit;

cout << "Geef de invoer file naam op: "; //VERANDER DIT
cin >> invoerFileNaam;
cout << "Geef de uitvoer file naam op: ";
cin >> uitvoerFileNaam;


fileInv.open(invoerFileNaam.c_str());
fileUit.open(uitvoerFileNaam.c_str());

if (fileInv.fail()) {
cout  << "De file "<< invoerFileNaam <<" kan niet geopend worden." << endl;
return 1 ;
}


cout << "Voer een pincode in: ";
cin >> pincode;

if (pincode < 0 || pincode > 9999) {
    cout << "Dit is een ongeldige pincode";
    return 1;
}

cout << "Als u wilt coderen, vul in 0. Als u wilt decoderen, vul in 1: " << endl;
cin >> keuze;

if (keuze == 1) {

    decoderenFile(pincode, fileInv,fileUit, aantalKar, aantalRegelOvergangen);

    cout << "Het aantal karakters in de file: " << aantalKar << endl;
    cout << "Het aantal regelovergangen in de file " << aantalRegelOvergangen << endl;

    fileInv.close();
    fileUit.close();


}//decoderen file

if (keuze == 0) {

    coderenFile(pincode, fileInv, fileUit, aantalKar, aantalRegelOvergangen);

    cout << "Het aantal karakters in de file: " << aantalKar << endl;
    cout << "Het aantal regelovergangen in de file " << aantalRegelOvergangen << endl;

    fileInv.close();
    fileUit.close();

}//coderen file


fileInv.open (invoerFileNaam.c_str());

char karLychrel;
char prevKarLychrel;
int karIntLychrel;
int getalFile = 0;
int getalFileRev;
int aantalIteraties = 0;
bool isPotentialLychrel;

while (! fileInv.eof()) {

    prevKarLychrel = karLychrel;
    karLychrel = fileInv.get();

    if (isdigit(karLychrel)) {
        karIntLychrel = karLychrel - 48;
        getalFile = getalFile * 10 + karIntLychrel;
    }

    if (isdigit(prevKarLychrel) && ! isdigit(karLychrel)) {

        cout << "Het getal in de file is: " << getalFile << endl;
        lychrelGetal(getalFile, getalFileRev, aantalIteraties, isPotentialLychrel);


            if (isPotentialLychrel) {
                cout << "Dit is een potentieel Lychrel getal.";
                cout << " Dit is bepaald na " << aantalIteraties << " herhalingen." << endl;

            }
            else {

                cout << "Dit getal wordt een palindroom na " << aantalIteraties;
                cout << " iteratie(s). Het getal is dan: " << getalFile << endl;
            }

        getalFile = 0;
        aantalIteraties = 0;

    }//if

}//while


fileInv.close();

	return 0;
}//main
