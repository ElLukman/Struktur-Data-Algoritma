#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "link_list_mahasiswa.h"

#define nil NULL 
#define true 1 
#define false 0

int main(void)
{
    address L1 = nil, L2 = nil;
    address newNode;
    Node dummy;  // variabel dummy untuk parameter sorting

    /* --- 1. Isi List L1 dengan data mahasiswa --- */
    Mhs mhs1 = {"Mahesa", 80};
    Mhs mhs2 = {"Andrea", 60};
    Mhs mhs3 = {"Supriadi", 75};
    Mhs mhs4 = {"Supriadi", 90}; // duplikat nama
    Mhs mhs5 = {"Zaky", 65};
    Mhs mhs6 = {"Salwa", 85};

    /* Masukkan data ke L1 dengan InsertLast (setelah setiap pengisian,
       kita nantinya akan melakukan sorting ascending berdasarkan nama) */
    CreateNode(&newNode);
    FillNode(&newNode, mhs1);
    InsertLast(&L1, newNode);

    CreateNode(&newNode);
    FillNode(&newNode, mhs2);
    InsertLast(&L1, newNode);

    CreateNode(&newNode);
    FillNode(&newNode, mhs3);
    InsertLast(&L1, newNode);

    CreateNode(&newNode);
    FillNode(&newNode, mhs4);
    InsertLast(&L1, newNode);

    CreateNode(&newNode);
    FillNode(&newNode, mhs5);
    InsertLast(&L1, newNode);

    CreateNode(&newNode);
    FillNode(&newNode, mhs6);
    InsertLast(&L1, newNode);

    /* --- 2. Tampilkan L1 terurut ascending berdasarkan Nama --- */
    SortingAscendingName(L1, dummy);
    system("cls");
    printf("\nList L1 (sorted ascending by Name):\n");
    PrintList(L1);

    /* --- 3. Tampilkan L1 terurut descending berdasarkan Nama --- */
    SortingDescendName(L1, dummy);
    printf("\nList L1 (sorted descending by Name):\n");
    PrintList(L1);

    /* --- 4. Tampilkan L1 terurut ascending berdasarkan Nilai --- */
    SortingAscendValue(L1, dummy);
    printf("\nList L1 (sorted ascending by Nilai):\n");
    PrintList(L1);

    /* --- 5. Tampilkan L1 terurut descending berdasarkan Nilai --- */
    SortingDescendValue(L1, dummy);
    printf("\nList L1 (sorted descending by Nilai):\n");
    PrintList(L1);

    /* --- 6. Hitung dan tampilkan jumlah elemen L1 --- */
    int count = CountElements(L1);
    printf("\nJumlah elemen di L1: %d\n", count);

    /* --- 7. Copy elemen L1 dengan Nilai > 70 ke L2 --- */
    address p = L1;
    while (p != nil) {
        if (p->Info.Nilai > 70) {
            CreateNode(&newNode);
            FillNode(&newNode, p->Info);
            InsertLast(&L2, newNode);
        }
        p = p->Next;
    }
    printf("\nList L2 (Nilai > 70) sebelum hapus duplikat:\n");
    PrintList(L2);

    /* --- 8. Hapus data duplikat di L2 (hanya menyisakan 1 data per nama) --- */
    address ptr = L2;
    while (ptr != nil) {
        address prev = ptr;
        address curr = ptr->Next;
        while (curr != nil) {
            if (strcmp(ptr->Info.Nama, curr->Info.Nama) == 0) {
                // Hapus node duplikat (bukan yang pertama)
                prev->Next = curr->Next;
                free(curr->Info.Nama);
                free(curr);
                curr = prev->Next;
            } else {
                prev = curr;
                curr = curr->Next;
            }
        }
        ptr = ptr->Next;
    }
    printf("\nList L2 setelah menghapus duplikat:\n");
    PrintList(L2);
    printf("Supriadi berhasil terhapus...");
    printf("\n\n");

    /* --- 9. Hapus L1 dan L2 --- */
    int dummyVal;
    while (L1 != nil) {
        DeleteFirst(&L1, &dummyVal);
    }
    while (L2 != nil) {
        DeleteFirst(&L2, &dummyVal);
    }

    return 0;
}
