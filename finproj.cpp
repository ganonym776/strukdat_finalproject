#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <string>
#include <windows.h>
//#include <stack>
//#include <fstream>
//#include <chrono>
#include <ctime>
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

typedef struct Staff Staff2;
struct Staff{
	int id_staff;
	string nama;
	string sname;
	string spass;
	Staff2 * next;
};

typedef struct Member Member2;
struct Member{
    int id_member=1000;
    string nama;
    string alamat;
    Member2 * next;
};

typedef struct Menu Menu2;
struct Menu{
    int id_menu=0;
    string nama_menu;
    int hrg;
    Menu2 * next;
};

typedef struct History History2;
struct History{
   int buyer;
   int jml_bayar;
   string kasir;
   History2 * next;
};

void login();
void addmenu();
void regist_staff();
void regist_member();
void header();

class StaffOp{
private:
    int a;
    string b,c,d;
    Staff2 *head, *tail, *hapus, *b1, *b2;
public:
    StaffOp(){
    head=NULL;
    tail=NULL;
    }
    void add_staff(int n, string m, string o, string p){
        Staff2 *tmp = new Staff;
        tmp->id_staff = n;
        tmp->nama = m;
        tmp->sname = o;
        tmp->spass = p;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    Staff2* gethead(){
        return head;
    }

    static void display(Staff2 *head){
        if(head==NULL){
            cout<<"No More Data..."<<endl;
        }
        else{
            cout<<head->id_staff<<"\t"<<head->nama<<"\t"<<endl;
            display(head->next);
        }
    }

    void front(int n, string m, string o, string p){
        Staff2 *tmp = new Staff;
        tmp->id_staff = n;
        tmp->nama = m;
        tmp->sname = o;
        tmp->spass = p;
        tmp->next=head;
        head=tmp;
    }

    void del_front(){
    if(head==NULL){
        cout<<"List Kosong..!\n";
    }
    else if(head==tail){
        hapus=head;
        head=NULL;
        tail==NULL;
        delete hapus;
    }
    else{
        hapus=head;
        head=head->next;
        delete hapus;
    }
    }

    void del_back(){
    if(head==NULL){
        cout<<"List Kosong..!\n";
    }
    else if(head==tail){
        hapus=head;
        head=NULL;
        tail==NULL;
        delete hapus;
    }
    else{
        b1=head;
        while(b1->next!=tail)
        {
            b1=b1->next;
        }
        hapus=tail;
        b1->next=NULL;
        tail=b1;
        delete hapus;
    }
    }

    void del_mid(int x){
    Staff2 *b;
    int ada=0;
    b=head;
    if(head==NULL)
        cout<<"List Kosong..!\n";
    else if(b->id_staff==x)
        del_front();
    else if(tail->id_staff==x)
        del_back();
    else{
        while(b!=NULL){
            if(b->id_staff==x){
                ada++;
            }
            b=b->next;
        }
        if(ada==0)
            cout<<"\n-->Data yang dimasukkan tidak valid<--\n\n";
        else{
            b=head;
            while(b->next->id_staff!=x){
                b=b->next;
            }
            b1=b->next;
            b2=b1->next;
            hapus=b1;
            b->next=b2;
            delete hapus;
        }
    }
    }

    void regist_staff(){
    cin.ignore();
    cout<<"\nMasukkan Nama Staff : "; getline(cin,b);
    cout<<"\nMasukkan Username Staff : "; cin>>c;
    cout<<"Masukkan Password Staff : "; cin>>d;
     a = ds + 1000;
    cout<<"\n\nStaff dengan ID "<<a<<" Telah ditambahkan..";
    add_staff(a,b,c,d);
    ds++;
    }

    bool cari_staff(string a, string b){
    Staff2 *c;

    if(c==NULL){
    c=head;
    }
    else{
    while(c!=NULL){
        if(c->sname==a && c->spass==b){
            get_staff=1;
            break;
        }
        c=c->next;
    }
    }
    cout<<get_staff;
    return get_staff;
    }

};

class MemberOp{
private:
    int a;
    string b,c;
    Member2 *head, *tail, *hapus, *b1, *b2;
public:
    MemberOp(){
    head=NULL;
    tail=NULL;
    }
    void add_member(int n, string m, string o){
        Member2 *tmp = new Member;
        tmp->id_member = n;
        tmp->nama = m;
        tmp->alamat = o;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    Member2* gethead(){
        return head;
    }

    static void display(Member2 *head){
        if(head==NULL){
            cout<<"No More Data..."<<endl;
        }
        else{
            cout<<head->id_member<<"\t"<<head->nama<<"\t"<<head->alamat<<endl;
            display(head->next);
        }
    }

    void del_front(){
    if(head==NULL){
        cout<<"List Kosong..!\n";
    }
    else if(head==tail){
        hapus=head;
        head=NULL;
        tail==NULL;
        delete hapus;
    }
    else{
        hapus=head;
        head=head->next;
        delete hapus;
    }
    }

    void del_back(){
    if(head==NULL){
        cout<<"List Kosong..!\n";
    }
    else if(head==tail){
        hapus=head;
        head=NULL;
        tail==NULL;
        delete hapus;
    }
    else{
        b1=head;
        while(b1->next!=tail)
        {
            b1=b1->next;
        }
        hapus=tail;
        b1->next=NULL;
        tail=b1;
        delete hapus;
    }
    }

    void del_mid(int x){
    Member2 *b;
    int ada=0;
    b=head;
    if(head==NULL)
        cout<<"List Kosong..!\n";
    else if(b->id_member==x)
        del_front();
    else if(tail->id_member==x)
        del_back();
    else{
        while(b!=NULL){
            if(b->id_member==x){
                ada++;
            }
            b=b->next;
        }
        if(ada==0)
            cout<<"\n-->Data yang dimasukkan tidak valid<--\n\n";
        else{
            b=head;
            while(b->next->id_member!=x){
                b=b->next;
            }
            b1=b->next;
            b2=b1->next;
            hapus=b1;
            b->next=b2;
            delete hapus;
        }
    }
    }

    void regist_member(){
    cin.ignore();
    cout<<"\nMasukkan Nama : "; getline(cin,b);
    cout<<"Masukkan Alamat : "; getline(cin,c);
    a = dm + 128738;
    cout<<"\n\nMember dengan ID "<<a<<" Telah ditambahkan..";
    add_member(a,b,c);
    dm++;
}

};

class MenuOp{
private:
    int a,b;
    string c;
    Menu2 *head, *tail, *hapus, *b1, *b2;
public:
    MenuOp(){
    head=NULL;
    tail=NULL;
    }
    void add_menu(int n, string m, int o){
        Menu2 *tmp = new Menu;
        tmp->id_menu = n;
        tmp->nama_menu = m;
        tmp->hrg = o;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    Menu2* gethead(){
        return head;
    }

    static void display(Menu2 *head){
        if(head==NULL){
            cout<<"No More Data..."<<endl;
        }
        else{
            cout<<head->id_menu<<"\t"<<head->nama_menu<<"\tRp."<<head->hrg<<endl;
            display(head->next);
        }
    }

    void del_front(){
    if(head==NULL){
        cout<<"List Kosong..!\n";
    }
    else if(head==tail){
        hapus=head;
        head=NULL;
        tail==NULL;
        delete hapus;
    }
    else{
        hapus=head;
        head=head->next;
        delete hapus;
    }
    }

    void del_back(){
    if(head==NULL){
        cout<<"List Kosong..!\n";
    }
    else if(head==tail){
        hapus=head;
        head=NULL;
        tail==NULL;
        delete hapus;
    }
    else{
        b1=head;
        while(b1->next!=tail)
        {
            b1=b1->next;
        }
        hapus=tail;
        b1->next=NULL;
        tail=b1;
        delete hapus;
    }
    }

    void del_mid(int x){
    Menu2 *b;
    int ada=0;
    b=head;
    if(head==NULL)
        cout<<"List Kosong..!\n";
    else if(b->id_menu==x)
        del_front();
    else if(tail->id_menu==x)
        del_back();
    else{
        while(b!=NULL){
            if(b->id_menu==x){
                ada++;
            }
            b=b->next;
        }
        if(ada==0)
            cout<<"\n-->Data yang dimasukkan tidak valid<--\n\n";
        else{
            b=head;
            while(b->next->id_menu!=x){
                b=b->next;
            }
            b1=b->next;
            b2=b1->next;
            hapus=b1;
            b->next=b2;
            delete hapus;
        }
    }
    }

    void regist_menu(){
    cin.ignore();
    cout<<"\nMasukkan Nama Menu : "; getline(cin,c);
    cout<<"Masukkan Harga : Rp."; cin>>b;
    a = dn + 1;
    cout<<"\n\nMenu dengan ID "<<a<<" Telah ditambahkan..";
    add_menu(a,c,b);
    dn++;
}

};

void header(){
    cout<<"\n=====================================================";
	cout<<"\n||               CAFENE SIMBOKK                    ||";
	cout<<"\n====================================================="<<endl;
};

void login(){
	int login;
	login = 0;

    StaffOp so;

	string pass, uname;

    do{

	cout<<"\n\nPlease Login First...";
	cout<<"\nUsername\t: "; cin>>uname;
	cout<<"Password\t: "; cin>>pass;
    so.cari_staff(uname,pass);

    if(get_staff==1){
        break;
    }

	else if(uname==owner.oname && pass==owner.opass){
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
    //playing date & time
    time_t now = time(0);
    //

    get_adm=0;
    get_staff=0;
    char plh;
    int del_id;

    //Definisi Class
    StaffOp so;
    MemberOp mo;
    MenuOp no;
    //End

    login_session:
	system("CLS");
	SetConsoleTitle("@Cafe_Simbok.Terminal");
    header();
    login();

    //Admin Session
    if(get_adm == 1){
    do{
    system("CLS");
	header();
	cout<<"Selamat Datang "<<*aktif<<" ..."<<endl;
	back_adm:
    cout<<"\nPilih Tindakan : ";
    cout<<"\n\t1. Add/Display/Delete Staff";
    cout<<"\n\t2. Add/Display/Delete Member";
    cout<<"\n\t3. Add/Display/Delete Menu";
    cout<<"\n\t4. Check History";
    cout<<"\n\nMasukkan Pilihan [1..4] : "; cin>>plh;


    switch(plh){
case '1':
    cout<<"\n\t\t1. Add Staff";
    cout<<"\n\t\t2. Display Staff";
    cout<<"\n\t\t3. Delete Staff";
    cout<<"\n\nMasukkan Pilihan : "; cin>>plh;
        switch(plh){
    case '1':
        so.regist_staff();
        break;
    case '2':
        StaffOp::display(so.gethead());
        break;
    case '3':
        StaffOp::display(so.gethead());
        cout<<"\nMasukkan ID Staff yg ingin di del : "; cin>>del_id;
        so.del_mid(del_id);
        break;
    }

    break;
case '2':
    cout<<"\n\t\t1. Add Member";
    cout<<"\n\t\t2. Display Member";
    cout<<"\n\t\t3. Delete Member";
    cout<<"\n\nMasukkan Pilihan : "; cin>>plh;
        switch(plh){
    case '1':
        mo.regist_member();
        break;
    case '2':
        MemberOp::display(mo.gethead());
        break;
    case '3':
        MemberOp::display(mo.gethead());
        cout<<"\nMasukkan ID Member yg ingin di del : "; cin>>del_id;
        mo.del_mid(del_id);
        break;
        }
    break;
case '3':
    cout<<"\n\t\t1. Add Menu";
    cout<<"\n\t\t2. Display Menu";
    cout<<"\n\t\t3. Delete Menu";
    cout<<"\n\nMasukkan Pilihan : "; cin>>plh;
        switch(plh){
     case '1':
         no.regist_menu();
        break;
     case '2':
         MenuOp::display(no.gethead());
        break;
     case '3':
         MenuOp::display(no.gethead());
        cout<<"\nMasukkan ID Menu yg ingin di del : "; cin>>del_id;
        no.del_mid(del_id);
        break;
        }
    break;
case '4':
    break;
default:
    cout<<"\nSalah Input...";
    getch();
    goto back_adm;
    }

    b:
    cout<<"\nLakukan Tindakan Lagi? y/n : "; cin>>plh;
        }while(plh == 'y' || plh == 'Y');
        }
    //End Admin Session

    //Staff Session
    else if(get_staff == 1){
    do{
    system("CLS");
	header();
	cout<<"Selamat Datang "<<*aktif<<" ..."<<endl<<endl;
    back_stf:
	cout<<"\nPilih Tindakan : ";
    cout<<"\n\t1. Add/Display/Delete Member";
    cout<<"\n\t2. Add/Display/Delete Menu";
    cout<<"\n\t3. Order";

    cout<<"\n\nMasukkan Pilihan [1..3] : "; cin>>plh;


    switch(plh){
case '1':
    cout<<"\n\t\t1. Add Member";
    cout<<"\n\t\t2. Display Member";
    cout<<"\n\t\t3. Delete Member";
    cout<<"\n\nMasukkan Pilihan : "; cin>>plh;
        switch(plh){
    case '1':
        mo.regist_member();
        break;
    case '2':
        MemberOp::display(mo.gethead());
        break;
    case '3':
        MemberOp::display(mo.gethead());
        cout<<"\nMasukkan ID Member yg ingin di del : "; cin>>del_id;
        mo.del_mid(del_id);
        break;
        }
    break;
case '2':
    cout<<"\n\t\t1. Add Menu";
    cout<<"\n\t\t2. Display Menu";
    cout<<"\n\t\t3. Delete Menu";
    cout<<"\n\nMasukkan Pilihan : "; cin>>plh;
        switch(plh){
     case '1':
         no.regist_menu();
        break;
     case '2':
         MenuOp::display(no.gethead());
        break;
     case '3':
         MenuOp::display(no.gethead());
        cout<<"\nMasukkan ID Menu yg ingin di del : "; cin>>del_id;
        no.del_mid(del_id);
        break;
    }
    break;
case '3':
   // show_menu();
    break;
default:
    cout<<"\nSalah Input...";
    getch();
    goto back_stf;
    }

        c:
    cout<<"\nLakukan Tindakan Lagi? y/n : "; cin>>plh;
        }while(plh == 'y' || plh == 'Y');
}
    //End Staff Session

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
