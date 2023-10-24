//
// Created by Carlo Verdi on 23/10/23.
//

#ifndef PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_PRODOTTIDABAGNO_H
#define PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_PRODOTTIDABAGNO_H


#include "Prodotto.h"

class ProdottiDaBagno : public Prodotto{
public:
    ProdottiDaBagno(std::string name, int quantity = 0, std::string category="Prodotti da Bagno") : Prodotto(name, quantity), productCategory(category){}
    ~ProdottiDaBagno() = default;

    void addQuantity(int q) override{
        productQuantity += q;
    }

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


#endif //PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_PRODOTTIDABAGNO_H
