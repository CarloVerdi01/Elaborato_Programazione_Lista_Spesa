//
// Created by Carlo Verdi on 23/10/23.
//

#ifndef PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_ALTRO_H
#define PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_ALTRO_H


#include "Prodotto.h"

class Altro : public Prodotto{
public:
    Altro(std::string name, int quantity, std::string category="Altro") : Prodotto(name, quantity), productCategory(category){}
    ~Altro()=default;
    void printProduct() override;

    void addQuantity(int q) override{
        productQuantity += q;
    }

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


#endif //PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_ALTRO_H
