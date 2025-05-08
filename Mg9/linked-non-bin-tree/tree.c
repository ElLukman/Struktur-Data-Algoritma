#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

void Create_tree(Isi_Tree X, int Jml_Node)
{
    // Inisialisasi semua node
    for (int i = 1; i <= jml_maks; i++)
    {
        X[i].info = ' ';
        X[i].ps_fs = 0;
        X[i].ps_nb = 0;
        X[i].ps_pr = 0;
    }

    // Variabel untuk menyimpan informasi node
    int parent_index, index = 1;
    char info;
    
    printf("Masukkan info root (level 0): ");
    scanf(" %c", &info);
    getchar(); // Clear buffer
    
    // Set root di index 1
    X[index].info = info;
    X[index].ps_fs = 0;
    X[index].ps_nb = 0;
    X[index].ps_pr = 0;
    
    // Jika jumlah node > 1, maka lanjutkan input
    if (Jml_Node > 1)
    {
        int current_level = 1;
        int nodes_in_level = 1;
        int node_count = 1;
        
        printf("\n--- Level %d ---\n", current_level);
        
        while (node_count < Jml_Node)
        {
            // Traverse semua node di level saat ini untuk input anaknya
            for (int level_index = 1; level_index <= nodes_in_level && node_count < Jml_Node; level_index++)
            {
                parent_index = level_index;
                
                int child_count;
                printf("Berapa jumlah anak dari node '%c': ", X[parent_index].info);
                scanf("%d", &child_count);
                getchar(); // Clear buffer
                
                // Input info child node
                for (int j = 0; j < child_count && node_count < Jml_Node; j++)
                {
                    node_count++;
                    index++;
                    
                    printf("Masukkan info child ke-%d dari '%c': ", j+1, X[parent_index].info);
                    scanf(" %c", &info);
                    getchar(); // Clear buffer
                    
                    X[index].info = info;
                    X[index].ps_pr = parent_index;
                    
                    // Set first son jika ini adalah anak pertama
                    if (j == 0)
                    {
                        X[parent_index].ps_fs = index;
                    }
                    else
                    {
                        // Cari saudara terakhir
                        int sibling_index = X[parent_index].ps_fs;
                        while (X[sibling_index].ps_nb != 0)
                        {
                            sibling_index = X[sibling_index].ps_nb;
                        }
                        // Set next brother
                        X[sibling_index].ps_nb = index;
                    }
                }
            }
            
            // Update untuk level berikutnya
            nodes_in_level = 0;
            for (int i = 1; i <= index; i++)
            {
                if (X[i].ps_pr == current_level)
                {
                    nodes_in_level++;
                }
            }
            
            current_level++;
            if (node_count < Jml_Node)
            {
                printf("\n--- Level %d ---\n", current_level);
            }
        }
    }
    
    printf("\nTree berhasil dibuat!\n");
}

boolean IsEmpty(Isi_Tree P)
{
    // Tree kosong jika elemen pertama kosong
    return (P[1].info == ' ');
}

void PreOrder(Isi_Tree P)
{
    if (IsEmpty(P))
    {
        printf("Tree kosong.\n");
        return;
    }
    
    // Lakukan traversal PreOrder dimulai dari root (index 1)
    printf("Hasil traversal PreOrder: ");
    PreOrder_Rec(P, 1);
    printf("\n");
}

void PreOrder_Rec(Isi_Tree P, int index)
{
    // Basis: Node tidak valid
    if (index == 0)
        return;
    
    // 1. Kunjungi node saat ini
    printf("%c ", P[index].info);
    
    // 2. Kunjungi semua anak-anaknya secara preorder
    int child = P[index].ps_fs;
    while (child != 0)
    {
        PreOrder_Rec(P, child);
        child = P[child].ps_nb;
    }
}

void InOrder(Isi_Tree P)
{
    if (IsEmpty(P))
    {
        printf("Tree kosong.\n");
        return;
    }
    
    // Lakukan traversal InOrder dimulai dari root (index 1)
    printf("Hasil traversal InOrder: ");
    InOrder_Rec(P, 1);
    printf("\n");
}

void InOrder_Rec(Isi_Tree P, int index)
{
    // Basis: Node tidak valid
    if (index == 0)
        return;
    
    // 1. Kunjungi first son
    int first_son = P[index].ps_fs;
    if (first_son != 0)
    {
        InOrder_Rec(P, first_son);
    }
    
    // 2. Kunjungi node saat ini
    printf("%c ", P[index].info);
    
    // 3. Kunjungi sisa anak secara inorder
    if (first_son != 0)
    {
        int next_brother = P[first_son].ps_nb;
        while (next_brother != 0)
        {
            InOrder_Rec(P, next_brother);
            next_brother = P[next_brother].ps_nb;
        }
    }
}

void PostOrder(Isi_Tree P)
{
    if (IsEmpty(P))
    {
        printf("Tree kosong.\n");
        return;
    }
    
    // Lakukan traversal PostOrder dimulai dari root (index 1)
    printf("Hasil traversal PostOrder: ");
    PostOrder_Rec(P, 1);
    printf("\n");
}

void PostOrder_Rec(Isi_Tree P, int index)
{
    // Basis: Node tidak valid
    if (index == 0)
        return;
    
    // 1. Kunjungi semua anak-anaknya secara postorder
    int child = P[index].ps_fs;
    while (child != 0)
    {
        PostOrder_Rec(P, child);
        child = P[child].ps_nb;
    }
    
    // 2. Kunjungi node saat ini
    printf("%c ", P[index].info);
}

void Level_order(Isi_Tree X, int Maks_node)
{
    if (IsEmpty(X))
    {
        printf("Tree kosong.\n");
        return;
    }
    
    printf("Hasil traversal Level Order: ");
    
    for (int i = 1; i <= Maks_node; i++)
    {
        if (X[i].info != ' ')
        {
            printf("%c ", X[i].info);
        }
    }
    printf("\n");
}

