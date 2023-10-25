//
// Created by Carlo Verdi on 23/10/23.
//

#include <iostream>
#include "Macelleria.h"

void Macelleria::printProduct() {
    std::cout << "Prodotto: " << productName << " - Quantità: " << productQuantity << " - Prezzo: " << productPrice << "€ - Categoria: " << productCategory << std::endl;
}