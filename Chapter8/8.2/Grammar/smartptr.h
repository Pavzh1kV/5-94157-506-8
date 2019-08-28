/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 8. Функции как носитель информации                *
*          8.2. Задача о расстановке ферзей на шахматной доске *
*               и другие задачи                                *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : smartptr.h                                       *
*  Описание : Определение классов для реализации "умных"       *
*             указателей                                       *
***************************************************************/

#ifndef __SMART_PTR
#define __SMART_PTR

#include <stdlib.h>

//--------------------------------------------------------------
// Шаблон RefCount представляет пару из указателя и счетчика
// ссылок на этот указатель. Реализованы только непустые указатели
//--------------------------------------------------------------
template <class Object>
class RefCount
{
    Object * obj;    // Указатель на объект
    int cnt;         // Счетчик количества ссылок

public :
    // Конструктор инициализирует счетчик ссылок,
    // устанавливая его равным единице
    RefCount(Object * o) : obj(o), cnt(1) {}

    // Деструктору делать нечего, поскольку к моменту уничтожения объекта
    // класса RefCount указуемый им объект уже должен быть уничтожен
    ~RefCount() {}

    // Функция инкрементации просто увеличивает значение счетчика
    void addRef()
    {
        ++cnt;
    }

    // Функция освобождения не только уменьшает значение счетчика
    // ссылок, но и уничтожает объект, если этот счетчик стал равен нулю.
    void release()
    {
        if (--cnt == 0)
        {
            delete obj;   // Уничтожается объект, на который велся учет ссылок
            delete this;  // Уничтожается и сам объект класса RefCount
        }
    }

    // Доступ к объекту реализован в виде оператора приведения к типу
    operator Object*() const
    {
        return obj;
    }
};

//--------------------------------------------------------------
// Шаблон SmartPtr представляет "умный" указатель. Он организует
// промежуточный счетчик ссылок и работает с ним при выполнении
// операций присваивания и уничтожения указателя.
//--------------------------------------------------------------
template <class Object>
class SmartPtr
{
    RefCount<Object> * ptr;   // Промежуточный счетчик ссылок

public :
    // Конструктор создает счетчик ссылок и запоминает указатель на объект.
    // Если исходный указатель пуст, то создается "пустая ссылка"
    SmartPtr(Object * o = NULL)
    {
        if (o == NULL)
        {
            ptr = NULL;
        }
        else
        {
            ptr = new RefCount<Object>(o);
        }
    }

    // Конструктор копирования увеличивает счетчик ссылок
    // в связи с появлением новой копии указателя
    SmartPtr(const SmartPtr<Object> & p) : ptr(p.ptr)
    {
        if (ptr) ptr->addRef();
    }

    // Деструктор уменьшает значение счетчика ссылок
    // (в результате объект может быть уничтожен)
    ~SmartPtr()
    {
        if (ptr) ptr->release();
    }

    // Оператор присваивания уменьшает значение одного счетчика
    // ссылок и увеличивает значение другого счетчика. Объект, ссылка
    // на который уничтожается, в результате тоже может быть уничтожен
    SmartPtr & operator = (const SmartPtr<Object> & p)
    {
        if (ptr != p.ptr)
        {
            if (ptr) ptr->release();
            if (p.ptr) p.ptr->addRef();
            ptr = p.ptr;
        }
        return *this;
    }

    // Проверка, не содержит ли указатель "пустую ссылку"
    bool empty() const
    {
        return ptr == NULL;
    }

    //--------------------------------------------------------------
    // Операторы, обеспечивающие доступ к объекту "как через обычный указатель"
    //--------------------------------------------------------------

    // Оператор преобразования типа к "обычному" указателю
    operator Object* ()
    {
        return (Object*)*ptr;
    }

    // Операторы дотупа к объекту по указателю
    Object & operator *()
    {
        return *(Object*)*ptr;
    }
    const Object & operator *() const
    {
        return *(Object*)*ptr;
    }

    // Операторы дотупа к полям и методам объекта
    Object * operator ->()
    {
        return (Object*)*ptr;
    }
    Object * operator ->() const
    {
        return (Object*)*ptr;
    }

    // Проверка пустоты
    operator bool() const
    {
        return !empty();
    }
    bool operator !() const
    {
        return empty();
    }

    // Операторы поверки на совпадение указателей
    bool operator == (const SmartPtr<Object> & p) const
    {
        return ptr == p.ptr;
    }
    bool operator == (Object * o) const
    {
        if (o == NULL) return ptr == NULL;
        if (ptr == NULL) return false;
        return *ptr == o;
    }

    // Операторы проверки на несовпадение указателей
    bool operator != (const SmartPtr<Object> & p) const
    {
        return !operator ==(p);
    }
    bool operator != (Object * o) const
    {
        return !operator ==(o);
    }
};

#endif
