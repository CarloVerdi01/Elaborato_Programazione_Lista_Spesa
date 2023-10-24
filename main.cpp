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
    std::shared_ptr<Prodotto> bistecca1 = std::make_shared<Macelleria>("Bistecca Fiorentina", 1);
    std::shared_ptr<Prodotto> baguette = std::make_shared<Forno>("Baguette", 5);
    std::shared_ptr<Prodotto> baguette1 = std::make_shared<Forno>("Baguette", 5);
    std::shared_ptr<Prodotto> latte = std::make_shared<Bevande>("Latte", 3);
    std::shared_ptr<Prodotto> dentifricio = std::make_shared<ProdottiDaBagno>("Dentifricio", 2);




    sapone->printProduct();
    coca_cola->printProduct();
    bistecca->printProduct();
    baguette->printProduct();
    latte->printProduct();
    std::cout << " " << std::endl;

    ListaDellaSpesa spesa_per_casa("Spesa Per Casa");
    spesa_per_casa.addProduct(sapone);
    spesa_per_casa.addProduct(coca_cola);
    spesa_per_casa.addProduct(bistecca);
    spesa_per_casa.addProduct(baguette);
    spesa_per_casa.addProduct(latte);
    spesa_per_casa.addProduct(dentifricio);
    spesa_per_casa.printList();
    std::cout << " " << std::endl;
    spesa_per_casa.addProduct(bistecca1);
    spesa_per_casa.printList();
    std::cout << " " << std::endl;
    spesa_per_casa.removeProduct(bistecca);
    std::cout << " " << std::endl;
    spesa_per_casa.printList();

    bool found = spesa_per_casa.findProduct(coca_cola);
    if (found)
        std::cout << "Trovato" << std::endl;
    else
        std::cout << "Non Trovato" << std::endl;


}
