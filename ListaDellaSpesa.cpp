//
// Created by Carlo Verdi on 23/10/23.
//

#include <iostream>
#include "ListaDellaSpesa.h"
#include "Prodotto.h"

void ListaDellaSpesa::addProduct(std::shared_ptr<Prodotto>& p, int quantity) {
    bool found = false;
    for (auto iter : lista_della_spesa){
        if (iter.second->getName() == p->getName()){
            iter.second->addQuantity(quantity);
            found = true;
            break;
        }
    }
    if (!found) {
        p->setQuantity(quantity);
        lista_della_spesa.insert(std::make_pair(p->getCategory(), p));
    }
}

bool ListaDellaSpesa::findProduct(std::shared_ptr<Prodotto>& p) const{
    bool found = false;
    for (auto iter : lista_della_spesa){
        if (iter.second->getName() == p->getName()){
            found = true;
            break;
        }
    }
    return found;
}


void ListaDellaSpesa::removeProduct(std::shared_ptr<Prodotto> &p) {
    for (auto iter = lista_della_spesa.begin(); iter != lista_della_spesa.end();) {
        if (iter->second->getName() == p->getName()) {
            lista_della_spesa.erase(iter);
            break;
        } else {
            ++iter;
        }
    }
}

void ListaDellaSpesa::printList() const {
    std::cout << listName << ":" << std::endl;
    for (auto iter : lista_della_spesa)
        iter.second->printProduct();
}
