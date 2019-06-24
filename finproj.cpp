#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <string>
#include <windows.h>
//#include <stack>
//#include <fstream>
#include <vector>
using namespace std;


bool get_adm;
bool get_staff;
int ds, dm, dn, dh;
string *aktif;

struct Owner{
    string nama = "Gunawan Prasetyo";
	string oname = "gunawan";
	string opass = "prasetyo";
}owner;

struct Staff{
	int id_staff;
	string nama;
	string sname;
	string spass;
}st[10];

struct Member{
    int id_member=1000;
    string nama;
    string alamat;
}mbr[100];

struct Menu{
    int id_menu=0;
    string menu;
    int hrg;
}mn[100];

struct History{
   int buyer;
   int jml_bayar;
   string kasir;

};

void login();
void addmenu();
void regist_staff();
void regist_member();
void header();

class sorting{
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
};

void addmenu(){

cout<<"\nMasukkan Nama Menu : "; cin>>mn[dn].menu;
cout<<"Masukkan Harga : Rp."; cin>>mn[dn].hrg;
mn[dn].id_menu = dn + 1;
cout<<"\n\nMenu dengan ID "<<mn[dn].id_menu<<" Telah ditambahkan..";
dn++;
}

void show_menu(){
cout<<"id_menu\t\tNama\t\tHarga"<<endl;
for(int i=0;i<dn;i++){
    cout<<mn[i].id_menu<<"\t\t"<<mn[i].menu<<"\t\tRp."<<mn[i].hrg<<endl;
}
}

void regist_member(){

    cout<<"\nMasukkan Nama : "; cin>>mbr[dm].nama;
    cout<<"Masukkan Alamat : "; cin>>mbr[dm].alamat;
    mbr[dm].id_member = dm + 128738;
    cout<<"\n\nMember dengan ID "<<mbr[dm].id_member<<" Telah ditambahkan..";
    dm++;
}

void regist_staff(){

    cout<<"\nMasukkan Nama Staff : "; getline(cin, st[ds].nama);
    cout<<"\nMasukkan Username Staff : "; cin>>st[ds].sname;
    cout<<"Masukkan Password Staff : "; cin>>st[ds].spass;
     st[ds].id_staff = ds + 1000;
    cout<<"\n\nStaff dengan ID "<<st[ds].id_staff<<" Telah ditambahkan..";
    ds++;
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


        for(int i = 0;i<ds;i++){
            if(uname==st[i].sname && pass==st[i].spass){
            aktif=&st[i].nama;
            get_staff = 1;
            break;
            }
        }

	if(uname==owner.oname && pass==owner.opass){
        get_adm = 1;
        aktif=&owner.oname;
        break;
	}

    else if(get_adm==0 && get_staff==0){
        cout<<"\n\nAnda Salah Input Username dan atau Password..!";
        login++;
    }
	}while(login<5 && get_staff!=1);

};

int main(){
    get_adm=0;
    get_staff=0;
    char plh;

    login_session:
	system("CLS");
	SetConsoleTitle("@Cafe_Simbok.Terminal");
    header();
    login();

    if(get_adm == 1){
    adm_session:
    system("CLS");
	header();
	cout<<"Selamat Datang "<<*aktif<<" ..."<<endl;
    cout<<"\nPilih Tindakan : ";
    cout<<"\n\t1. Add/Remove Staff";
    cout<<"\n\t2. Add/Remove Member";
    cout<<"\n\t3. Add/Remove Menu";
    cout<<"\n\t4. Check History";
    cout<<"\n\nMasukkan Pilihan [1..4] : "; cin>>plh;


    switch(plh){
case '1':

    regist_staff();
    cout<<"\nLihat Daftar Staff...";

    break;
case '2':
    regist_member();
    break;
case '3':
    addmenu();
    break;
case '4':
    break;
default:
    cout<<"\nSalah Input...";
    getch();
    goto adm_session;
    }

    b:
    cout<<"\nLakukan Tindakan Lagi? y/n : "; cin>>plh;
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
    stf_session:
    system("CLS");
	header();
	cout<<"Selamat Datang "<<*aktif<<" ..."<<endl<<endl;

	cout<<"\nPilih Tindakan : ";
    cout<<"\n\t1. Add/Remove Member";
    cout<<"\n\t2. Add/Remove Menu";
    cout<<"\n\t3. Order";

    cout<<"\n\nMasukkan Pilihan [1..3] : "; cin>>plh;


    switch(plh){
case '1':
    regist_member();
    cout<<"\nLihat Daftar Member...";
    break;
case '2':
    addmenu();
    break;
case '3':
    show_menu();
    break;
default:
    cout<<"\nSalah Input...";
    getch();
    goto stf_session;
    }

        c:
    cout<<"\nLakukan Tindakan Lagi? y/n : "; cin>>plh;
        if(plh == 'y' || plh == 'Y'){
        goto stf_session;
        }
        else if(plh == 'n' || plh == 'N'){

        }
        else{
        goto c;
        }

}


    udg:
    cout<<"\nLogin Kembali? (y/n) : "; cin>>plh;
    if(plh == 'y' || plh == 'Y'){
        get_adm = 0;
        get_staff = 0;
        aktif=nullptr;
        goto login_session;
    }
    else if(plh == 'n' || plh == 'N'){
      cout<<"\n\nSemoga Harimu Menyenangkan...";
    }
    else{
        goto udg;
    }
}
