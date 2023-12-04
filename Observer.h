//
// Created by Carlo Verdi on 24/10/23.
//

#ifndef PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_OBSERVER_H
#define PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_OBSERVER_H


#include "Prodotto.h"

enum class Operazione {
    Aggiunta,
    Rimozione,
    Decremento,
    ModificaStato
};


class Observer {
public:
    virtual ~Observer() {};

    virtual void update(Operazione operazione, std::string ls, Prodotto& p, const std::string& product, int quantity, bool state) = 0;





};


#endif //PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_OBSERVER_H
