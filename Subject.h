//
// Created by Carlo Verdi on 24/10/23.
//

#ifndef PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_SUBJECT_H
#define PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_SUBJECT_H


#include <memory>
#include "Observer.h"

class Subject {
public:
    virtual ~Subject() {};

    virtual void registerObserver(std::unique_ptr<Observer> o) = 0;
    virtual void removeObserver(std::unique_ptr<Observer> o) = 0;
    virtual void notify() = 0;
};


#endif //PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_SUBJECT_H
