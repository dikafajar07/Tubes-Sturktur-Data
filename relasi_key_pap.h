#ifndef RELASI_KEY_PAP_H_INCLUDED
#define RELASI_KEY_PAP_H_INCLUDED

#include "paper.h"
#include "keyword.h"
#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define prev(P) P->prev
#define paper(P) P->paper
#define keyword(P) P->keyword

typedef struct elm_r *address_r;

struct elm_r {
    address_key keyword;
    address_pap paper;
    address_r next;
    address_r prev;
};

struct list_r {
    address_r first;
};

void createList(list_r &L);
address_r alokasi(address_pap P, address_key K );
void insertFirst(list_r &L,address_r P);
void deleteElement(list_r &L,address_r &P);
address_r findElement(list_r L, infotype_pap px, infotype_key kx);
void connect(list_r &LR, list_pap LP, list_key LK, infotype_pap px, infotype_key kx);
void disconnect(list_r &LR, infotype_pap px, infotype_key kx);
void printRelasiKey(list_r LR, list_key LK);
void printRelasiPap(list_r LR, list_pap LP);
void SameKey(list_r LR,list_key LK, infotype_key x);
void disconnectKey(list_r &LR, list_key &LK, infotype_key kx);
void disconnectPap(list_r &LR, list_pap &LP, infotype_pap px);
void KeyPop(list_r LR,list_key LK);

#endif // RELASI_KEY_PAP_H_INCLUDED
