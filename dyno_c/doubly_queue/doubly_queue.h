// doubly_Doubly_queue.c

#ifndef DOUBLY_Doubly_queue_H
#define DOUBLY_Doubly_queue_H


#include "../data_dyno_type.h"


// Doubly_queue's node struct
typedef struct Doubly_node{
    struct Doubly_node* next, *prev;
    Data_dyno_type data;
} Doubly_node;

// Doubly Queue struct
typedef struct {
    Doubly_node* front, *rear;
} Doubly_queue;

// if empty -> 1 else 0
int is_emptyDoubly_queue(Doubly_queue *q);

// return length of Doubly_queue
int lenDoubly_queue(Doubly_queue *q);

// Sub-function for creating node
Doubly_node* newDoubly_node(Data_dyno_type data);

// Function for creating Doubly_queue
Doubly_queue *createDoubly_queue();

// Put element in Doubly_queue
void enDoubly_queue(Doubly_queue* q, Data_dyno_type data);

// Remove top element from Doubly_queue
void deDoubly_queue(Doubly_queue* q);

// Lookup for data in Queue, found -> 1 else 0
int searchDoubly_queue(Doubly_queue* q, Data_dyno_type data); // right now works only for integer

// Print Doubly_queue from first to last
void printDoubly_queueFront(Doubly_queue* q); // right now works only for integer

void printDoubly_queueBack(Doubly_queue* q);

#endif