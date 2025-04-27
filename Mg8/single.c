#include "common.h"
#include "single.h"

// Constructor
void CreateNodeSingle (address *p)
{
    *p = (address) malloc(sizeof(NodeElmt));
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
    if (*p != nil)
    {
        (pNew)->next = *p;
        *p = pNew;
    }
    else {printf("Node belum dialokasi\n");}
}

void InsertLastSingle (address *p, address pNew)
{
    address current = *p;

    if (*p != nil)
    {
        if (isEmpty(p))
        {
            *p = pNew;
        }
        else 
        {
            while (current != nil)
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

    if (*pBef != nil && pNew != nil)
    {
        (pNew)->next = (current)->next;
        (current)->next = pNew;
    }
    else {printf("Node belum dialokasi\n");}
}

// Modify 
address ModifyByNamaSingle (address *p, char *nama_target, char *nama_baru, int status)
{
    address current = *p; 

    while (current != nil && strcmp((current)->nama, nama_target) != 0)
    {
        current = (current)->next;
    }

    if (current != nil)
    {
        (current)->nama = strdup(nama_baru);
        (current)->status = status; 
    }
}

// Other 
boolean isEmptySingle (address p)
{
    return (p == nil);
}