#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    Isi_Tree pohon;
    int jumlah_node;
    char cari_node, node1, node2;

    printf("==============================================\n");
    printf("  PROGRAM SIMULASI ADT NON BINARY TREE STATIS\n");
    printf("==============================================\n\n");

    // 1. Membuat Tree
    printf("--- PEMBUATAN TREE ---\n");
    printf("Masukkan jumlah node: ");
    scanf("%d", &jumlah_node);
    getchar(); // Clear buffer

    if (jumlah_node > jml_maks)
    {
        printf("Jumlah node melebihi kapasitas maksimal (%d)!\n", jml_maks);
        return 1;
    }

    Create_tree(pohon, jumlah_node);
    printf("\n");

    // 2. Memeriksa apakah tree kosong
    printf("--- STATUS TREE ---\n");
    if (IsEmpty(pohon))
    {
        printf("Tree kosong.\n");
    }
    else
    {
        printf("Tree tidak kosong.\n");
    }
    printf("\n");

    // 3. Menampilkan struktur tree
    printf("--- STRUKTUR TREE ---\n");
    PrintTree(pohon);
    printf("\n");

    // 4. Traversal tree
    printf("--- TRAVERSAL TREE ---\n");
    PreOrder(pohon);
    InOrder(pohon);
    PostOrder(pohon);
    Level_order(pohon, jumlah_node);
    printf("\n");

    // 5. Menghitung jumlah elemen dan daun
    printf("--- INFORMASI JUMLAH ---\n");
    printf("Jumlah node dalam tree: %d\n", nbElmt(pohon));
    printf("Jumlah daun dalam tree: %d\n", nbDaun(pohon));
    printf("Kedalaman tree: %d\n", Depth(pohon));
    printf("\n");

    // 6. Mencari node
    printf("--- PENCARIAN NODE ---\n");
    printf("Masukkan node yang ingin dicari: ");
    scanf(" %c", &cari_node);
    getchar(); // Clear buffer

    if (Search(pohon, cari_node))
    {
        printf("Node '%c' ditemukan dalam tree.\n", cari_node);
        printf("Node '%c' berada pada level %d.\n", cari_node, Level(pohon, cari_node));

        // Tampilkan informasi node yang dicari
        int node_index = 0;
        for (int i = 1; i <= jml_maks; i++)
        {
            if (pohon[i].info == cari_node)
            {
                node_index = i;
                break;
            }
        }
        PrintNodeInfo(pohon, node_index);
    }
    else
    {
        printf("Node '%c' tidak ditemukan dalam tree.\n", cari_node);
    }
    printf("\n");

    // 7. Membandingkan dua node
    printf("--- PERBANDINGAN NODE ---\n");
    printf("Masukkan node pertama: ");
    scanf(" %c", &node1);
    getchar(); // Clear buffer

    printf("Masukkan node kedua: ");
    scanf(" %c", &node2);
    getchar(); // Clear buffer

    CompareNodes(pohon, node1, node2);
    printf("\n");

    // 8. Mencari nilai maksimal dari dua data
    printf("--- NILAI MAKSIMAL ---\n");
    printf("Nilai maksimal antara '%c' dan '%c' adalah '%c'.\n",
           node1, node2, Max(node1, node2));
    printf("\n");

    printf("Program selesai.\n");
    return 0;
}