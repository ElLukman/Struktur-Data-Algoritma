#include "book_single.h"

void DeleteFirstBookSingle (address *p)
{
    address temp = nil;

    if(!isEmptySingle(*p))
    {
        // while((*p)->status > 0)
        // {
        //     DeleteFirstAnggotaSingle(p);
        //     (*p)->status --;
        // }
        
        temp = *p;
        *p = (*p)->next;
        temp->next = nil;

        free(temp->nama);
        free(temp);
    }
    else {printf("Node masih kosong \n");}
}

void DeleteLastBookSingle (address *p)
{
    address current, prev = nil;
    
    if (!isEmptySingle(*p))
    {
        current = (*p)->next;

        while ((current)->next != nil)
        {
            prev = current;
            current = (current)->next;
        }

        // while ((current)->next_orang != nil)
        // {
        //     DeleteFirstOrang(&current);
        // }

        if (prev != nil)
        {
            (prev)->next = nil;
        }
        else 
        {
            (current)->next = nil;
        }

        free(current->nama);
        free(current);
    }
    else {printf("Node masih kosong\n");}
}

void DeleteBookByNameSingle (address *p, char *nama_target)
{
    address current = *p;

    if (*p != nil)
    {
        while (current != nil && strcmp(current->nama, nama_target) != 0)
        {
            current = current->next;
        }
    }
    else 
    {printf("Node masih kosong\n");}
}