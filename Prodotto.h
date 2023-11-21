//
// Created by Carlo Verdi on 23/10/23.
//

#ifndef PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_PRODOTTO_H
#define PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_PRODOTTO_H


#include <string>

class Prodotto {
public:
    Prodotto(std::string name, std::string category, int quantity = 0, bool bought = false) : productName(name), productCategory(category), productQuantity(quantity), productStatus(bought) {};

    Prodotto(const Prodotto& other) : productName(other.productName), productCategory(other.productCategory), productQuantity(other.productQuantity), productStatus(other.productStatus) {}

    ~Prodotto() = default;


    void setCategory(const std::string c)  {
        productCategory = c;
    }

    const std::string& getCategory() const{
        return productCategory;
    }

    void addQuantity(const int q){
        if (q >= 0){
            productQuantity += q;
        } else
            std::cout << "Quantità non accettabile!" << std::endl;
    }

    void removeQuantity(const int q){
        if (q > 0){
            productQuantity -= q;
        } else
            std::cout << "Quantità non accettabile!" << std::endl;
    }

    void printProduct() const;

    bool operator ==(const Prodotto& other) const{
        return (productName == other.productName);
    }

    void setName(const std::string n){
        productName = n;
    }

    const std::string getName() const{
        return productName;
    }

    void setQuantity(const int q){
        if (q >= 0){
            productQuantity = q;
        }
        else
            std::cout << "Quantità non accettabile!" << std::endl;
    }

    int getQuantity() const{
        return productQuantity;
    }

    void setStatus(const bool s){
        productStatus = s;
    }

    const bool getStatus() const{
        return productStatus;
    }





private:
    std::string productName;
    int productQuantity;
    std::string productCategory;
    bool productStatus;

};


#endif //PROVA_ELABORATO_PROGRAMAZIONE_LISTA_SPESA_PRODOTTO_H
