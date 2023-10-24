//
// Created by Carlo Verdi on 24/10/23.
//

#include "Utente.h"

ListaDellaSpesa Utente::creaListaDellaSpesa(std::string name) {
    ListaDellaSpesa nuovaLista(name);
    listeSpesa.push_back(nuovaLista);
    return nuovaLista;
}

/*void Utente::addProductToList(std::string n, std::shared_ptr<Prodotto> &p) {
    for (auto iter : listeSpesa){
        if (iter.getListName() == n){
            iter.addProduct(p);
        }
    }
}
*/

void Utente::addProductToList(ListaDellaSpesa &ls, std::shared_ptr<Prodotto> &p, int quantity) {
    ls.addProduct(p, quantity);
}

void Utente::printList(const ListaDellaSpesa &ls) {
    ls.printList();
}

void Utente::removeProductFromList(ListaDellaSpesa &ls, std::shared_ptr<Prodotto> &p) {
    ls.removeProduct(p);
}

void Utente::getShoopingLists() const {
    for (auto iter : listeSpesa){
        iter.printList();
    }
}
