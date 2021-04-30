//stack.h

#ifndef STACK_H
#define STACK_H


#include "data_dyno_type.h"


// Структура для описания узла стека
typedef struct{
    Node_stack* next;
    Data_dyno_type data;
} Node_stack;

// Структура для стека
typedef struct {
    Node_stack* start;
} Stack;

// Инициализация стека
Stack* init_stack();

// Добавление элемента в стек
void push(Stack* stack, Data_dyno_type data);

// Удаляет элемент из стека и возвращает его назад
Data_dyno_type pop(Stack* stack);

// Проверяет элемент стека на пустоту
int is_empty(Stack* stack);

// Просмотреть верхний элемент
Data_dyno_type top(Stack* stack);

#endif