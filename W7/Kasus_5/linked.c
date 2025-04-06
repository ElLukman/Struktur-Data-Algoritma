#include "linked.h"

// Konstruktor
void CreateNode(address *PNew)
{
    *PNew = (address) malloc(sizeof(Orang));

    if (*PNew == nil)
    {printf("Alokasi gagal");}
}

void InsertNode(address *PNew, char *Nama)
{
    if (*PNew != nil)
    {
        (*PNew)->nama_orang = strdup(Nama);
        (*PNew)->next = nil;
    }
}

// Insert
void InsertFirst(address *head, address PNew)
{
    if(PNew != nil)
    {
        (PNew)->next = *head;
        *head = PNew;
    }
    else {printf("Node belum dialokasi\n");}
}

void InsertLast(address *head, address PNew)
{
    address current;
    if(PNew != nil)
    {
        (PNew)->next = nil;
        if (isEmptyList(*head))
        {
            *head = PNew;
        }
        else 
        {
            current = *head;
            while ((current)->next != nil)
            {
                current = (current)->next;
            }
            (current)->next = PNew;
        }
    }
    else {printf("Node belum dialokasi\n");}
}

void InsertAfter(address *P_After, address PNew)
{
    if (*P_After != nil && PNew != nil)
    {
        (PNew)->next = (*P_After)->next;
        (*P_After)->next = PNew;
    }
    else
    {printf("Node sebelum atau node baru belum dialokasi");}
}

// Modify
void EditNama(address target, char *Nama)
{
    if (target != nil) 
    {
        free(target->nama_orang); 
        target->nama_orang = strdup(Nama);
    }
}

// Delete
void DeleteFirst(address*p, char *Nama)
{
    address temp;
    if (!isEmptyList(*p))
    {
        temp = *p;
        strcpy(Nama, temp->nama_orang);
        *p = (temp)->next;
        free(temp);
    }
    else {printf("Linked list kosong\n");}
}

void DeleteLast(address*p, char *Nama)
{
    address current, prev;
    if (!isEmptyList(*p))
    {
        current = *p;
        prev = nil;
        
        while((current)->next != nil)
        {
            prev = current;
            current = (current)->next;
        }
        strcpy(Nama, current->nama_orang);
        if (prev != nil)
        {   (prev)->next = nil; }
        else 
        {   *p = nil;   }
        free(current);
    }
    else {printf("Linked list kosong\n");}
}

void DeleteAfter(address*PBefore, char *Nama)
{
    address temp;
    if (*PBefore != nil && (*PBefore)->next != nil)
    {
        temp = (*PBefore)->next;
        strcpy(Nama, (temp)->nama_orang);
        (*PBefore)->next = (temp)->next;
        free(temp);
    }
    else {printf("Node setelah pBefore tidak ada atau pBefore NULL\n");}
}

void Dealloc(address *pNode)

{
    if (*pNode != nil)
    {
        free(*pNode);
        *pNode = nil;
    }
}

// Other
address FindOrang(address head, const char *Nama)
{
    address current = head;
    while ( current != nil )
    {
        if(strcmp(current->nama_orang, Nama) == 0)
        {
            printf("Nama dengan %s ditemukan\n", Nama);
            return current;
        }
        current = (current)->next;
    }
    printf("Nama dengan %s tidak ditemukan\n", Nama);
    return nil;
}

boolean isEmptyList(address head)
{
    return (head == nil);
}