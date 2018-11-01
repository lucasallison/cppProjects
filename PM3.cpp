#include<iostream>
using namespace std;





int hoofdmenu () {

    char keuzeGebruiker;

    cout << "Maak een keuze uit: s(C)hoon, (R)andom, (P)arameters of (S)toppen" << endl;
    cin >> keuzeGebruiker;

    do {
            switch (keuzeGebruiker) {

                case 'C':
                    cout << "U heeft C/c geantwoord" << endl;
                break;
                case 'c':
                    cout << "U heeft C/c geantwoord" << endl;
                break;
                case 'R':
                    cout << "U heeft R/r geantwoord" << endl;
                break;
                case 'r':
                    cout << "U heeft R/r geantwoord" << endl;
                break;
                case 'P':
                    cout << "U heeft P/p geantwoord" << endl;
                break;
                case 'p':
                    cout << "U heeft P/p geantwoord" << endl;
                break;
                case 'S':
                    return 1;
                case 's':
                    return 1;
                default:
                    cout << "Vul een valide letter in;";
                    cin >> keuzeGebruiker;
            }//switch

    } while ( keuzeGebruiker != 'C' || keuzeGebruiker != 'c' ||
              keuzeGebruiker != 'R' || keuzeGebruiker != 'r' ||
              keuzeGebruiker != 'P' || keuzeGebruiker != 'p' ||
              keuzeGebruiker != 'S' || keuzeGebruiker != 's');



}//hoofdmenu







int main () {

    hoofdmenu();

    return 0;
}