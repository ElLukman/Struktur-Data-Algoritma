#ifndef KOTA_H
#define KOTA_H

#include "boolean.h"
#include "type.h"
#include "common.h"
#include "type.h"

typedef struct DaftarKota
{
    address_kota next_kota;
    char *nama_kota;
    address_orang next_orang;
} DaftarKota;

// Konstruktor 
void CreateNodeKota(address_kota *pKota);
void InsertNodeKota(address_kota *pKota, char *nama);

// Insert
void InsertFirstKota(address_kota *pKota, address_kota PNew);
void InsertLastKota(address_kota *pKota, address_kota PNew);
void InsertAfterNamaKota(address_kota *P_Before, char *nama_target, address_kota PNew);

// Delete
void DeleteFirstKota(address_kota *pKota);
void DeleteLastKota(address_kota *pKota);
void DeleteAfterNamaKota(address_kota *pKota, char *nama_target);
void DeleteAllKota(address_kota *pKota);

// Print
void PrintKota(address_kota pKota, char *nama);
void PrintAllKota(address_kota pKota);


// Other
address_kota FindNamaBerdasarkanKota(address_kota pKota, const char *nama);
boolean isEmptyKota(address_kota pKota);

#endif