#ifndef PAPER_H_INCLUDED
#define PAPER_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define countt(P) P->countt
#define next(P) P->next

typedef string infotype_pap;
typedef int infohitung;
typedef struct elm_pap *address_pap;

struct elm_pap {
    infotype_pap info;
    infohitung countt;
    address_pap next;
};

struct list_pap {
    address_pap first;
    address_pap last;
};

void createList(list_pap &L);
address_pap alokasiin(infotype_pap x);
void insertFirst (list_pap &L, address_pap P);
void deletePap(list_pap &L, infotype_pap x);
void deleteFirst_pap(list_pap &L, address_pap &P);
void deleteLast_pap(list_pap &L, address_pap &P);
void deleteAfter_pap(list_pap &L, address_pap Prec, address_pap &P);
void printPap(list_pap L);
address_pap findPap(list_pap L, infotype_pap x);



#endif // PAPER_H_INCLUDED
