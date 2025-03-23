#ifndef queue_h
#define queue_h
#include "linked.h"
#include "boolean.h"

typedef address Queue;

typedef struct
{
    int head;
    int tail;
} List;

/*Membuat sebuah queue baru dengan Front dan Rear NULL*/
void CreateQueue(Queue *Q);

/*Memeriksa apakah queue kosong*/
boolean is_Empty(Queue Q);

/*Memeriksa apakah queue penuh*/
boolean is_Full(Queue Q);

/*Melakukan insertion pada queue*/
void InsQueue(Queue *Q, int X);
void Insert_Last(Queue *Q, int X);

/*Melakukan deletion pada queue*/
void DelQueue(Queue *Q, int *X);


#endif
