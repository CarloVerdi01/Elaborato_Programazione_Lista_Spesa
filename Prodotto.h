//
// Created by Carlo Verdi on 23/10/23.
//

#ifndef PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_PRODOTTO_H
#define PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_PRODOTTO_H


#include <string>

class Prodotto {
public:
    explicit Prodotto(std::string name, int quantity) : productName(name), productQuantity(quantity) {};
    virtual ~Prodotto() = default;

    virtual void printProduct() = 0;
    virtual void setCategory(std::string c) = 0;
    virtual std::string getCategory() const = 0;

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


protected:
    std::string productName;
    int productQuantity;

};


#endif //PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_PRODOTTO_H
