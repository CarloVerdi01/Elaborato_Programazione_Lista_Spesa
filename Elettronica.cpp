//
// Created by Carlo Verdi on 23/10/23.
//

#include <iostream>
#include "Elettronica.h"

void Elettronica::printProduct() {
    std::cout << "Prodotto: " << productName << " - Quantità: " << productQuantity << " - Prezzo: " << productPrice << "€ - Categoria: " << productCategory << std::endl;
}
