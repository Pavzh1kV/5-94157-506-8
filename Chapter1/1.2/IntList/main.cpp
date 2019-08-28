/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 1. Способы представления структур данных          *
*          1.2. Списки                                         *
*                                                              *
*  Автор    : A.Кубенский                                      *
*  Файл     : main.cpp                                         *
*  Описание : Тестовая функция:                                *
*             проверка методов работы со списком               *
***************************************************************/

#include "IntList.h"

int main()
{
    IntList list;         // Создание пустого списка
    list.addLast(2);      // Добавление элементов
    list.addLast(3);
    list.addFirst(1);
    list.printAll();      // Печать элементов

    IntList list1(list);  // Копирование списка
    list1.addLast(4);     // Добавление элемента
    list1.remove(2);      // Удаление некоторых элементов
    list1.remove(5);
    list1.remove(4);
    list1.printAll();     // Печать результата

    return 0;
}