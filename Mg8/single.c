#include "common.h"
#include "single.h"

// Constructor
void CreateNodeSingle (address *p)
{
    *p = (address) malloc(sizeof(Node));
    if (*p == nil)
    {printf("Alokasi gagal\n");}
}

void FillNodeSingle (address *p, char *nama, int status)
{
    if (*p != nil)
    {
        (*p)->nama = strdup(nama);
        (*p)->status = status;
        (*p)->next = nil;
    }
}

// Insert 
void InsertFirstSingle (address *p, address pNew)
{
    if (pNew != nil)
    {
        pNew->next = *p;
        *p = pNew;
    }
    else {printf("Node belum dialokasi\n");}
}

void InsertLastSingle (address *p, address pNew)
{
    address current = *p;

    if (pNew != nil)
    {
        if (isEmptySingle(*p))
        {
            *p = pNew;
        }
        else 
        {
            while (current->next != nil)
            {
                current = (current)->next;
            }
            (current)->next = pNew;
        }
    }
    else {printf("Node belum dialokasi\n");}
}

void InsertAfterNameSingle (address *pBef, char *nama_target, address pNew)
{
    address current = *pBef;

    while (current != nil && strcmp(current->nama, nama_target) != 0)
    {
        current = (current)->next;
    }

    if (current != nil && pNew != nil)
    {
        (pNew)->next = (current)->next;
        (current)->next = pNew;
    }
    else {printf("Node belum dialokasi\n");}
}


// Other 
boolean isEmptySingle (address p)
{
    return (p == nil);
}