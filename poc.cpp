#include <iostream>
#include <fstream>
#include<iomanip>
#include<string.h>
using namespace std;

enum pozicija {clan, administrator};

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

//	Clan clanovi[maxclanova];

char * linija = "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
Administrator admin;
Clan cln;


//-------------------------------STRUKTURE I DEKLARACIJE--------------------------------------------------------------

//LOGIN

int loginMeni(){
    system("cls");
    int izbor;
    do{
        cout << linija << "\t  LOGIN " << linija;
        cout << "1. Login " << endl;
        cout << "2. Registracija clana " << endl;
        cout << "3. Napustiti sistem " << endl;
        cout << "Unesite izbor: ";
        cin >> izbor;
        cin.ignore();
    }while(izbor<1 || izbor>3);
    system("cls");
    return izbor;
}
//CLAN MENI
void clanMeni(){

    int izbor1, izbor2;
    cout<<linija;
    do{
        cout<<"\t \t MENI";
        cout<<linija;
        cout<<"1. Iznajmljivanje knjiga  "<<endl;
        cout<<"2. Vracanje knjiga "<<endl;
        cout<<"3. Iznajmljene knjige "<<endl;
        cout<<"0. Exit ";
        cout<<linija;
        cin>>izbor1;
        system("cls");
    }while(izbor1<0 || izbor1>3);


    if (izbor1==1){
        cout<<linija;
        cout<<"\t \t PRETRAGA ";
        cout<<linija;
        do{
            cout<<"1. Pretraga knjiga abecedno "<<endl;
            cout<<"2. Pretraga knjiga po zanru "<<endl;
            cout<<"3. Pretraga knjiga po piscu "<<endl;
            cout<<"4. Pretraga po nazivu knjige ";
            cout<<linija;
            cin>>izbor2;
            system("cls");
        }while(izbor1<2 || izbor1>4);
    }
}
//ADMIN MENI
int adminMeni() {
    int izbor;

    system("cls");
    do
    {
        cout << linija << "\t ADMIN" << linija;
        cout << "1. Pregled clanova" << endl;
        cout << "2. Unos nove knjige" << endl;
        /*	cout << "3. " << endl;
            cout << "4. " << endl;
            cout << "5. " << endl;
            cout << "6. " << endl;
            cout << "7. " << endl;
            cout << "8. Kraj rada" << crt;*/
        cout << "Unesite izbor: ";
        cin >> izbor;
        cin.ignore();
    } while (izbor<1 || izbor>8);

    return izbor;

}


//---------------------------------LOGIN---------------------------------------------------------------

//------------------------------------------------------------------------------------------------
int login(char username[30], char password[30], int br_clanova){
    cout << linija << "\t Login " << linija;
    cout << "Korisnicko ime: ";
    cin.getline(username,30);
    cout << "Lozinka: ";
    cin.getline(password,30);
    if(!strcmp(username,admin.administrator.username) && !strcmp(password, admin.administrator.password)){
        return 0000;
    }else{
        for(int i=0;i<br_clanova;i++){
            if(!strcmp(username, cln.clan.username) &&  !strcmp(password, cln.clan.password)){
                return cln.clan.ID;
            }
        }
    }
    cin.ignore();
}
//------------------------------------------------------------------------------------------------
//__________________________________REGISTRACIJE_________________________________________________

void registracija_clana (){

    cout<<"Unesite ID: \n";
    cin>> cln.clan.ID;
    cin.ignore();
    cout<<"Unesite Ime i prezime: \n";
    cin.getline(cln.clan.ime_prez,50);
    cout<<"Unesite korisnicko ime: \n";
    cin.getline(cln.clan.username,30);
    cin.ignore();
    cout<<"Unesite lozinku: \n";
    cin.getline(cln.clan.password,30);

    ofstream file_;
    file_.open("text.txt", ios::app);
    file_<< cln.clan.ID<< "\n";
    file_<< cln.clan.ime_prez<< "\n";
    file_<< cln.clan.username<< "\n";
    file_<< cln.clan.password<< "\n";
    file_.close();
}

void registracija_knjige(){
    Knjiga unos;
    system ("cls");
    cout<<"Unesite naziv knjige: "<<endl;
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

void ispisClanova(){
    fstream file_;

    file_.open("text.txt", ios::in);
    string line;
    if( file_.is_open()){
        while(getline(file_,line)){
            cout<<line<<endl;
        }
    }
    file_.close();
}


//MAIN  MAIN  MAIN  MAIN  MAIN  MAIN  MAIN  MAIN  MAIN  MAIN  MAIN  MAIN  MAIN  MAIN  MAIN
//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------

int main(){

    strcpy(admin.administrator.ime_prez, "Ana Anic");
    strcpy(admin.administrator.username, "bibliotekar");
    strcpy(admin.administrator.password, "biblioteka");
    admin.administrator.ID = 0000;
    admin.uloga = administrator;

    registracija_knjige();

//------------------------------------------------------------------------------------------------
    int br_clanova=0;
    //char nazivknjige[30];
    ofstream knjige;



    if(loginMeni()==1){
        char username[20];
        char password[30];
        int broj=login(username,password,br_clanova);
        if (broj==admin.administrator.ID){
            if (adminMeni()==1){
                ispisClanova();
            }


            if (adminMeni()==2){
                registracija_knjige();
                cout<<"  REGISTROVALI STE KNJIGU U SISTEM. "
                    <<endl<<endl;
                system("pause");
                system ("cls");
            }
            else{
                if (broj==cln.clan.ID){
                    clanMeni();}
            }
        }
    }
    if(loginMeni()==2){
        registracija_clana();

        br_clanova=br_clanova+1;
        system ("cls");
        cout<<"                  REGISTROVALI STE SE U NAS SISTEM. "
            <<endl<<endl<<"                  Izvrsite login:"<<endl<<endl;
        system("pause");
        system ("cls");

        loginMeni();
    }
    if(loginMeni()==3){
        system ("pause");

    }
//------------------------------------------------------------------------------------------------



    system ("pause");
    return 0;
}
