#ifndef STACK_H
#define STACK_H
#include "linked.h"

//Method
void PushStack(address *top, boolean nilai);
void PopStack(address *top, int *X);
boolean isEmptyStack(address top);
void DesimalConverterToBinary (int desimal, address *top);
void PrintStack(address top);

#endif