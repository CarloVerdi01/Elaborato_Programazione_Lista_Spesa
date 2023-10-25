//
// Created by Carlo Verdi on 23/10/23.
//

#ifndef PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_PRODOTTO_H
#define PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_PRODOTTO_H


#include <string>

class Prodotto {
public:
    Prodotto(std::string name, float price, int quantity) : productName(name), productPrice(price), productQuantity(quantity) {};

    Prodotto(const Prodotto& other) : productName(other.productName), productPrice(other.productPrice), productQuantity(other.productQuantity) {}

    virtual ~Prodotto() = default;

    virtual void printProduct() = 0;

    virtual void setCategory(std::string c) = 0;

    virtual std::string getCategory() const = 0;

    virtual void addQuantity(int q) = 0;

    virtual void removeQuantity(int q) = 0;

    bool operator ==(const Prodotto& other) const{
        return (productName == other.productName);
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


protected:
    std::string productName;
    int productQuantity;
    float productPrice;
};


#endif //PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_PRODOTTO_H
