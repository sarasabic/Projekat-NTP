#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

enum pozicija {clan, administrator};

// ------------------------------------------------------------------------------------------------------------
// ---------------------------------------STRUKTURE------------------------------------------------------------
struct Osoba{
    char ime_prez[50];
    char username[30];
    char password[30];
    int ID;
};

struct Administrator{
    Osoba administrator;
    pozicija uloga;
};


struct Clan{
    Osoba clan;
    pozicija uloga;

};

struct Knjiga{
    char Naziv_knjige[30];
    char Ime_autora[30];
    char Prezime_autora[30];
    int Godina_izdanja;
    char Zanr[30];
};

//--------------------------------------------------GLOBALNE VARIJABLE------------------------------------------

char * linija = "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
Administrator admin;
Clan cln;
int br_clanova=0;

// ------------------------------------------------------------------------------------------------------------
//-------------------------------FUNKCIJE----------------------------------------------------------------------


//--------------------------------LOGIN------------------------------------------------------------------------
int login(char username[30], char password[30], int br_clanova){
    cin.ignore();
    cout << linija << "\t Login " << linija;
    cout << "Korisnicko ime: ";
    cin.getline(username,30);
    cout << "Lozinka: ";
    cin.getline(password,30);
    if(!strcmp(username,admin.administrator.username) && !strcmp(password, admin.administrator.password)){
        system("cls");
        return 0000;
    }else{
        for(int i=0;i<br_clanova;i++){
            if(!strcmp(username, cln.clan.username) &&  !strcmp(password, cln.clan.password)){
                return cln.clan.ID;
            }
        }
    }

    cin.ignore();
    system("cls");
}
//------------------------------------------------------------------------------------------------
// ---------------------------------REGISTRACIJE--------------------------------------------------

void registracija_clana (){

    cout<<"Unesite ID: \n";
    cin>> cln.clan.ID;
    cin.ignore();
    cout<<"Unesite Ime i prezime: \n";
    cin.getline(cln.clan.ime_prez,50);
    cout<<"Unesite korisnicko ime: \n";
    cin.getline(cln.clan.username,30);
    cout<<"Unesite lozinku: \n";
    cin.getline(cln.clan.password,30);

    ofstream file_;
    file_.open("text.txt", ios::app);
    file_<< cln.clan.ime_prez<< "\n";
    file_<< cln.clan.ID<< "\n";
    file_<< cln.clan.username<< "\n";
    file_<< cln.clan.password<< "\n";
    file_.close();
}

void registracija_knjige(){
    Knjiga unos;

    cout<<"Unesite naziv knjige: "<<endl;
    cin.ignore();
    cin.getline(unos.Naziv_knjige, 30);

    cout<<"Unesite ime autora: "<<endl;
    cin.getline(unos.Ime_autora, 30);
    cout<<"Unesite prezime autora: "<<endl;
    cin.getline(unos.Prezime_autora, 30);
    cout<<"Unesite godinu izdanja knjige: "<<endl;
    cin>>unos.Godina_izdanja;
    cin.ignore();
    cout<<"Unesite zanr: "<<endl;
    cin.getline(unos.Zanr, 30);
    ofstream knjige;
    knjige.open("knjige_nazivi.txt", ios::app);
    knjige<< unos.Naziv_knjige<<"\n";
    knjige<< unos.Ime_autora<<"\n";
    knjige<< unos.Prezime_autora<<"\n";
    knjige<< unos.Godina_izdanja<<"\n";
    knjige<< unos.Zanr<<"\n";
    knjige.close();
    system ("cls");
}

// ------------------------------------------------------------------------------------------------------------
// -----------------------------------------ISPIS KNJIGA-------------------------------------------------------

void pregled_knjiga() {
    ifstream datoteka("knjige_nazivi.txt");
    if (!datoteka) {
        cerr << "Nemoguce otvoriti datoteku knjige_nazivi.txt." << endl;
        return;
    }
    string naziv, ime, prezime, godina, zanr;

    while (getline(datoteka, naziv) && getline(datoteka, ime) && getline(datoteka, prezime)&& getline(datoteka, godina)&& getline(datoteka, zanr)) {
        cout << "Naslov: " << naziv << endl;
        cout << "Ime autora: " << ime<< endl;
        cout << "Prezime autora: " << prezime << endl;
        cout << "Godina izdanja: " << godina << endl;
        cout << "Zanr: " << zanr << endl;
        cout << endl;
    }

    datoteka.close();
    system("pause");
    system("cls");
}

