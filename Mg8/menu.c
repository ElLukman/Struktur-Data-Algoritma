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
    scanf("%d", &pil_menu);
    getch();
}

void SUB_MENU_SLL()
{
    system("cls");
    printf("=========================================\n");
    printf("            Single Linked List           \n");
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
    scanf("%d", &pil_sub_menu1);
    getch();
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
    scanf("%d", &pil_sub_menu1);
    getch();
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
    scanf("%d", &pil_sub_menu1);
    getch();
}

// 1. Add Buku
void MENU_INPUT_JUDULBUKU()
{
    printf("Tuliskan judul buku: ");
}

void MENU_INPUT_STOKBUKU()
{
    printf("Masukan jumlah stok buku: ");
}

// 2. Edit Buku
void MENU_EDIT_PILIHBUKU()
{
    printf("Pilih buku yang ingin diedit: ");
}

void MENU_EDIT_JUDULBUKU()
{
    printf("Tuliskan judul baru: ");
}

void MENU_EDIT_STOKBUKU()
{
    printf("Edit stok buku: ");
}

// 3. Delete Buku
void MENU_DELETE_BUKU()
{
    printf("Pilih buku yang ingin dihapus: ");
}

// 4. Create Anggota
void MENU_INPUT_NAMA_ANGGOTA()
{
    printf("Tuliskan nama anggota: ");
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
void MENU_EDIT_NAMA_ANGGOTA()
{
    printf("Edit nama anggota: ");
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
void MENU_DELETE_ANGGOTA()
{
    printf("Pilih anggota yang ingin dihapus: ");
}

// 7. Pinjam Buku
void MENU_PILIH_BUKU()
{
    printf("Pilih buku yang ingin dipinjam: ");
}

// 8. Kembalikan Buku 
void MENU_KEMBALIKAN_BUKU()
{
    printf("Pilih buku yang ingin dikembalikan: ");
}

// 9. Tampilkan Visual
void TAMPILKAN_VISUAL()
{
    printf("===============================\n");
    printf("          Tampilan Data        \n");
    printf("===============================\n");
}

// Other 
void MENU_PILIH_ORANG()
{
    printf("Pilih anggota: ");
}