//
// Created by Carlo Verdi on 23/10/23.
//

#include <iostream>
#include "Utente.h"
#include "ListaDellaSpesa.h"
#include "Prodotto.h"

void ListaDellaSpesa::addProduct(Prodotto& p, const int quantity ) {
    if (quantity > 0) {
        bool found = false;
        for (auto iter: listaDellaSpesa) {
            if (iter.second.getName() == p.getName()) {
                iter.second.addQuantity(quantity);
                found = true;
                break;
            }
        }
        if (!found) {
            Prodotto copia(p);
            copia.setQuantity(quantity);
            listaDellaSpesa.insert(std::make_pair(copia.getCategory(), copia));
        }
        notify(Operazione::Aggiunta, listName, p, " ", quantity, false);
    } else
        std::cout << "Quantità non accettabile!" << std::endl;
}

bool ListaDellaSpesa::findProduct(const std::string product) const{
    bool found = false;
    for (auto iter : listaDellaSpesa){
        if (iter.second.getName() == product){
            found = true;
            break;
        }
    }
    return found;
}


void ListaDellaSpesa::removeProduct(const std::string product) {
    bool found = false;
    for (auto iter = listaDellaSpesa.begin(); iter != listaDellaSpesa.end();) {
        if (iter->second.getName() == product) {
            found = true;
            listaDellaSpesa.erase(iter);
            //notifyRemove(listName, product);
            notify(Operazione::Rimozione, listName, iter->second, product, 0, false);
            break;
        } else {
            ++iter;
        }
    }
    if (!found){
        std::cout << "Prodotto " << product << " non presente nella lista!" << std::endl;
    }
}

void ListaDellaSpesa::printList() const {
    std::cout << listName << ":" << std::endl;
    for (auto iter : listaDellaSpesa) {
        iter.second.printProduct();
    }
    int count = getNumberOfPurchasedProduct();
    int count2 = getNumberOfProduct();
    std::cout << count<<"/"<<count2 << std::endl;
}

void ListaDellaSpesa::reduceProductQuantity(const std::string product, const int q) {
    if (q > 0) {
        bool found = false;
        for (auto iter = listaDellaSpesa.begin(); iter != listaDellaSpesa.end();) {
            if (iter->second.getName() == product) {
                found = true;
                if (iter->second.getQuantity() < q || iter->second.getQuantity() == q) {
                    listaDellaSpesa.erase(iter);
                    break;
                } else {
                    iter->second.removeQuantity(q);
                    break;
                }
            } else {
                ++iter;
            }
        }
        auto firstElementIterator = listaDellaSpesa.begin();
        Prodotto &firstElementSecond = firstElementIterator->second;
        notify(Operazione::Decremento, listName, firstElementSecond, product, q, false);

        if (!found)
            std::cout << "Prodotto " << product << " non presente nella lista!" << std::endl;
    } else
        std::cout << "Quantità non accettabile!" << std::endl;
}

void ListaDellaSpesa::shareList(Observer* o, const std::string user) {
    utentiCondivisi.push_back(user);
    registerObserver(o);


}

void ListaDellaSpesa::printListSharedUsers() const {
        printListOwner();
        std::cout << "Lista " << listName << " condivisa con: " << std::endl;
        for (auto iter : utentiCondivisi){
            std::cout << iter << std::endl;
        }
        std::cout << " " << std::endl;
}

const bool ListaDellaSpesa::isSharedUser(const std::string u) const {
    for (auto iter: utentiCondivisi){
        if ( iter == u)
            return true;
    }
    return false;
}

int ListaDellaSpesa::getProductQuantity(const std::string p) {
    int quantity = 0;
    for (auto iter : listaDellaSpesa){
        if (iter.second.getName() == p)
            quantity =  iter.second.getQuantity();
    }
    return quantity;
}


const std::list<std::string> ListaDellaSpesa::findProductOfCategory(const std::string category) const {
    std::list<std::string> prodotti;
    for (auto iter : listaDellaSpesa){
        if (iter.first == category){
            std::string name = iter.second.getName();
            prodotti.push_back(name);
        }
    }
    return prodotti;
}

const int ListaDellaSpesa::getNumberOfProduct() const {
    int count = 0;
    for (auto iter : listaDellaSpesa){
        count += 1;
    }
    return count;
}


const int ListaDellaSpesa::getNumberOfProductToBuy() const {
    int count = 0;
    for (auto iter : listaDellaSpesa){
        if (!iter.second.getStatus())
            count+= 1;
    }
    return count;
}

const int ListaDellaSpesa::getNumberOfPurchasedProduct() const {
    int count = 0;
    for (auto iter : listaDellaSpesa){
        if (iter.second.getStatus())
            count += 1;
    }
    return count;
}

void ListaDellaSpesa::setProductBought(const std::string product) {
    bool found = false;
    for (auto iter = listaDellaSpesa.begin(); iter != listaDellaSpesa.end(); ++iter){
        if (iter->second.getName() == product){
            found = true;
            iter->second.setStatus(true);
            auto firstElementIterator = listaDellaSpesa.begin();
            Prodotto& firstElementSecond = firstElementIterator->second;
            notify(Operazione::ModificaStato, listName, firstElementSecond, product, 0 , true);
        }
    }
    if (!found)
        std::cout << "Prodotto " << product << " non presente nella lista!" << std::endl;

}


void ListaDellaSpesa::setProductNotBought(const std::string product) {
    bool found = false;
    for (auto iter = listaDellaSpesa.begin(); iter != listaDellaSpesa.end(); ++iter){
        if (iter->second.getName() == product){
            found = true;
            iter->second.setStatus(false);
            auto firstElementIterator = listaDellaSpesa.begin();
            Prodotto& firstElementSecond = firstElementIterator->second;
            notify(Operazione::ModificaStato, listName, firstElementSecond, product, 0 , false);
        }
    }
    if (!found)
        std::cout << "Prodotto " << product << " non presente nella lista!" << std::endl;

}

bool ListaDellaSpesa::getProductStatus(std::string product) const {
    for (auto iter : listaDellaSpesa){
        if (iter.second.getName() == product){
            if (iter.second.getStatus())
                return true;
            else
                return false;
        }
    }
}
