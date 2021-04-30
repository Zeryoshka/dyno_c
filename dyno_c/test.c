#include <stdio.h>
#include <stdlib.h>
#include "dyno_c.h"

int main(){
    Queue *q = createQueue();
    enQueue(q, 1);
    printQueue(q);
    printQueue(q);
    deQueue(q);
    enQueue(q, 1);
    printQueue(q);
}