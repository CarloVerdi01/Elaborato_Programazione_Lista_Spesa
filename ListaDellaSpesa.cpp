//
// Created by Carlo Verdi on 23/10/23.
//

#include <iostream>
#include "ListaDellaSpesa.h"
#include "Prodotto.h"

void ListaDellaSpesa::addProduct(std::shared_ptr<Prodotto>& p) {
    lista_della_spesa.insert(std::make_pair(p->getCategory(), p));
}

void ListaDellaSpesa::printList() const {
    std::cout << listName << ":" << std::endl;
    for (auto iter : lista_della_spesa)
        iter.second->printProduct();
}
