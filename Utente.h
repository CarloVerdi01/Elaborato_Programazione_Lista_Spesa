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
    Utente(const std::string& name, const std::string& surname) : userName(name), userSurname(surname) {
        user = userName + " " + userSurname;
    }

    ~Utente() {};

    ListaDellaSpesa& creaListaDellaSpesa(const std::string& name, const std::string& owner);

    void addProductToList(ListaDellaSpesa& ls, Prodotto& p, int quantity = 1);

    void addProductToListByName(const std::string& n, Prodotto& p, int quantity);

    void removeProductFromListByName(const std::string& n, const std::string& prodcut);

    void reduceProductFromListByName(const std::string& n, const std::string& product, int quantity);

    void addNewList(ListaDellaSpesa& ls);

    void printOneShoppingList(const ListaDellaSpesa& ls) const;

    void removeProductFromList(ListaDellaSpesa& ls, const std::string& product);

    void reduceProductQuantity(ListaDellaSpesa& ls, const std::string& product, int q);

    void getShoppingLists() const;

    void setProductBought(ListaDellaSpesa& ls, const std::string& product);

    void setProductBoughtByName(const std::string& ls, const std::string& product);

    void setProductNotBought(ListaDellaSpesa& ls, const std::string& product);

    void setProductNotBoughtByName(const std::string& ls, const std::string& product);

    void printAllShoppingLists() const;

    bool findList(const std::string& n) const;

    bool findProductInList(const ListaDellaSpesa& ls, const std::string& product);

    bool findProductInListByName(const std::string& n, const std::string& product);

    int getProductQuantityInList(const std::string& list, const std::string& product);

    void printAllShoopingListsName() const;

    const bool& isProductBought(const std::string& ls, const std::string& product) const;


    void update(Operazione operazione, std::string ls, Prodotto& p, const std::string& product, int quantity, bool state) override{
        switch(operazione) {
            case (Operazione::Aggiunta) :
                addProductToListByName(ls, p, quantity);
                break;
            case (Operazione::Rimozione) :
                removeProductFromListByName(ls, product);
                break;
            case (Operazione::Decremento) :
                reduceProductFromListByName(ls, product, quantity);
                break;
            case (Operazione::ModificaStato) :
                if (state)
                    setProductBoughtByName(ls, product);
                else
                    setProductNotBoughtByName(ls, product);
            }

    }


    void shareList(ListaDellaSpesa& ls, Utente& u );

    void printListOwner(ListaDellaSpesa& ls){
        ls.printListOwner();
    }

    void printListSharedUsers(ListaDellaSpesa& ls){
        ls.printListSharedUsers();
    }

    const std::string& getListOwner(const ListaDellaSpesa& ls) const{
        return ls.getOwner();
    }

    const std::list<std::string>& getListSharedUsers(const ListaDellaSpesa& ls) const{
        return ls.getSharedUsers();
    }


    void setName(std::string n){
        userName = n;
    }

    const std::string& getName() const{
        return userName;
    }

    void setSurname(std::string s){
        userSurname = s;
    }

    const std::string& getSurname() const{
        return userSurname;
    }

    const std::string& getUser() const{
        return user;
    }

    void setUser(std::string& n, std::string& s){
        userName = n;
        userSurname = s;
    }




private:
    std::string user;
    std::string userName;
    std::string userSurname;
    std::list<ListaDellaSpesa> listeSpesa;


};


#endif //PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_UTENTE_H
