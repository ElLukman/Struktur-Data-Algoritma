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
void CreateNodeOrang(address_orang *pOrang);
void InsertNodeOrang(address_orang *pOrang, char *nama);

// Insert
void InsertFirstOrang(address_kota *pKota, address_orang PNew);
void InsertLastOrang(address_kota *pKota, address_orang PNew);
void InsertAfterNamaOrang(address_kota *pKota, address_orang PNew, char *nama_target);

// Modify
void EditNamaOrang(address_kota *pKota, char *nama_baru, char *nama_target);

// Delete
void DeleteFirstOrang(address_kota *pKota);
void DeleteLastOrang(address_kota *pKota);
void DeleteAfterNamaOrang(address_kota *pKota, char *nama_target);

// Other
boolean isEmptyOrang(address_orang pOrang);

#endif