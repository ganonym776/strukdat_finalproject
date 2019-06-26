#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <windows.h>
#include <ctime>
#define max 10


using namespace std;


bool get_adm;
bool get_staff;
int ds, dm, dn, dh,hrg_ttl;
string *aktif, *aktif_member;

struct Owner{
    string nama = "Admin@Cafe_simbok.com";
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
    int id_member;
    string nama;
    string alamat;
    Member2 * next;
};

typedef struct Menu Menu2;
struct Menu{
    int id_menu=0;
    string nama_menu;
    int hrg;
    string jenis;
    Menu2 * next;
};

struct History{
    string datetime[max];
    string buyer[max];
    int jml_bayar[max];
    string kasir[max];
    int head;
    int tail;
}story;

void login();
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
        tmp->id_staff  = n;
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

    void del_front(){
    if(head==NULL){
        cout<<"List Kosong..!\n";
    }
    else if(head==tail){
        hapus=head;
        head=NULL;
        tail=NULL;
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

    void search_stf(string username, string password){

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
        cout<<b;
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

    void cari_member(int id){
    Member2 * awal;
    awal=head;
    bool ketemu=0;
    while(awal!=NULL)
    {
        if(awal->id_member==id){
        ketemu=1;
        aktif_member=&awal->nama;
        break;
        }
        awal=awal->next;
    }

    if(ketemu==1){
        cout<<"Member dengan id <"<<id<<"> ditemukan.."<<endl<<endl;
        cout<<awal->id_member<<"\t"<<awal->nama<<"\t"<<awal->alamat<<endl;
    }
    else{
        cout<<"\nMember dengan id <"<<id<<"> Tidak ditemukan...!"<<endl;
    aktif_member=NULL;
    }
    }
};

class MenuOp{
private:
    int a,b;
    string c,d;
    Menu2 *head, *tail, *hapus, *b1, *b2;
public:
    MenuOp(){
    head=NULL;
    tail=NULL;
    }
    void add_menu(int n, string m, int o, string p){
        Menu2 *tmp = new Menu;
        tmp->id_menu = n;
        tmp->nama_menu = m;
        tmp->hrg = o;
        tmp->jenis = p;
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
            cout<<head->id_menu<<"\t"<<head->nama_menu<<"\t\t"<<head->jenis<<"\tRp."<<head->hrg<<endl;
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
    cout<<"Masukkan jenis [Makanan/Minuman] : "; cin>>d;
    cout<<"Masukkan Harga : Rp."; cin>>b;
    a = dn + 1;
    cout<<"\n\nMenu dengan ID "<<a<<" Telah ditambahkan..";
    add_menu(a,c,b,d);
    dn++;
}

    void cari_menu(int id){
    Menu2 * awal;
    awal=head;
    bool ketemu=0;
    while(awal!=NULL)
    {
        if(awal->id_menu==id){
        ketemu=1;
        break;
        }
        awal=awal->next;
    }

    if(ketemu==1){
        cout<<"----------------------------------------------------"<<endl;
        cout<<awal->id_menu<<"\t"<<awal->nama_menu<<"\t"<<awal->jenis<<"\t"<<awal->hrg<<endl;
    }
    else{
        cout<<"\nMenu dengan id <"<<id<<"> Tidak ditemukan...!"<<endl;
    }
    }

    void pembelian(int id, int jml){
    Menu2 * awal;
    int hrgt_brg = 0;
    awal=head;
    bool ketemu=0;
    while(awal!=tail)
    {
        if(awal->id_menu==id){
        ketemu=1;
        break;
        }
        awal=awal->next;
    }

    if(ketemu==1){
        cout<<"----------------------------------------------------"<<endl;
        hrgt_brg=jml*(awal->hrg);
        hrg_ttl=hrg_ttl+hrgt_brg;
        cout<<awal->id_menu<<"\t"<<awal->nama_menu<<"\tx"<<jml<<"\t"<<hrgt_brg<<endl;
    }
    else{
        cout<<"\nMenu dengan id <"<<id<<"> Tidak ditemukan...!"<<endl;
    }
    }

int count ()
{
    Menu2 * hitung;
    hitung = head;
    int c = 0 ;

    /* traverse the entire linked list */
while ( hitung != NULL )
    {
        hitung = hitung->next ;
        c++ ;
    }

    return c ;
}

void selection_sort ( int n )
{
    int i, j, temp;
    string tmp;
    Menu2 *dat_1, *dat_2 ;

    dat_1 = head ;
    for ( i = 0 ; i < n - 1 ; i++ )
    {
        dat_2 = dat_1->next;
        for ( j = i + 1 ; j < n ; j++ )
        {
            if ( dat_1->jenis > dat_2->jenis )
            {
                //menukar jenis dari menu
                tmp = dat_1->jenis ;
                dat_1->jenis = dat_2->jenis ;
                dat_2->jenis = tmp ;
                //menukar harga dari menu
                temp = dat_1->hrg ;
                dat_1->hrg = dat_2->hrg ;
                dat_2->hrg = temp ;
                //menukar nama dari menu
                tmp = dat_1->nama_menu ;
                dat_1->nama_menu = dat_2->nama_menu ;
                dat_2->nama_menu = tmp ;

            }
            dat_2 = dat_2 -> next ;
        }
        dat_1 = dat_1 -> next ;
    }
}


};

class HistoryOp{
public:
void Create(){
   story.head=story.tail=-1;
   }

int IsEmpty(){
   if(story.tail==-1)
       return 1;
   else
       return 0;
}

int IsFull(){
    if(story.tail==max-1)
    {
        Dequeue();
        return 1;
    }
    else
        return 0;
}

void Enqueue(string date,string buyer,int bayar,string staf){
        if(IsEmpty()==1)
        {
            story.head=story.tail=0;
            story.datetime[story.tail]=date;
            story.buyer[story.tail]=buyer;
            story.jml_bayar[story.tail]=bayar;
            story.kasir[story.tail]=staf;
        } else
        if(IsFull()==0)
        {
            story.tail++;
            story.datetime[story.tail]=date;
            story.buyer[story.tail]=buyer;
            story.jml_bayar[story.tail]=bayar;
            story.kasir[story.tail]=staf;
		}
}

void Dequeue(){
    if(IsEmpty()==0){
        for(int i=0; i<=story.tail-1;i++)
        {
            story.datetime[i]=story.datetime[i+1];
            story.buyer[i]=story.buyer[i+1];
            story.jml_bayar[i]=story.jml_bayar[i+1];
            story.kasir[i]=story.kasir[i+1];
        }
        story.tail--;
    }
    else{
        cout<<"\nTidak ada history transaksi..."<<endl;
    }
}

void tampil(){
    if(IsEmpty()==0){
        for(int i=story.head;i<=story.tail-1;i++){
            cout<<story.datetime[i]<<"\t"<<story.buyer[i]<<"\t"<<story.jml_bayar<<"\t"<<story.kasir<<endl;
        }
	}
	else{
        cout<<"\nTidak ada history transaksi..."<<endl;
    }
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
	string username,password;

    do{

	cout<<"\n\nPlease Login First...";
	cout<<"\nUsername\t: "; cin>>username;
	cout<<"Password\t: "; cin>>password;


	if(username==owner.oname && password==owner.opass){
        get_adm = 1;
        aktif=&owner.nama;
        break;
	}
    else if(username=="prasetyo" && password=="gunawan"){
        get_staff=1;
        //so.search_stf(username,password);
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
    time_t now;
    struct tm * timeinfo;
    char buffer[80];
    //

    get_adm=0;
    get_staff=0;
    char plh;
    int del_id, cari, jmlh_pesan, total;
    string common="???????";

    //Definisi Class
    StaffOp so;
    MemberOp mo;
    MenuOp no;
    HistoryOp ho;
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
    cout<<"\n\t\t4. Cari Member";
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
    case '4':
        cout<<"Masukkan ID member yg ingin ditampilkan : "; cin>>cari;
        mo.cari_member(cari);
        }
    break;
case '3':
    cout<<"\n\t\t1. Add Menu";
    cout<<"\n\t\t2. Display Menu";
    cout<<"\n\t\t3. Delete Menu";
    cout<<"\n\t\t4. Cari Menu";
    cout<<"\n\t\t5. Sorting Menu Berdasarkan Jenis";
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
     case '4':
        cout<<"Masukkan ID member yg ingin ditampilkan : ";cin>>cari;
        no.cari_menu(cari);
        break;
     case '5':
        int jml_menu=no.count();
        no.selection_sort(jml_menu);
        cout<<"\nMenu telah diurutkan..."<<endl;
        MenuOp::display(no.gethead());
        }
    break;
case '4':
    ho.tampil();
    break;
default:
    cout<<"\nSalah Input...";
    getch();
    goto back_adm;
    }


    cout<<"\nLakukan Tindakan Lagi? y/n : "; cin>>plh;
        }while(plh == 'y' || plh == 'Y');
}
    //End Admin Session

    //Staff Session
    else if(get_staff == 1){
    do{
    system("CLS");
	header();
	cout<<"Selamat Datang "<<" ..."<<endl<<endl;
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
    cout<<"\n\t\t4. Cari Member";
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
    case '4':
        cout<<"Masukkan ID member yg ingin ditampilkan : "; cin>>cari;
        mo.cari_member(cari);
        }
    break;
case '2':
    cout<<"\n\t\t1. Add Menu";
    cout<<"\n\t\t2. Display Menu";
    cout<<"\n\t\t3. Delete Menu";
    cout<<"\n\t\t4. Cari Menu";
    cout<<"\n\t\t5. Sorting Menu Berdasarkan Jenis";
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
     case '4':
        cout<<"Masukkan ID member yg ingin ditampilkan : ";cin>>cari;
        no.cari_menu(cari);
        break;
     case '5':
        int jml_menu=no.count();
        no.selection_sort(jml_menu);
        cout<<"\nMenu telah diurutkan..."<<endl;
        MenuOp::display(no.gethead());
        }
    break;
case '3':
    hrg_ttl=0;
    cout<<"Ada ID Member? [y/n] : "; cin>>plh;
    if(plh=='y' || plh=='Y'){
        cout<<"Masukkan ID member yg ingin ditampilkan : "; cin>>cari;
        Member2 * awal = NULL;
        mo.cari_member(cari);
        cout<<"---------------------------------------------------------"<<endl<<endl;
        if(aktif_member==NULL){
        *aktif_member = common;
        }
    }
    else{
         *aktif_member = common;
    }
    MenuOp::display(no.gethead());
    do{
        cout<<"\n\nPilih Pesanan... "<<endl;
        cout<<"\nMasukkan ID Menu\t\t: "; cin>>cari;
        cout<<"Masukkan Jumlah Pemesanan\t: "; cin>>jmlh_pesan;
        no.pembelian(cari,jmlh_pesan);
        cout<<"\n\nPesan Lagi? [y/n] : ";cin>>plh;
    }while(plh=='y' || plh=='Y');
    cout<<"---------------------------------------------------------"<<endl;
    if(*aktif_member==common){
        cout<<"Harga Akhir :\t\tRp."<<hrg_ttl<<endl;
    }
    else{
        cout<<"Harga Total :\t\tRp."<<hrg_ttl<<endl;
        cout<<"Diskon Member 10% :\t-"<<hrg_ttl*10/100<<endl;
        hrg_ttl=hrg_ttl-(hrg_ttl*10/100);
        cout<<"Harga Akhir :\t\tRp."<<hrg_ttl<<endl;
    }
    /*time (&now);
    timeinfo = localtime(&now);
    strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
    string datenow(buffer);
    ho.Enqueue(datenow,*aktif_member,hrg_ttl,*aktif);*/
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
