//
// Created by Carlo Verdi on 24/10/23.
//

#ifndef PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_UTENTE_H
#define PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_UTENTE_H

#include "ListaDellaSpesa.h"
#include <string>
#include <list>

class Utente {
public:
    Utente(std::string name, std::string surname) : userName(name), userSurname(surname) {}

    ~Utente() {};

    ListaDellaSpesa& creaListaDellaSpesa(std::string name);

    //void addProductToList(std::string n, std::shared_ptr<Prodotto>& p);

    void addProductToList(ListaDellaSpesa& ls, std::shared_ptr<Prodotto>& p, int quantity);

    void printOneShoppingList(const ListaDellaSpesa& ls);

    void removeProductFromList(ListaDellaSpesa& ls, std::shared_ptr<Prodotto> &p);

    void addNewList(const ListaDellaSpesa& ls);

    void reduceProductQuantity(ListaDellaSpesa& ls, std::shared_ptr<Prodotto> &p, int q);

    void getShoppingLists() const;

    void printAllShoppingLists() const;

    void shareList(Utente& u, const ListaDellaSpesa& ls);


    void setName(std::string n){
        userName = n;
    }

    std::string getName() const{
        return userName;
    }

    void setSurname(std::string s){
        userSurname = s;
    }

    std::string getSurname() const{
        return userSurname;
    }

private:
    std::string userName;
    std::string userSurname;
    std::list<ListaDellaSpesa> listeSpesa;


};


#endif //PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_UTENTE_H
