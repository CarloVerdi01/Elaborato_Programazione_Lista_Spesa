//
// Created by Carlo Verdi on 23/10/23.
//

#ifndef PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_LISTADELLASPESA_H
#define PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_LISTADELLASPESA_H


#include <map>
#include "Prodotto.h"

class ListaDellaSpesa {
public:
    explicit ListaDellaSpesa(std::string name) : listName(name) {}
    ~ListaDellaSpesa(){
        lista_della_spesa.clear();
    }

    void addProduct(std::shared_ptr<Prodotto>& p);

    void removeProduct(std::shared_ptr<Prodotto>& p);

    bool findProduct(std::shared_ptr<Prodotto>& p) const;


    void printList() const;

private:
    std::multimap<std::string, std::shared_ptr<Prodotto>> lista_della_spesa;
    std::string listName;
};


#endif //PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_LISTADELLASPESA_H
