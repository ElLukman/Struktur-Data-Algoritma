#include "queue.h"

int main()
{
    Queue antrianBank;
    int pilihan, nomorAntrian = 0, prosesAntrian;

    // Inisialisasi antrian kosong
    CreateQueue(&antrianBank);
    system("cls");

    do
    {
        printf("\n===== SIMULASI ANTRIAN BANK =====\n");
        printf("1. Ambil Antrian\n");
        printf("2. Proses Antrian\n");
        printf("3. Cetak Antrian\n");
        printf("0. Keluar\n");
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
            printf("\nTekan enter dua kali untuk kembali ke main menu");
            getch();
            getch();
            system("cls");
            break;

        case 2: // Proses Antrian
            if (is_Empty(antrianBank))
            {
                printf("\nAntrian kosong, tidak ada pelanggan untuk diproses!\n");
                getch();
                getch();
                system("cls");
                printf("\nTekan enter dua kali untuk kembali ke main menu");
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
                getch();
                getch();
                printf("\nTekan enter dua kali untuk kembali ke main menu");
                system("cls");
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
            getch();
            getch();
            printf("\nTekan enter dua kali untuk kembali ke main menu");
            system("cls");
            break;

        case 0: // Keluar
            printf("\nTerima kasih telah menggunakan sistem antrian bank!\n");
            break;

        default:
            printf("\nPilihan tidak valid! Silakan pilih kembali.\n");
        }

    } while (pilihan != 0);

    return 0;
}