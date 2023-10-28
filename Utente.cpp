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


void Utente::addProductToList(ListaDellaSpesa& ls, std::shared_ptr<Prodotto> &p, int quantity) {
    bool found = false;
    if (user == ls.getOwner()){
        found = true;
        ls.addProduct(p, quantity);
    } else{
        found = ls.isSharedUser(user);
        if (found){
            ls.addProduct(p, quantity);
        }
    }
    if (!found){
        std::cout << userName << " non può aggiungere prodotti alla lista '" << ls.getListName() << "' perchè non condivisa con "<< user  << std::endl;
    }

}

void Utente::addProductToListByName(std::string n, std::shared_ptr<Prodotto> &p, int quantity) {
    bool found = false;
    bool usable = false;
    for (auto iter = listeSpesa.begin(); iter != listeSpesa.end(); ++iter) {
        if (iter->getListName() == n) {
            found = true;
            if (user == iter->getOwner()) {
                iter->addProduct(p, quantity);
            } else {
                usable = iter->isSharedUser(user);
                if (found) {
                    iter->addProduct(p, quantity);
                }

            } break;
        }
    }
    if (!found) {
        std::cout << userName << " non può aggiungere prodotti alla lista '" << n
        << "' perchè non condivisa con " << user << std::endl;
    }

}

void Utente::removeProductFromListByName(std::string n, std::shared_ptr<Prodotto> &p) {
    bool found = false;
    bool usable = false;
    for (auto iter = listeSpesa.begin(); iter != listeSpesa.end(); ++iter) {
        if (iter->getListName() == n) {
            found = true;
            if (user == iter->getOwner()) {
                iter->removeProduct(p);
            } else {
                usable = iter->isSharedUser(user);
                if (found) {
                    iter->removeProduct(p);
                }

            } break;
        }
    }
    if (!found) {
        std::cout << userName << " non può rimuovere prodotti dalla lista '" << n
                  << "' perchè non condivisa con " << user << std::endl;
    }

}

void Utente::reduceProductFromListByName(std::string n, std::shared_ptr<Prodotto> &p, int quantity) {
    bool found = false;
    bool usable = false;
    for (auto iter = listeSpesa.begin(); iter != listeSpesa.end(); ++iter) {
        if (iter->getListName() == n) {
            found = true;
            if (user == iter->getOwner()) {
                iter->reduceProductQuantity(p, quantity);
            } else {
                usable = iter->isSharedUser(user);
                if (found) {
                    iter->reduceProductQuantity(p, quantity);
                }

            } break;
        }
    }
    if (!found) {
        std::cout << userName << " non può ridurre la quantità di un prodotto dalla lista '" << n
                  << "' perchè non condivisa con " << user << std::endl;
    }

}


void Utente::printOneShoppingList(const ListaDellaSpesa& ls) {
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

void Utente::removeProductFromList(ListaDellaSpesa &ls, std::shared_ptr<Prodotto> &p) {
    ls.removeProduct(p);
}

void Utente::getShoppingLists() const {
    std::cout << "Liste della spesa di " << userName << " " << userSurname << ": " << std::endl;
    for (auto iter: listeSpesa) {
        std::cout << iter.getListName() << std::endl;
    }
}


void Utente::reduceProductQuantity(ListaDellaSpesa &ls, std::shared_ptr<Prodotto> &p, int q) {
    ls.reduceProductQuantity(p, q);
}


void Utente::printAllShoppingLists() const{
    std::cout << "Liste spese " << userName << ":" <<std::endl;
    for (auto iter : listeSpesa) {
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

