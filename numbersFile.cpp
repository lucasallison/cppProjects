#include <iostream>
#include <fstream>
using namespace std;

int main () {

ifstream invoer;
ofstream uitvoer;
char kar;
int getalFile = 0;
 
invoer.open("..\\invoer.txt");
kar = invoer.get();

while (! invoer.eof()) {
	if (isdigit(kar)) {
        int getal = (int)kar - 48;
        getalFile = getalFile * 10 + getal;
        kar = invoer.get();
	} else  {
	    if (getalFile == 0) {
            kar = invoer.get();
	    } else {
            cout << "Dit is het kwadraad van uw getal (" << getalFile << "): " << getalFile * getalFile << endl;
            getalFile = 0;
            kar = invoer.get();
        }//else
	}//else
}//while

invoer.close();

	return 0;
}
