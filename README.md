# Dyno_C lib

## О библиотеке

**Dyno_C** - библиотека, содержащая реализации следующих динамических структур на языке C:

* Стек *(Stack)*
* Очередь *(Queue)*
* Циклический стек *(Cyclic_stack)*
* Двусвязный стек *(Doubly_stack)*
* Двусвязная очередь *(Doubly_Queue)*

Особенности библиотеки:
* Библиотека содержит реализацию универсальных динамических структур для любого типа поддерживаемого в языке си
* Часть реализованных структур реализованы только для лабораторных работ в МИЭМ НИУ ВШЭ, при этом различий в использовании с классическими структурами нет, они существуют только на уровне реализации, Примером такой структуры может послужить *Cyclic_stack* (Циклический стек). 
* Каждый модуль библиотеки содержит реализацию каждой динамической структуры через malloc и free (Из stdlib.h), а так же альтернативную реализацию этой структуры через new и delte (с++), эта реализация была добавлена для соблюдения требования лабораторной работы МИЭМ НИУ ВШЭ.
