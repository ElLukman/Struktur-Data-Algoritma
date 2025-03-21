#include <stdio.h>
#include "linked.h"
#include <malloc.h>
#define nilai(P) (P)->nilai
#define next(P) (P)->next
#define mod %

//Konstruktor
void CreateNode(address *p)
{
    *p = (address) malloc(sizeof(Node));
    if (*p == nil) 
    {
        printf("Alokasi gagal");
    }   
}

void IsiNode(address *p, int nilai)
{
    if (*p != nil)
    {
        nilai(*p) = nilai;
        next(*p) = nil;
    }
    else
    {
        printf("Node belum dialokasi\n");
    }
}

//Insert
void InsertFirst(address *p, address PNew)
{
    if (PNew != nil)
    {
        next(PNew) = *p;
        *p = PNew;
    }
    else 
    {
        printf("Node belum dialokasi\n");
    }
}

void InsertLast(address *p, address PNew)
{
    address current;
    if (PNew != nil)
    {
        next(PNew) = nil;
        if (isEmpty(*p))
        {
            *p = PNew;
        }
        else
        {
            current = *p;
            while (next(current) != nil)
            {
                current = next(current);
            }
            next(current) = PNew;
        }
    }
    else
    {
        printf("Node baru belum dialokasi\n");
    }
}

void InsertAfter(address *pBef, address PNew)
{
    if (*pBef != nil && PNew != nil)
    {
        next(PNew) = next(*pBef);
        next(*pBef) = PNew;
    }
    else
    {
        printf("Node sebelum atau node baru belum dialokasi\n");
    }
}

//Delete
void DeleteFirst(address *p, int *X)
{
    address temp;
    if (!isEmpty(*p))
    {
        temp = *p;
        *X = nilai(temp);
        *p = next(temp);
        free(temp);
    }
    else
    {
        printf("Linked list kosong\n");
    }
}

void DeleteLast(address *p, int *X)
{
    address current, previous;
    if (!isEmpty(*p))
    {
        current = *p;
        previous = nil;
        while (next(current) != nil)
        {
            previous = current;
            current = next(current);
        }
        *X = nilai(current);
        if (previous != nil)
        {
            next(previous) = nil;
        }
        else
        {
            *p = nil;
        }
        free(current);
    }
    else
    {
        printf("Linked list kosong\n");
    }
}

void DeleteAfter(address *pBef, int *X)
{
    address temp;
    if (*pBef != nil && next(*pBef) != nil)
    {
        temp = next(*pBef);
        *X = nilai(temp);
        next(*pBef) = next(temp);
        free(temp);
    }
    else
    {
        printf("Node setelah pBef tidak ada atau pBef NULL\n");
    }
}

void DeleteOdd(address *p, int *X)
{
    address current, prev;
    int deleted;
    
    while (*p != nil && nilai(*p) % 2 != 0)
    {
        DeleteFirst(p, X);
    }
    
    if (*p != nil)
    {
        current = *p;
        prev = current;
        current = next(current);
        
        while (current != nil)
        {
            if (nilai(current) % 2 != 0)
            {
                address temp = current;        
                next(prev) = next(current);     
                current = next(current);
                *X = nilai(temp);
                free(temp);
            }
            else
            {
                prev = current;
                current = next(current);
            }
        }
    }
}

//Other

void Dealloc(address *p)
{
    if (*p != nil)
    {
        free(*p);
        *p = nil;
    }
}

void PrintLinkedList (address p)
{
    address current = p;
    while (current != nil)
    {
        printf("%d", nilai(current));
        current = next(current);
    }
    printf("\n");
}


boolean isEmpty(address p)
{
    return (p == nil);
}
