#include <iostream>
#include <fstream>
using namespace std;

int main () {

ifstream invoer;
ofstream uitvoer;
char kar;
int getalFile = 0;
 
invoer.open("/home/pi/cpp/invoer.txt");
kar = invoer.get();

while (! invoer.eof()) {
	if (kar == '0' || kar == '1' || kar == '2' || kar == '3' || kar == '4' || kar == '5' || kar == '6' || kar == '7' || kar == '8' || kar == '9') {
	cout << kar << endl;	
	getalFile = getalFile * 10 + kar;
	cout << getalFile << endl;
	kar = invoer.get();
	} else  {
	cout << getalFile * getalFile << endl;	
	kar = invoer.get();
	}
}//while

invoer.close();

	return 0;
}
