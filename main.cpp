/* NAMA     : IMAM PRAYOGA        (1301190346)
              DIKA FAJAR RAMADHAN (1301190260)
   KELOMPOK : 5
   KELAS    : IF-43-10
*/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include "keyword.h"
#include "paper.h"
#include "relasi_key_pap.h"

using namespace std;

list_key keywords;
list_pap paper;
list_r relasi;
int main()
{
mulai:
system("cls");
int pil;
string m,n;
cout<<"--------Menu----------\n";
cout<<" 1. Input Paper                \n";
cout<<" 2. Input Keyword                \n";
cout<<" 3. Menampilkan Paper            \n";
cout<<" 4. Menampilkan Keyword          \n";
cout<<" 5. Menghubungkan Paper dan keyword                \n";
cout<<" 6. Menghapus hubungan paper dan keyword            \n";
cout<<" 7. Menghapus Paper                \n";
cout<<" 8. Menghapus Keyword              \n";
cout<<" 9. Menampilkan relasi yang ada (dari keyword maupun paper)      \n";
cout<<" 10. Menampilkan keyword terpopuler         \n";
cout<<" 11. Mencari paper dengan memasukan keyword      \n";
cout<<" 12. Menampilkan paper berkeyword sama          \n";
cout<<" 13. Exit                                    \n";
cout<<"----------------------\n";
cout<<"Masukan Pilihan anda[1..13]= ";cin>>pil;

switch(pil) {
case 1:
    system("cls");
    cout<<"Input paper = ";
    cin>>m;
    insertFirst(paper,alokasiin(m));
    getch();
    goto mulai;

case 2:
    system("cls");
    cout<<"Input Keyword = ";
    cin>>m;
    insertFirst(keywords,alokasi(m));
    getch();
    goto mulai;

case 3:
    system("cls");
    printPap(paper);
    getch();
    goto mulai;

case 4:
    system("cls");
    printKey(keywords);
    getch();
    goto mulai;

case 5:
    system("cls");
    cout<<"Input paper yang ingin dihubungkan = ";
    cin>>m;
    cout<<endl;
    cout<<"Input keyword yang ingin dihubungkan = ";
    cin>>n;
    connect(relasi,paper,keywords,m,n);
    getch();
    goto mulai;

case 6:
    system("cls");
    cout<<"Input paper yang ingin dihapus hubungannya = ";
    cin>>m;
    cout<<"keyword dari paper = ";
    cin>>n;
    disconnect(relasi,m,n);
    getch();
    goto mulai;

case 7:
    system("cls");
    cout<<"Input paper yang ingin dihapus = ";
    cin>>m;
    deletePap(paper,m);
    disconnectPap(relasi,paper,m);
    cout<<endl;
    getch();
    goto mulai;

case 8:
    system("cls");
    cout<<"Input keyword yang ingin dihapus = ";
    cin>>m;
    deleteKey(keywords,m);
    disconnectKey(relasi,keywords,m);
    getch();
    goto mulai;

case 9:
    system("cls");
    cout<<"Print relasi dari Keyword"<<endl;
    printRelasiKey(relasi,keywords);
    cout<<endl;

    printRelasiPap(relasi,paper);
    getch();
    goto mulai;

case 10:
    system("cls");
    KeyPop(relasi,keywords);
    getch();
    goto mulai;

case 11:
    system("cls");
    cout<<"Masukan keyword = ";
    cin>>m;
    SameKey(relasi,keywords,m);
    getch();
    goto mulai;

case 12:
    system("cls");
    cout<<"List paper-paper yang memiliki keyword sama = "<<endl;
    printRelasiKey(relasi,keywords);
    getch();
    goto mulai;

case 13:
    system("cls");
    cout<<"TERIMA KASIH SUDAH BERKUNJUNG :)"<<endl;
    getch();
    exit(0);

default:
    system("cls");
    cout<<"\n Tidak ada pilihan yang dimaksud, silahkan masukkan pilihan dengan benar";
   getch();
   goto mulai;
}

    return 0;
}