// ------------------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------------------
// --------------------------------------------PRETRAGA KNJIGA-------------------------------------------------

void pretraga_po_imenu(){
    ifstream file("knjige_nazivi.txt");
    if (!file) {
        cerr << "Nemoguce otvoriti file." << endl;
    }

    string trazeni_red;
    string red;
    int brReda = 1;
    cout << "Ime knjige: ";
    cin >> trazeni_red;
    bool found = false;

    while (getline(file, red)) {
        if (red.find(trazeni_red) != string::npos) {
            found = true;
            for (int i = 0; i < 4; i++) {
                if(i==0){
                    cout<<"Ime autora: ";
                }
                if(i==1){
                    cout<<"Prezime autora ";
                }
                if(i==2){
                    cout<<"Godina izdanja: ";
                }
                if(i==3){
                    cout<<"Zanr: ";
                }


                if (getline(file, red))
                    cout << red<< endl;
                else
                    break;
            }
            break;
        }
        brReda ++;
    }
    file.close();

    if (!found) {
        cout << "Nema trazene knjige." << endl;
    }
}
// ------------------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------------------
// --------------------------------------------PRETRAGA CLANA--------------------------------------------------
void pretraga_clana(){
    ifstream file("text.txt");
    if (!file) {
        cerr << "Nemoguce otvoriti file." << endl;
    }

    string trazeni_red;
    string red;
    int brReda = 1;
    cout << "Ime i prezime: ";
    cin >> trazeni_red;
    bool found = false;

    while (getline(file, red)) {
        if (red.find(trazeni_red) != string::npos) {
            found = true;
            for (int i = 0; i < 3; i++) {
                if(i==0){
                    cout<<"ID: ";
                }
                if(i==1){
                    cout<<"Korisnicko ime: ";
                }
                if(i==2){
                    cout<<"Lozinka: ";
                }
                if (getline(file, red))
                    cout << red<< endl;
                else
                    break;
            }
            break;
        }
        brReda ++;
    }
    file.close();

    if (!found) {
        cout << "Nema trazenog clana." << endl;
    }

    file.close();
    system("pause");
}

// ------------------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------------------
// --------------------------------------------POTVRDA CLANSTVA------------------------------------------------

void potvrda_clanstva(fstream file_){
    string trazena_linija;
    file_.open("text.txt");
    if(file_.fail()){
        cout<<"Nije moguce otvoriti file!"<<endl;
    }
    int current_line=0;
    string line;
    while (!file_.eof()){
        current_line++;
        trazena_linija= cln.clan.username;
        //	if (current_line == trazena_linija);
        cout<<current_line<<endl;
    }
}

// ------------------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------------------------
// ------------------------------------------------ISPIS CLANOVA-----------------------------------------------

void ispisClanova(){
    ifstream datoteka("text.txt");
    if (!datoteka) {
        cerr << "Nemoguce otvoriti datoteku knjige_nazivi.txt." << endl;
        return;
    }
    string id, imeiprezime, username, password;

    while (getline(datoteka, id) && getline(datoteka, imeiprezime) && getline(datoteka, username)&& getline(datoteka, password)) {
        cout << "ID: " << id << endl;
        cout << "Ime i prezime : " << imeiprezime<< endl;
        cout << "Korisnicko ime: " << username << endl;
        cout << "Lozinka: " << password << endl;
        cout << endl;
    }

    datoteka.close();
    system("pause");
    system("cls");
}
// ------------------------------------------------------------------------------------------------------------
// ----------------------------------------------OPCIJE ZA MENI------------------------------------------------


void opcija4() {
    cout << "Opcija 1." << endl;
    ispisClanova();

}

void opcija5() {
    cout << "Opcija 2." << endl;
    registracija_knjige();

}
void opcija6() {
    cout << "Opcija 3." << endl;
    pregled_knjiga();

}

void opcija100() {
    cout << "Opcija 4." << endl;
    pretraga_clana();

}
// ------------------------------------------------------------------------------------------------------------


