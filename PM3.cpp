#include<iostream>
#include<string>

using namespace std;


int randomGetal ( ) {
    static int getal = 42;
    getal = ( 221 * getal + 1 ) % 1000;
    return getal;
}//randomgetal


char gebruikerInvoer () {

    char invoer;
    cin.get(invoer);
    while (invoer == '\n') {
        cin.get(invoer);
    }

}

int leesGetal(){

    int max = 100;
    int getal = 0;
    char invoer;

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

    getal = getal * 10 - 1;
    return getal;
}



const int MAX = 15;


class nonogram {

    public:
        nonogram ();
        void drukAf ();
        void maakSchoon ();
        void vulRandom ();
        void zetPercentage ();

    private:

        bool nono[MAX][MAX];
        int hoogte;
        int breedte;
        int percentage;



};


nonogram::nonogram() {

    hoogte = 4;
    breedte = 4;
    percentage = 499;
    maakSchoon();



}

void nonogram::zetPercentage ( ) {

    cout << "Vul een percentage in" << endl;
    percentage = leesGetal ();
}//zetpercentage

void nonogram::drukAf() {
    int i;
    int j;

    for (j = 0; j < breedte + 2; j++) {
        cout << "+ ";
    }

    for (i = 0; i <= hoogte; i++) {
        cout << "\n";
        cout << "+ ";
        for (j = 0; j < breedte; j++) {
            if (nono[i][j]) {
                cout << "X ";

            } else {
                cout << "  ";

            }
        }//forTwo
        cout << "+";
    }//forOne

    cout << "\n";
    for (j = 0; j < breedte + 2; j++) {
        cout << "+ ";
    }
    cout << "\n";
}//drukAf

void nonogram::vulRandom() {
    int i, j;
    for (i = 0; i <= hoogte; i++) {
        for (j=0; j <= breedte; j++) {
            if (randomGetal() < percentage) {
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



void submenu (nonogram & nono) {

    char keuzeSubmenu;

    cout << "Welkom in het submenu. ";

    do {
       cout << "Maak een keuze uit: (P)ercentage wijzigen, (G)rootte wijzigen of (T)erug" << endl;
       keuzeSubmenu = gebruikerInvoer();
        switch (keuzeSubmenu) {

            case 'P': case 'p':
                nono.zetPercentage();
                break;
            case 'G': case 'g':
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
            case 'P': case 'p':
                submenu(nono);
                break;
            case 'R': case 'r':
                nono.vulRandom();
                break;
            case 'S': case 's':
                cout << "Einde van het programma" << endl;
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