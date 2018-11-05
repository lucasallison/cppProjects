#include<iostream>
#include<string>

using namespace std;

char gebruikerInvoer () {

    char invoer;
    cin.get(invoer);
    while (invoer == '\n') {
        cin.get(invoer);
    }

}

int leesGetal(){

    int max = 10000;
    int getal = 0;
    char invoer;
    cout << "Vul iets in. " << endl;
    cin.get(invoer);
    while (invoer == '\n') {
        cin.get(invoer);
    }
    while (invoer != '\n') {
        if (isdigit(invoer)) {
            getal = getal * 10 + invoer - '0';
        }

        if (getal > max) {
            do {
                getal = getal/10;
            } while (getal > max);
        }
        cin.get(invoer);
    }

    return getal;
}




void submenu () {

    char keuzeSubmenu;

    cout << "Welkom in het submenu. Maak een keuze uit: A, B of T" << endl;

    do {
       keuzeSubmenu = gebruikerInvoer();
        switch (keuzeSubmenu) {

            case 'A': case 'a':
                cout << "U heeft A/a geantwoord" << endl;
                break;
            case 'B': case 'b':
                cout << "U heeft B/b geantwoord" << endl;
                break;
            case 'T':  case 't':
                cout << "Welkom in het hoofdmenu. Maak een keuze uit: s(C)hoon, (R)andom, (P)arameters of (S)toppen" << endl;
                break;
            default:
                cout << "Vul een valide letter in:" << endl;
        }//switch

    } while (keuzeSubmenu != 'T' && keuzeSubmenu != 't' );


}//submenu


void hoofdmenu () {

    char keuzeHoofdmenu;

    cout << "Welkom in het hoofdmenu. Maak een keuze uit: s(C)hoon, (R)andom, (P)arameters of (S)toppen" << endl;

    while (keuzeHoofdmenu != 's' && keuzeHoofdmenu != 'S') {
      keuzeHoofdmenu = gebruikerInvoer();
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



    cout << leesGetal();



    return 0;
}