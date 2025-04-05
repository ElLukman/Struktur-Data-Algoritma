#ifndef LINKED_H
#define LINKED_H

#include "boolean.h"
#include "type.h"
#include "common.h"
#include "kota.h"

typedef struct Orang
{
    char *nama_orang;
    address next;
} Orang;

// Konstruktor
void CreateNode(address *PNew);
void InsertNode(address *PNew, char *Nama);

// Insert
void InsertFirst(address *head, address PNew);
void InsertLast(address *head, address PNew);
void InsertAfter(address *P_After, address PNew);

// Modify
void EditNama(address target, char *Nama);

// Delete
void DeleteFirst(address*head, char *Nama);
void DeleteLast(address*head, char *Nama);
void DeleteAfter(address*PBefore, char *Nama);
void Dealloc(address *pNode);

// Other
address FindOrang(address head, const char *Nama);
boolean isEmptyList(address head);

#endif