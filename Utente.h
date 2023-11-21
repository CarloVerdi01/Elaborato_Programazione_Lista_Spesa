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

    void addProductToList(ListaDellaSpesa& ls, Prodotto& p, int quantity = 1);

    void addProductToListByName(std::string n, Prodotto& p, int quantity);

    void removeProductFromListByName(std::string n, std::string prodcut);

    void reduceProductFromListByName(std::string n, std::string product, int quantity);

    void addNewList(ListaDellaSpesa& ls);

    void printOneShoppingList(const ListaDellaSpesa& ls) const;

    void removeProductFromList(ListaDellaSpesa& ls, std::string product);

    void reduceProductQuantity(ListaDellaSpesa& ls, std::string product, int q);

    void getShoppingLists() const;

    void setProductBought(ListaDellaSpesa& ls, std::string product);

    void setProductBoughtByName(const std::string ls, std::string product);

    void setProductNotBought(ListaDellaSpesa& ls, std::string product);

    void setProductNotBoughtByName(const std::string ls, std::string product);


    void printAllShoppingLists() const;

    bool findList(const std::string n) const;

    bool findProductInList(const ListaDellaSpesa& ls, std::string product);

    bool findProductInListByName(const std::string n, std::string product);

    int getProductQuantityInList(const std::string list, std::string product);

    void printAllShoopingListsName() const;

    bool isProductBought(std::string ls, std::string product) const;


    void update(Operazione operazione, std::string ls, Prodotto& p, std::string product, int quantity, bool state) override{
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



    /*

    void updateAdd(std::string ls, Prodotto& p, int q) override{
        addProductToListByName(ls, p, q );
    }

    void updateRemove(std::string ls, std::string p) override{
        removeProductFromListByName(ls, p);
    }

    void updateDecrement(std::string ls, std::string p, int q) override{
        reduceProductFromListByName(ls, p, q);
    }

     */



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
