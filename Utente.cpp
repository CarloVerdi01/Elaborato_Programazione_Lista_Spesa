//
// Created by Carlo Verdi on 24/10/23.
//

#include <iostream>
#include "Utente.h"

ListaDellaSpesa& Utente::creaListaDellaSpesa(std::string name) {
    ListaDellaSpesa nuovaLista(name);
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
    ls.addProduct(p, quantity);
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

void Utente::addNewList(const ListaDellaSpesa &ls) {
    listeSpesa.push_back(ls);
}

void Utente::reduceProductQuantity(ListaDellaSpesa &ls, std::shared_ptr<Prodotto> &p, int q) {
    ls.reduceProductQuantity(p, q);
}

void Utente::shareList(Utente &u, const ListaDellaSpesa& ls) {
    u.addNewList(ls);
}

void Utente::printAllShoppingLists() const{
    for (auto iter : listeSpesa) {
        iter.printList();
        std::cout << " " << std::endl;
    }
}