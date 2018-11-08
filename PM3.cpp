#include<iostream>
#include<string>

using namespace std;


int randomGetal ( ) {
    int getalR;
    static int getal = 42;
    getalR = ( 221 * getal + 1 ) % 1000;
    return getalR;
}//randomgetal



char gebruikerInvoer () {

    char invoer;
    cin.get(invoer);
    while (invoer == '\n') {
        cin.get(invoer);
    }

}




const int MAX = 15;


class nonogram {

    public:
        nonogram ();
        void drukAf ();
        void maakSchoon ();
        void vulRandom ();

    private:

        bool nono[MAX][MAX];
        int hoogte;
        int breedte;


};


nonogram::nonogram() {

    hoogte = 10;
    breedte = 10;
    nonogram voorbeeld;
    voorbeeld.maakSchoon();


}

void nonogram::drukAf() {
    int i;
    int j;

    for (j = 0; j <= breedte + 3; j++) {
        cout << "+ ";
    }


    for (i = 0; i <= hoogte; i++) {
        cout << "\n";
        cout << "+ ";
        for (j = 0; j < breedte + 2; j++) {
            if (nono[i][j]) {
                cout << "X ";

            } else {
                cout << "  ";

            }
        }//forTwo
        cout << "+";
    }//forOne

    cout << "\n";
    for (j = 0; j <= breedte + 3; j++) {
        cout << "+ ";
    }
    cout << "\n";
}//drukAf

void nonogram::vulRandom() {
    int i, j;
    for (i = 0; i <= hoogte; i++) {
        for (j=0; j <= breedte; j++) {
            if (randomGetal() < 499) {
                nono[i][j] = true;

            } else {
                nono[i][j] = false;

            }

        }//forTwo
    }//forOne
}//vulRandom



void nonogram::maakSchoon () {

    int i, j;

    for(i=0; i <= hoogte; i ++) {
        for (j=0;j <= breedte; j++) {
            nono[i][j] = false;
        }//forTwo
    }//forOne
}//maakSchoon


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




void submenu (nonogram & nono) {

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

    nonogram nono;
    char keuzeHoofdmenu;


    cout << "Welkom in het hoofdmenu." << endl;

    while (keuzeHoofdmenu != 's' && keuzeHoofdmenu != 'S') {
        nono.drukAf();
        cout << "Maak een keuze uit: s(C)hoon, (R)andom, (P)arameters of (S)toppen" << endl;
        keuzeHoofdmenu = gebruikerInvoer();
        switch (keuzeHoofdmenu) {

            case 'C': case 'c':
                nono.maakSchoon();
                break;
            case 'R': case 'r':
                nono.vulRandom();
                nono.drukAf();
                break;
            case 'P': case 'p':
                submenu(nono);
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