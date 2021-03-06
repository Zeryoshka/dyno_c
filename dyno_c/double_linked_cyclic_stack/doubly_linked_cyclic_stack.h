// doubly_linked_stack.h

#ifndef DOUBLY_LINKED_CYCLIC_STACK_H
#define DOUBLY_LINKED_CYCLIC_STACK_H


#include "../data_dyno_type.h"


// Структура для описания узла двусвязного циклического стека
// Doubly cyclic stack node structure
typedef struct{
    Node_doubly_linked_cyclic_stack* next;
    Node_doubly_linked_cyclic_stack* prev;
    Data_dyno_type data;
} Node_doubly_linked_cyclic_stack;

// Структура для двусвязного циклического стека
// Doubly cyclic stack main struct
typedef struct {
    Node_doubly_linked_cyclic_stack* start;
    Node_doubly_linked_cyclic_stack* end;
} Doubly_linked_cyclic_stack;

// Инициализация двусвязного циклического стека
// Doubly cyclic stack initialization
Doubly_linked_cyclic_stack* init_stack();

// Добавление элемента в двусвязный цкилический стек
// Push element to doubly linked cyclic stack
void push(Doubly_linked_cyclic_stack* stack, Data_dyno_type data);

// Удаляет элемент из двусвязного стека и возвращает его назад
// Remove top element and return it
Data_dyno_type pop(Doubly_linked_cyclic_stack* stack);

// Проверяет двусвязный цкилический стек на пустоту
// Check if stack is empty
int is_empty(Doubly_linked_cyclic_stack* stack);

// Просмотреть верхний элемент двусвязного цкилического стека
// Return top element
Data_dyno_type top(Doubly_linked_cyclic_stack* stack);

#endif