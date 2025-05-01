#ifndef QUEUE_SINGLE_H
#define QUEUE_SINGLE_H

#include "single.h"
#include "book_single.h"

typedef struct Node *address;
typedef struct QueueAnggotaSingle
{
    address front; 
    address rear; 
    address head;
    int size;
} QueueAnggotaSingle;

// Anggota Handler
void CreateAnggota(address *p);
void EditAnggota(address p);
void PrintListAnggota(address *p);

// Function declarations for queue operations
void CreateQueueSingle(QueueAnggotaSingle *q);
void EnqueueAnggota(QueueAnggotaSingle *q, address anggota, address buku);
address DequeueAnggota(QueueAnggotaSingle *q);

// Peminjaman buku handler
void PinjemBukuSingle(address *buku, address anggota, QueueAnggotaSingle *q);
void KembalikanBukuSingle(address *buku, address anggota, QueueAnggotaSingle *q);

// Other
boolean isQueueEmpty(QueueAnggotaSingle q);

/*
// Queue operations for future implementation
void PinjamBukuSingle(address *buku, QueueAnggotaSingle *q, address anggota);
void KembalikanBukuSingle(address *buku, QueueAnggotaSingle *q);
*/


#endif