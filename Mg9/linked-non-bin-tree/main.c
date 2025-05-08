#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

// Fungsi untuk membersihkan layar terminal
void CLEARBUFFER()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Fungsi untuk pause program
void PAUSE()
{
    printf("\nTekan Enter untuk melanjutkan...");
    getchar();
}

// Fungsi untuk menampilkan menu utama
void DISPLAY_MENU()
{
    printf("\n================================================\n");
    printf("           PROGRAM NON BINARY TREE STATIS        \n");
    printf("================================================\n");
    printf("1. Traversal PreOrder\n");
    printf("2. Traversal InOrder\n");
    printf("3. Traversal PostOrder\n");
    printf("4. Traversal Level Order\n");
    printf("5. Print Tree\n");
    printf("6. Search node Tree\n");
    printf("7. Jumlah Daun/Leaf\n");
    printf("8. Mencari Level node Tree\n");
    printf("9. Kedalaman Tree\n");
    printf("10. Membandingkan 2 node Tree\n");
    printf("11. Exit\n");
    printf("================================================\n");
    printf("Pilih Menu: ");
}

int main()
{
    Isi_Tree tree;
    int pilihan, jml_node;
    char node_info;
    boolean program_running = true;

    CLEARBUFFER();
    printf("================================================\n");
    printf("           PROGRAM NON BINARY TREE STATIS        \n");
    printf("================================================\n");

    printf("Masukkan jumlah node yang diinginkan (max %d): ", jml_maks);
    scanf("%d", &jml_node);
    getchar(); // Clear buffer

    if (jml_node <= 0 || jml_node > jml_maks)
    {
        printf("Jumlah node tidak valid!\n");
        return 1;
    }

    // Inisialisasi tree
    Create_tree(tree, jml_node);

    while (program_running)
    {
        CLEARBUFFER();
        DISPLAY_MENU();
        scanf("%d", &pilihan);
        getchar(); // Clear buffer

        switch (pilihan)
        {
        case 1:
            CLEARBUFFER();
            printf("================================================\n");
            printf("                TRAVERSAL PREORDER               \n");
            printf("================================================\n");
            PreOrder(tree);
            PAUSE();
            break;

        case 2:
            CLEARBUFFER();
            printf("================================================\n");
            printf("                TRAVERSAL INORDER                \n");
            printf("================================================\n");
            InOrder(tree);
            PAUSE();
            break;

        case 3:
            CLEARBUFFER();
            printf("================================================\n");
            printf("                TRAVERSAL POSTORDER              \n");
            printf("================================================\n");
            PostOrder(tree);
            PAUSE();
            break;

        case 4:
            CLEARBUFFER();
            printf("================================================\n");
            printf("               TRAVERSAL LEVEL ORDER             \n");
            printf("================================================\n");
            Level_order(tree, jml_node);
            PAUSE();
            break;

        case 5:
            CLEARBUFFER();
            printf("================================================\n");
            printf("                   PRINT TREE                    \n");
            printf("================================================\n");
            PrintTree(tree);
            PAUSE();
            break;

        case 6:
            CLEARBUFFER();
            printf("================================================\n");
            printf("                  SEARCH NODE                    \n");
            printf("================================================\n");
            printf("Masukkan info node yang ingin dicari: ");
            scanf(" %c", &node_info);
            getchar(); // Clear buffer

            if (Search(tree, node_info))
            {
                printf("Node '%c' ditemukan dalam tree.\n", node_info);

                // Tampilkan informasi node
                for (int i = 1; i <= jml_maks; i++)
                {
                    if (tree[i].info == node_info)
                    {
                        PrintNodeInfo(tree, i);
                        break;
                    }
                }
            }
            else
            {
                printf("Node '%c' tidak ditemukan dalam tree.\n", node_info);
            }
            PAUSE();
            break;

        case 7:
            CLEARBUFFER();
            printf("================================================\n");
            printf("                 JUMLAH DAUN/LEAF                \n");
            printf("================================================\n");
            printf("Jumlah daun dalam tree: %d\n", nbDaun(tree));
            PAUSE();
            break;

        case 8:
            CLEARBUFFER();
            printf("================================================\n");
            printf("                LEVEL NODE TREE                  \n");
            printf("================================================\n");
            printf("Masukkan info node yang ingin dicari levelnya: ");
            scanf(" %c", &node_info);
            getchar(); // Clear buffer

            int level = Level(tree, node_info);
            if (level >= 0)
            {
                printf("Node '%c' berada pada level %d.\n", node_info, level);
            }
            else
            {
                printf("Node '%c' tidak ditemukan dalam tree.\n", node_info);
            }
            PAUSE();
            break;

        case 9:
            CLEARBUFFER();
            printf("================================================\n");
            printf("                 KEDALAMAN TREE                  \n");
            printf("================================================\n");
            printf("Kedalaman tree adalah %d level.\n", Depth(tree));
            PAUSE();
            break;

        case 10:
            CLEARBUFFER();
            printf("================================================\n");
            printf("              MEMBANDINGKAN 2 NODE               \n");
            printf("================================================\n");
            char node1, node2;
            printf("Masukkan info node pertama: ");
            scanf(" %c", &node1);
            getchar(); // Clear buffer
            printf("Masukkan info node kedua: ");
            scanf(" %c", &node2);
            getchar(); // Clear buffer

            CompareNodes(tree, node1, node2);
            PAUSE();
            break;

        case 11:
            CLEARBUFFER();
            printf("================================================\n");
            printf("           TERIMA KASIH TELAH MENGGUNAKAN        \n");
            printf("           PROGRAM NON BINARY TREE STATIS        \n");
            printf("================================================\n");
            program_running = false;
            break;

        default:
            printf("Pilihan tidak valid! Silakan pilih menu yang tersedia.\n");
            PAUSE();
            break;
        }
    }

    return 0;
}