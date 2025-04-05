#include "linked.h"
#include "kota.h"
NodeKota daftarKota[6];

// Konstruktor
void initKota()
{
    for (int i = 0; i < 6; i++)
    {
        daftarKota[i].kota = nil;
        daftarKota[i].headOrang = nil;
    }
}

// Insert
void InsertKota(int index, const char *Nama)
{
    daftarKota[index].kota = strdup(Nama);
    daftarKota[index].headOrang = nil;
}

// Delete
void DeleteKota(int index, const char *Nama)
{
    address current = daftarKota[index].headOrang;
    char tempNama[30];

    while(!isEmpty(daftarKota[index].headOrang))
    {
        DeleteFirst(&daftarKota[index].headOrang, tempNama);
    }

    if (daftarKota[index].kota != nil)
    {
        free(daftarKota[index].kota);
        daftarKota[index].kota = nil;
    }
}

// Print
void PrintAll()
{
    for (int i = 0; i < 6; i++)
    {
        if(daftarKota[i].kota != nil)
        {
            printf("kota[%d]: %s -> ", i+1, daftarKota[i].kota);
            address current = daftarKota[i].headOrang;
            while(current != nil)
            {
                printf("%s -> ", current->nama_orang);
                current = current->next;
            }
            printf("\n");
        }
    }
}

void PrintKota(int index)
{
    if(daftarKota[index].kota != nil)
    {
        printf("kota[%d]: %s -> ", index, daftarKota[index].kota);
        address current = daftarKota[index].headOrang;
        while(current != nil)
        {
            printf("%s -> ", current->nama_orang);
            current = current->next;
        }
        printf("\n");
    }
    else {printf("Kota belum diinisialisasi\n");}
}

// Other
void FindNamaBerdasarkanKota(const char *Nama)
{
    for (int i = 0; i < 6; i++)
    {
        address current = daftarKota[i].headOrang;
        while (current != nil)
        {
            if(strcmp(current->nama_orang, Nama) == 0)
            {
                printf("%s ditemukan di kota %s\n", Nama, daftarKota[i].kota);
                return;
            }
            current = (current)->next;
        }
    }
    printf("Nama %s tidak ditemukan di kota manapun.\n", Nama);
}

boolean isEmpty(address head)
{
    return head == nil;
}