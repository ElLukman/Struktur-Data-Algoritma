#include "linked.h"
#include "kota.h"

int main ()
{
    // Temp
    char tempNama[100];

    // Inisialisasi array
    initKota();

    // Tambah nama kota & Kota terbatas
    InsertKota(0, "Bandung");
    InsertKota(1, "Jakarta");
    InsertKota(2, "Surabaya");

    // Tambah orang ke kota
    address orang1, orang2, orang3, orang4, orang5, orang6, orang7; // Tidak terbatas sampe memori heap penuh
    CreateNode(&orang1);
    InsertNode(&orang1, "Djajang");
    InsertFirst(&daftarKota[0].headOrang, orang1);
    
    CreateNode(&orang2);
    InsertNode(&orang2, "Hariono");
    InsertFirst(&daftarKota[0].headOrang, orang2);
    
    CreateNode(&orang3);
    InsertNode(&orang3, "Ale");
    InsertFirst(&daftarKota[1].headOrang, orang3);
    
    CreateNode(&orang4);
    InsertNode(&orang4, "Murad");
    InsertFirst(&daftarKota[1].headOrang, orang4);
    
    CreateNode(&orang5);
    InsertNode(&orang5, "Agung");
    InsertFirst(&daftarKota[2].headOrang, orang5);
    
    CreateNode(&orang6);
    InsertNode(&orang6, "Fajar");
    InsertFirst(&daftarKota[2].headOrang, orang6);

    CreateNode(&orang7);
    InsertNode(&orang7, "Lukman");
    InsertFirst(&daftarKota[0].headOrang, orang7);
    
    // Print semua kota dan orangnya
    system("cls");
    printf("Daftar semua Kota dan Orang \n");
    PrintAll();

    // Cari seseorang
    printf("\nCari Orang\n");
    FindNamaBerdasarkanKota("Fajar");
    FindNamaBerdasarkanKota("Ronaldo");

    // Hapus Murad
    printf("\nMenghapus Ale\n");
    DeleteAfter(&orang4, tempNama);

    // Hapus Awal
    printf("\nMenghapus Agung\n");
    DeleteFirst(&daftarKota[2].headOrang, tempNama);

    // Insert Last
    address orang8;
    CreateNode(&orang8);
    InsertNode(&orang8, "Xil");
    InsertLast(&daftarKota[0].headOrang, orang8);

    // Hapus Kota Surabaya
    printf("\nMenghapus Kota Surabaya:\n");
    DeleteKota(2, "Surabaya");
    PrintAll();

    // Print kota tertentu
    printf("\nPrint kota tertentu\n");
    PrintKota(0);

    // PrintAll setelah operasi
    printf("\nPrint semua kota setelah operasi\n");
    PrintAll();

    return 0;
}