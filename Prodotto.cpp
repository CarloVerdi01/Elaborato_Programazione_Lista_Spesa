//
// Created by Carlo Verdi on 23/10/23.
//
#include <iostream>
#include "Prodotto.h"

void Prodotto::printProduct() const {
    std::cout << "Prodotto: " << productName << " - Quantità: " << productQuantity  << " - Categoria: " << productCategory << " - Acuistato: " << productStatus << std::endl;
}
