/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 4. Символьные преобразования                      *
*          4.1. Представление выражений                        *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : dictionary.h                                     *
*  Описание : Представление словаря в виде хеш-таблицы         *
***************************************************************/

#ifndef __DICTIONARY_H
#define __DICTIONARY_H

#include <string>
#include <iostream>
#include "iterator.h"

using namespace std;

//=============================================================
// Класс, представляющий словарь в виде хеш-таблицы
//=============================================================
class HashDictionary
{
    friend ostream & operator << (ostream & out, HashDictionary & dict);

protected:

#ifndef P
#define P        557
#endif
#ifndef Q
#define Q        811
#endif
#ifndef LENGTH
#define LENGTH   1000
#endif

    string *dict[LENGTH];      // хранилище на 1000 слов

public:

    /******************************************************
     * Функция расстановки, основанная на сложении кодов
     * букв со смещением, соответствующим их позиции
     ******************************************************/
    static int hash(const string & str);

protected:

    // Класс для представления внешнего итератора слов из словаря
    class KeysIterator : public Iterator<string>
    {
        // Текущая позиция в таблице слов (указатель)
        int pos;
        // Указатель на сам массив слов
        string ** dict;

    public :
        // Конструктор устанавливает указатель на первое непустое слово
        KeysIterator(string **dict) : pos(-1), dict(dict)
        {
            ++*this;
        }
        // Слова еще есть, если указатель еще находтся в пределах массива
        bool hasMoreElements() const
        {
            return pos < LENGTH;
        }
        // Сдвиг итератора на следующий элемент
        Iterator<string> & operator ++();
        // Доступ к текущему слову
        const string & operator *() const
        {
            return *dict[pos];
        }
        string & operator *()
        {
            return *dict[pos];
        }
    };

    /******************************************************
     * Внутренняя функция поиска позиции слова в словаре
     ******************************************************/
    int findPos(const string & word) const;

public:
    /******************************************************
     * Конструктор записывает в словарь пустые ссылки
     ******************************************************/
    HashDictionary()
    {
        memset(dict, 0, sizeof(dict));
    }

    /******************************************************
     * Функция добавления слова в словарь. Если слово уже было
     * в словаре, то второй раз оно в словарь не попадает
     ******************************************************/
    void add(const string & word);

    /******************************************************
     * Функция проверки наличия слова в словаре
     ******************************************************/
    bool hasWord(const string & word) const;

    /******************************************************
     * Функция порождения внешнего итератора слов
     ******************************************************/
    Iterator<string> * keys()
    {
        return new KeysIterator(dict);
    }
};

#endif
