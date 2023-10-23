//
// Created by Carlo Verdi on 23/10/23.
//

#ifndef PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_BEVANDE_H
#define PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_BEVANDE_H


#include "Prodotto.h"

class Bevande : public Prodotto{
public:
    Bevande(std::string name, int quantity, std::string category= "Bevande") : Prodotto(name, quantity), productCategory(category){}
    ~Bevande() = default;

    void printProduct() override;

    void setCategory(std::string c) override{
        productCategory = c;
    }

    std::string getCategory() const override{
        return productCategory;
    }

    void setName(std::string n){
        productName = n;
    }

    std::string getName() const{
        return productName;
    }

    void setQuantity(int q){
        productQuantity = q;
    }

    int getQuantity() const{
        return productQuantity;
    }

private:

    std::string productCategory;
    int prova;

};


#endif //PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_BEVANDE_H
