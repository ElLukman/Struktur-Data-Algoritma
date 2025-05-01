#include "menu.h"
#include "single.h"
#include "book_single.h"
// #include "double.h"
// #include "array.h"

int main()
{
    address headbuku = nil;
    address headorang = nil;

    while (1)
    {
        MENU_AWAL();
        scanf(" %d", &pil_menu);
        getch();
        
        // STATEMENT MENU
        switch (pil_menu)
        {
        // Single Linked List
        case 1:
            // SUB_MENU 1
            SUB_MENU_SLL();
            scanf(" %d", &pil_sub_menu1);    
            getch();

            switch (pil_sub_menu1)
            {
            // 1. Create Buku
            case 1:
                MENU_TITLE_CREATE_BUKU();
                CreateBuku(&headbuku);
                break;
            // 2. Edit Buku
            case 2:
                MENU_TITLE_EDIT_BUKU();
                EditBuku(headbuku);
                break;
            // 3. Delete Buku
            case 3:
                printf("Feature under development\n");
                PAUSE();
                break;
            // 4. Create Anggota
            case 4:
                MENU_TITLE_CREATE_ANGGOTA();
                PAUSE();
                CreateAnggota(&headorang);
                break;
            // 5. Edit Anggota
            case 5:
                MENU_TITLE_EDIT_ANGGOTA();
                EditAnggota(headorang);
                PAUSE();
                break;
            // 6. Delete Anggota
            case 6:
                printf("Feature under development\n");
                PAUSE();
                break;
            // 7. Pinjam Buku
            case 7:
                printf("Feature under development\n");
                PAUSE();
                break;
            // 8. Kembalikan Buku
            case 8:
                printf("Feature under development\n");
                PAUSE();
                break;
            // 9. Print Visual
            case 9:
                printf("Feature under development\n");
                PAUSE();
                break;
            // 10. Exit
            case 10:
                exit(0);
                break;
            default:
                printf("\n Masukan input yang valid!: ");
            }
            break;
            // Double Linked List

        case 2:
            // SUB_MENU 2
            SUB_MENU_DLL();
            scanf(" %d", &pil_sub_menu1);
            getch();

            printf("Feature under development\n");
            PAUSE();
            /*
            switch (pil_sub_menu1)
            {
            case 1:
                // SUB_MENU 2.1
                break;
            case 2:
                break;
            default:
            }
            */
            break;
        case 3:
            // SUB_MENU 3
            SUB_MENU_ARR();
            scanf(" %d", &pil_sub_menu1);
            getch();

            /*
            switch (pil_sub_menu1)
            {
            case 1:
                // SUB_MENU 3.1
                break;
            case 2:
                break;
            default:
            }
            */
            break;
        case 4:
            exit(0);

        default:
            MENU_WARNING();
        }
    }

    return 0;
}