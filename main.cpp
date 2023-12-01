#include <iostream>
#include <memory>
#include "Prodotto.h"
#include "Utente.h"
#include "ListaDellaSpesa.h"



int main() {
    Prodotto matita("Lapis", "Prodotti Disegno");
    Prodotto baguette("Baguette", "Forno");
    Prodotto spazzolino("Spazzolino", "Igiene");
    Prodotto bistecca("Bistecca", "Macelleria");
    Prodotto uva("Uva", "Frutta e Verdura");

    Utente carlo("Carlo", "Verdi");
    Utente paolo("Paolo", "Verdi");
    Utente cecilia("Cecilia", "Verdi");

    ListaDellaSpesa& spesa_nonna = carlo.creaListaDellaSpesa("Spesa Nonna", carlo.getUser());
    ListaDellaSpesa& spesa_casa = paolo.creaListaDellaSpesa("Spesa Casa", paolo.getUser());
    ListaDellaSpesa& spesa_gita = cecilia.creaListaDellaSpesa("Spesa Gita", cecilia.getUser());

    carlo.shareList(spesa_nonna, paolo);
    carlo.shareList(spesa_nonna, cecilia);

    carlo.addProductToList(spesa_nonna, baguette, 3);
    paolo.addProductToList(spesa_nonna, spazzolino);
    cecilia.addProductToList(spesa_nonna, uva, 2);
    carlo.removeProductFromList(spesa_nonna, "Uva");
    paolo.reduceProductQuantity(spesa_nonna, "Baguette", 1);
    cecilia.reduceProductQuantity(spesa_nonna, "Spazzolino", 3);
    carlo.setProductBought(spesa_nonna, "Baguette");
    paolo.addProductToList(spesa_nonna, matita, 6);
    cecilia.reduceProductQuantity(spesa_nonna, "Lapis", 3);
    carlo.removeProductFromList(spesa_nonna, "Baguette");
    paolo.setProductBought(spesa_nonna, "Lapis");

    paolo.shareList(spesa_casa, carlo);
    paolo.shareList(spesa_casa, cecilia);

    cecilia.shareList(spesa_gita, carlo);
    cecilia.shareList(spesa_gita, paolo);

    carlo.addProductToList(spesa_casa, baguette);
    paolo.addProductToList(spesa_casa, matita);
    cecilia.addProductToList(spesa_casa, bistecca, 3);
    carlo.reduceProductQuantity(spesa_casa, "Bistecca", 1);
    paolo.removeProductFromList(spesa_casa, "Lapis");


    paolo.addProductToList(spesa_gita, spazzolino, 3);
    carlo.addProductToList(spesa_gita, baguette);
    cecilia.addProductToList(spesa_gita, baguette);


    carlo.setProductBought(spesa_gita, "Baguette");

    carlo.printAllShoppingLists();
    paolo.printAllShoppingLists();
    cecilia.printAllShoppingLists();

    carlo.reduceProductQuantity(spesa_nonna, "Lapis", -3);





















}