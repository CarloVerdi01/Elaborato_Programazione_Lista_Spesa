//
// Created by Carlo Verdi on 23/10/23.
//

#include <iostream>
#include "Abbigliamento.h"

void Abbigliamento::printProduct() {
    std::cout << "Prodotto: " << productName << " - Quantità: " << productQuantity << " - Categoria: " << productCategory << std::endl;
}
