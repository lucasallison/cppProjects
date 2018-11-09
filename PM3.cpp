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

    return invoer;
}

int leesGetal(int max){


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

        if (getal >= max) {
            do {
                getal = getal/10;
            } while (getal > max);
        }
        cin.get(invoer);
    }

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
        void zetAfmetingen();
        void beweegLinks ();
        void beweegOmhoog();
        void beweegOmlaag();
        void beweegRechts();
        void toggle ();
        void maakBeschrijving ();
        void maakArraySchoon ();

    private:

        bool nono[MAX][MAX];
        int beschrijvingVerticaal[MAX][MAX];
        int hoogte;
        int breedte;
        int hoogteCurser;
        int breedteCurser;
        int percentage;
        int plekKolom;
        int plekRij;



};


nonogram::nonogram() {

    hoogte = MAX;
    breedte = MAX;
    hoogteCurser = hoogte / 2;
    breedteCurser = breedte / 2;
    percentage = 499;
    plekKolom = 0;
    plekRij = 0;
    maakSchoon();

}

void nonogram::drukAf() {
    int i;
    int j;

    for (j = 0; j < breedte + 2; j++) {
        cout << "+ ";
    }


    


    for (i = 0; i < hoogte; i++) {
        cout << "\n";
        cout << "+ ";
        for (j = 0; j < breedte; j++) {

            if (i == hoogteCurser && j == breedteCurser ) {

                cout << "* ";

            } else {

                if (nono[i][j]) {
                    cout << "X ";

                } else {
                    cout << "  ";
                }

            }//ifCurser
        }//forTwo
        cout << "+";

        maakBeschrijving();

        for (j = 0; j < breedte; j++) {
           cout <<  beschrijvingVerticaal[i][j];

        }

    }//forOne







    cout << "\n";
    for (j = 0; j < breedte + 2; j++) {
        cout << "+ ";
    }
    cout << "\n";
}//drukAf

void nonogram::maakArraySchoon() {

}//maakArraySchoon

void nonogram::maakBeschrijving () {
    int i, j;
    int teller = 0;


    for (int i = 0; i < hoogte; i++ ) {

        for (int j = 0; j < breedte; j++) {

            beschrijvingVerticaal[i][j] = 0;

            if (nono[i][j]) { // true

                beschrijvingVerticaal[i][teller]++;

            } else if (beschrijvingVerticaal[i][teller] != 0) {

                teller++;
            }
        }
        teller = 0;
    }
}//maakBeschrijving



void nonogram::zetPercentage ( ) {

    cout << "Vul een percentage in" << endl;
    percentage = leesGetal (100) * 10;
}//zetpercentage

void nonogram::zetAfmetingen(){

    cout << "Vul de hoogte in:" << endl;
    hoogte = leesGetal(50);
    cout << "Vul de breedte in:" << endl;
    breedte = leesGetal(50);
}//zetAfmetingen


void nonogram::beweegLinks () {
    if (breedteCurser != 0) {
        breedteCurser = breedteCurser - 1;
    }
}//beweegLinks

void nonogram::beweegOmhoog () {
    if (hoogteCurser != 0) {
        hoogteCurser = hoogteCurser - 1;
    }
}//beweegLinks

void nonogram::beweegOmlaag () {
    if (hoogteCurser != hoogte - 1) {
        hoogteCurser = hoogteCurser + 1;
    }
}//beweegOmlaag

void nonogram::beweegRechts () {
    if (breedteCurser != breedte - 1) {
        breedteCurser = breedteCurser + 1;
    }
}//beweegRechts

void nonogram::toggle() {

    if (nono[hoogteCurser][breedteCurser]) {
        nono[hoogteCurser][breedteCurser] = false;
    } else {
        nono[hoogteCurser][breedteCurser] = true;
    }


}//toggle



void nonogram::vulRandom() {
    int i, j;
    for (i = 0; i < hoogte; i++) {
        for (j=0; j < breedte; j++) {
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
                nono.zetAfmetingen();
                break;
            case 'T':  case 't':
                cout << "Welkom in het hoofdmenu. " << endl;
                break;
            default:
                cout << "Vul een valide letter in:" << endl;
        }//switch

    } while (keuzeSubmenu != 'T' && keuzeSubmenu != 't' );


}//submenu


void hoofdmenu () {

    nonogram nono;
    char keuzeHoofdmenu = '?';


    cout << "Welkom in het hoofdmenu." << endl;

    while (keuzeHoofdmenu != 's' && keuzeHoofdmenu != 'S') {
        nono.drukAf();
        cout << "Maak een keuze uit: s(C)hoon, (R)andom, (P)arameters, (T)oggle of (S)toppen" << endl;
        cout << "Om te curser te bewegen: (A)links, (W)omhoog , (Z)omlaag, (D)rechts" << endl;
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
            case 'T': case 't':
                nono.toggle();
                break;
            case 'A': case 'a':
                nono.beweegLinks();
                break;
            case 'W': case 'w':
                nono.beweegOmhoog();
                break;
            case 'Z': case 'z':
                nono.beweegOmlaag();
                break;
            case 'D': case 'd':
                nono.beweegRechts();
                break;
            case 'S': case 's':
                cout << "Einde van het programma" << endl;
                break;
            default:
                cout << "Vul een valide letter in!" << endl;
        }//switch
    }//while
}//hoofdmenu





int main () {


    hoofdmenu();


    return 0;
}