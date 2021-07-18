// doubly_linked_stack.h

#ifndef DOUBLY_LINKED_STACK_H
#define DOUBLY_LINKED_STACK_H


#include "../data_dyno_type.h"


// Структура для описания узла двусвязного стека
// Doubly cyclic stack node structure
typedef struct{
    Node_doubly_linked_stack* next;
    Node_doubly_linked_stack* prev;
    Data_dyno_type data;
} Node_doubly_linked_stack;

// Структура для двусвязного стека
// Doubly cyclic stack main struct
typedef struct {
    Node_doubly_linked_stack* start;
} Doubly_linked_stack;

// Инициализация двусвязного стека
// Doubly cyclic stack initialization
Doubly_linked_stack* init_stack();

// Добавление элемента в двусвязный стек
// Push element to doubly linked cyclic stack
void push(Doubly_linked_stack* stack, Data_dyno_type data);

// Удаляет элемент из двусвязного стека и возвращает его назад
// Remove top element and return it
Data_dyno_type pop(Doubly_linked_stack* stack);

// Проверяет двусвязный стек на пустоту
// Check if stack is empty
int is_empty(Doubly_linked_stack* stack);

// Просмотреть верхний элемент двусвязного стека
// Return top element
Data_dyno_type top(Doubly_linked_stack* stack);

#endif