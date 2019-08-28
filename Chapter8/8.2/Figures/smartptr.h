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
    // Конструктор создает счетчик ссылок и запоминает указатель на объект
    SmartPtr(Object * o) : ptr(new RefCount<Object>(o)) {}

    // Конструктор копирования увеличивает счетчик ссылок
    // в связи с появлением новой копии указателя
    SmartPtr(const SmartPtr<Object> & p) : ptr(p.ptr)
    {
        ptr->addRef();
    }

    // Деструктор уменьшает значение счетчика ссылок
    // (в результате объект может быть уничтожен)
    ~SmartPtr()
    {
        ptr->release();
    }

    // Оператор присваивания уменьшает значение одного счетчика
    // ссылок и увеличивает значение другого счетчика. Объект, ссылка
    // на который уничтожается, в результате тоже может быть уничтожен
    SmartPtr & operator = (const SmartPtr<Object> & p)
    {
        if (ptr != p.ptr)
        {
            ptr->release();
            p.ptr->addRef();
            ptr = p.ptr;
        }
        return *this;
    }

    // Операторы, обеспечивающие доступ к объекту "как через обычный указатель"
    operator Object* ()
    {
        return (Object*)*ptr;
    }
    Object & operator *()
    {
        return *(Object*)*ptr;
    }
    const Object & operator *() const
    {
        return *(Object*)*ptr;
    }
    Object * operator ->()
    {
        return (Object*)*ptr;
    }
    Object * operator ->() const
    {
        return (Object*)*ptr;
    }
};

#endif
