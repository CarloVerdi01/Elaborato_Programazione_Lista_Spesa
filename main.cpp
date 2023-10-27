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
    std::shared_ptr<Prodotto> sapone = std::make_shared<ProdottiDaBagno>("Saponetta", 2.00);
    std::shared_ptr<Prodotto> coca_cola = std::make_shared<Bevande>("Coca-Cola", 1.60);
    std::shared_ptr<Prodotto> bistecca = std::make_shared<Macelleria>("Bistecca Fiorentina", 20.00);
    std::shared_ptr<Prodotto> baguette = std::make_shared<Forno>("Baguette", 1.20);
    std::shared_ptr<Prodotto> latte = std::make_shared<Bevande>("Latte", 1.25);
    std::shared_ptr<Prodotto> dentifricio = std::make_shared<ProdottiDaBagno>("Dentifricio", 2.50);
    std::shared_ptr<Prodotto> televisore = std::make_shared<Elettronica>("Telelvisore", 249.99);



    /*
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
    spesa_per_casa.addProduct(bistecca, 3);
    spesa_per_casa.printList();
    std::cout << " " << std::endl;
    spesa_per_casa.removeProduct(bistecca);
    std::cout << " " << std::endl;
    spesa_per_casa.printList();
    std::cout << " " << std::endl;
     */




    Utente carlo("Carlo", "Verdi");
    //std::cout << carlo.getUser() << std::endl;
    Utente paolo("Paolo", "Verdi");

    ListaDellaSpesa& spesa_nonna = carlo.creaListaDellaSpesa("Spesa Nonna", carlo.getUser());
    carlo.addProductToList(spesa_nonna, coca_cola, 2);
    carlo.addProductToList(spesa_nonna, bistecca, 1);
    carlo.addProductToList(spesa_nonna, sapone, 5);
    carlo.reduceProductQuantity(spesa_nonna, coca_cola, 1);
    carlo.removeProductFromList(spesa_nonna, bistecca);
    carlo.addProductToList(spesa_nonna, televisore, 1);
    //carlo.printAllShoppingLists();
    std::cout << " " << std::endl;
    //carlo.printListOwner(spesa_nonna);
    std::cout << " " << std::endl;
    //carlo.printListSharedUsers(spesa_nonna);

    carlo.shareList(spesa_nonna, paolo);




    //carlo.printListSharedUsers(spesa_nonna);


    paolo.printAllShoppingLists();


    carlo.printAllShoppingLists();


    carlo.addProductToList(spesa_nonna, bistecca, 3);
    paolo.addProductToList(spesa_nonna, dentifricio, 1);

    carlo.addProductToList(spesa_nonna, latte, 10);

    paolo.addProductToList(spesa_nonna, latte, 2);



    //carlo.printListSharedUsers(spesa_nonna);



    carlo.printAllShoppingLists();

    paolo.printAllShoppingLists();







}