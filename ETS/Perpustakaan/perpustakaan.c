#include "perpustakaan.h"
#include "linked.h"

// Konstruktor 
void CreateNodebuku(address_buku *pbuku)
{
    *pbuku = (address_buku) malloc(sizeof(Daftarbuku));
    if (*pbuku == nil)
    {printf("Alokasi gagal\n");}
}

void InsertNodebuku(address_buku *pbuku, char *nama)
{
    if(*pbuku != nil)
    {
        (*pbuku)->next_buku = nil;
        (*pbuku)->nama_buku = strdup(nama);
        (*pbuku)->next_orang = nil;
    }
}

// Insert
void InsertFirstbuku(address_buku *pbuku, address_buku PNew)
{
    if(PNew != nil)
    {
        (PNew)->next_buku = *pbuku;
        *pbuku = PNew;
    }
    else {printf("Node belum dialokasi\n");}
}

void InsertLastbuku(address_buku *pbuku, address_buku PNew)
{
    address_buku current = *pbuku;

    if (PNew != nil)
    {
        (PNew)->next_buku = nil;
        if (isEmptybuku(*pbuku))
        {
            *pbuku = PNew;
        }
        else 
        {
            while ((current)->next_buku != nil)
            {
                current = (current)->next_buku;
            }   
            (current)->next_buku = PNew;
        }
    }
    else {printf("Node belum dialokasi\n");}
}

void InsertAfterNamabuku(address_buku *P_Before, char *nama_target, address_buku PNew)
{
    address_buku current = *P_Before;

    while (current != nil && strcmp(current->nama_buku, nama_target) != 0)
    {
        current = (current)->next_buku;
    }

    if (current != nil && PNew != nil)
    {
        (PNew)->next_buku = (current)->next_buku;
        (current)->next_buku = PNew;
    }
    else {printf("Target tidak ditemukan atau node belum dialokasi \n");}
}

// Delete
void DeleteFirstbuku(address_buku *pbuku)
{
    address_buku temp = nil;

    if(!isEmptybuku(*pbuku))
    {
        while((*pbuku)->next_orang != nil)
        {
            DeleteFirstOrang(pbuku);
        }
        
        temp = *pbuku;
        *pbuku = (*pbuku)->next_buku;
        temp->next_buku = nil;

        free(temp->nama_buku);
        free(temp);
    }
    else {printf("Node masih kosong \n");}
}

void DeleteLastbuku(address_buku *pbuku)
{
    address_buku current, prev = nil;
    
    if (!isEmptybuku(*pbuku))
    {
        current = (*pbuku)->next_buku;

        while ((current)->next_buku != nil)
        {
            prev = current;
            current = (current)->next_buku;
        }

        while ((current)->next_orang != nil)
        {
            DeleteFirstOrang(&current);
        }

        if (prev != nil)
        {
            (prev)->next_buku = nil;
        }
        else 
        {
            (current)->next_buku = nil;
        }

        free(current->nama_buku);
        free(current);
    }
    else {printf("Node masih kosong\n");}
}

void DeleteAfterNamabuku(address_buku *pbuku, char *nama_target)
{
    address_buku temp;
    address_buku current = *pbuku;

    if (current != nil)
    {
        while (current != nil && strcmp(current->nama_buku, nama_target) != 0)
        {
            current = current->next_buku;
        }

        if (current != nil && current->next_buku != nil)
        {
            temp = current->next_buku;

            while (temp->next_orang != nil)
            {
                DeleteFirstOrang(&temp); 
            }

            current->next_buku = temp->next_buku;
            temp->next_buku = nil;

            free(temp->nama_buku);
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

void DeleteAllbuku(address_buku *pbuku)
{
    while (!isEmptybuku(*pbuku))
    {
        DeleteFirstbuku(pbuku);
    }
}

// Print
void PrintAllbuku(address_buku pbuku)
{
    int index = 1;
    if (pbuku == nil)
    {
        printf("Daftar buku kosong\n");
    }

    while (pbuku != nil)
    {
        printf("[buku-%d-'%s']", index, pbuku->nama_buku);

        address_orang current = pbuku->next_orang;
        while (current != nil)
        {
            printf("-> %s ", current->nama_orang);
            current = current->next_orang;
        }
        pbuku = pbuku->next_buku;
        index++;
        printf("\n");
    }
}

void Printbuku(address_buku pbuku, char *nama)
{
    if (pbuku == nil)
    {printf("buku dengan nama %s tidak ditemukan\n", nama);}

    while (pbuku != nil)
    {
        if (strcmp(pbuku->nama_buku, nama) == 0)
        {
            printf("[buku '%s']",pbuku->nama_buku);

            address_orang current = pbuku->next_orang;
            while (current != nil)
            {
                printf("-> %s ", current->nama_orang);
                current = current->next_orang;
            }
            return;
        }
        pbuku = pbuku->next_buku;
    }
}

// Other
address_buku FindNamaBerdasarkanbuku(address_buku pbuku, const char *nama)
{
    while (pbuku != nil)
    {
        address_orang current = pbuku->next_orang;
        while (current != nil)
        {
            if (strcmp(current->nama_orang, nama) == 0)
            {
                printf("Orang dengan nama %s ditemukan di buku %s", nama, pbuku->nama_buku);
                return pbuku; 
            }
            current = current->next_orang;
        }
        pbuku = pbuku->next_buku;
    }

    printf("Orang dengan nama %s tidak ditemukan di buku manapun", nama);
    return nil; 
}

boolean isEmptybuku(address_buku pbuku)
{
    return (pbuku == nil);
}
