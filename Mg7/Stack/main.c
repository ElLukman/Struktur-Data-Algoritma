#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "linked.h"

int main()
{
    system("cls");
    address top = NULL;
    int desimal, hasil;  

    // Input angka desimal
    printf("Masukkan angka desimal: ");
    scanf("%d", &desimal);

    // Konversi desimal ke biner
    DesimalConverterToBinary(desimal, &top);
    
    // Print hasil stack setelah konversi
    printf("\nHasil konversi ke biner (LIFO): \n");
    PrintStack(top);

    // Mengeluarkan angka biner satu per satu (stack LIFO)
    printf("\nHasil konversi biner (dibaca dari bawah ke atas): ");
    while (!isEmptyStack(top))
    {
        PopStack(&top, &hasil);
        printf("%d", hasil);
    }
    printf("\n");

    return 0;
}
