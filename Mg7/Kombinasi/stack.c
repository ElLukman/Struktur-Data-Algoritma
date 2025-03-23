#include "stack.h"

void PushStack(address *top, boolean X)
{
    address PNew;
    CreateNode(&PNew);
    IsiNode(&PNew, X);
    InsertFirst(top, PNew);
}

void PopStack(address *top, int *X) 
{
    if (!isEmptyStack(*top)) 
    {
        DeleteFirst(top, X);
    } 
    else 
    {
        printf("Stack kosong!\n");
    }
}

boolean isEmptyStack(address top)
{
    return (top == NULL);
}

void DesimalConverterToBinary (int desimal, address *top)
{
    while (desimal > 0)
    {
        int bit = desimal % 2;  // Ubah tipe bit ke int agar sesuai dengan IsiNode()
        PushStack(top, bit);
        desimal = desimal / 2;
    }
}

void PrintStack(address top)
{
    printf("\nStack: \n");
    printf("TOP\n");
    printf(" | \n");
    printf(" V \n");

    address temp = top;
    while (temp != NULL)
    {
        printf("| %d |\n", temp->nilai);
        printf(" ---- \n");
        temp = temp->next;
    }

    if (top == NULL)
        printf("| EMPTY |\n");
}
