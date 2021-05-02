// queue.h

#ifndef QUEUE_H
#define QUEUE_H


#include "../data_dyno_type.h"

// Queue's node struct
typedef struct NodeQ{
    struct NodeQ *next;
    Data_dyno_type data;
} NodeQ;

// Queue main struct
typedef struct Queue{
    NodeQ *front, *rear;
} Queue;

// if empty -> 1 else 0
int is_emptyQueue(Queue *q);

// return length of queue
int lenQueue(Queue *q);

// Sub-function for creating node
NodeQ* newNodeQ(Data_dyno_type data);

// Function for creating Queue
Queue *createQueue();

// Put element in Queue
void enQueue(Queue* q, Data_dyno_type data);

// Remove top element from Queue
void deQueue(Queue* q);

// Lookup for data in Queue, found -> 1 else 0
int searchQueue(Queue* q, Data_dyno_type data); // works only for integer

// Print Queue from first to last
void printQueue(Queue* q); // right now works only for integer

#endif