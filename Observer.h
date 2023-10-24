//
// Created by Carlo Verdi on 24/10/23.
//

#ifndef PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_OBSERVER_H
#define PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_OBSERVER_H


class Observer {
public:
    virtual ~Observer() {};

    virtual void attach() = 0;
    virtual void detach() = 0;
    virtual void update() = 0;

private:


};


#endif //PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_OBSERVER_H
