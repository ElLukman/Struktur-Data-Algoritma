#include "kota.h"
#include "linked.h"

// Konstruktor 
void CreateNode(address_kota *pKota)
{
    *pKota = (address_kota) malloc(sizeof(DaftarKota));
    if (*pKota == nil)
    {printf("Alokasi gagal\n");}
}

void InsertNode(address_kota *pKota, char *nama)
{
    if(*pKota != nil)
    {
        (*pKota)->next_kota = nil;
        (*pKota)->nama_kota = strdup(nama);
        (*pKota)->next_orang = nil;
    }
}

// Insert
void InsertFirstNode(address_kota *pKota, address_kota PNew)
{
    if(PNew != nil)
    {
        (PNew)->next_kota = *pKota;
        *pKota = PNew;
    }
    else {printf("Node belum dialokasi\n");}
}

void InsertLastNode(address_kota *pKota, address_kota PNew)
{
    address_kota current = *pKota;
    if (PNew != nil)
    {
        (PNew)->next_kota = nil;
        if (isEmptyKota(*pKota))
        {
            *pKota = PNew;
        }
        else 
        {
            while ((current)->next_kota != nil)
            {
                current = (current)->next_kota;
            }   
            (current)->next_kota = PNew;
        }
    }
    else {printf("Node belum dialokasi\n");}
}

void InsertAfterNama(address_kota *P_Before, char *nama_target, address_kota PNew)
{
    address_kota current = *P_Before;

    while (current != nil && strcmp(current->nama_kota, nama_target) != 0)
    {
        current = (current)->next_kota;
    }

    if (current != nil && PNew != nil)
    {
        (PNew)->next_kota = (current)->next_kota;
        (current)->next_kota = PNew;
    }
    else {printf("Target tidak ditemukan atau node belum dialokasi \n");}
}

// Delete
void DeleteFirstNode(address_kota *pKota)
{
//     address_kota temp;
//     if (!isEmptyKota(*pKota))
//     {
//         temp = *pKota;
//         *pKota = (temp)->next_kota;
//         free(temp);
//     }
//     else {printf("Node belum dialokasi \n");}
// 
}

void DeleteLastNode(address_kota *pKota)
{

}

void DeleteAfterNama(address_kota *pKota, char *nama)
{

}

void DeleteAll(address_kota *pKota, char *nama)
{

}

// Print
void PrintAll()
{

}

void PrintKota(char *nama)
{

}

// Other
address_kota FindNamaBerdasarkanKota(const char *nama)
{

}

boolean isEmptyKota(address_kota pKota)
{
    return (pKota == nil);
}
