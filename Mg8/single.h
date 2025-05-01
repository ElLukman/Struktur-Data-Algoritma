#ifndef SINGLE_LINKED_LIST_H 
#define SINGLE_LINKED_LIST_H
#include "common.h"
#include "boolean.h"

// Dependensi
struct Node;
typedef struct Node *address;

// Deklarasi Data
typedef struct Node
{
    char *nama; 
    int status;
    address next;
} Node;

// ================================================
// NODE HANDLING
// ================================================

// Construct 
void CreateNodeSingle (address *p);
void FillNodeSingle (address *p, char *nama, int status);

// Insert 
void InsertFirstSingle (address *p, address pNew);
void InsertLastSingle (address *p, address pNew);
void InsertAfterNamaSingle (address *pBef, char *nama_target, address pNew);

// Other 
boolean isEmptySingle (address p);

#endif