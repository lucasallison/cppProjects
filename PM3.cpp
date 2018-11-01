#include<iostream>
using namespace std;



void submenu () {

    char keuzeSubmenu;

    cout << "Welkom in het submenu. Maak een keuze uit: A, B of T" << endl;

    do {
        cin >> keuzeSubmenu;
        switch (keuzeSubmenu) {

            case 'A': case 'a':
                cout << "U heeft A/a geantwoord" << endl;
                break;
            case 'B': case 'b':
                cout << "U heeft B/b geantwoord" << endl;
                break;
            case 'T':  case 't':
                break;
            default:
                cout << "Vul een valide letter in:" << endl;
        }//switch

    } while ( keuzeSubmenu != 'A' && keuzeSubmenu != 'a' &&
              keuzeSubmenu != 'B' && keuzeSubmenu != 'b' &&
              keuzeSubmenu != 'T' && keuzeSubmenu != 't' );


}//submenu


void hoofdmenu () {

    char keuzeHoofdmenu;

    cout << "Welkom in het hoofdmenu. Maak een keuze uit: s(C)hoon, (R)andom, (P)arameters of (S)toppen" << endl;

    while (keuzeHoofdmenu != 's' && keuzeHoofdmenu != 'S') {
        cin  >> keuzeHoofdmenu;
        switch (keuzeHoofdmenu) {

            case 'C': case 'c':
                cout << "U heeft C/c geantwoord" << endl;
                break;
            case 'R': case 'r':
                cout << "U heeft R/r geantwoord" << endl;
                break;
            case 'P': case 'p':
                submenu();
                break;
            default:
                cout << "Vul een valide letter in:" << endl;
        }//switch
    }//while
}//hoofdmenu



int main () {

    hoofdmenu();

    return 0;
}