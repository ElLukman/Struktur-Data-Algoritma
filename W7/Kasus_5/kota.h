#ifndef KOTA_H
#define KOTA_H

#include "boolean.h"
#include "type.h"
#include "common.h"
#include "linked.h"

typedef struct NodeKota
{
    char *kota;
    address headOrang;
} NodeKota;

extern NodeKota daftarKota[6];

// Konstruktor
void initKota();

// Insert
void InsertKota(int index, const char *Nama);

// Delete
void DeleteKota(int index, const char *Nama);

// Print
void PrintAll();
void PrintKota(int index);

// Other
void FindNamaBerdasarkanKota(const char *Nama);
boolean isEmpty(address head);

#endif
