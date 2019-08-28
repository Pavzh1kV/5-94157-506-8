/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 7. Обмен сообщениями и обработка сообщений        *
*          7.2. Об одном способе вычисления конечных сумм      *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : message.h                                        *
*  Описание : Описание класса для представления сообщений      *
***************************************************************/

#ifndef __MESSAGE_H
#define __MESSAGE_H

//-------------------------------------------------------------
// Класс Message - основа для реализации сообщений
//-------------------------------------------------------------

class Message
{
    int msgClass;     // класс сообщения

public :
    /*   Конструкторы   */
    Message(int cl) : msgClass(cl) {}
    Message(const Message & msg) : msgClass(msg.msgClass) {}

    /*   Деструктор   */
    virtual ~Message() {}

    /*   Функции доступа   */
    int getMsgClass() const
    {
        return msgClass;
    }
};

#endif