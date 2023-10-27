//
// Created by Carlo Verdi on 24/10/23.
//

#ifndef PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_OBSERVER_H
#define PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_OBSERVER_H


#include "Prodotto.h"

class Observer {
public:
    virtual ~Observer() {};

    virtual void updateAdd(std::string ls, std::shared_ptr<Prodotto> p, int q) = 0;





};


#endif //PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_OBSERVER_H
