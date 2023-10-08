#include "keyword.h"

void createList(list_key &L){
    first(L)=NULL;
    last(L)=NULL;
}
address_key alokasi(infotype_key x){
    address_key P = new elm_key;
    info(P)=x;
    next(P)=NULL;

    return P;
}
void insertFirst (list_key &L, address_key P){
    next(P)=first(L);
    first(L)=P;
}


void deleteKey(list_key &L, infotype_key x){
    address_key P, Q;
    P = findKey(L, x);

    if(P == first(L)){
        deleteFirst_key(L, P);
        cout<<"Keyword berhasil dihapus";
    } else if(P == last(L)){
        deleteLast_key(L, P);
        cout<<"Keyword berhasil dihapus";
    } else if(P==NULL) {
        cout<<"keyword tidak ditemukan";
    } else {
        P = first(L);
        while(info(P) != x && P != NULL){
            Q = P;
            P = next(P);
        }
        deleteAfter_key(L, Q, P);
        cout<<"Keyword berhasil dihapus";
    }
}

void deleteFirst_key(list_key &L, address_key &P){
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
void deleteLast_key(list_key &L, address_key &P){
    address_key Q;
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
void deleteAfter_key(list_key &L, address_key Prec, address_key &P){
    if(Prec == NULL){
        cout<<"  PREC TIDAK DITEMUKAN!  "<<endl;
        P = NULL;
    } else if(Prec == last(L)){
        cout<<"  TIDAK ADA ELEMEN SETELAH PREC  "<<endl;
        P = NULL;
    } else if(next(Prec) == last(L)){
        deleteLast_key(L, P);
    } else {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
    }
}
void printKey(list_key L){
    address_key P=first(L);

   cout<<"List keyword"<<endl;
   while (P!=NULL) {
    cout<<info(P)<<", ";
    P = next(P);
   }
   cout<<endl<<endl;

}
address_key findKey(list_key L, infotype_key x){
    address_key P=first(L);
    while(P!=NULL) {
        if(info(P)==x) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

