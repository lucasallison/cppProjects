//Programeurs: Lucas Allison en Thom Stokx.
//Naam bestand: AllisonStokx.cpp
/*Dit programma vraagt de gebruiker om een invoerfile, een 'doelfile'
  en een pincode om te coderen. Met behulp van de pincode codeert het
  programma de invoerfile zodat er een 'geheimtekst' in de doelfile gezet wordt.
  Ook wordt er afgedrukt uit hoeveel karakters en regels de invoerfile bestaat.
  Een file kan ook gedecodeert worden. Als de gebruiker zijn pincode niet
  meer weet kan de pincode bepaald worden, en de file vervolgens gedecodeert.
*/
//Gebruikte programma (editor and compiler): CLion en Cmake
//Laatste bewerkingen van het programma gemaakt op: 15-10-2018

#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
using namespace std;

//functie om een file te coderen
void coderenFile (int pin, ifstream &invoer, ofstream &uitvoer, int & k, int & r) {

int pincodeFile = 0; //om pincode van file in op te slaan
int codePlek = 0; // bepaalt welke digit het is
int karInt; //omzetten char getal naar int getal
char kar; //karakter in file
char prevKar; //vorige karakter in file
char karEncoded; // kar omgezet met de pin
//opgespliste pin
int digit1 = pin / 1000;
int digit2 = (pin / 100) % 10;
int digit3 = (pin / 10) % 10;
int digit4 = pin % 10;

while (! invoer.eof()) {

    prevKar = kar;
    kar = invoer.get();


    //getal van file omzetten in nieuwe pin
    if (isdigit(kar)) {
        karInt = kar - 48;
        pincodeFile = pincodeFile * 10 + karInt;
    }

    //aannpassen kar naar karEncoded
    if (kar != '\n') {
        if (codePlek == 0) {
            karEncoded = (kar + digit1 + 128) % 128;
            uitvoer.put(karEncoded);
        }
        if (codePlek == 1) {
            karEncoded = (kar + digit2 + 128) % 128;
            uitvoer.put(karEncoded);

        }
        if (codePlek == 2) {
            karEncoded = (kar + digit3 + 128) % 128;
            uitvoer.put(karEncoded);
        }
        if (codePlek == 3) {
            karEncoded = (kar + digit4 + 128) % 128;
            uitvoer.put(karEncoded);
        }

        codePlek++;
        codePlek = codePlek % 4;
        k++;

    }
    else {
        codePlek = 0;
        uitvoer.put(kar);
        r++;

    }

    //als er een nieuwe pin in file is gevonden, oude pin vervangen
    if (isdigit(prevKar) && ! isdigit(kar)) {
        if (pincodeFile >= 0 && pincodeFile <= 9999) {

            pin = pincodeFile;
            digit1 = pin / 1000;
            digit2 = (pin / 100) % 10;
            digit3 = (pin / 10) % 10;
            digit4 = pin % 10;

            pincodeFile = 0;
            codePlek = 0;
        }
        else {
            pincodeFile = 0;
        }
    }


}//while
}//void coderenFile

void decoderenFile (int pin, ifstream &invoer, ofstream &uitvoer, int & k, int & r) {

    int pincodeFile = 0;
    int codePlek = 0;
    int karInt; //omzetten char getal naar int getal
    char kar;
    char prevKar;
    char karDecoded;
    int digit1 = pin / 1000;
    int digit2 = (pin / 100) % 10;
    int digit3 = (pin / 10) % 10;
    int digit4 = pin % 10;

    while (! invoer.eof()) {

        prevKar = karDecoded;
        kar = invoer.get();


        if (kar != '\n') {
            if (codePlek == 0) {
                karDecoded = (kar - digit1 + 128) % 128;
                uitvoer.put(karDecoded);
            }
            if (codePlek == 1) {
                karDecoded = (kar - digit2 + 128) % 128;
                uitvoer.put(karDecoded);

            }
            if (codePlek == 2) {
                karDecoded = (kar - digit3 + 128) % 128;
                uitvoer.put(karDecoded);
            }
            if (codePlek == 3) {
                karDecoded = (kar - digit4 + 128) % 128;
                uitvoer.put(karDecoded);
            }

            codePlek++;
            codePlek = codePlek % 4;
            k++;

        }
        else {
            codePlek = 0;
            uitvoer.put(kar);
            r++;
            karDecoded = 'a';//om aan de if te doen voor nieuwe pin

        }

        //getallen in de file omzetten in pin
        if (isdigit(karDecoded)) {
            karInt = karDecoded - 48;
            pincodeFile = pincodeFile * 10 + karInt;
        }

        //als er een nieuwe pin in file is gevonden, oude pin vervangen
        if (isdigit(prevKar) && ! isdigit(karDecoded)) {
            if (pincodeFile >= 0 && pincodeFile <= 9999) {

                pin = pincodeFile;
                digit1 = pin / 1000;
                digit2 = (pin / 100) % 10;
                digit3 = (pin / 10) % 10;
                digit4 = pin % 10;

                pincodeFile = 0;
                codePlek = 0;
            }
            else {
                pincodeFile = 0;
            }
        }


    }//while
}//void decoderenFile

