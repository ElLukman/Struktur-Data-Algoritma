#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "link-list-mahasiswa.h"

#define nil NULL 
#define true 1 
#define false 0

//Validator 
bool IsEmpty (address p)
{
    return (p == nil);
}

bool CheckName (Mhs *Nama)
{
    return (Nama->Nama != nil && strlen(Nama->Nama) > 0);
}

//Getter and Setter
char *getNama (Mhs Info)
{
    return Info.Nama;
}

int getNilai (Mhs *Info)
{
    return Info->Nilai;
}

void setNama (Mhs *Info, char *NewName)
{
    Info->Nama = *NewName;
}

void setNilai (Mhs *Info, int nilai)
{
    Info->Nilai = nilai;        
}

//Konstruktor
void CreateNode (address *p)
{
    *p = (address) malloc(sizeof(Node));
    if (*p = nil)
    {
        (*p)->Info.Nama = nil;
        (*p)->Info.Nilai = 0;
        (*p)->Next = nil;
    }
}

void FillNode (address *p, Mhs Info)
{
    if (*p != nil)
    {
        (*p)->Info.Nama = (char *) malloc(strlen(Info.Nama) + 1);
        strcpy((*p)->Info.Nama, Info.Nama);
        (*p)->Info.Nilai = Info.Nilai;
        (*p)->Next = nil;
    }
}

void InsertFirst (address *p, address NewNode)
{
    NewNode->Next = *p;
    *p = NewNode;
}

void InsertLast (address *p, address NewNode)
{
    if (IsEmpty(*p))
    {
        *p = NewNode;
    }
    else
    {
        address current = *p;
        while (current->Next != nil)
        {
            current = current->Next;
        }
        current->Next = NewNode;
    }
}

void InsertAfter (address *p, address NewNode)
{
    if(*p != nil)
    {
        NewNode->Next = (*p)->Next;
        (*p)->Next = NewNode;
    }
}

//Destruktor
void DeleteFirst(address *p, int *X)
{
    if (!IsEmpty(*p))
    {
        address temp = *p;
        *X = temp->Info.Nilai;
        *p = temp->Next;
        free(temp->Info.Nama);
        free(temp);
    }
}

void DeleteLast(address *p, int *X)
{
    if (!IsEmpty(*p))
    {
        if ((*p)->Next == nil)
        {
            // Only one element
            *X = (*p)->Info.Nilai;
            free((*p)->Info.Nama);
            free(*p);
            *p = nil;
        }
        else
        {
            // Find the last node
            address current = *p;
            address prev = nil;
            
            while (current->Next != nil)
            {
                prev = current;
                current = current->Next;
            }
            
            *X = current->Info.Nilai;
            prev->Next = nil;
            free(current->Info.Nama);
            free(current);
        }
    }

}

void DeleteAfter(address *p, int *X)
{
    if (*p != nil && (*p)->Next != nil)
    {
        address temp = (*p)->Next;
        *X = temp->Info.Nilai;
        (*p)->Next = temp->Next;
        free(temp->Info.Nama);
        free(temp);
    }
}

//PrintObject
void PrintList (address p)
{
    address current = p;
    while (current != nil)
    {
        printf("|%s|%d|->", (current)->Info.Nama, (current)->Info.Nilai);
        current = (current)->Next;
    }
    printf("\n");
}

//Sorting and Filtering
void SortingAscendingName (address p, Node)
{
    if (p == nil || p->Next == nil)
    {
        return; 
    }

    address i, j;
    bool swapped;
    
    for (i = p; i->Next != nil; i = i->Next)
    {
        swapped = false;
        for (j = p; j->Next != nil; j = j->Next)
        {
            if (strcmp(j->Info.Nama, j->Next->Info.Nama) > 0)
            {
                // Swap data
                Mhs temp = j->Info;
                j->Info = j->Next->Info;
                j->Next->Info = temp;
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}

void SortingAscendValue (address p, Node)
{
    if (p == nil || p->Next == nil)
    {return;}         
    
    address i, j;
    bool swapped;
    
    for (i = p; i->Next != nil; i = i->Next)
    {
        swapped = false;
        for (j = p; j->Next != nil; j = j->Next)
        {
            if (j->Info.Nilai > j->Next->Info.Nilai)
            {
                // Swap data
                Mhs temp = j->Info;
                j->Info = j->Next->Info;
                j->Next->Info = temp;
                swapped = true;
            }
        }

    if (!swapped)
    {break;}
    }
}

void SortingDescendName (address p, Node)
{
    if (p == nil || p->Next == nil)
    {return;}

    address i, j;
    bool swapped;
    
    for (i = p; i->Next != nil; i = i->Next)
    {
        swapped = false;
        for (j = p; j->Next != nil; j = j->Next)
        {
            if (strcmp(j->Info.Nama, j->Next->Info.Nama) < 0)
            {
                // Swap data
                Mhs temp = j->Info;
                j->Info = j->Next->Info;
                j->Next->Info = temp;
                swapped = true;
            }
        }
        if (!swapped)
        {break;}
    }
}

void SortingDescendValue (address p, Node)
{
    if (p == nil || p->Next == nil)
    {return;} 
    
    // Bubble sort for descending value
    address i, j;
    bool swapped;
    
    for (i = p; i->Next != nil; i = i->Next)
    {
        swapped = false;
        for (j = p; j->Next != nil; j = j->Next)
        {
            if (j->Info.Nilai < j->Next->Info.Nilai)
            {
                // Swap data
                Mhs temp = j->Info;
                j->Info = j->Next->Info;
                j->Next->Info = temp;
                swapped = true;
            }
        }
        if (!swapped)
        {break;}
    }
}

void FilterValue(address p, Node)
{
    address current = p;
    Node filteredList;
    filteredList.Next = nil;
    address *filtered = &filteredList.Next;
    
    while (current != nil)
    {
        if (current->Info.Nilai > 70)  
        {
            address newNode;
            CreateNode(&newNode);
            FillNode(&newNode, current->Info);
            *filtered = newNode;
            filtered = &(newNode->Next);
        }
        current = current->Next;
    }
}