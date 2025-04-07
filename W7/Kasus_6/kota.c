#include "kota.h"
#include "linked.h"

// Konstruktor 
void CreateNodeKota(address_kota *pKota)
{
    *pKota = (address_kota) malloc(sizeof(DaftarKota));
    if (*pKota == nil)
    {printf("Alokasi gagal\n");}
}

void InsertNodeKota(address_kota *pKota, char *nama)
{
    if(*pKota != nil)
    {
        (*pKota)->next_kota = nil;
        (*pKota)->nama_kota = strdup(nama);
        (*pKota)->next_orang = nil;
    }
}

// Insert
void InsertFirstKota(address_kota *pKota, address_kota PNew)
{
    if(PNew != nil)
    {
        (PNew)->next_kota = *pKota;
        *pKota = PNew;
    }
    else {printf("Node belum dialokasi\n");}
}

void InsertLastKota(address_kota *pKota, address_kota PNew)
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

void InsertAfterNamaKota(address_kota *P_Before, char *nama_target, address_kota PNew)
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
void DeleteFirstKota(address_kota *pKota)
{
    address_kota temp = nil;

    if(!isEmptyKota(*pKota))
    {
        while((*pKota)->next_orang != nil)
        {
            DeleteFirstOrang(pKota);
        }
        
        temp = *pKota;
        *pKota = (*pKota)->next_kota;
        temp->next_kota = nil;

        free(temp->nama_kota);
        free(temp);
    }
    else {printf("Node masih kosong \n");}
}

void DeleteLastKota(address_kota *pKota)
{
    address_kota current, prev = nil;
    
    if (!isEmptyKota(*pKota))
    {
        current = (*pKota)->next_kota;

        while ((current)->next_kota != nil)
        {
            prev = current;
            current = (current)->next_kota;
        }

        while ((current)->next_orang != nil)
        {
            DeleteFirstOrang(&current);
        }

        if (prev != nil)
        {
            (prev)->next_kota = nil;
        }
        else 
        {
            (current)->next_kota = nil;
        }

        free(current->nama_kota);
        free(current);
    }
    else {printf("Node masih kosong\n");}
}

void DeleteAfterNamaKota(address_kota *pKota, char *nama_target)
{
    address_kota temp;
    address_kota current = *pKota;

    if (current != nil)
    {
        while (current != nil && strcmp(current->nama_kota, nama_target) != 0)
        {
            current = current->next_kota;
        }

        if (current != nil && current->next_kota != nil)
        {
            temp = current->next_kota;

            while (temp->next_orang != nil)
            {
                DeleteFirstOrang(&temp); 
            }

            current->next_kota = temp->next_kota;
            temp->next_kota = nil;

            free(temp->nama_kota);
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

void DeleteAllKota(address_kota *pKota)
{
    while (!isEmptyKota(*pKota))
    {
        DeleteFirstKota(pKota);
    }
}

// Print
void PrintAllKota(address_kota pKota)
{
    int index = 1;
    if (pKota == nil)
    {
        printf("Daftar kota kosong\n");
    }

    while (pKota != nil)
    {
        printf("[Kota-%d-'%s']", index, pKota->nama_kota);

        address_orang current = pKota->next_orang;
        while (current != nil)
        {
            printf("-> %s ", current->nama_orang);
            current = current->next_orang;
        }
        pKota = pKota->next_kota;
        index++;
        printf("\n");
    }
}

void PrintKota(address_kota pKota, char *nama)
{
    if (pKota == nil)
    {printf("Kota dengan nama %s tidak ditemukan\n", nama);}

    while (pKota != nil)
    {
        if (strcmp(pKota->nama_kota, nama) == 0)
        {
            printf("[Kota '%s']",pKota->nama_kota);

            address_orang current = pKota->next_orang;
            while (current != nil)
            {
                printf("-> %s ", current->nama_orang);
                current = current->next_orang;
            }
            return;
        }
        pKota = pKota->next_kota;
    }
}

// Other
address_kota FindNamaBerdasarkanKota(address_kota pKota, const char *nama)
{
    while (pKota != nil)
    {
        address_orang current = pKota->next_orang;
        while (current != nil)
        {
            if (strcmp(current->nama_orang, nama) == 0)
            {
                printf("Orang dengan nama %s ditemukan di kota %s", nama, pKota->nama_kota);
                return pKota; 
            }
            current = current->next_orang;
        }
        pKota = pKota->next_kota;
    }

    printf("Orang dengan nama %s tidak ditemukan di kota manapun", nama);
    return nil; 
}

boolean isEmptyKota(address_kota pKota)
{
    return (pKota == nil);
}