// ------------------------------------------------------------------------------------------------------------
// -----------------------------------------------ADMIN MENI---------------------------------------------------

int adminMeni() {
    system("cls");
    system("color 0D");

    while (true) {
        cout << linija << "\t ADMIN" << linija;
        cout << "1. Pregled clanova" << endl;
        cout << "2. Unos nove knjige" << endl;
        cout << "3. Pregled knjiga"<<endl;
        cout << "4. Pretraga clana"<<endl;
        cout << "5. Exit" << endl;

        int izbor;
        cout << "Unesite izbor: ";
        cin >>izbor ;
        system("cls");
        switch (izbor) {
            case 1:
                opcija4();
                break;
            case 2:
                opcija5();
                break;
            case 3:
                opcija6();
                break;
            case 4:
                opcija100();
                break;
            case 5:
                cout << "Exiting..." << endl;
                system("cls");
                return 0;
            default:
                cout << "Nepostojeca opcija!" << endl;
        }
    }
}
// ------------------------------------------------------------------------------------------------------------


// ------------------------------------------------------------------------------------------------------------
// -------------------------------------------------OPCIJE ZA MENI---------------------------------------------

void opcija1() {
    cout << "Opcija 1." << endl;
    char username[20];
    char password[30];
    int broj=login(username,password,br_clanova);
    if (broj==admin.administrator.ID){
        adminMeni();
        system("cls");
    }}
void opcija2() {
    cout << "Opcija 2." << endl;
    registracija_clana();

    br_clanova=br_clanova+1;
    system ("cls");
    system("color E0");
    cout<<"REGISTROVALI STE SE U NAS SISTEM. " <<endl<<endl;
    system("pause");
    system ("cls");
}

void opcija3() {
    cout << "Exit"<< endl;
    system("cls");

}
void opcija7() {
    cout << "Opcija 1." << endl;

}

void opcija8() {
    cout << "Opcija 2." << endl;

}

void opcija9() {
    cout << "Opcija 3." << endl;
    pregled_knjiga();

}
// ----------------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------------
// -----------------------------------------------CLAN MENI--------------------------------------------------

void clanMeni(){
    system("color 0E");
    while (true) {
        cout<<"\t \t MENI";
        cout<<linija;
        cout<<"1. Podizanje knjiga  "<<endl;
        cout<<"2. Podignute knjige  "<<endl;
        cout<<"3. Pregled knjiga "<<endl;
        cout<<"4. ";

        int izbor;
        cout << "Unesite izbor: ";
        cin >> izbor ;
        system("cls");
        switch (izbor) {
            case 1:
                opcija7();
                break;
            case 2:
                opcija8();
                break;
            case 3:
                opcija9();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return;
            default:
                cout << "Nepostojeca opcija!" << endl;

        }
    }
}
// ------------------------------------------------------------------------------------------------------------


// ------------------------------------------------------------------------------------------------------------
// ----------------------------------------------LOGIN MENI----------------------------------------------------

int loginMeni(){
    system("color 03");
    while (true) {
        cout << linija << "\t  LOGIN " << linija;
        cout << "1. Login" << endl;
        cout << "2. Registracija clana" << endl;
        cout << "3. Exit" << endl;

        int opcija;
        cout << "Izaberite opciju: ";
        cin >> opcija;
        system("cls");
        switch (opcija) {
            case 1:
                opcija1();
                system("cls");
                break;
            case 2:
                opcija2();
                system("cls");
                break;
            case 3:
                cout << "Exiting..." << endl;
                system("cls");
                return 1;
            default:
                cout << "Netocan odabir. Pokusajte ponovo." << endl;
        }
    }

    system("cls");

}

// ------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------------------
//----------MAIN----------------MAIN-----------------MAIN-------------------MAIN-------------------------------

int main(){

// ------------------------------------------------------------------------------------------------------------
// -----------------------------------------------ADMIN INFO---------------------------------------------------

    strcpy(admin.administrator.ime_prez, "Ana Anic");
    strcpy(admin.administrator.username, "b");
    strcpy(admin.administrator.password, "b");
    admin.administrator.ID = 0000;
    admin.uloga = administrator;

//-------------------------------------------------------------------------------------------------------------

    ofstream knjige;

    loginMeni();

    system ("pause");
    return 0;
}
