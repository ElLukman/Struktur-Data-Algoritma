#ifndef LINKED_H
#define LINKED_H
#include "boolean.h"
#include "type.h"
#include "common.h"
#include "type.h"


typedef struct Orang
{
    address_pinjam next_pinjam;
    char *nama_orang;
    kunci key;
    address_orang next_orang;
} Orang;

typedef struct Storage
{
    address_buku cnc; 
    boolean status;
} Storage;

// Konstruktor
void CreateNodeOrang(address_orang *pOrang);
void InsertNodeOrang(address_orang *pOrang, char *nama, kunci key);

// Insert
void InsertFirstOrang(address_buku *pbuku, address_orang PNew);
void InsertLastOrang(address_buku *pbuku, address_orang PNew);
void InsertAfterNamaOrang(address_buku *pbuku, address_orang PNew, char *nama_target);

// Modify
void EditNamaOrang(address_buku *pbuku, char *nama_baru, char *nama_target);

// Delete
void DeleteFirstOrang(address_buku *pbuku);
void DeleteLastOrang(address_buku *pbuku);
void DeleteAfterNamaOrang(address_buku *pbuku, char *nama_target);

// Other
boolean isEmptyOrang(address_orang pOrang);

#endif