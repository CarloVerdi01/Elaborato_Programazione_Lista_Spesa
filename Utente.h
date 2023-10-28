//
// Created by Carlo Verdi on 24/10/23.
//

#ifndef PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_UTENTE_H
#define PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_UTENTE_H

#include "Observer.h"
#include "ListaDellaSpesa.h"
#include <string>
#include <list>

class Utente : public Observer{
public:
    Utente(std::string name, std::string surname) : userName(name), userSurname(surname) {
        user = userName + " " + userSurname;
    }

    ~Utente() {};

    ListaDellaSpesa& creaListaDellaSpesa(std::string name, std::string owner);

    //void addProductToList(std::string n, std::shared_ptr<Prodotto>& p);

    void addProductToList(ListaDellaSpesa& ls, std::shared_ptr<Prodotto>& p, int quantity);

    void addProductToListByName(std::string n, std::shared_ptr<Prodotto>& p, int quantity);

    void removeProductFromListByName(std::string n, std::shared_ptr<Prodotto>& p);

    void reduceProductFromListByName(std::string n, std::shared_ptr<Prodotto>& p, int quantity);

    void addNewList(ListaDellaSpesa& ls);

    void printOneShoppingList(const ListaDellaSpesa& ls);

    void removeProductFromList(ListaDellaSpesa& ls, std::shared_ptr<Prodotto> &p);

    void reduceProductQuantity(ListaDellaSpesa& ls, std::shared_ptr<Prodotto> &p, int q);

    void getShoppingLists() const;

    void printAllShoppingLists() const;

    void updateAdd(std::string ls, std::shared_ptr<Prodotto> p, int q) override{
        addProductToListByName(ls, p, q );
    }

    void updateRemove(std::string ls, std::shared_ptr<Prodotto> p) override{
        removeProductFromListByName(ls, p);
    }

    void updateDecrement(std::string ls, std::shared_ptr<Prodotto> p, int q) override{
        reduceProductFromListByName(ls, p, q);
    }


    void shareList(ListaDellaSpesa& ls, Utente& u );

    void printListOwner(ListaDellaSpesa& ls){
        ls.printListOwner();
    }

    void printListSharedUsers(ListaDellaSpesa& ls){
        ls.printListSharedUsers();
    }

    std::string getListOwner(const ListaDellaSpesa& ls) const{
        return ls.getOwner();
    }

    std::list<std::string> getListSharedUsers(const ListaDellaSpesa& ls) const{
        return ls.getSharedUsers();
    }


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

    std::string getUser() const{
        return user;
    }

    void setUser(std::string n, std::string s){
        userName = n;
        userSurname = n;
    }




private:
    std::string user;
    std::string userName;
    std::string userSurname;
    std::list<ListaDellaSpesa> listeSpesa;


};


#endif //PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_UTENTE_H
