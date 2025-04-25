#include "perpustakaan.h"
#include "linked.h"

int main() {
    // Inisialisasi list buku kosong
    address_buku listbuku = nil;
    
    printf("=== Demonstrasi Linked List buku dan Orang ===\n\n");
    
    // 1. Membuat Buku
    printf("1. Membuat dan menambahkan buku\n");
    
    // Membuat Buku 1 dan Buku 2
    address_buku Buku1;
    CreateNodebuku(&Buku1);
    InsertNodebuku(&Buku1, "Kalkulus 1");
    
    address_buku Buku2;
    CreateNodebuku(&Buku2);
    InsertNodebuku(&Buku2, "Data Science");

    PrintAllbuku(listbuku);

    // 2. Insert elemen antrian
    printf("2. Anggota Peminjaman Buku\n");
    address_orang Anggota1, Dosen1, Umum1, Umum2;

    // Insert Elemen
    CreateNodeOrang(&Anggota1);
    CreateNodeOrang(&Dosen1);
    CreateNodeOrang(&Umum1);
    CreateNodeOrang(&Umum2);

    InsertNodeOrang(&Anggota1, "Lukman", MHS);
    InsertNodeOrang(&Dosen1, "Rizal", DSN);
    InsertNodeOrang(&Umum1, "Abdi", UMUM);
    InsertNodeOrang(&Umum2, "Alfes", UMUM);

    // Buku 1
    InsertFirstOrang(&Buku1, Anggota1);
    InsertFirstOrang(&Buku1, Dosen1);

    // Buku 2
    InsertFirstOrang(&Buku2, Umum1);
    InsertFirstOrang(&Buku2, Umum2);

    PrintAllbuku(listbuku);

    // 3. Hasil Peminjaman
    printf("3. Hasil peminjaman Buku \n");


    PrintAllbuku(listbuku);

    
    
    
    printf("\n=== Demonstrasi selesai ===\n");
    
    return 0;
}