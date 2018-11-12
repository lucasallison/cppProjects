#include<iostream>
#include<string>
#include<fstream>

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
        void cursorCase ();
        void maakBeschrijving ();
        void maakBeschrijvingCheck ();
        void maakBeschrijvingSchoon ();
        void veranderBool (int i, int j);
        void eigenBeschrijvingInvoeren ();

    private:

        bool checkVerticaal (int i);
        bool checkHorizontaal (int j);
        bool nono[MAX][MAX];
        bool cursorVerander;
        int beschrijvingVerticaal[MAX][MAX];
        int beschrijvingVerticaalCheck[MAX][MAX];
        int beschrijvingHorizontaal[MAX][MAX];
        int beschrijvingHorizontaalCheck[MAX][MAX];
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
    cursorVerander = false;
    maakSchoon();
    maakBeschrijvingSchoon();
}


void nonogram::drukAf() {
    int i;
    int j;

    cout << "\n";
    for (j = 0; j < breedte + 2; j++) {
        cout << "+ ";
    }


    


    for (i = 0; i < hoogte; i++) {
        cout << "\n";
        cout << "+ ";
        for (j = 0; j < breedte; j++) {

            if (i == hoogteCurser && j == breedteCurser) {
                if (cursorVerander) {
                    veranderBool(i,j);
                }
                cout << "* ";

            } else {

                if (nono[i][j]) {
                    cout << "X ";

                } else {
                    cout << "  ";
                }

            }
        }
        cout << "+";

        if (checkVerticaal(i)) {
            cout << " V ";
        } else {
            cout << "   ";
        }

            for (j = 0; beschrijvingVerticaal[i][j] != 0; j++) {
                cout << beschrijvingVerticaal[i][j] << " ";
            }


    }


    cout << "\n";
    for (j = 0; j < breedte + 2; j++) {
        cout << "+ ";
    }

    cout << "\n" << "  ";
    for (j = 0; j < breedte; j++) {

        if (checkHorizontaal(j)) {
            cout << "V ";
        } else {
            cout << "  ";
        }

    }

    cout << "\n";

    bool nietKlaar = true;
    for (i = 0; i < hoogte; i++) {
        cout << "  ";

        if (nietKlaar) {
            nietKlaar = false;
            for (j = 0; j < breedte; j++) {
                if (beschrijvingHorizontaal[i][j] !=0) {
                    nietKlaar = true;
                }
            }
            for (j = 0; j < breedte; j++) {

                    if (beschrijvingHorizontaal[i][j] == 0) {
                        cout << "  ";
                    } else {
                        if (beschrijvingHorizontaal[i][j] > 9){
                            cout << beschrijvingHorizontaal[i][j];
                        } else {
                            cout << beschrijvingHorizontaal[i][j] << " ";
                        }
                    }
                }
            cout << "\n";
        }
    }
    cout << "\n";
}//drukAf

void nonogram::eigenBeschrijvingInvoeren() {
        int i, j;
        string invoerfile;
        cout << "Hoe heet het bestand waaruit u de beschrijving over wilt nemen? ";
        cin >> invoerfile;
        ifstream invoer;
        invoer.open(invoerfile.c_str());
        if (!invoer){
            cout << "Deze file kan niet gevonden worden." << endl;
            return;
        }

        invoer >> hoogte >> breedte;
        for (int i = 0; i < hoogte; i++){
            j = 0;
            invoer >> beschrijvingVerticaal[i][j];
            while (beschrijvingVerticaal[i][j] != 0){
                j++;
                invoer >> beschrijvingVerticaal[i][j];

            }
        }


        for (int j = 0; j < breedte; j++){
            i = 0;
            invoer >> beschrijvingHorizontaal[i][j];
            while (beschrijvingHorizontaal[i][j] != 0){
                i++;
                invoer >> beschrijvingHorizontaal[i][j];
            }
        }
        invoer.close();
        hoogteCurser = hoogte / 2;
        breedteCurser = breedte / 2;
}//eigenBeschrijvingInvoeren


