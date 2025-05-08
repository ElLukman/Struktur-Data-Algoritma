#include "menu.h"
#include "common.h"

void MENU_AWAL()
{
    system("cls");
    printf("=========================================\n");
    printf("Program Perpustakaan berbasis Struktur Data\n");
    printf("=========================================\n");
    printf("Pilih struktur data yang ingin digunakan\n");
    printf("1. Single Linked List\n");
    printf("2. Double Linked List\n");
    printf("3. Array\n");
    printf("4. Exit\n");
    printf("=========================================\n");
    printf("\nPilihan menu : ");
}

void SUB_MENU_SLL()
{
    system("cls");
    printf("=========================================\n");
    printf("            Single Linked List           \n");
    printf("=========================================\n");
    printf("1. Create Buku\n");
    printf("2. Edit Buku\n");
    printf("3. Delete Buku\n");
    printf("4. Create Anggota\n");
    printf("5. Edit Anggota\n");
    printf("6. Delete Anggota\n");
    printf("7. Pinjam Buku\n");
    printf("8. Kembalikan Buku\n");
    printf("9. Print Visual\n");
    printf("10. Exit\n");
    printf("=========================================\n");
    printf("\nPilihan menu : ");
}

void SUB_MENU_DLL()
{
    system("cls");
    printf("=========================================\n");
    printf("            Double Linked List           \n");
    printf("=========================================\n");
    printf("1. Add Buku\n");
    printf("2. Edit Buku\n");
    printf("3. Delete Buku\n");
    printf("4. Create Anggota\n");
    printf("5. Edit Anggota\n");
    printf("6. Delete Anggota\n");
    printf("7. Pinjam Buku\n");
    printf("8. Kembalikan Buku\n");
    printf("9. Tampilkan Visual\n");
    printf("10. Exit\n");
    printf("=========================================\n");
    printf("\nPilihan menu : ");
}

void SUB_MENU_ARR()
{
    system("cls");
    printf("=========================================\n");
    printf("                  Array                  \n");
    printf("=========================================\n");
    printf("1. Add Buku\n");
    printf("2. Edit Buku\n");
    printf("3. Delete Buku\n");
    printf("4. Create Anggota\n");
    printf("5. Edit Anggota\n");
    printf("6. Delete Anggota\n");
    printf("7. Pinjam Buku\n");
    printf("8. Kembalikan Buku\n");
    printf("9. Tampilkan Visual\n");
    printf("10. Exit\n");
    printf("=========================================\n");
    printf("\nPilihan menu : ");
}

// 1. Add Buku
void MENU_TITLE_CREATE_BUKU()
{
    system("cls");
    printf("===============================\n");
    printf("           Create Buku         \n");
    printf("===============================\n");
}

// 2. Edit Buku
void MENU_TITLE_EDIT_BUKU()
{
    system("cls");
    printf("===============================\n");
    printf("           Edit Buku           \n");
    printf("===============================\n");
}

// 3. Delete Buku

// 4. Create Anggota

void MENU_TITLE_CREATE_ANGGOTA()
{
    system("cls");
    printf("===============================\n");
    printf("         Create Anggota        \n");
    printf("===============================\n"); 
}

void MENU_INPUT_LEVEL_ANGGOTA()
{
    printf("List level anggota\n");
    printf("1. Dosen\n");
    printf("2. Mahasiswa\n");
    printf("3. Masyarakat Umum\n");
    printf("Pilih level anggota: ");
}

// 5. Edit Anggota 

void MENU_TITLE_EDIT_ANGGOTA()
{
    system("cls");
    printf("===============================\n");
    printf("         Edit Anggota          \n");
    printf("===============================\n"); 
}

void MENU_EDIT_LEVEL_ANGGOTA()
{
    printf("List level anggota\n");
    printf("1. Dosen\n");
    printf("2. Mahasiswa\n");
    printf("3. Masyarakat Umum\n");
    printf("Edit level anggota: ");
}

// 6. Delete Anggota


// 7. Pinjam Buku
void MENU_TITLE_PINJAM_BUKU()
{
    system("cls");
    printf("===============================\n");
    printf("          Pinjam Buku          \n");
    printf("===============================\n"); 
}

// 8. Kembalikan Buku 
void MENU_TITLE_KEMBALIKAN_BUKU()
{
    system("cls");
    printf("===============================\n");
    printf("        Kembalikan Buku        \n");
    printf("===============================\n"); 
}

// 9. Tampilkan Visual
void TAMPILKAN_VISUAL()
{
    printf("===============================\n");
    printf("          Tampilan Data        \n");
    printf("===============================\n");
}

// Other 
void MENU_WARNING()
{
    while (pil_menu < 1 && pil_menu > 4)
    {
        system("cls");
        printf("\n MASUKAN INPUT YANG VALID! \n");
        MENU_AWAL();
        scanf("%d", &pil_menu);
        getchar(); 
    }
}

void PAUSE()
{
    printf("Tekan ENTER untuk melanjutkan...");
    getchar();
}

void CLEARBUFFER()
{
    // CLEAR BUFFER
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
