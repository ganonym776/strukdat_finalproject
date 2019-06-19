#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <queue>

using namespace std;

bool get_adm = 0;
bool get_staff = 0;

struct Owner{
	string oname = "gunawan";
	string opass = "prasetyo";
}owner;

struct Staff{
	string sname;
	string spass;
}st;

struct Menu{
    string pesanan;
    int jml;
    int hrg;
}mn;

void login();
void addmenu();
void regist_staff();
void regist_member();
void header();

void regist_member(){

}

void regist_staff(){
    cout<<"\nMasukkan Username Staff : "; cin>>st.sname;
    cout<<"Masukkan Password Staff : "; cin>>st.spass;
    cout<<"\nRegistrasi Staff Berhasil..";
};

void header(){
    cout<<"\n=====================================================";
	cout<<"\n||               CAFENE SIMBOKK                    ||";
	cout<<"\n====================================================="<<endl;
};

void login(){
	int login;
	login = 0;

	string pass, uname;

    do{
	cout<<"\n\nPlease Login First...";
	cout<<"\nUsername\t: "; cin>>uname;
	cout<<"Password\t: "; cin>>pass;

	if(uname==st.sname && pass==st.spass){
        get_staff = 1;
        break;
	}
	else if(uname==owner.oname && pass==owner.opass){
        get_adm = 1;
        break;
	}
    else{
        cout<<"\n\nAnda Salah Input Username dan atau Password..!";
        login++;
    }
	}while(login<5);

};

int main(){
    char plh;

    login_session:
	system("CLS");
	SetConsoleTitle("Cafe_Simbok@Terminal");
    header();
    login();

    if(get_adm == 1){
    adm_session:
    system("CLS");
	header();
	cout<<"Selamat Datang "<<owner.oname<<" ..."<<endl;
    cout<<"\nPilih Tindakan : ";
    cout<<"\n\t1. Add/Remove Staff";
    cout<<"\n\t2. Add/Remove Member";
    cout<<"\n\t3. Add/Remove Menu";
    cout<<"\n\t4. Check Balance";
    cout<<"\n\nMasukkan Pilihan [1..4] : "; cin>>plh;

    a:
    switch(plh){
case '1':
    regist_staff();
    break;
case '2':
    break;
case '3':
    break;
case '4':
    break;
default:
    cout<<"Salah Input...";
    getch();
    goto a;
    break;
    }

    b:
    cout<<"Lakukan Tindakan Lagi? y/n : "; cin>>plh;
    if(plh == 'y' || plh == 'Y'){
        goto adm_session;
    }
    else if(plh == 'n' || plh == 'N'){

    }
    else{
        goto b;
    }
    }
    else if(get_staff == 1){
    system("CLS");
	header();
    cout<<"Selamat Datang "<<st.sname<<" ..."<<endl<<endl;
    }


    udg:
    cout<<"Login Kembali? (y/n) : "; cin>>plh;
    if(plh == 'y' || plh == 'Y'){
        get_adm = 0;
        get_staff = 0;
        goto login_session;
    }
    else if(plh == 'n' || plh == 'N'){
      cout<<"\n\nSemoga Harimu Menyenangkan...";
    }
    else{
        goto udg;
    }
}
