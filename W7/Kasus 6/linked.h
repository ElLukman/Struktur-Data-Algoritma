#ifndef LINKED_H
#define LINKED_H
#include "boolean.h"
#include "type.h"
#include "common.h"
#include "type.h"

typedef struct Orang
{
    char *nama_orang;
    address_orang next_orang;
} Orang;

// Konstruktor
void CreateNode(address_orang *pOrang);
void InsertNode(address_orang *pOrang, char *nama);

// Insert
void InsertFirst(address_orang *pOrang, address_orang PNew);
void InsertLast(address_orang *pOrang, address_orang PNew);
void InsertAfterNama(address_orang *P_Before, address_orang PNew, char *nama_target);

// Modify
void EditNama(address_orang target, char *nama_target);

// Delete
void DeleteFirst(address_orang *pOrang, char *nama);
void DeleteLast(address_orang *pOrang, char *nama);
void DeleteAfterNama(address_orang *PBefore, char *nama);

// Other
boolean isEmptyOrang(address_orang pOrang);

#endif