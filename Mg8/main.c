#include "menu.h"
#include "single.h"
// #include "double.h"
// #include "array.h"

int main ()
{
    
    // STATEMENT MENU 
    MENU_AWAL(); 

    switch (pil_menu)
    {
        // Single Linked List
        case 1: 
            // SUB_MENU 1
            switch (pil_sub_menu1)
            {
                case 1:
                // SUB_MENU 1.1
                    break;
                case 2: 
                // Exit
                    break;
                default:
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
        default:
            // WARNING



    } 





    return 0;
}