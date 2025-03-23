#include "linked.h"
#include "stack.h"
#include "queue.h"
#include <string.h>

void mainMenu();
void sllMenu();
void stackMenu();
void queueMenu();
void konversiMenu();

int main()
{
    int pilihan;

    do
    {
        system("cls");
        mainMenu();
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            sllMenu();
            break;
        case 2:
            stackMenu();
            break;
        case 3:
            queueMenu();
            break;
        case 4:
            konversiMenu();
            break;
        case 0:
            printf("\nTerima kasih telah menggunakan program ini!\n");
            break;
        default:
            printf("\nPilihan tidak valid! Silakan pilih kembali.\n");
            getch();
            break;
        }
    } while (pilihan != 0);

    return 0;
}

void mainMenu()
{
    printf("======================================\n");
    printf("   PROGRAM STRUKTUR DATA KOMPLEKS\n");
    printf("======================================\n");
    printf("1. Operasi Single Linked List\n");
    printf("2. Operasi Stack\n");
    printf("3. Simulasi Antrian Bank (Queue)\n");
    printf("4. Konversi Bilangan\n");
    printf("0. Keluar\n");
    printf("--------------------------------------\n");
    printf("Pilihan Anda: ");
}

void sllMenu()
{
    address head = nil;
    address temp;
    int pilihan, nilai, deleted;

    do
    {
        system("cls");
        printf("=================================\n");
        printf("    MENU SINGLE LINKED LIST\n");
        printf("=================================\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Delete First\n");
        printf("4. Delete Last\n");
        printf("5. Delete Odd Numbers\n");
        printf("6. Show List\n");
        printf("0. Kembali ke Menu Utama\n");
        printf("---------------------------------\n");
        printf("List saat ini: ");
        if (isEmpty(head))
        {
            printf("Kosong\n");
        }
        else
        {
            PrintLinkedList(head);
        }
        printf("---------------------------------\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            printf("Masukkan nilai: ");
            scanf("%d", &nilai);
            CreateNode(&temp);
            IsiNode(&temp, nilai);
            InsertFirst(&head, temp);
            printf("Nilai %d berhasil ditambahkan di awal list\n", nilai);
            getch();
            break;

        case 2:
            printf("Masukkan nilai: ");
            scanf("%d", &nilai);
            CreateNode(&temp);
            IsiNode(&temp, nilai);
            InsertLast(&head, temp);
            printf("Nilai %d berhasil ditambahkan di akhir list\n", nilai);
            getch();
            break;

        case 3:
            if (!isEmpty(head))
            {
                DeleteFirst(&head, &deleted);
                printf("Nilai %d berhasil dihapus dari awal list\n", deleted);
            }
            else
            {
                printf("List kosong, tidak ada yang dapat dihapus!\n");
            }
            getch();
            break;

        case 4:
            if (!isEmpty(head))
            {
                DeleteLast(&head, &deleted);
                printf("Nilai %d berhasil dihapus dari akhir list\n", deleted);
            }
            else
            {
                printf("List kosong, tidak ada yang dapat dihapus!\n");
            }
            getch();
            break;

        case 5:
            if (!isEmpty(head))
            {
                printf("Menghapus semua bilangan ganjil...\n");
                DeleteOdd(&head, &deleted);
                printf("Semua bilangan ganjil berhasil dihapus\n");
            }
            else
            {
                printf("List kosong, tidak ada yang dapat dihapus!\n");
            }
            getch();
            break;

        case 6:
            printf("\nIsi list lengkap: ");
            if (isEmpty(head))
            {
                printf("Kosong\n");
            }
            else
            {
                PrintLinkedList(head);
            }
            getch();
            break;

        case 0:
            // Bersihkan memori sebelum kembali ke menu utama
            while (!isEmpty(head))
            {
                DeleteFirst(&head, &deleted);
            }
            break;

        default:
            printf("\nPilihan tidak valid! Silakan pilih kembali.\n");
            getch();
            break;
        }
    } while (pilihan != 0);
}

void stackMenu()
{
    address top = nil;
    int pilihan, nilai, deleted;

    do
    {
        system("cls");
        printf("=================================\n");
        printf("         MENU STACK\n");
        printf("=================================\n");
        printf("1. Push (Tambah ke Stack)\n");
        printf("2. Pop (Ambil dari Stack)\n");
        printf("3. Tampilkan Stack\n");
        printf("0. Kembali ke Menu Utama\n");
        printf("---------------------------------\n");
        printf("Status Stack: %s\n", isEmptyStack(top) ? "Kosong" : "Berisi");
        printf("---------------------------------\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            printf("Masukkan nilai (0/1 untuk boolean, bilangan bulat lain untuk desimal): ");
            scanf("%d", &nilai);
            PushStack(&top, nilai);
            printf("Nilai %d berhasil ditambahkan ke Stack\n", nilai);
            getch();
            break;

        case 2:
            if (!isEmptyStack(top))
            {
                PopStack(&top, &deleted);
                printf("Nilai %d berhasil diambil dari Stack\n", deleted);
            }
            else
            {
                printf("Stack kosong, tidak ada yang dapat diambil!\n");
            }
            getch();
            break;

        case 3:
            PrintStack(top);
            getch();
            break;

        case 0:
            // Bersihkan memori sebelum kembali ke menu utama
            while (!isEmptyStack(top))
            {
                PopStack(&top, &deleted);
            }
            break;

        default:
            printf("\nPilihan tidak valid! Silakan pilih kembali.\n");
            getch();
            break;
        }
    } while (pilihan != 0);
}