void nonogram::cursorCase() {
    char modus;
    cout << "selecteer welke modus u wilt voor uw cursor:" << endl;
    cout << "(A)lle punten waarop de cursor staat worden veranderd" << endl;
    cout << "(G)een van de punten waarop de cursor staat worden veranderd." << endl;
    cin >> modus;

    switch (modus) {
        case 'A': case 'a':
            cursorVerander = true;
            break;
        case 'G': case 'g':
            cursorVerander = false;
            break;
        default:
            cout << "vul een valide cijfer in.";
    }



}//cursorCase

void nonogram::veranderBool(int i, int j) {
   if(nono[i][j]) {
       nono[i][j] = false;
   } else {
       nono[i][j] = true;
   }
}//veranderBool





void nonogram::maakBeschrijvingSchoon() {
    int i, j;
    for (i = 0; i < MAX; i++){
        for (j = 0; j < MAX; j++) {
            beschrijvingVerticaal[i][j] = 0;
            beschrijvingHorizontaal[i][j] = 0;

        }
    }

}//maakArraySchoon



void nonogram::maakBeschrijving() {
    int i, j;
    int teller = 0;

    for (int i = 0; i < hoogte; i++ ) {
        for (int j = 0; j < breedte; j++) {
            beschrijvingVerticaal[i][j] = 0;
            if (nono[i][j]) {cursorVerander = false;

                beschrijvingVerticaal[i][teller]++;

            } else if (beschrijvingVerticaal[i][teller] != 0) {

                teller++;
            }
        }
        teller = 0;
    }
    

    for (int j = 0; j < breedte; j++ ){
        for (int i = 0; i < hoogte; i++ ){
            beschrijvingHorizontaal[i][j] = 0;
            if (nono[i][j]) {

                beschrijvingHorizontaal[teller][j]++;

            } else if (beschrijvingHorizontaal[teller][j] != 0){
                teller++;

            }
        }
        teller = 0;
    }
}//maakBeschrijving



bool nonogram::checkVerticaal (int i) {
    int j;
    bool check = true;

    for (j = 0; j< breedte; j++) {
        if (beschrijvingVerticaal[i][j] !=  beschrijvingVerticaalCheck[i][j]) {
            check = false;
        }
    }

    if (check) {
        return true;
    } else {
        return false;
    }
}//checkBeschrijvingVerticaal





void nonogram::maakBeschrijvingCheck() {

    int i, j;
    int teller = 0;

    for (int j = 0; j < breedte; j++ ){
        for (int i = 0; i < hoogte; i++ ){
            beschrijvingHorizontaalCheck[i][j] = 0;
            if (nono[i][j]) {

                beschrijvingHorizontaalCheck[teller][j]++;

            } else if (beschrijvingHorizontaalCheck[teller][j] != 0){
                teller++;

            }
        }
        teller = 0;
    }

    for (int i = 0; i < hoogte; i++ ) {
        for (int j = 0; j < breedte; j++) {
            beschrijvingVerticaalCheck[i][j] = 0;
            if (nono[i][j]) {

                beschrijvingVerticaalCheck[i][teller]++;

            } else if (beschrijvingVerticaalCheck[i][teller] != 0) {

                teller++;
            }
        }
        teller = 0;
    }

}//maakBeschrijvingCheck


bool nonogram::checkHorizontaal(int j) {

    int i;
    bool check = true;

    for (i = 0; i < hoogte; i++) {
            if (beschrijvingHorizontaal[i][j] != beschrijvingHorizontaalCheck[i][j]) {
                check = false;
            }
    }

    if (check) {
        return true;
    } else {
        return false;
    }

}//checkHorizontaal














void nonogram::zetPercentage ( ) {
    cout << "Vul een percentage in" << endl;
    percentage = leesGetal (101) * 10;
}//zetpercentage

