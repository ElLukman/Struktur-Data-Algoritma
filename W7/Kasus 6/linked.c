#include "kota.h"
#include "linked.h"

// Konstruktor
void CreateNode(address_orang *pOrang)
{
    *pOrang = (address_orang) malloc(sizeof(Orang));

    if(*pOrang == nil)
    {printf("Alokasi gagal\n");}
}

void InsertNode(address_orang *pOrang, char *nama)
{
    if(*pOrang != nil)
    {
        (*pOrang)->nama_orang = strdup(nama);
        (*pOrang)->next_orang = nil;
    }
}

// Insert
void InsertFirst(address_orang *pOrang, address_orang PNew)
{
    if (PNew != nil)
    {
        (PNew)->next_orang = *pOrang;
        *pOrang = PNew;
    }
    else 
    {printf("Node belum dialokasi\n");}
}

void InsertLast(address_orang *pOrang, address_orang PNew)
{
    address_orang current = nil;

    if (PNew != nil)
    {
        if(isEmptyOrang(*pOrang))
        {
            *pOrang = PNew;
        }
        else 
        {
            while((current)->next_orang != nil)
            current = *pOrang;
            {
                current = (current)->next_orang;
            }
            (current)->next_orang = PNew;
        }
    }
    else 
    {printf("Node belum dialokasi\n");}
    free(current);
}

void InsertAfterNama(address_orang *P_Before, address_orang PNew, char *nama_target)
{
    address_orang current = *P_Before;

    while (current != nil && strcmp(current->nama_orang, nama_target) != 0)
    {
        current = (current)->next_orang;
    }

    if (current != nil && PNew != nil)
    {
        (PNew)->next_orang = (current)->next_orang;
        (current)->next_orang = PNew;
    }
    else {printf("Node belum dialokasi \n");}   
}

// Modify
void EditNama(address_orang target, char *nama_target)
{

}

// Delete
void DeleteFirst(address_orang *pOrang, char *nama)
{

}
void DeleteLast(address_orang *pOrang, char *nama)
{

}
void DeleteAfterNama(address_orang *PBefore, char *nama)
{

}

// Other
boolean isEmptyOrang(address_orang pOrang)
{
    return (pOrang == nil);
}