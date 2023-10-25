//
// Created by Carlo Verdi on 23/10/23.
//

#include <iostream>
#include "Pulizia.h"

void Pulizia::printProduct() {
    std::cout << "Prodotto: " << productName << " - Quantità: " << productQuantity << " - Prezzo: " << productPrice << "€ - Categoria: " << productCategory << std::endl;
}