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

    void addProduct(std::shared_ptr<Prodotto>& p, int quantity);

    void removeProduct(std::shared_ptr<Prodotto>& p);

    void reduceProductQuantity(std::shared_ptr<Prodotto>& p, int q);

    bool findProduct(std::shared_ptr<Prodotto>& p) const;

    void printList() const;

    std::string getListName() const{
        return listName;
    }

    void setListName(std::string n) {
        listName = n;
    }

private:
    std::multimap<std::string, std::shared_ptr<Prodotto>> lista_della_spesa;
    std::string listName;
};


#endif //PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_LISTADELLASPESA_H
