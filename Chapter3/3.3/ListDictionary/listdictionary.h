/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 3. Обработка текстов                              *
*          3.3. Словари, представленные списками и деревьями   *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : listdictionary.h                                 *
*  Описание : Представление словаря в виде упорядоченного      *
*             списка пар (ключ, значение).                     *
***************************************************************/

#ifndef __LIST_DICTIONARY_H
#define __LIST_DICTIONARY_H

#include <cstring>
#include "pair.h"
#include "sortedlist.h"
#include "iterator.h"

using namespace std;

//=============================================================
// Класс представляет упорядоченный список пар (ключ, значение),
// где ключом является строка типа string, а значением может
// быть произвольным объектом. Для повышения быстродействия
// при поиске список упорядочен по возрастанию ключей.
//=============================================================

template <class Object>
class ListDictionary
{
    // Список list содержит упорядоченный список пар
    SortedList<Pair<Object> > list;

public :

    // Функция добавляет в упорядоченный список новую пару
    void add(string key, const Object & obj)
    {
        list.insert(Pair<Object>(key, obj));
    }

    // Функция осуществляет поиск пары по ключу и удаляет
    // найденную пару, если она в списке была
    void remove(string key)
    {
        list.remove(Pair<Object>(key));
    }

    // Функция поиска связанного объекта по ключу
    Object * find(string key)
    {
        Pair<Object> * found = list.find(Pair<Object>(key));
        return found ? &found->obj : NULL;
    }

    // Функция выдает внешний итератор пар, используя внешний
    // итератор упорядоченного списка
    Iterator<Pair<Object> > * iterator()
    {
        return list.iterator();
    }
};

#endif
