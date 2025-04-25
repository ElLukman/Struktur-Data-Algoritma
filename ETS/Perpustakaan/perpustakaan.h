#ifndef buku_H
#define buku_H

#include "boolean.h"
#include "type.h"
#include "common.h"
#include "type.h"

typedef struct Daftarbuku
{
    address_buku next_buku;
    char *nama_buku;
    address_orang next_orang;
} Daftarbuku;

// Konstruktor 
void CreateNodebuku(address_buku *pbuku);
void InsertNodebuku(address_buku *pbuku, char *nama);

// Insert
void InsertFirstbuku(address_buku *pbuku, address_buku PNew);
void InsertLastbuku(address_buku *pbuku, address_buku PNew);
void InsertAfterNamabuku(address_buku *P_Before, char *nama_target, address_buku PNew);

// Delete
void DeleteFirstbuku(address_buku *pbuku);
void DeleteLastbuku(address_buku *pbuku);
void DeleteAfterNamabuku(address_buku *pbuku, char *nama_target);
void DeleteAllbuku(address_buku *pbuku);

// Print
void Printbuku(address_buku pbuku, char *nama);
void PrintAllbuku(address_buku pbuku);


// Other
address_buku FindNamaBerdasarkanbuku(address_buku pbuku, const char *nama);
boolean isEmptybuku(address_buku pbuku);

#endif