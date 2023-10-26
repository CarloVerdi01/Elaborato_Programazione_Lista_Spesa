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

/*void Utente::addProductToList(std::string n, std::shared_ptr<Prodotto> &p) {
    for (auto iter : listeSpesa){
        if (iter.getListName() == n){
            iter.addProduct(p);
        }
    }
}
*/

void Utente::addProductToList(ListaDellaSpesa& ls, std::shared_ptr<Prodotto> &p, int quantity) {
    bool found = false;
    /*for (auto iter : listeSpesa){
        if (iter.getListName() == ls.getListName()){
            ls.addProduct(p, quantity);
            found = true;
            break;
        }
    }
     */
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
    ls.shareList(u.user);
    ListaDellaSpesa copiaLista = ls;
    u.addNewList(copiaLista);
}

void Utente::addNewList(ListaDellaSpesa &ls) {
    listeSpesa.push_back(ls);
}