void vindPin (string fileNaam, int &pinPV) {

    ifstream invoer;
    char karVindPin = '\0';
    int pinTest;
    int aantalThe = 0;
    int aantalThePrev = 0;
    int plekThe;

    int karDecodedPV;
    int codePlekPV = 0;
    int pincodeFilePV;
    int karIntPV;
    char prevKarPV;

    //for loop, vult telkens een nieuwe pin in
    for (pinTest = 0; pinTest < 10000; pinTest++) {

        invoer.open(fileNaam.c_str());

        prevKarPV = karVindPin;
        karVindPin = invoer.get();

        aantalThe = 0;
        plekThe = 0;

        int digit1 = pinTest / 1000;
        int digit2 = (pinTest / 100) % 10;
        int digit3 = (pinTest / 10) % 10;
        int digit4 = pinTest % 10;
        if(invoer.is_open()) {
            // while loop om een pincode te testen
            while (!invoer.eof()) {
                if (karVindPin != '\n') {
                    if (codePlekPV == 0) {
                        karDecodedPV = (karVindPin - digit1 + 128) % 128;
                    }
                    if (codePlekPV == 1) {
                        karDecodedPV = (karVindPin - digit2 + 128) % 128;

                    }
                    if (codePlekPV == 2) {
                        karDecodedPV = (karVindPin - digit3 + 128) % 128;
                    }
                    if (codePlekPV == 3) {
                        karDecodedPV = (karVindPin - digit4 + 128) % 128;
                    }

                    codePlekPV++;
                    codePlekPV = codePlekPV % 4;
                } else {
                    codePlekPV = 0;
                    plekThe = 0;
                    karDecodedPV = '\n';
                }

                if (isdigit(karDecodedPV)) {
                    karIntPV = karDecodedPV - 48;
                    pincodeFilePV = pincodeFilePV * 10 + karIntPV;
                }

                if (isdigit(prevKarPV) && !isdigit(karDecodedPV)) {
                    if (pincodeFilePV >= 0 && pincodeFilePV <= 9999) {

                        digit1 = pincodeFilePV / 1000;
                        digit2 = (pincodeFilePV / 100) % 10;
                        digit3 = (pincodeFilePV / 10) % 10;
                        digit4 = pincodeFilePV % 10;

                        pincodeFilePV = 0;
                        codePlekPV = 0;
                    } else {
                        pincodeFilePV = 0;
                    }
                }

                //tellen van het allen 'the' in de file
                if (plekThe == 0 && (karDecodedPV == 't' || karDecodedPV == 'T')) {
                    plekThe++;
                } else if (plekThe == 1 && (karDecodedPV == 'h' || karDecodedPV == 'H')) {
                    plekThe++;
                } else if (plekThe == 2 && (karDecodedPV == 'e' || karDecodedPV == 'E')) {
                    plekThe = 0;
                    aantalThe++;
                } else {
                    plekThe = 0;

                }
                if(pinTest == 1234) {
                }

                prevKarPV = karDecodedPV;
                karVindPin = invoer.get();

            }//while
        } // if isopen

        //bepalen beste pin met het meeste 'the'
        if (aantalThe > aantalThePrev) {
            aantalThePrev = aantalThe;
            pinPV = pinTest;

        }


        invoer.close();

    }//for
}//void vindPin

//functie om een getal om te draaien
void draaiNummer (int a, int & x) {

    int p;

    x=0;
    while (a != 0) {
        p = a%10;
        x = x*10 + p;
        a /=10;
    }//while
}//void

//fuctie om te kijken wanneer een getal een palindroom wordt of een potentieel lychrel getal
void lychrelGetal (int &nummerInv, int nummerRev, int &her, bool &lychrelPot) {

lychrelPot = false;
draaiNummer(nummerInv, nummerRev);

    while (nummerInv != nummerRev) {

        if (nummerInv > INT_MAX - nummerRev) {
            nummerInv = nummerRev;
            lychrelPot = true;

        }
        else {
            nummerInv = nummerInv + nummerRev;
            draaiNummer(nummerInv, nummerRev);
            her++;

        }//else
    }//while
}//void lychrelGetal


