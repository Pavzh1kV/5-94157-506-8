/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 5. Алгоритмы распределения памяти                 *
*          5.2. Распределение памяти блоками постоянной длины  *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : treedictionary.h                                 *
*  Описание : Реализация простого словаря на базе бинарного    *
*             дерева поиска с хранением элементов в системе    *
*             распределения памяти с блоками постоянной длины  *
***************************************************************/

#ifndef __TREE_DICTIONARY_H
#define __TREE_DICTIONARY_H

#include "blockbuffer.h"
#include <string>
#include <iostream>

//==============================================================
// Класс Actor задает абстрактное действие,
// выполняемое над словами из словаря
//==============================================================

class Actor
{
public :
    virtual void act(string & s) = 0;
};

//==============================================================
// Класс TreeDictionary реализует простое бинарное дерево слов
// с хранением узлов дерева в системе распределения памяти,
// представленной объектом класса BlockBuffer
//==============================================================

class TreeDictionary
{
    // Вложенная структура TreeItem представляет узел дерева
    struct TreeItem
    {
        string word;      // Хранящееся в словаре слово
        TreeItem * left,  // Ссылка на левое поддерево (меньшие слова)
                 * right; // Ссылка на правое поддерево (большие слова)
        // Конструктор задает содержимое узла
        TreeItem(string word, TreeItem * left = NULL, TreeItem * right = NULL)
            : word(word), left(left), right(right) {}
    };

    // Корень дерева:
    TreeItem * root;
    // Система управления памятью для узлов дерева
    BlockBuffer<sizeof(TreeItem)> * memoryManagement;

public :

    // Конструктор дерева создает пустое дерево
    // и создает систему управления памятью
    TreeDictionary(int capacity)
        : root(NULL),
          memoryManagement(new BlockBuffer<sizeof(TreeItem)>(capacity)) {}

    // Деструктор словаря уничтожает систему управления памятью
    ~TreeDictionary()
    {
        delete memoryManagement;
    }

    // Функция добавления нового слова в словарь:
    void addWord(string w);
    // Внутренний итератор слов в порядке возрастания:
    void intIterator(Actor & actor);

private:

    // Вспомогательная рекурсивная функция, реализующая простой
    // алгоритм добавления нового узла в дерево словаря
    void addWord(const string & w, TreeItem ** root);

    // Вспомогательная рекурсивная функция,
    // реализующая левосторонний обход узлов дерева
    void traverse(TreeItem * root, Actor & actor);
};

// Функция вывода слов из словаря в выходной поток в порядке возрастания
ostream & operator << (ostream & out, TreeDictionary & dict);

#endif