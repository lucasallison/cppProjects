#include <iostream>
#include <fstream>
using namespace std;

int main () {

ifstream invoer;
ofstream uitvoer;
char kar;
int getalFile = 0;
int pincode = 3285;
int digit1;
int digit2;
int digit3;
int digit4;
int codePlek = 0;
 
invoer.open("..\\invoer.txt");
uitvoer.open("..\\uitvoer.txt");
kar = invoer.get();

if (invoer.fail()) {
cout  << "De file kan niet geopend worden." << endl;
return 1 ;
}


    digit1 = pincode / 1000;
    digit2 = (pincode / 100) % 10;
    digit3 = (pincode / 10) % 10;
    digit4 = pincode % 10;


while (! invoer.eof()) {

    if (isdigit(kar)) {
        int getal = (int)kar - 48;
        getalFile = getalFile * 10 + getal;
    } else  {
        if ( ! getalFile == 0) {
            cout << "Dit is het kwadraad van uw getal (" << getalFile << "): " << getalFile * getalFile << endl;
            getalFile = 0;
        }
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
    }

    codePlek++;
    codePlek = codePlek % 4;

	uitvoer.put(kar);
	kar = invoer.get();
}

invoer.close();
uitvoer.close();

	return 0;
}
