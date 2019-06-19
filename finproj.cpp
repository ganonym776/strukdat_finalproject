#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <windows.h>

using namespace std;




struct Owner{
	string oname = "gunawan";
	string opass = "prasetyo";
}owner;

struct Staff{
	string sname;
	string spass;
}st;

int main(){
	system("CLS");
	SetConsoleTitle("Cafe_Simbok@Terminal");
	
	int login, login_owner, login_staff;
	login = 0;
	login_owner = 0;
	login_staff = 0;

	cout<<"\n=====================================================";
	cout<<"\n||               CAFENE SIMBOKK                    ||";
	cout<<"\n=====================================================";
	
	string pass, uname;

	cout<<"\n\nPlease Login First...";
	cout<<"\nUsername\t: "; cin>>uname; 
	cout<<"Password\t: "; cin>>pass;


}