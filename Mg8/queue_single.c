#include "queue_single.h"

void InsertQueueSingle(address *Buku, address *Anggota, address AnggotaBaru)
{
    address current, rear, front = *Anggota; 


    (AnggotaBaru)->next = *Anggota;
}

void PinjamBukuSingle(address *p, address *Buku, address *Anggota)
{
    if(!isEmptySingle(Buku))
    {
        if ((*Anggota)->next != Anggota)
        {
            InsertFirstSingle (Buku, Anggota);
        }
        else 
        {
        }
    }
    else 
    {printf("Buku tidak ada\n");}
}