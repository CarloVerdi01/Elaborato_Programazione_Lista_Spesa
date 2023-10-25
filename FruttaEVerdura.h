//
// Created by Carlo Verdi on 23/10/23.
//

#ifndef PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_FRUTTAEVERDURA_H
#define PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_FRUTTAEVERDURA_H


#include "Prodotto.h"

class FruttaEVerdura : public Prodotto{
public:
    FruttaEVerdura(std::string name, float price, int quantity = 0, std::string category="Frutta e Verdura") : Prodotto(name, price, quantity), productCategory(category){}
    ~FruttaEVerdura() = default;
    void printProduct() override;

    void addQuantity(int q) override{
        productQuantity += q;
    }

    void removeQuantity(int q) override{
        productQuantity -= q;
    };

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

    void setPrice(float p){
        productPrice = p;
    }

    float getPrice() const{
        return productPrice;
    }

private:
    std::string productCategory;

};


#endif //PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_FRUTTAEVERDURA_H