void queueMenu()
{
    Queue antrianBank;
    int pilihan, nomorAntrian = 0, prosesAntrian;

    // Inisialisasi antrian kosong
    CreateQueue(&antrianBank);

    do
    {
        system("cls");
        printf("\n===== SIMULASI ANTRIAN BANK =====\n");
        printf("1. Ambil Nomor Antrian\n");
        printf("2. Proses Antrian\n");
        printf("3. Tampilkan Antrian\n");
        printf("0. Kembali ke Menu Utama\n");
        printf("---------------------------------\n");
        printf("Status Antrian: %s\n", is_Empty(antrianBank) ? "Kosong" : "Berisi");
        printf("---------------------------------\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1: // Ambil Antrian
            nomorAntrian++;
            printf("\nAnda mendapatkan nomor antrian: %d\n", nomorAntrian);
            InsQueue(&antrianBank, nomorAntrian);
            printf("Antrian saat ini: ");
            PrintLinkedList(antrianBank);
            printf("\nTekan enter untuk melanjutkan...");
            getch();
            break;

        case 2: // Proses Antrian
            if (is_Empty(antrianBank))
            {
                printf("\nAntrian kosong, tidak ada pelanggan untuk diproses!\n");
                printf("\nTekan enter untuk melanjutkan...");
                getch();
            }
            else
            {
                DelQueue(&antrianBank, &prosesAntrian);
                printf("\nMemproses pelanggan dengan nomor antrian: %d\n", prosesAntrian);
                printf("Antrian saat ini: ");
                if (is_Empty(antrianBank))
                {
                    printf("Kosong\n");
                }
                else
                {
                    PrintLinkedList(antrianBank);
                }
                printf("\nTekan enter untuk melanjutkan...");
                getch();
            }
            break;

        case 3: // Cetak Antrian
            printf("\nDaftar antrian saat ini: ");
            if (is_Empty(antrianBank))
            {
                printf("Kosong\n");
            }
            else
            {
                PrintLinkedList(antrianBank);
            }
            printf("\nTekan enter untuk melanjutkan...");
            getch();
            break;

        case 0: // Keluar
            // Bersihkan memori sebelum kembali ke menu utama
            while (!is_Empty(antrianBank))
            {
                DelQueue(&antrianBank, &prosesAntrian);
            }
            break;

        default:
            printf("\nPilihan tidak valid! Silakan pilih kembali.\n");
            getch();
        }
    } while (pilihan != 0);
}

void konversiMenu()
{
    address binaryStack = nil;
    int pilihan, desimal, deleted;
    char hasil[100] = "";
    char temp[2];

    do
    {
        system("cls");
        printf("=================================\n");
        printf("     MENU KONVERSI BILANGAN\n");
        printf("=================================\n");
        printf("1. Konversi Desimal ke Biner\n");
        printf("2. Tampilkan Stack Hasil Konversi\n");
        printf("0. Kembali ke Menu Utama\n");
        printf("---------------------------------\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            // Reset stack dan hasil sebelum konversi baru
            while (!isEmptyStack(binaryStack))
            {
                PopStack(&binaryStack, &deleted);
            }
            strcpy(hasil, "");

            printf("Masukkan bilangan desimal: ");
            scanf("%d", &desimal);

            if (desimal == 0)
            {
                // Kasus khusus untuk input 0
                PushStack(&binaryStack, 0);
                printf("Hasil konversi desimal %d ke biner: 0\n", desimal);
            }
            else
            {
                DesimalConverterToBinary(desimal, &binaryStack);

                // Cetak hasil konversi
                printf("Hasil konversi desimal %d ke biner: ", desimal);

                // Simpan hasil dalam string untuk ditampilkan
                address temp = binaryStack;
                while (temp != NULL)
                {
                    printf("%d", nilai(temp));
                    temp = next(temp);
                }
                printf("\n");
            }

            getch();
            break;

        case 2:
            PrintStack(binaryStack);
            printf("\nTekan enter untuk melanjutkan...");
            getch();
            break;

        case 0:
            // Bersihkan memori sebelum kembali ke menu utama
            while (!isEmptyStack(binaryStack))
            {
                PopStack(&binaryStack, &deleted);
            }
            break;

        default:
            printf("\nPilihan tidak valid! Silakan pilih kembali.\n");
            getch();
            break;
        }
    } while (pilihan != 0);
}