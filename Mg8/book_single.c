#include "book_single.h"
#include "menu.h"

// Handling
void CreateBuku(address *p)
{
    CLEARBUFFER();

    // BUFFER (VAR_LOKAL)
    char judul_buku[100];
    int stok_buku;
    address new_node;

    MENU_TITLE_CREATE_BUKU();

    printf("Masukan Judul Buku: ");
    fgets(judul_buku, sizeof(judul_buku), stdin);
    judul_buku[strcspn(judul_buku, "\n")] = '\0';

    printf("Masukan Stok Buku: ");
    scanf(" %d", &stok_buku);
    getchar();

    CreateNodeSingle(&new_node);
    FillNodeSingle(&new_node, judul_buku, stok_buku);
    
    InsertLastSingle(p, new_node);
    printf("Buku berhasil ditambahkan!\n");
    PAUSE();
}

void EditBuku(address p)
{
    CLEARBUFFER();

    address current = p; 

    // BUFFER (VAR_LOKAL)
    char judul_buku[100], judul_buku_baru[100], condition[10];
    int stok_buku;

    if (p != nil)
    {
        PrintListBuku(&p);

        printf("Pilih judul buku yang ingin diedit: ");
        fgets(judul_buku, sizeof(judul_buku), stdin);
        judul_buku[strcspn(judul_buku, "\n")] = '\0';

        while (current != nil && strcmp(current->nama, judul_buku) != 0)
        {
            current = current->next;
        }

        if (current == nil)
        {
            printf("Buku tidak ditemukan!\n");
            PAUSE();
            return;
        }

        printf("Masukan Judul Buku Baru: ");
        fgets(judul_buku_baru, sizeof(judul_buku_baru), stdin);
        judul_buku_baru[strcspn(judul_buku_baru, "\n")] = '\0';
        
        printf("Edit Stok Buku?\n");
        printf("Y/N: ");
        fgets(condition, sizeof(condition), stdin);
        judul_buku_baru[strcspn(judul_buku_baru, "\n")] = '\0';

        while (strcmp(condition, "Y\n") != 0 && strcmp(condition, "N\n") != 0)
        {
            system("cls");
            printf("Masukan input yang valid!\n");
            printf("Edit Stok Buku?\n");
            printf("Y/N : ");
            fgets(condition, sizeof(condition), stdin);
            condition[strcspn(condition, "\n")] = '\0';
        }

        if (strcmp(condition, "Y") == 0)
        {
            printf("Masukan Stok Buku: ");
            scanf(" %d", &stok_buku);
            getchar();
            (current)->status = stok_buku;
        }

        free(current->nama);
        (current)->nama = strdup(judul_buku_baru);

        system("cls");
        printf("\nBuku %s berhasil diedit menjadi %s\n", judul_buku, judul_buku_baru);
        PAUSE();
    }
    else 
    {
        printf("Buku masih kosong!");
        PAUSE();
    }
}

void PrintListBuku(address *p)
{
    int num = 1;
    address current = *p;

    if (*p != nil)
    {
        while (current != nil)
        {
            printf("%d. %s [%d]\n", num, (current)->nama, (current)->status);
            current = (current)->next;
            num++;
        }
    }
    else 
    {
        printf("Buku masih kosong \n\n");
    }
}


// Delete
/*
void DeleteFirstBookSingle (address *p)
{
    address temp = nil;

    if(!isEmptySingle(*p))
    {
        // while((*p)->status > 0)
        // {
        //     DeleteFirstAnggotaSingle(p);
        //     (*p)->status --;
        // }
        
        temp = *p;
        *p = (*p)->next;
        temp->next = nil;

        free(temp->nama);
        free(temp);
    }
    else {printf("Node masih kosong \n");}
}

void DeleteLastBookSingle (address *p)
{
    address current, prev = nil;
    
    if (!isEmptySingle(*p))
    {
        current = (*p)->next;

        while ((current)->next != nil)
        {
            prev = current;
            current = (current)->next;
        }

        // while ((current)->next_orang != nil)
        // {
        //     DeleteFirstOrang(&current);
        // }

        if (prev != nil)
        {
            (prev)->next = nil;
        }
        else 
        {
            (current)->next = nil;
        }

        free(current->nama);
        free(current);
    }
    else {printf("Node masih kosong\n");}
}

void DeleteBookByNameSingle (address *p, char *nama_target)
{
    address current = *p;

    if (*p != nil)
    {
        while (current != nil && strcmp(current->nama, nama_target) != 0)
        {
            current = current->next;
        }
    }
    else 
    {printf("Node masih kosong\n");}
}



*/
