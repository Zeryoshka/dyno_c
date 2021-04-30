//cyclic_stack.h

#ifndef STACK_H
#define STACK_H

#include "../data_dyno_type.h"


// Структура для описания узла циклического стека
typedef struct{
    Node_cyclic_stack* next;
    Data_dyno_type data;
} Node_cyclic_stack;

// Структура для циклического стека
typedef struct {
    Node_cyclic_stack* top;
    Node_cyclic_stack* bottom;
} Cyclic_stack;

// Инициализация циклического стека
Cyclic_stack* init_cyclic_stack();

// Добавление элемента в циклический стек
void push(Cyclic_stack* stack, Data_dyno_type data);

// Удаляет элемент из циклического стека и возвращает его назад
Data_dyno_type pop(Cyclic_stack* stack);

// Проверка циклического стека на пустоту
int is_empty(Cyclic_stack* stack);

// Просмотреть верхний элемент циклического стека
Data_dyno_type top(Cyclic_stack* stack);

#endif