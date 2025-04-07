#include "kota.h"
#include "linked.h"

int main() {
    // Inisialisasi list kota kosong
    address_kota listKota = nil;
    
    printf("=== Demonstrasi Linked List Kota dan Orang ===\n\n");
    
    // 1. Membuat kota
    printf("1. Membuat dan menambahkan kota\n");
    
    // Membuat kota Jakarta
    address_kota jakarta;
    CreateNodeKota(&jakarta);
    InsertNodeKota(&jakarta, "Jakarta");
    
    // Membuat kota Bandung
    address_kota bandung;
    CreateNodeKota(&bandung);
    InsertNodeKota(&bandung, "Bandung");
    
    // Membuat kota Surabaya
    address_kota surabaya;
    CreateNodeKota(&surabaya);
    InsertNodeKota(&surabaya, "Surabaya");

    // Membuat kota Yogyakarta
    address_kota yogyakarta;
    CreateNodeKota(&yogyakarta);
    InsertNodeKota(&yogyakarta, "Yogyakarta");
    
    // 2. Menambahkan kota ke dalam list
    printf("- Inserting Jakarta (first)\n");
    InsertFirstKota(&listKota, jakarta);
    
    printf("- Inserting Bandung (last)\n");
    InsertLastKota(&listKota, bandung);
    
    printf("- Inserting Surabaya (after Jakarta)\n");
    InsertAfterNamaKota(&listKota, "Jakarta", surabaya);

    printf("- Inserting Yogyakarta (last)");
    InsertLastKota(&listKota, yogyakarta);
    
    // Menampilkan daftar kota sementara
    printf("\nDaftar kota saat ini:\n");
    PrintAllKota(listKota);
    printf("\n");
    
    // 3. Menambahkan orang ke dalam kota
    printf("\n3. Menambahkan orang ke kota\n");

    // JAKARTA

        address_orang abdul, irfan, yusuf;
        // Membuat orang Abdul
        CreateNodeOrang(&abdul);
        InsertNodeOrang(&abdul, "Abdul");

        // Membuat orang Irfan
        CreateNodeOrang(&irfan);
        InsertNodeOrang(&irfan, "Irfan");
        
        // Membuat orang Yusuf
        CreateNodeOrang(&yusuf);
        InsertNodeOrang(&yusuf, "Yusuf");
        
        printf("- Inserting Abdul to Jakarta (first)\n");
        InsertFirstOrang(&jakarta, abdul);
        
        printf("- Inserting irfan to Jakarta (last)\n");
        InsertLastOrang(&jakarta, irfan);
        
        printf("- Inserting Yusuf after Abdul (after nama)\n");
        InsertAfterNamaOrang(&jakarta, yusuf, "Abdul");

    // BANDUNG
        address_orang asep, dadang;
        
        // Membuat orang Asep
        CreateNodeOrang(&asep);
        InsertNodeOrang(&asep, "Asep");
        
        // Membuat orang Dadang
        CreateNodeOrang(&dadang);
        InsertNodeOrang(&dadang, "Dadang");
        
        printf("- Inserting Asep to Bandung (first)\n");
        InsertFirstOrang(&bandung, asep);
        
        printf("- Inserting Dadang to Bandung (last)\n");
        InsertLastOrang(&bandung, dadang);
    
    // SURABAYA
        address_orang eko, mega;

        // Membuat orang Eko
        CreateNodeOrang(&eko);
        InsertNodeOrang(&eko, "Eko");

        // Membuat orang Mega
        CreateNodeOrang(&mega);
        InsertNodeOrang(&mega, "Mega");

        printf("- Inserting Eko to Surabaya (first)\n");
        InsertFirstOrang(&surabaya, eko);
        
        printf("- Inserting Mega to Surabaya (last)\n");
        InsertLastOrang(&surabaya, mega);

    // YOGYAKARTA
        address_orang ganjar, mulyono;

        // Membuat orang Ganjar
        CreateNodeOrang(&ganjar);
        InsertNodeOrang(&ganjar, "Ganjar");

        // Membuat orang Mulyono
        CreateNodeOrang(&mulyono);
        InsertNodeOrang(&mulyono, "Mulyono");

        printf("- Inserting Ganjar to Yogyakarta (first)\n");
        InsertFirstOrang(&yogyakarta, ganjar);
        
        printf("- Inserting Mulyono to Yogyakarta (last)\n");
        InsertLastOrang(&yogyakarta, mulyono);

    // Menampilkan daftar kota dan orang
    printf("\nDaftar kota dan orang saat ini:\n");
    PrintAllKota(listKota);
    printf("\n");
    
    // 4. Mencari orang berdasarkan nama
    printf("\n4. Mencari orang berdasarkan nama\n");
    printf("- Mencari orang dengan nama 'Ganjar':\n");
    FindNamaBerdasarkanKota(listKota, "Ganjar");
    printf("\n");
    
    printf("- Mencari orang dengan nama 'Asep':\n");
    FindNamaBerdasarkanKota(listKota, "Asep");
    printf("\n");
    
    printf("- Mencari orang dengan nama 'Fufufafa' (tidak ada):\n");
    FindNamaBerdasarkanKota(listKota, "Fufufafa");
    printf("\n");
    
    // 5. Mencetak informasi kota tertentu
    printf("\n5. Mencetak informasi kota tertentu\n");
    printf("- Informasi kota Jakarta:\n");
    PrintKota(listKota, "Jakarta");
    printf("\n\n");
    
    printf("- Informasi kota Yogyakarta:\n");
    PrintKota(listKota, "Yogyakarta");
    printf("\n\n");
    
    // 6. Mengedit nama orang
    printf("\n5. Mengedit nama orang\n");
    
    printf("- Mengubah nama 'Mulyono' menjadi 'Jokowi'\n");
    EditNamaOrang(&yogyakarta, "Jokowi", "Mulyono");
    
    // Mencetak kembali daftar setelah edit
    printf("\nDaftar setelah edit nama:\n");
    PrintAllKota(listKota);
    printf("\n");
    
    // 7. Menghapus orang dari kota
    printf("\n7. Menghapus orang dari kota\n");
    
    printf("- Menghapus orang pertama dari Jakarta\n");
    DeleteFirstOrang(&jakarta);
    
    printf("- Menghapus orang terakhir dari Bandung\n");
    DeleteLastOrang(&bandung);

    printf("- Menghapus orang setelah nama Yusuf - (Irfan)\n");
    DeleteAfterNamaOrang(&jakarta, "Yusuf");
    
    // Mencetak kembali daftar setelah hapus orang
    printf("\nDaftar setelah hapus orang:\n");
    PrintAllKota(listKota);
    printf("\n");
    
    // 8. Menghapus kota
    printf("\n8. Menghapus kota\n");
    printf("- Menghapus kota Surabaya\n");
    DeleteAfterNamaKota(&listKota, "Jakarta");
    
    printf("- Menghapus kota pertama (Jakarta)\n");
    DeleteFirstKota(&listKota);
    
    // Mencetak kembali daftar setelah hapus kota
    printf("\nDaftar setelah hapus kota:\n");
    PrintAllKota(listKota);
    printf("\n");
    
    // 9. Membersihkan seluruh daftar
    printf("\n9. Membersihkan seluruh daftar\n");
    DeleteAllKota(&listKota);
    
    // Mencetak daftar kosong
    printf("\nDaftar setelah dibersihkan:\n");
    PrintAllKota(listKota);
    
    printf("\n=== Demonstrasi selesai ===\n");
    
    return 0;
}