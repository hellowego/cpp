#include "../include/Queue.h"

Stack *stackCreate(int cpacity)
{
    Stack *ret = malloc(sizeof(Stack));
    ret->stk = malloc(sizeof(int) * cpacity);
    ret->stkSize = 0;
    ret->stkCapacity = cpacity;
    return ret;
}
