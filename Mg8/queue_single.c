#include "queue_single.h"

void CreateAnggota(address *p)
{
    CLEARBUFFER();

    // BUFFER (VAR_LOKAL)
    char nama_anggota[100];
    int status_anggota;
    address new_node;

    printf("Masukan Nama Anggota: ");
    fgets(nama_anggota, sizeof(nama_anggota), stdin);
    nama_anggota[strcspn(nama_anggota, "\n")] = '\0';

    while(1)
    {
        MENU_INPUT_LEVEL_ANGGOTA();
        scanf(" %d", &status_anggota);
        getchar();
    
        if (status_anggota == 1)
        {
            CreateNodeSingle(&new_node);
            FillNodeSingle(&new_node, nama_anggota, DOSEN);
            InsertLastSingle(p, new_node);
            printf("Anggota berhasil ditambahkan!\n");
            PAUSE();
            return;
        }
        else if (status_anggota == 2)
        {
            CreateNodeSingle(&new_node);
            FillNodeSingle(&new_node, nama_anggota, MHS);
            InsertLastSingle(p, new_node);
            printf("Anggota berhasil ditambahkan!\n");
            PAUSE();
            return;
        }
        else if (status_anggota == 3)
        { 
            CreateNodeSingle(&new_node);
            FillNodeSingle(&new_node, nama_anggota, MASSA);
            InsertLastSingle(p, new_node);
            printf("Anggota berhasil ditambahkan!\n");
            PAUSE();
            return;
        }   
        else 
        {
            system("cls");
            printf("Input tidak valid!\n");
        }
    }
}

void EditAnggota(address p)
{
    CLEARBUFFER();

    address current = p; 

    // BUFFER (VAR_LOKAL)
    char nama_anggota[100], nama_baru[100], condition[10];
    int status;
    int sub_condition = 1;

    if (p != nil)
    {
        PrintListAnggota(&p);

        printf("Pilih nama anggota yang ingin diedit: ");
        fgets(nama_anggota, sizeof(nama_anggota), stdin);
        nama_anggota[strcspn(nama_anggota, "\n")] = '\0';

        while (current != nil && strcmp(current->nama, nama_anggota) != 0)
        {
            current = current->next;
        }

        if (current == nil)
        {
            printf("Anggota tidak ditemukan!\n");
            PAUSE();
            return;
        }

        printf("Masukan Nama Baru: ");
        fgets(nama_baru, sizeof(nama_baru), stdin);
        nama_baru[strcspn(nama_baru, "\n")] = '\0';
        
        printf("Edit Status?\n");
        printf("Y/N: ");
        fgets(condition, sizeof(condition), stdin);
        nama_baru[strcspn(nama_baru, "\n")] = '\0';

        while (strcmp(condition, "Y\n") != 0 && strcmp(condition, "N\n") != 0)
        {
            system("cls");
            printf("Masukan input yang valid!\n");
            printf("Edit Status?\n");
            printf("Y/N : ");
            fgets(condition, sizeof(condition), stdin);
            condition[strcspn(condition, "\n")] = '\0';
        }

        while (sub_condition == 1)
        {
            if (strcmp(condition, "Y") == 0)
            {
                MENU_EDIT_LEVEL_ANGGOTA();    
                printf("Edit Status: ");
                scanf(" %d", &status);
                getchar();
    
                if (status == 1)
                {
                    (current)->status = DOSEN;
                    sub_condition --;
                }
                else if (status == 2)
                {
                    (current)->status = MHS;
                    sub_condition --;
                }
                else if(status == 3)
                {
                    (current)->status = MASSA;
                    sub_condition --;
                }
                else 
                {
                    system("cls");
                    printf("Input tidak valid!\n");
                }
            }
            sub_condition --;
        }

        free(current->nama);
        (current)->nama = strdup(nama_baru);

        system("cls");
        printf("\n Anggota %s berhasil diedit menjadi %s\n", nama_anggota, nama_baru);
        PAUSE();
    }
    else 
    {
        printf("Anggota masih kosong!");
        PAUSE();
    }
}

void PrintListAnggota(address *p)
{
    int num = 1;
    address current = *p;

    if (*p != nil)
    {
        while (current != nil)
        {
            if (current->status == DOSEN)
            {
                printf("%d. %s [Dosen]\n", num, (current)->nama);
            }
            else if (current->status == MHS)
            {
                printf("%d. %s [Mahasiswa]\n", num, (current)->nama);
            }
            else if (current->status == MASSA)
            {
                printf("%d. %s [Masyarakat Umum]\n", num, (current)->nama);
            }
            current = (current)->next;
            num++;
        }
    }
    else 
    {
        printf("Anggota masih kosong \n\n");
    }
}

// Inisialisasi Queue
void CreateQueueSingle(QueueAnggotaSingle *q)
{
    q->front = nil;
    q->rear = nil;
    q->head = nil;
    q->size = 0;
}

// Priority Queue
int getPriority(int status) {
    if (status == DOSEN) return 1;
    else if (status == MHS) return 2;
    else return 3;
}

// Add new member to queue based on priority
void EnqueueAnggota(QueueAnggotaSingle *q, address anggota, address buku)
{
    if (isQueueEmpty(*q))
    {
        q->front = anggota;
        q->rear = anggota;
        q->head = anggota; 
        anggota->next = buku;
        buku->status --;
    }
    else
    {
        int new_priority;
        boolean condition = false;
        address current;
        address prev = nil; 

        // Var temp
        new_priority = getPriority(anggota->status);
        
        // Normal Connect
        current = q->head;
        anggota->next = q->head; // Menyambungkan anggota baru ke dalam antrian
        q->head = anggota; // Head berpindah ke sini
        prev = q->head;

        // Rear Handling
        if (buku->status > 0)
        {
            q->rear = q->head;
            buku->status --;
            condition = true;
        }   
        
        // Priority Check
        while (new_priority > current->status && prev->next != q->front 
               && prev->next != q->rear)
        {
            if (condition == true)
            {
                break;
            }
            prev = current;
            current = current->next; 
        }

        // Priority Connect
        // anggota->next = current;

        if (condition == false && q->head->next == prev)
        {
            anggota->next = current;
            prev->next = anggota;
            q->head = prev;
        }
    }
    
    q->size++;
}

address DequeueAnggota(QueueAnggotaSingle *q)
{
    address temp = nil;
    
    if (!isQueueEmpty(*q))
    {
        temp = q->front;
        q->front = q->front->next;
        
        if (q->front == nil)
        {
            q->rear = nil;
        }
        
        temp->next = nil;
        q->size--;
    }
    
    return temp;
}


void PinjamBukuSingle(address *buku, QueueAnggotaSingle *q, address anggota)
{
    MENU_TITLE_PINJAM_BUKU();  
    PrintListBuku(buku);
    printf("\n Pilih buku yang mau dipinjam");
    
}

// Future implementation for book return
void KembalikanBukuSingle(address *buku, address anggota, QueueAnggotaSingle *q)
{
    MENU_TITLE_KEMBALIKAN_BUKU();
}

// Other
boolean isQueueEmpty(QueueAnggotaSingle q)
{
    return (q.front == nil);
}