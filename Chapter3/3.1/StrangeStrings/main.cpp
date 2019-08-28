/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 3. Обработка текстов                              *
*          3.1. Способы представления строк                    *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : main.cpp                                         *
*  Описание : Пример ошибочной работы со строками языка C      *
***************************************************************/

#include <iostream>
#include <string.h>

using namespace std;

//===============================================================
// Это пример короткой программы, в которой в выходной поток
// выводятся не те строки, которые могли бы ожидаться программистом
//===============================================================

int main()
{
    char * str1 = "Fleur-de-Lys";
    char * str2 = str1;

    strcpy(str1, "Esmeralda");
    // Неудивительно, что при исполнении следующей строки
    // в стандартный выходной поток будет выведена строка "Esmeralda"
    cout << str2 << endl;

    // Удивительно, что строка "Esmeralda" будет выведена в
    // стандартный выходной поток и при исполнении следующих строк:
    char * str3 = "Fleur-de-Lys";
    cout << str3 << endl;

    return 0;
}
