#ifndef KEYWORD_H_INCLUDED
#define KEYWORD_H_INCLUDED


#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next

typedef string infotype_key;
typedef int infohitung;
typedef struct elm_key *address_key;

struct elm_key {
    infotype_key info;
    address_key next;
};

struct list_key {
    address_key first;
    address_key last;
};

void createList(list_key &L);
address_key alokasi(infotype_key x);
void insertFirst (list_key &L, address_key P);
void deleteKey(list_key &L, infotype_key x);
void deleteFirst_key(list_key &L, address_key &P);
void deleteLast_key(list_key &L, address_key &P);
void deleteAfter_key(list_key &L, address_key Prec, address_key &P);
void printKey(list_key L);
address_key findKey(list_key L, infotype_key x);


#endif // KEYWORD_H_INCLUDED
