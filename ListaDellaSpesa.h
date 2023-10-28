//
// Created by Carlo Verdi on 23/10/23.
//

#ifndef PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_LISTADELLASPESA_H
#define PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_LISTADELLASPESA_H


#include <map>
#include <list>
#include "Prodotto.h"
#include "Subject.h"
#include "Observer.h"


class ListaDellaSpesa : public Subject{
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

    void shareList(Observer* o, std::string user);

    void notifyAdd(std::string ls, std::shared_ptr<Prodotto> p, int q) override{
        for (auto iter = observers.begin(); iter != observers.end(); ++iter) {
            (*iter)->updateAdd(ls, p, q);
        }
    }

    void notifyRemove(std::string ls, std::shared_ptr<Prodotto> p) override{
        for (auto iter = observers.begin(); iter != observers.end(); ++iter) {
            (*iter)->updateRemove(ls, p);
        }
    }

    void notifyDecrement(std::string ls, std::shared_ptr<Prodotto> p, int q) override{
        for (auto iter = observers.begin(); iter != observers.end(); ++iter) {
            (*iter)->updateDecrement(ls, p, q);
        }
    }

    void registerObserver(Observer* o) override{
        observers.push_back(o);
    }

    void removeObserver(Observer* o) override{
        observers.remove(o);
    }

    void printListOwner(){
        std::cout << "Creatore lista " << listName << ": " << userOwner << std::endl;
    }

    void printListSharedUsers();

    std::list<std::string> getSharedUsers() const{
        return utentiCondivisi;
    }

    bool isSharedUser(std::string u);

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
    std::list<Observer*> observers;

};


#endif //PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_LISTADELLASPESA_H
