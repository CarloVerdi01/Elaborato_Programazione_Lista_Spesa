//
// Created by Carlo Verdi on 23/10/23.
//

#include <iostream>
#include "ListaDellaSpesa.h"
#include "Prodotto.h"
#include "ProdottiDaBagno.h"
#include "Abbigliamento.h"
#include "Altro.h"
#include "Bevande.h"
#include "Elettronica.h"
#include "Forno.h"
#include "FruttaEVerdura.h"
#include "Igiene.h"
#include "Macelleria.h"
#include "Pescheria.h"
#include "Pulizia.h"

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
        std::shared_ptr<Prodotto> copia;
        if ( std::dynamic_pointer_cast<ProdottiDaBagno>(p)) {
            copia = std::make_shared<ProdottiDaBagno>(p->getName(), p->getPrice());
        } else if (std::dynamic_pointer_cast<Abbigliamento>(p)){
            copia = std::make_shared<Abbigliamento>(p->getName(), p->getPrice());
        } else if (std::dynamic_pointer_cast<Altro>(p)){
            copia = std::make_shared<Altro>(p->getName(), p->getPrice());
        } else if (std::dynamic_pointer_cast<Bevande>(p)){
            copia = std::make_shared<Bevande>(p->getName(), p->getPrice());
        }else if (std::dynamic_pointer_cast<Elettronica>(p)){
            copia = std::make_shared<Elettronica>(p->getName(), p->getPrice());
        } else if (std::dynamic_pointer_cast<Forno>(p)){
            copia = std::make_shared<Forno>(p->getName(), p->getPrice());
        } else if (std::dynamic_pointer_cast<FruttaEVerdura>(p)){
            copia = std::make_shared<FruttaEVerdura>(p->getName(), p->getPrice());
        } else if (std::dynamic_pointer_cast<Igiene>(p)){
            copia = std::make_shared<Igiene>(p->getName(), p->getPrice());
        } else if (std::dynamic_pointer_cast<Macelleria>(p)){
            copia = std::make_shared<Macelleria>(p->getName(), p->getPrice());
        } else if (std::dynamic_pointer_cast<Pescheria>(p)){
            copia = std::make_shared<Pescheria>(p->getName(), p->getPrice());
        } else if (std::dynamic_pointer_cast<Pulizia>(p)){
            copia = std::make_shared<Pulizia>(p->getName(), p->getPrice());
        }
        if (copia) {
            copia->setQuantity(quantity);
            lista_della_spesa.insert(std::make_pair(copia->getCategory(), copia));
        }
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
    float count = 0;
    std::cout << listName << ":" << std::endl;
    for (auto iter : lista_della_spesa) {
        iter.second->printProduct();
        count += (iter.second->getPrice() * iter.second->getQuantity());
    }
    std::cout << "Spesa totale: " << count << "€" << std::endl;
}

void ListaDellaSpesa::reduceProductQuantity(std::shared_ptr<Prodotto> &p, int q) {
    for (auto iter = lista_della_spesa.begin(); iter != lista_della_spesa.end();) {
        if (iter->second->getName() == p->getName()) {
            if (iter->second->getQuantity() < q ||  iter->second->getQuantity() == q) {
                lista_della_spesa.erase(iter);
                break;
            }
            else {
                iter->second->removeQuantity(q);
                break;
            }
        } else {
            ++iter;
        }
    }
}

