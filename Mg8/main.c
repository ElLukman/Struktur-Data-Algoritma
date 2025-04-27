#include "menu.h"
#include "single.h"
// #include "double.h"
// #include "array.h"

int main ()
{
    
    // STATEMENT MENU 
    switch (pil_menu)
    {
        MENU_AWAL(); 
        scanf(" %d", pil_menu);
        // Single Linked List
        case 1: 
            // SUB_MENU 1
            switch (pil_sub_menu1)
            {
                SUB_MENU_SLL();
                // 1. Create Buku
                case 1:
                    MENU_TITLE_CREATE_BUKU();
                    break;
                // 2. Edit Buku
                case 2: 
                    break;
                // 3. Delete Buku
                case 3:
                    break; 
                // 4. Create Anggota
                case 4:
                    break; 
                // 5. Edit Anggota
                case 5: 
                    break; 
                // 6. Delete Anggota
                case 6:
                    break;
                // 7. Pinjam Buku 
                case 7: 
                    break;
                // 8. Kembalikan Buku
                case 8: 
                    break; 
                // 9. Print Visual 
                case 9: 
                    break;
                // 10. Exit 
                case 10: 
                    return; 
                    break; 
                default:
                    printf("\n Masukan input yang valid!: ");

            }
            break;
        // Double Linked List
        
        case 2: 
            // SUB_MENU 2 
            switch(pil_sub_menu1)
            {
                case 1: 
                // SUB_MENU 2.1
                    break;
                case 2: 
                    break;
                default:
            }
            break; 
        case 3: 
            // SUB_MENU 3
            switch(pil_sub_menu1)
            {
                case 1:
                // SUB_MENU 3.1
                    break;
                case 2: 
                    break;
                default:
            }
            break;
        case 4: 
            exit(0);
        default:
            MENU_WARNING();



    } 





    return 0;
}