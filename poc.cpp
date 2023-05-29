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
//---------------------------------------------------------------------------------------------
char * linija = "\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
Administrator admin;


	
	int loginMeni(){
		system("cls");
		int izbor;
		do{
			cout << linija << "\t  LOGIN " << linija;
			cout << "1. Login " << endl;
			cout << "2. Napustiti sistem " << endl;
			cout << "Unesite izbor: ";
			cin >> izbor;
			cin.ignore();
		}while(izbor<1 || izbor>3);
		system("cls");
		return izbor;
	}
//------------------------------------------------------------------------------------------------	
	int login(char username[30], char password[30]){
		cout << linija << "\t Login " << linija;
		cout << "Korisnicko ime: ";
		cin.getline(username,30);
		cout << "Lozinka: ";
		cin.getline(password,30);
		if(!strcmp(username,admin.administrator.username) && !strcmp(password, admin.administrator.password)){
			return 0000;		
	
		}
		cin.ignore();
	}
	
	//------------------------------------------------------------------------------------------------
		//ADMIN MENI
	int adminMeni() {
		int izbor;

		system("cls");
		do
		{
			cout << linija << "\t ADMIN" << linija;
			cout << "1. Pregled clanova" << endl;
			cout << "2. Unos nove knjige" << endl;
		/*	cout << "3. Prikazi rezultate testova" << endl;
			cout << "4. Pretraga" << endl;
			cout << "5. Resetuj test za studenta" << endl;
			cout << "6. Prikazi sve studente" << endl;
			cout << "7. Priakzi sva pitanja sa testa" << endl;
			cout << "8. Kraj rada" << crt;*/
			cout << "Unesite izbor: ";
			cin >> izbor;
				cin.ignore();
		} while (izbor<1 || izbor>8);

		return izbor;

	}

//------------------------------------------------------------------------------------------------
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
void registracija_knjige(){
    char nazivknjige[30];
    cout<<"Unesite naziv knjige: "<<endl;
    cin.getline(nazivknjige,30);

    ofstream knjige;
    knjige.open("knjige_nazivi.txt", ios::app);
    knjige<< nazivknjige <<"\n";
    knjige.close();
}

//MAIN
//------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------

int main(){
	
	
	strcpy(admin.administrator.ime_prez, "Ana Anic");
	strcpy(admin.administrator.username, "bibliotekar");
	strcpy(admin.administrator.password, "biblioteka");
	admin.administrator.ID = 0000;
	admin.uloga = administrator;
//------------------------------------------------------------------------------------------------	
    char nazivknjige[30];

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

//------------------------------------------------------------------------------------------------	
	//DATOTEKA
//------------------------------------------------------------------------------------------------
	fstream knjige;
    knjige.open("knjige_nazivi.txt", ios::out);
    knjige.close();
system ("pause");
return 0;
}


