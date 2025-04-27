#ifndef SINGLE_LINKED_LIST_H 
#define SINGLE_LINKED_LIST_H
#include "common.h"
#include "boolean.h"
#include "queue_single.h"
#include "book_single.h"

// Deklarasi data

typedef struct Node *address;
typedef struct Node
{
    char *nama; 
    int status;
    address next;
} NodeElmt;

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

// Modify
address ModifyByNamaSingle (address *p, char *nama_target, char *nama_baru, int status);

// Other 
boolean isEmptySingle (address p);

// ================================================
// PROCESS HANDLING
// ================================================

#endif