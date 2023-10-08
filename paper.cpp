#include "paper.h"

void createList(list_pap &L){
    first(L)=NULL;
    last(L)=NULL;
}
address_pap alokasiin(infotype_pap x){
    address_pap P = new elm_pap;
    info(P)=x;
    next(P)=NULL;

    return P;
}
void insertFirst (list_pap &L, address_pap P){
    if (first(L)==NULL) {
        first(L)=P;
        last(L)=P;
    } else {
    next(P)=first(L);
    first(L)=P;
    }
}
void deletePap(list_pap &L, infotype_pap x){
    address_pap P, Q;
    P = findPap(L, x);

    if(P == first(L)){
        deleteFirst_pap(L, P);
        cout<<"Paper berhasil dihapus";
    } else if(P == last(L)){
        deleteLast_pap(L, P);
        cout<<"Paper berhasil dihapus";
    } else if(P == NULL ) {
        cout<<"Paper tidak ditemukan";
    } else {
        P = first(L);
        while(info(P) != x && P != NULL){
            Q = P;
            P = next(P);
        }
        deleteAfter_pap(L, Q, P);
        cout<<"Paper berhasil dihapus";
    }
}

void deleteFirst_pap(list_pap &L, address_pap &P){
        if(first(L) == NULL){
        cout<<"  DATA KOSONG!  "<<endl;
        P = NULL;
    } else if(next(first(L)) == NULL){
        first(L) = NULL;
        last(L) = NULL;
        P = NULL;
    } else {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}
void deleteLast_pap(list_pap &L, address_pap &P){
    address_pap Q;
    if(first(L) == NULL){
        cout<<"  DATA KOSONG!  "<<endl;
        P = NULL;
    } else if(next(first(L)) == NULL){
        first(L) = NULL;
        last(L) = NULL;
        P = NULL;
    } else {
        P = first(L);
        while(next(P) != NULL){
            Q = P;
            P = next(P);
        }
        next(Q) = NULL;
        last(L) = Q;
    }
}
void deleteAfter_pap(list_pap &L, address_pap Prec, address_pap &P){
    if(Prec == NULL){
        cout<<"  PREC TIDAK DITEMUKAN!  "<<endl;
        P = NULL;
    } else if(Prec == last(L)){
        cout<<"  TIDAK ADA ELEMEN SETELAH PREC  "<<endl;
        P = NULL;
    } else if(next(Prec) == last(L)){
        deleteLast_pap(L, P);
    } else {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}
void printPap(list_pap L){
    address_pap P=first(L);

   cout<<"List Paper"<<endl;
   while (P!=NULL) {
    cout<<info(P)<<", ";
    P = next(P);
   }
   cout<<endl<<endl;

}
address_pap findPap(list_pap L, infotype_pap x){
    address_pap P=first(L);
    while(P!=NULL) {
        if(info(P)==x) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}
