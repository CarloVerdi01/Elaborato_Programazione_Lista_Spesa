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
#include "Utente.h"

int main() {
    std::shared_ptr<Prodotto> sapone = std::make_shared<ProdottiDaBagno>("Saponetta");
    std::shared_ptr<Prodotto> coca_cola = std::make_shared<Bevande>("Coca-Cola");
    std::shared_ptr<Prodotto> bistecca = std::make_shared<Macelleria>("Bistecca Fiorentina");
    std::shared_ptr<Prodotto> bistecca1 = std::make_shared<Macelleria>("Bistecca Fiorentina");
    std::shared_ptr<Prodotto> baguette = std::make_shared<Forno>("Baguette");
    std::shared_ptr<Prodotto> baguette1 = std::make_shared<Forno>("Baguette");
    std::shared_ptr<Prodotto> latte = std::make_shared<Bevande>("Latte");
    std::shared_ptr<Prodotto> dentifricio = std::make_shared<ProdottiDaBagno>("Dentifricio");




    sapone->printProduct();
    coca_cola->printProduct();
    bistecca->printProduct();
    baguette->printProduct();
    latte->printProduct();
    std::cout << " " << std::endl;

    ListaDellaSpesa spesa_per_casa("Spesa Per Casa");
    spesa_per_casa.addProduct(sapone, 2);
    spesa_per_casa.addProduct(coca_cola, 5);
    spesa_per_casa.addProduct(bistecca, 1);
    spesa_per_casa.addProduct(baguette, 4);
    spesa_per_casa.addProduct(latte, 3);
    spesa_per_casa.addProduct(dentifricio, 5);
    spesa_per_casa.printList();
    std::cout << " " << std::endl;
    spesa_per_casa.addProduct(bistecca1, 3);
    spesa_per_casa.printList();
    std::cout << " " << std::endl;
    spesa_per_casa.removeProduct(bistecca);
    std::cout << " " << std::endl;
    spesa_per_casa.printList();
/*

    Utente carlo("Carlo", "Verdi");
    Utente paolo("Paolo", "Verdi");
    ListaDellaSpesa spesa_nonna = carlo.creaListaDellaSpesa("Spesa Nonna");
    carlo.addProductToList(spesa_nonna, coca_cola);
    paolo.addProductToList(spesa_nonna, bistecca);
    carlo.removeProductFromList(spesa_nonna, coca_cola);
    carlo.printList(spesa_nonna);

    ListaDellaSpesa spesa_zia = carlo.creaListaDellaSpesa("Spesa Zia");
    carlo.addProductToList(spesa_zia, coca_cola);

    */



}
