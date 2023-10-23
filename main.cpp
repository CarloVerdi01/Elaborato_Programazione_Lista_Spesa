#include <iostream>
#include <memory>
#include "Prodotto.h"
#include "ProdottiDaBagno.h"
#include "Bevande.h"
#include "Macelleria.h"
#include "Forno.h"
#include "Abbigliamento.h"
#include "Altro.h"
#include "Elettronica.h"
#include "FruttaEVerdura.h"
#include "Igiene.h"
#include "ListaDellaSpesa.h"
#include "Pescheria.h"
#include "Pulizia.h"

int main() {
    std::shared_ptr<Prodotto> sapone = std::make_shared<ProdottiDaBagno>("Saponetta", 2);
    std::shared_ptr<Prodotto> coca_cola = std::make_shared<Bevande>("Coca-Cola", 1);
    std::shared_ptr<Prodotto> bistecca = std::make_shared<Macelleria>("Bistecca Fiorentina", 1);
    std::shared_ptr<Prodotto> baguette = std::make_shared<Forno>("Baguette", 5);


    sapone->printProduct();
    coca_cola->printProduct();
    bistecca->printProduct();
    baguette->printProduct();

    ListaDellaSpesa spesa_per_casa("Spesa Per Casa");
    spesa_per_casa.addProduct(sapone);
    spesa_per_casa.addProduct(coca_cola);
    spesa_per_casa.addProduct(bistecca);
    spesa_per_casa.addProduct(baguette);
    spesa_per_casa.printList();

}
