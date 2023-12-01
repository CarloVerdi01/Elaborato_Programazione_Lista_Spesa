//
// Created by Carlo Verdi on 24/10/23.
//

#include <iostream>
#include "Utente.h"



ListaDellaSpesa& Utente::creaListaDellaSpesa(std::string name, std::string owner ) {
    ListaDellaSpesa nuovaLista(name, owner);
    listeSpesa.push_back(nuovaLista);
    return listeSpesa.back();
}


void Utente::addProductToList(ListaDellaSpesa& ls, Prodotto& p, int quantity ) {
    if (quantity > 0) {
        bool found = false;
        if (user == ls.getOwner()) {
            found = true;
            ls.addProduct(p, quantity);
        } else {
            found = ls.isSharedUser(user);
            if (found) {
                ls.addProduct(p, quantity);
            }
        }
        if (!found) {
            std::cout << userName << " non può aggiungere prodotti alla lista '" << ls.getListName()
                      << "' perchè non condivisa con " << user << std::endl;
        }
    }else
        std::cout << "Quantità non accettabile!" << std::endl;

}

void Utente::addProductToListByName(const std::string n, Prodotto& p, const int quantity) {
    bool found = false;
    bool usable = false;
    for (auto iter = listeSpesa.begin(); iter != listeSpesa.end(); ++iter) {
        if (iter->getListName() == n) {
            found = true;
            iter->addProduct(p, quantity);
            break;
        }
    }
    if (!found) {
        std::cout << userName << " non può aggiungere prodotti alla lista '" << n
        << "' perchè non condivisa con " << user << std::endl;
    }

}

void Utente::removeProductFromListByName(const std::string n, const std::string product) {
    bool found = false;
    bool usable = false;
    for (auto iter = listeSpesa.begin(); iter != listeSpesa.end(); ++iter) {
        if (iter->getListName() == n) {
            found = true;
            iter->removeProduct(product);
            break;
        }
    }
    if (!found) {
        std::cout << userName << " non può rimuovere prodotti dalla lista '" << n
                  << "' perchè non condivisa con " << user << std::endl;
    }

}

void Utente::reduceProductFromListByName(const std::string n, const std::string product, const int quantity) {
    bool found = false;
    bool usable = false;
    for (auto iter = listeSpesa.begin(); iter != listeSpesa.end(); ++iter) {
        if (iter->getListName() == n) {
            found = true;
            iter->reduceProductQuantity(product, quantity);
            break;
        }
    }
    if (!found) {
        std::cout << userName << " non può ridurre la quantità di un prodotto dalla lista '" << n
                  << "' perchè non condivisa con " << user << std::endl;
    }

}


void Utente::printOneShoppingList(const ListaDellaSpesa& ls) const {
    bool found = false;
    for (auto iter : listeSpesa){
        if (iter.getListName() == ls.getListName()){
            iter.printList();
            found = true;
            break;
        }
    }
    if (!found){
        std::cout << "Lista non appartenente all'utente!" << std::endl;
    }

}

void Utente::removeProductFromList(ListaDellaSpesa &ls, const std::string product) {
    ls.removeProduct(product);
}

void Utente::getShoppingLists() const {
    std::cout << "Liste della spesa di " << userName << " " << userSurname << ": " << std::endl;
    for (auto iter: listeSpesa) {
        std::cout << iter.getListName() << std::endl;
    }
}


void Utente::reduceProductQuantity(ListaDellaSpesa &ls, const std::string product, const int q) {
    if (q > 0) {
        ls.reduceProductQuantity(product, q);
    } else
        std::cout << "Quantità non accettabile!" << std::endl;
}


void Utente::printAllShoppingLists() const {
    std::cout << "Liste spesa " << userName << ":" <<std::endl;
    for (const auto& iter : listeSpesa) {
        iter.printList();
        std::cout << " " << std::endl;
    }
}

void Utente::shareList(ListaDellaSpesa& ls, Utente& u) {
    ls.shareList(&u, u.user);
    ListaDellaSpesa copiaLista = ls;
    u.addNewList(copiaLista);
}

void Utente::addNewList(ListaDellaSpesa &ls) {
    listeSpesa.push_back(ls);
}

bool Utente::findProductInList(const ListaDellaSpesa &ls, const std::string product) {
    return ls.findProduct(product);
}

void Utente::printAllShoopingListsName() const {
    std::cout << "Liste spesa " << user << ": " << std::endl;
    for (auto iter : listeSpesa)
        std::cout << iter.getListName() << std::endl;
    std::cout << " " << std::endl;
}

const bool Utente::findList(const std::string n) const {
    bool found = false;
    for (auto iter:listeSpesa){
        if (iter.getListName() == n){
            found = true;
            break;
        }
    }
    return found;
}

bool Utente::findProductInListByName(const std::string n, const std::string product) {
    bool found = false;
    for (auto iter : listeSpesa){
        if (iter.getListName() == n){
            found = iter.findProduct(product);
            break;
        }
    }
    return found;
}

int Utente::getProductQuantityInList(const std::string lista, const std::string product) {
    int quantity = 0;
    for (auto iter = listeSpesa.begin(); iter != listeSpesa.end(); ++iter){
        if (iter->getListName() == lista)
            quantity = iter->getProductQuantity(product);
    }
    return quantity;
}

void Utente::setProductBought(ListaDellaSpesa &ls, const std::string product) {
    bool found = false;
    if (user == ls.getOwner()){
        found = true;
        ls.setProductBought(product);
    } else{
        found = ls.isSharedUser(user);
        if (found){
            ls.setProductBought(product);
        }
    }
    if (!found)
        std::cout << "Lista non presente tra quelle dell'utente!" << std::endl;
}

void Utente::setProductNotBought(ListaDellaSpesa &ls, const std::string product) {
    bool found = false;
    if (user == ls.getOwner()){
        found = true;
        ls.setProductNotBought(product);
    } else{
        found = ls.isSharedUser(user);
        if (found){
            ls.setProductNotBought(product);
        }
    }
    if (!found)
        std::cout << "Lista non presente tra quelle dell'utente!" << std::endl;
}


void Utente::setProductBoughtByName(const std::string ls, const std::string product) {
    bool found = false;
    for (auto iter = listeSpesa.begin(); iter != listeSpesa.end(); ++iter){
        if (iter->getListName() == ls){
            found = true;
            iter->setProductBought(product);
            break;
        }
    }
    if (!found){
        std::cout << "Lista non presente tra quelle dell'utente!" << std::endl;
    }
}

void Utente::setProductNotBoughtByName(const std::string ls,  const std::string product) {
    bool found = false;
    for (auto iter = listeSpesa.begin(); iter != listeSpesa.end(); ++iter){
        if (iter->getListName() == ls){
            found = true;
            iter->setProductNotBought(product);
            break;
        }
    }
    if (!found){
        std::cout << "Lista non presente tra quelle dell'utente!" << std::endl;
    }
}

const bool& Utente::isProductBought(const std::string ls, const std::string product) const {
    for (auto iter : listeSpesa){
        if (iter.getListName() == ls){
            return iter.getProductStatus(product);
        }
    }
}