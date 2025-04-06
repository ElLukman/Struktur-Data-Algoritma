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
void CreateNode(address_kota *pKota);
void InsertNode(address_kota *pKota, char *nama);

// Insert
void InsertFirstNode(address_kota *pKota, address_kota PNew);
void InsertLastNode(address_kota *pKota, address_kota PNew);
void InsertAfterNama(address_kota *P_Before, char *nama_target, address_kota PNew);

// Delete
void DeleteFirstNode(address_kota *pKota);
void DeleteLastNode(address_kota *pKota);
void DeleteAll(address_kota *pKota, char *nama);

// Print
void PrintAll();
void PrintKota(char *nama);


// Other
address_kota FindNamaBerdasarkanKota(const char *nama);
boolean isEmptyKota(address_kota pKota);

#endif