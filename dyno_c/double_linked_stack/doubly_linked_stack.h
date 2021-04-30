// doubly_linked_stack.h

#ifndef STACK_H
#define STACK_H


#include "../data_dyno_type.h"


// Структура для описания узла двусвязного стека
typedef struct{
    Node_doubly_linked_stack* next;
    Node_doubly_linked_stack* prev;
    Data_dyno_type data;
} Node_doubly_linked_stack;

// Структура для двусвязного стека
typedef struct {
    Node_doubly_linked_stack* start;
} Doubly_linked_stack;

// Инициализация двусвязного стека
Doubly_linked_stack* init_stack();

// Добавление элемента в двусвязный стек
void push(Doubly_linked_stack* stack, Data_dyno_type data);

// Удаляет элемент из двусвязного стека и возвращает его назад
Data_dyno_type pop(Doubly_linked_stack* stack);

// Проверяет двусвязный стек на пустоту
int is_empty(Doubly_linked_stack* stack);

// Просмотреть верхний элемент двусвязного стека
Data_dyno_type top(Doubly_linked_stack* stack);

#endif