void PrintTree(Isi_Tree P)
{
    if (IsEmpty(P))
    {
        printf("Tree kosong.\n");
        return;
    }
    
    printf("\nStruktur Non Binary Tree:\n");
    
    // Hitung kedalaman tree
    int depth = Depth(P);
    
    // Array untuk menyimpan node di setiap level
    int nodes_by_level[depth+1][jml_maks];
    int count_by_level[depth+1];
    
    // Inisialisasi array
    for (int i = 0; i <= depth; i++)
    {
        count_by_level[i] = 0;
        for (int j = 0; j < jml_maks; j++)
        {
            nodes_by_level[i][j] = 0;
        }
    }
    
    // Isi array dengan node pada setiap level
    for (int i = 1; i <= jml_maks; i++)
    {
        if (P[i].info != ' ')
        {
            int level = Level(P, P[i].info);
            nodes_by_level[level][count_by_level[level]] = i;
            count_by_level[level]++;
        }
    }
    
    // Cetak tree berdasarkan level
    for (int level = 0; level <= depth; level++)
    {
        printf("Level %d: ", level);
        for (int j = 0; j < count_by_level[level]; j++)
        {
            int node_idx = nodes_by_level[level][j];
            printf("%c ", P[node_idx].info);
        }
        printf("\n");
    }
}

boolean Search(Isi_Tree P, infotype X)
{
    if (IsEmpty(P))
    {
        return false;
    }
    
    // Linear search untuk menemukan node dengan nilai X
    for (int i = 1; i <= jml_maks; i++)
    {
        if (P[i].info == X)
        {
            return true;
        }
    }
    
    return false;
}

int nbElmt(Isi_Tree P)
{
    if (IsEmpty(P))
    {
        return 0;
    }
    
    int count = 0;
    
    // Hitung jumlah node yang valid
    for (int i = 1; i <= jml_maks; i++)
    {
        if (P[i].info != ' ')
        {
            count++;
        }
    }
    
    return count;
}

int nbDaun(Isi_Tree P)
{
    if (IsEmpty(P))
    {
        return 0;
    }
    
    int count = 0;
    
    // Hitung jumlah node yang tidak memiliki anak (daun)
    for (int i = 1; i <= jml_maks; i++)
    {
        if (P[i].info != ' ' && P[i].ps_fs == 0)
        {
            count++;
        }
    }
    
    return count;
}

int Level(Isi_Tree P, infotype X)
{
    if (IsEmpty(P))
    {
        return -1;
    }
    
    // Temukan index node dengan nilai X
    int index = -1;
    for (int i = 1; i <= jml_maks; i++)
    {
        if (P[i].info == X)
        {
            index = i;
            break;
        }
    }
    
    if (index == -1)
    {
        return -1; // Node tidak ditemukan
    }
    
    // Hitung level node
    int level = 0;
    while (P[index].ps_pr != 0)
    {
        level++;
        index = P[index].ps_pr;
    }
    
    return level;
}

int Depth(Isi_Tree P)
{
    if (IsEmpty(P))
    {
        return 0;
    }
    
    int max_level = 0;
    
    // Temukan level tertinggi
    for (int i = 1; i <= jml_maks; i++)
    {
        if (P[i].info != ' ')
        {
            int level = Level(P, P[i].info);
            if (level > max_level)
            {
                max_level = level;
            }
        }
    }
    
    return max_level;
}

int Max(infotype Data1, infotype Data2)
{
    return (Data1 > Data2) ? Data1 : Data2;
}

// Fungsi tambahan untuk menampilkan informasi node
void PrintNodeInfo(Isi_Tree P, int index)
{
    if (index < 1 || index > jml_maks || P[index].info == ' ')
    {
        printf("Node tidak valid.\n");
        return;
    }
    
    printf("Informasi Node '%c':\n", P[index].info);
    printf("Level: %d\n", Level(P, P[index].info));
    printf("Parent: %c\n", (P[index].ps_pr != 0) ? P[P[index].ps_pr].info : '-');
    printf("First Son: %c\n", (P[index].ps_fs != 0) ? P[P[index].ps_fs].info : '-');
    printf("Next Brother: %c\n", (P[index].ps_nb != 0) ? P[P[index].ps_nb].info : '-');
    
    // Cetak semua anak
    printf("Children: ");
    if (P[index].ps_fs == 0)
    {
        printf("None (Leaf node)");
    }
    else
    {
        int child = P[index].ps_fs;
        while (child != 0)
        {
            printf("%c ", P[child].info);
            child = P[child].ps_nb;
        }
    }
    printf("\n");
}

// Fungsi untuk membandingkan 2 node
void CompareNodes(Isi_Tree P, infotype Node1, infotype Node2)
{
    if (IsEmpty(P) || !Search(P, Node1) || !Search(P, Node2))
    {
        printf("Salah satu atau kedua node tidak ditemukan.\n");
        return;
    }
    
    int level1 = Level(P, Node1);
    int level2 = Level(P, Node2);
    
    printf("Perbandingan node '%c' dan '%c':\n", Node1, Node2);
    printf("Level '%c': %d\n", Node1, level1);
    printf("Level '%c': %d\n", Node2, level2);
    
    if (level1 == level2)
    {
        printf("Kedua node berada pada level yang sama.\n");
    }
    else if (level1 < level2)
    {
        printf("'%c' berada pada level yang lebih tinggi dari '%c'.\n", Node1, Node2);
    }
    else
    {
        printf("'%c' berada pada level yang lebih tinggi dari '%c'.\n", Node2, Node1);
    }
}