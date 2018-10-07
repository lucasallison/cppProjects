#include <iostream>
#include <fstream>
using namespace std;

int main () {

ifstream invoer;
ofstream uitvoer;
char kar;
int getalFile = 0;
 
invoer.open("/home/pi/cppProjects/invoer.txt");
uitvoer.open("/home/pi/cppProjects/uitvoer.txt");
kar = invoer.get();

if (invoer.fail()) {
cout  << "De file kan niet geopend worden." << endl;
return 1 ;
}//if

while (! invoer.eof()) {
uitvoer.put(kar);

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
uitvoer.close();

	return 0;
}
