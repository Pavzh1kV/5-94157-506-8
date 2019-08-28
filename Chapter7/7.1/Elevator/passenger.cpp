/***************************************************************
*  Структуры и алгоритмы обработки данных:                     *
*  объектно-ориентированный подход и реализация на C++         *
*      Глава 7. Обмен сообщениями и обработка сообщений        *
*          7.1. Схема обмена сообщениями                       *
*                                                              *
*  Автор    : А.Кубенский                                      *
*  Файл     : passenger.cpp                                    *
*  Описание : Реализация операций  класса, определяющего       *
*             поведение пассажиров лифта                       *
***************************************************************/

#include "passenger.h"

// Функции генерации и обработки сообщений
Message * Passenger::generate()
{
    // Реализация метода отсутствует

    // Новый появившийся в системе пассажир должен сгененрировать
    // заявку на обслуживание его лифтом. Кроме того, с течением
    // времени он может отменить заявку. Возможно, в системе
    // обрабатываются и другие сообщения от пассажиров:
    // об изменении состояния, об удовлетворении заявки и т.п.
    return NULL;
}

bool Passenger::handle(const Message & msg)
{
    // Реализация метода отсутствует

    // Обработка сообщения может заключаться в следующем:
    // - с течением времени (сообщение от таймера) пассажир может
    //   отменить заявку и покинуть систему;
    // - с приходом лифта (обработка сообщения от лифта) пассажир
    //   изменяет свое состояние (входит в лифт);
    // - пассажир перемещается (изменяет состояние) вместе с лифтом;
    // - когда лифт останавливается на нужном пассажиру этаже,
    //   пассажир тоже меняет свое состояние, выходя из лифта
    return false;
}
