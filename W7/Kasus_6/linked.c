#include "kota.h"
#include "linked.h"

// Konstruktor
void CreateNodeOrang(address_orang *pOrang)
{
    *pOrang = (address_orang) malloc(sizeof(Orang));

    if(isEmptyOrang(*pOrang))
    {printf("Alokasi gagal\n");}
}

void InsertNodeOrang(address_orang *pOrang, char *nama)
{
    if(!isEmptyOrang(*pOrang))
    {
        (*pOrang)->nama_orang = strdup(nama);
        (*pOrang)->next_orang = nil;
    }
}

// Insert
void InsertFirstOrang(address_kota *pKota, address_orang PNew)
{
    if (PNew != nil)
    {
        (PNew)->next_orang = (*pKota)->next_orang;
        (*pKota)->next_orang = PNew;
    }
    else 
    {printf("Node belum dialokasi\n");}
}

void InsertLastOrang(address_kota *pKota, address_orang PNew)
{
    address_orang current = nil;

    if (PNew != nil)
    {
        if(isEmptyOrang((*pKota)->next_orang))
        {
            (*pKota)->next_orang = PNew;
        }
        else 
        {
            current = (*pKota)->next_orang;
            while((current)->next_orang != nil)
            {
                current = (current)->next_orang;
            }
            (current)->next_orang = PNew;
        }
        (PNew)->next_orang = nil;
    }
    else 
    {printf("Node belum dialokasi\n");}
}

void InsertAfterNamaOrang(address_kota *pKota, address_orang PNew, char *nama_target)
{
    address_orang current = (*pKota)->next_orang;

    while (current != nil && strcmp(current->nama_orang, nama_target) != 0)
    {
        current = (current)->next_orang;
    }

    if (current != nil && PNew != nil)
    {
        (PNew)->next_orang = (current)->next_orang;
        (current)->next_orang = PNew;
    }
    else {printf("Nama %s tidak ditemukan sehingga node baru gagal dialokasi\n", nama_target);}   
}

// Modify
void EditNamaOrang(address_kota *pKota, char *nama_baru, char *nama_target)
{
    address_orang current = (*pKota)->next_orang;

    while (current != nil && strcmp(current->nama_orang, nama_target) != 0)
    {
        current = (current)->next_orang;
    }

    if (current != nil)
    {
        free(current->nama_orang);
        (current)->nama_orang = strdup(nama_baru);
    }
    else {printf("Nama %s tidak ditemukan sehingga edit nama gagal\n", nama_target);}
}

// Delete
void DeleteFirstOrang(address_kota *pKota)
{
    address_orang temp = nil;

    if ((*pKota)->next_orang != nil)
    {
        temp = (*pKota)->next_orang;
        (*pKota)->next_orang = temp->next_orang;
        free(temp->nama_orang);
        free(temp);
    }
    else {printf("Node masih kosong\n");}
}

void DeleteLastOrang(address_kota *pKota)
{
    address_orang current, prev = nil;

    if ((*pKota)->next_orang != nil)
    {
        current = (*pKota)->next_orang;

        while ((current)->next_orang != nil)
        {
            prev = current;
            current = (current)->next_orang;
        }

        if (prev != nil)
        {
            (prev)->next_orang = nil;
        }
        else 
        {
            (current)->next_orang = nil;
        }
        free(current->nama_orang);
        free(current);
    }
    else {printf("Node masih kosong\n");}
}

void DeleteAfterNamaOrang(address_kota *pKota, char *nama_target)
{
    address_orang temp;
    address_orang current = (*pKota)->next_orang;

    if (current != nil)
    {
        while (current != nil && strcmp((current)->nama_orang, nama_target) != 0)
        {
            current = (current)->next_orang;
        }
        
        if (current != nil && (current)->next_orang != nil)
        {
            temp = current->next_orang;
            current->next_orang = temp->next_orang;
            temp->next_orang = nil;

            free(temp->nama_orang);
            free(temp);
        }
        else 
        {
            printf("Tidak ada node setelah %s yang bisa dihapus\n", nama_target);
        } 
    }
    else 
    {
        printf("Node masih kosong\n");
    }
}

// Other
boolean isEmptyOrang(address_orang pOrang)
{
    return (pOrang == nil);
}