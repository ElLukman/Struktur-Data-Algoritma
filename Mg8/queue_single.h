#ifndef QUEUE_SINGLE_H
#define QUEUE_SINGLE_H

#include "single.h"

typedef struct QueueAnggotaSingle
{
    address front; 
    address rear; 
    address head;
    int size;
} QueueAnggotaSingle;

// Anggota Handling
void PinjamBukuSingle();
// Pilih buku dulu 
// Cek status
// Ngantri
// IF STOK MASIH ADA
//      THEN MASIH NGANTRI SESUAI URUTAN 
// IF STOK TIDAK ADA 
//      THEN NGANTRI SETELAH REAR BARU ATURAN BERLAKU
// CONCLUSION: QUEUE JADI ADA 2 (1. Yang sedang diproses, 2. Yang sedang booking antrian)

void KembalikanBukuSingle();
// Rear 
// 



#endif