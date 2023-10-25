//
// Created by Carlo Verdi on 23/10/23.
//

#include <iostream>
#include "ProdottiDaBagno.h"

void ProdottiDaBagno::printProduct() {
    std::cout << "Prodotto: " << productName << " - Quantità: " << productQuantity << " - Prezzo: " << productPrice << "€ - Categoria: " << productCategory << std::endl;
}