void nonogram::zetAfmetingen(){

    cout << "Vul de hoogte in:" << endl;
    hoogte = leesGetal(51);
    hoogteCurser = hoogte / 2;
    cout << "Vul de breedte in:" << endl;
    breedte = leesGetal(50);
    breedteCurser = breedte / 2;

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

        }
    }
}//vulRandom



void nonogram::maakSchoon () {

    int i, j;

    for(i=0; i < MAX; i ++) {
        for (j=0;j < MAX; j++) {
            nono[i][j] = false;
        }
    }
}//maakSchoon


void submenu (nonogram & nono) {

    char keuzeSubmenu;

    cout << "\n" << "Welkom in het submenu." << endl;

    do {
       cout << "Maak een keuze uit: (P)ercentage wijzigen, (G)rootte wijzigen, (C)ursor modus aanpassen of (T)erug" << endl;
       keuzeSubmenu = gebruikerInvoer();
        switch (keuzeSubmenu) {

            case 'P': case 'p':
                nono.zetPercentage();
                nono.maakSchoon();
                nono.maakBeschrijvingCheck();
                nono.maakBeschrijvingSchoon();
                break;
            case 'G': case 'g':
                nono.zetAfmetingen();
                nono.maakSchoon();
                nono.maakBeschrijvingCheck();
                nono.maakBeschrijvingSchoon();
                break;
            case 'C': case 'c':
                nono.cursorCase();
                break;
            case 'T':  case 't':
                cout << "\n" << "Welkom in het hoofdmenu." << endl;
                break;
            default:
                cout << "Vul een valide letter in." << endl;
        }//switch

    } while (keuzeSubmenu != 'T' && keuzeSubmenu != 't' );

}//submenu


void hoofdmenu () {

    nonogram nono;
    char keuzeHoofdmenu = '?';
    nono.maakBeschrijvingCheck();
    nono.maakBeschrijving();


    cout << "Welkom in het hoofdmenu." << endl;

    while (keuzeHoofdmenu != 's' && keuzeHoofdmenu != 'S') {

        nono.drukAf();
        cout << "Maak een keuze uit: s(C)hoon, (R)andom, (P)submenu, (T)oggle, (M)aak beschrijvingen, (E)igenbeschrijving invoeren of (S)toppen" << endl;
        cout << "Om te curser te bewegen: (A)links, (W)omhoog , (Z)omlaag, (D)rechts" << endl;
        keuzeHoofdmenu = gebruikerInvoer();
        switch (keuzeHoofdmenu) {

            case 'C': case 'c':
                nono.maakSchoon();
                nono.maakBeschrijvingCheck();
                break;
            case 'P': case 'p':
                submenu(nono);
                break;


            case 'R': case 'r':
                nono.vulRandom();
                nono.maakBeschrijvingCheck();
                break;
            case 'T': case 't':
                nono.toggle();
                nono.maakBeschrijvingCheck();
                break;

            case 'M': case 'm':
                nono.maakBeschrijving();
                break;
            case 'E': case 'e':
                nono.maakBeschrijvingSchoon();
                nono.eigenBeschrijvingInvoeren();
                break;

            case 'A': case 'a':
                nono.beweegLinks();
                nono.maakBeschrijvingCheck();
                break;
            case 'W': case 'w':
                nono.beweegOmhoog();
                nono.maakBeschrijvingCheck();
                break;
            case 'Z': case 'z':
                nono.beweegOmlaag();
                nono.maakBeschrijvingCheck();
                break;
            case 'D': case 'd':
                nono.beweegRechts();
                nono.maakBeschrijvingCheck();
                break;
            case 'S': case 's':
                cout << "Einde van het programma" << endl;
                break;
            default:
                cout << "Vul een valide letter in." << endl;
        }//switch
    }//while
}//hoofdmenu





int main () {

    hoofdmenu();


    return 0;
}