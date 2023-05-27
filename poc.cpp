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

//void unosClana(){}
	
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
