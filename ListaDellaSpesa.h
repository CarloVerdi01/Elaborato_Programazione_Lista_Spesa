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
        listaDellaSpesa.clear();
    }

    ListaDellaSpesa(const ListaDellaSpesa &other) : listName(other.listName), userOwner(other.userOwner) {
        for (auto iter  : other.listaDellaSpesa) {
            addProduct(iter.second, iter.second.getQuantity());
        }
    }


    void addProduct(Prodotto& p, int quantity );

    void removeProduct(std::string product);

    void reduceProductQuantity(std::string product, int q);

    const std::list<std::string> findProductOfCategory(std::string category) const;

    const int getNumberOfProduct() const;

    const int getNumberOfProductToBuy() const;

    const int getNumberOfPurchasedProduct() const;

    void printList() const;

    void shareList(Observer* o, std::string user);

    void setProductBought(std::string product);

    void setProductNotBought(std::string product);

    int getProductQuantity(std::string p);

    const bool isSharedUser(std::string u) const;


    void notify(Operazione operazioni, std::string ls, Prodotto& p, std::string product, int q , bool state) override{
        for (auto iter = observers.begin(); iter != observers.end(); ++iter){
            (*iter)->update(operazioni, ls, p, product, q , state);
        }
    }

    void registerObserver(Observer* o) override{
        observers.push_back(o);
    }

    void removeObserver(Observer* o) override{
        observers.remove(o);
    }

    void printListOwner() const{
        std::cout << "Creatore lista " << listName << ": " << userOwner << std::endl;
    }

    void printListSharedUsers() const;

    const std::list<std::string>& getSharedUsers() const{
        return utentiCondivisi;
    }


    void setOwner(std::string o) {
        userOwner = o;
    }

    const std::string& getOwner() const{
        return userOwner;
    }

    const std::string& getListName() const{
        return listName;
    }

    void setListName(const std::string& n) {
        listName = n;
    }

    bool findProduct(std::string product) const;

    bool getProductStatus(std::string product) const;



private:
    std::multimap<std::string, Prodotto> listaDellaSpesa;
    std::string listName;
    std::string userOwner;
    std::list<std::string> utentiCondivisi;
    std::list<Observer*> observers;



};


#endif //PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_LISTADELLASPESA_H
