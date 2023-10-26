//
// Created by Carlo Verdi on 23/10/23.
//

#ifndef PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_LISTADELLASPESA_H
#define PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_LISTADELLASPESA_H


#include <map>
#include <list>
#include "Prodotto.h"



class ListaDellaSpesa {
public:
    ListaDellaSpesa(std::string name, std::string owner) : listName(name), userOwner(owner){}

    ~ListaDellaSpesa(){
        lista_della_spesa.clear();
    }

    ListaDellaSpesa(const ListaDellaSpesa &other) : listName(other.listName), userOwner(other.userOwner) {
        for (auto iter  : other.lista_della_spesa) {
            addProduct(iter.second, iter.second->getQuantity());
        }
    }


    void addProduct(std::shared_ptr<Prodotto>& p, int quantity);

    void removeProduct(std::shared_ptr<Prodotto>& p);

    void reduceProductQuantity(std::shared_ptr<Prodotto>& p, int q);

    bool findProduct(std::shared_ptr<Prodotto>& p) const;

    void printList() const;

    void shareList(std::string user);

    void printListOwner(){
        std::cout << "Creatore lista " << listName << ": " << userOwner << std::endl;
    }

    void printListSharedUsers() {
        printListOwner();
        std::cout << "Lista " << listName << " condivisa con: " << std::endl;
        for (auto iter : utentiCondivisi){
            std::cout << iter << std::endl;
        }
    }

    std::list<std::string> getSharedUsers() const{
        return utentiCondivisi;
    }

    bool isSharedUser(std::string u){
        for (auto iter: utentiCondivisi){
            if ( iter == u)
                return true;
        }
        return false;
    }

    void setOwner(std::string o) {
        userOwner = o;
    }

    std::string getOwner() const{
        return userOwner;
    }



    std::string getListName() const{
        return listName;
    }

    void setListName(std::string n) {
        listName = n;
    }


private:
    std::multimap<std::string, std::shared_ptr<Prodotto>> lista_della_spesa;
    std::string listName;
    std::string userOwner;
    std::list<std::string> utentiCondivisi;

};


#endif //PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_LISTADELLASPESA_H
