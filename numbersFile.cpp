#include <iostream>
#include <fstream>
using namespace std;

int main () {

ifstream invoer;
ofstream uitvoer;
char kar;
int karInt;
char prevKar;
int pincode;
int pincodeFile = 0;
int digit1;
int digit2;
int digit3;
int digit4;
int codePlek = 0;

//openen in- en uitvoerfile
invoer.open("..\\invoer.txt");
uitvoer.open("..\\uitvoer.txt");
kar = invoer.get();
prevKar = kar;

//kijken of de file geopend kan worden
if (invoer.fail()) {
cout  << "De file kan niet geopend worden." << endl;
return 1 ;
}

//opvragen en checken van pincode
cout << "Voer een pincode in: ";
cin >> pincode;
if (pincode < 0 || pincode > 9999) {
    cout << "Dit is een ongeldige pincode";
    return 1;
}

//omzetten van pincode in aparte intergers
digit1 = pincode / 1000;
digit2 = (pincode / 100) % 10;
digit3 = (pincode / 10) % 10;
digit4 = pincode % 10;

//coderen van een invoerfile
while (! invoer.eof()) {

    //aanpassen pincode
    if (isdigit(kar)) {
        karInt = kar - 48;
        pincodeFile = pincodeFile * 10 + karInt;
    }


    if (kar != '\n') {
        if (codePlek == 0) {
            kar = (kar + digit1) % 128;
        }
        if (codePlek == 1) {
            kar = (kar + digit2) % 128;
        }
        if (codePlek == 2) {
            kar = (kar + digit3) % 128;
        }
        if (codePlek == 3) {
            kar = (kar + digit4) % 128;
        }

        codePlek++;
        codePlek = codePlek % 4;
    }
    else {
        codePlek = 0;
    }

    if (isdigit(prevKar) && ! isdigit(kar)) {
        if (pincode >= 0 && pincode <= 9999) {

            pincode = pincodeFile;
            digit1 = pincode / 1000;
            digit2 = (pincode / 100) % 10;
            digit3 = (pincode / 10) % 10;
            digit4 = pincode % 10;

            codePlek = 0;
        }
        else {
            pincodeFile = 0;
        }
    }

    prevKar = kar;
	uitvoer.put(kar);
	kar = invoer.get();


}

invoer.close();
uitvoer.close();

	return 0;
}