int main () {


//infoblokje voor de gebruiker:
cout << "Programeurs: Lucas Allison en Thom Stokx.\n"
     << "Naam bestand: StokxAllison2.cpp\n"
     << "Dit programma vraagt de gebruiker om een invoerfile, een 'doelfile'"
     << "en een pincode om te coderen.\nMet behulp van de pincode codeert het"
     << " programma de invoerfile zodat er een 'geheimtekst' in de doelfile"
     << "gezet wordt.\nOok wordt er afgedrukt uit hoeveel karakters en regels"
     << "de invoerfile bestaat.\nEen file kan ook gedecodeert worden. "
     << "Als de gebruiker zijn pincode niet\n"
     << "meer weet kan de pincode bepaald worden, en de file vervolgens gedecodeert."
     << "Gebruikte programma (editor and compiler): CLion en Cmake.\n"
     << "Laatste bewerkingen van het programma gemaakt op: 15-10-2018.\n";



    string invoerFileNaam;
string uitvoerFileNaam;
int pincode; //de pincode die de gebruiker invoert
int aantalKar = 0; //aantal karakters in de file
int aantalRegelOvergangen = 0; //aantal regelovergangen in de file
//om te bepalen welke functies worden aangeroepen
int keuze;
int eersteKeuze;
int keuzePV;

ifstream fileInv;
ofstream fileUit;

cout << "Geef de invoer file naam op: ";
cin >> invoerFileNaam;
cout << "Geef de uitvoer file naam op: ";
cin >> uitvoerFileNaam;


cout << "Wilt u de file coderen/decoderen vul in: 0. Bent u uw pin vergeten vul in: -1." << endl;
cin >> eersteKeuze;


//pincode vinden
if (eersteKeuze == -1) {

    pincode = 0;

    vindPin(invoerFileNaam, pincode);
    cout << "Uw pincode was waarschijnlijk: " << pincode << endl;
    cout << "Wilt u de file decoderen? Als u dit wil, typ 1." << endl;
    cin >> keuzePV;

    //decodeert file
    if (keuzePV == 1) {

        fileInv.open(invoerFileNaam.c_str());
        fileUit.open(uitvoerFileNaam.c_str());

        decoderenFile(pincode, fileInv, fileUit, aantalKar, aantalRegelOvergangen);

        cout << "Het aantal karakters in de file: " << aantalKar << endl;
        cout << "Het aantal regelovergangen in de file " << aantalRegelOvergangen << endl;

        fileInv.close();
        fileUit.close();

    } //if
} //if, eerste keuze

if (eersteKeuze == 0) {

    fileInv.open(invoerFileNaam.c_str());
    fileUit.open(uitvoerFileNaam.c_str());

    //checken of file kan
    if (fileInv.fail()) {
        cout << "De file " << invoerFileNaam << " kan niet geopend worden." << endl;
        return 1;
    }


    cout << "Voer een pincode in: ";
    cin >> pincode;

    //afwijzen ongeldige pincode
    if (pincode < 0 || pincode > 9999) {
        cout << "Dit is een ongeldige pincode";
        return 1;
    }

    cout << "Als u de file wilt coderen, vul in 0. Als u de file wilt decoderen, vul in 1: " << endl;
    cin >> keuze;

    //decoderen file
    if (keuze == 1) {

        decoderenFile(pincode, fileInv, fileUit, aantalKar, aantalRegelOvergangen);

        cout << "Het aantal karakters in de file: " << aantalKar << endl;
        cout << "Het aantal regelovergangen in de file " << aantalRegelOvergangen << endl;

        fileInv.close();
        fileUit.close();

    } //if keuze decoderen

    //coderen file
    if (keuze == 0) {

        coderenFile(pincode, fileInv, fileUit, aantalKar, aantalRegelOvergangen);

        cout << "Het aantal karakters in de file: " << aantalKar << endl;
        cout << "Het aantal regelovergangen in de file " << aantalRegelOvergangen << endl;

        fileInv.close();
        fileUit.close();

    } //if keuze coderen

}//if eerste keuze

    //lychrel getallen bepalen
    fileInv.open(invoerFileNaam.c_str());

    char karLychrel;
    char prevKarLychrel;
    int karIntLychrel; //de char van de .get omzetten in int
    int getalFile = 0; //om het getal van de file in op te slaan
    int getalFileRev; //omgedraaide van getalFile
    int aantalIteraties = 0;
    bool isPotentialLychrel; //om te kijken of het een potentieel lychrel getal is

    while (!fileInv.eof()) {

        prevKarLychrel = karLychrel;
        karLychrel = fileInv.get();

        //getal ophalen uit de file
        if (isdigit(karLychrel)) {
            karIntLychrel = karLychrel - 48;
            getalFile = getalFile * 10 + karIntLychrel;
        }

        //Bepalen of het een lychrel getal is
        if (isdigit(prevKarLychrel) && !isdigit(karLychrel)) {

            cout << "Het getal in de file is: " << getalFile << endl;
            lychrelGetal(getalFile, getalFileRev, aantalIteraties, isPotentialLychrel);


            if (isPotentialLychrel) {
                cout << "Dit is een potentieel Lychrel getal.";
                cout << " Dit is bepaald na " << aantalIteraties << " herhalingen." << endl;

            } else {

                cout << "Dit getal wordt een palindroom na " << aantalIteraties;
                cout << " iteratie(s). Het getal is dan: " << getalFile << endl;
            }

            getalFile = 0;
            aantalIteraties = 0;

        }//if

    }//while

    fileInv.close();

	return 0;
}//main
