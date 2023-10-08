#include "relasi_key_pap.h"

void createList(list_r &L){
    first(L)=NULL;
}
address_r alokasi(address_pap P, address_key K ){
    address_r R = new elm_r;
    paper(R) = P;
    keyword(R) = K;
    next(R) = NULL;
    prev(R) = NULL;

    return R;
}
void insertFirst(list_r &L,address_r P){
    if(first(L)==NULL) {
        first(L)=P;
        next(P)=P;
        prev(P)=P;
    } else {
        next(P)=first(L);
        prev(P)=prev(first(L));
        next(prev(P))=P;
        prev(first(L))=P;
        first(L)=P;
    }
}

void deleteElement(list_r &L,address_r &P){
    if(next(P)==P) {
        first(L)=NULL;
    } else {
        if(first(L)==P) {
            first(L)=next(P);
        }
        next(prev(P)) = next(P);
        prev(next(P)) = prev(P);
    }
    prev(P) = NULL;
    next(P) = NULL;
}

address_r findElement(list_r L, infotype_pap px, infotype_key kx){
    address_r R = first(L);
    if(R!=NULL) {
        do{
            if(info(paper(R))==px && info(keyword(R))==kx) {
                return R;
            }
            R = next(R);
        } while(R!=first(L));
    }
    return NULL;
}
void connect(list_r &LR, list_pap LP, list_key LK, infotype_pap px, infotype_key kx){
    address_pap P = findPap(LP, px);
    address_key K = findKey(LK, kx);
    if (P!=NULL && K!=NULL) {
        address_r R = alokasi(P,K);
        insertFirst(LR,R);
        cout<<"\nPaper dan keyword berhasil dihubungkan!!"<<endl;
    } else if (P==NULL && K!=NULL) {
        cout<<"\nData paper tidak ada didalam list"<<endl;
    } else if (P!=NULL && K==NULL) {
        cout<<"\nData keyword tidak ada didalam list"<<endl;
    } else if (P==NULL && K==NULL) {
        cout<<"\nKedua data tidak ada didalam list"<<endl;
    }
}

void disconnect(list_r &LR, infotype_pap px, infotype_key kx){
    address_r R = findElement (LR, px, kx);
    if(R!=NULL) {
        deleteElement(LR, R);
        delete R;
        cout<<"\nhubungan berhasil dihapus!";
    } else {
        cout<<"\nPaper dan keyword tidak memiliki hubungan/tidak valid";
    }
}

void disconnectKey(list_r &LR, list_key &LK, infotype_key kx) {
    address_r R = first(LR);

    if(R!=NULL) {
        do{
            if(info(keyword(R))==kx) {
                address_r M = R;
                R = next(R);
                deleteElement(LR,M);
                delete M;
                if(first(LR)==NULL) {
                    R = NULL;
                }
            } else {
                R = next(R);
            }
        }while(R!=first(LR));
    }
}

void disconnectPap(list_r &LR, list_pap &LP, infotype_pap px) {
    address_r R = first(LR);

    if(R!=NULL) {
        do{
            if(info(paper(R))==px) {
                address_r M = R;
                R = next(R);
                deleteElement(LR,M);
                delete M;
                if(first(LR)==NULL) {
                    R = NULL;
                }
            } else {
                R = next(R);
            }
        }while(R!=first(LR));
    }
}

void printRelasiKey(list_r LR, list_key LK){
    address_key P = first(LK);
    while(P!=NULL) {
        cout<<info(P)<<" - ";
        address_r R = first(LR);
        if(R!=NULL) {
            do{
                if(keyword(R)==P) {
                    cout<<info(paper(R))<<", ";
                }
                R=next(R);
            }while (R!=first(LR));
        }
        cout<<endl;
        P = next(P);
    }
    cout<<endl<<endl;
}
void KeyPop(list_r LR, list_key LK) {
address_key P = first(LK);

    int terbanyak;
    string inpo;
    terbanyak = 0;
    while(P!=NULL) {
        address_r R = first(LR);
        if(R!=NULL) {
            do{
                if(keyword(R)==P) {
                    countt(paper(R))=countt(paper(R)) + 1;
                }
                R=next(R);
            }while (R!=first(LR));
        if (terbanyak < countt(paper(R))) {
        terbanyak = countt(paper(R));
        inpo = info(P);
        }
        }
        P = next(P);
    }
    cout<<"keyword terpopuler adalah = ";
    cout<<inpo;
}
void printRelasiPap(list_r LR, list_pap LP){
    address_pap P = first(LP);
    cout<<"Print relasi dari Paper"<<endl;
    while(P!=NULL) {
        cout<<info(P)<<" - ";
        address_r R = first(LR);
        if(R!=NULL) {
            do{
                if(paper(R)==P) {
                    cout<<info(keyword(R))<<", ";
                }
                R=next(R);
            }while (R!=first(LR));
        }
        cout<<endl;
        P = next(P);
    }
    cout<<endl<<endl;
}

void SameKey(list_r LR, list_key LK, infotype_key x) {
        bool tanda;
        tanda = false;
       address_key P = first(LK);
       while(P!=NULL) {
        address_r R = first(LR);
        if(R!=NULL) {
            do {
                if(keyword(R)==P) {
                    if(info(keyword(R))==x) {
                        cout<<info(paper(R))<<", ";
                        tanda=true;
                    }
                    R = next(R);
                }
            }while (R!=first(LR));
        }
        cout<<endl;
        P=next(P);
       }

       if (tanda==false) {
        cout<<"keyword tidak ditemukan / tidak ada paper yang memiliki keyword itu";
       }

}
