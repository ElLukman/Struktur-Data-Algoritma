#include "queue.h"
#include "boolean.h"

void CreateQueue(Queue *Q)
{
    *Q = nil;
}

boolean is_Empty(Queue Q)
{
    return isEmpty(Q);
}

boolean is_Full(Queue Q)
{
    return false;
}

void InsQueue(Queue *Q, int X)
{
    Insert_Last(&(*Q), X);
}

void DelQueue(Queue *Q, int *X)
{
    DeleteFirst(&(*Q), &(*X));
}

void Insert_Last(Queue *Q, int X)
{
    address P;
    CreateNode(&P);
    if (P != nil)
    {
        IsiNode(&P, X);
        InsertLast(Q, P);
    }
}