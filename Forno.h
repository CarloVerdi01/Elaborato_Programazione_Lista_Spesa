//
// Created by Carlo Verdi on 23/10/23.
//

#ifndef PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_FORNO_H
#define PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_FORNO_H


#include "Prodotto.h"

class Forno : public Prodotto{
public:
    Forno(std::string name, int quantity, std::string category="Forno") : Prodotto(name, quantity), productCategory(category) {};
    ~Forno() = default;
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




};


#endif //PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_FORNO_H
