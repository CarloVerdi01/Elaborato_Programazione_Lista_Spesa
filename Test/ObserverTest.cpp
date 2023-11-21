//
// Created by Carlo Verdi on 31/10/23.
//
#include "gtest/gtest.h"
#include "../Utente.h"


class ObserverSuite : public ::testing::Test {
protected:

    Utente carlo = Utente("Carlo", "Verdi");
    Utente paolo = Utente("Paolo", "Verdi");
    Utente cecilia = Utente("Cecilia", "Verdi");
    ListaDellaSpesa &spesa_carlo = carlo.creaListaDellaSpesa("Spesa Carlo", carlo.getUser());
    ListaDellaSpesa &spesa_paolo = paolo.creaListaDellaSpesa("Spesa Paolo", paolo.getUser());
    Prodotto sapone = Prodotto("Saponetta", "Igiene");
    Prodotto coca_cola = Prodotto("Coca Cola", "Bevande");
    Prodotto baguette = Prodotto("Baguette", "Forno");
};




TEST_F(ObserverSuite, ShareListTest){
    carlo.shareList(spesa_carlo, paolo);
    ASSERT_TRUE(carlo.findList(spesa_carlo.getListName()));
    ASSERT_TRUE(paolo.findList(spesa_carlo.getListName()));
    ASSERT_FALSE(cecilia.findList(spesa_carlo.getListName()));
    paolo.shareList(spesa_paolo, cecilia);
    ASSERT_TRUE(paolo.findList(spesa_paolo.getListName()));
    ASSERT_TRUE(cecilia.findList(spesa_paolo.getListName()));
    ASSERT_FALSE(carlo.findList(spesa_paolo.getListName()));
}

TEST_F(ObserverSuite, AddProductToSharedList){
    carlo.addProductToList(spesa_carlo, sapone, 3);
    carlo.shareList(spesa_carlo, paolo);
    paolo.addProductToList(spesa_carlo, baguette, 4);
    ASSERT_TRUE(carlo.findProductInListByName(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_TRUE(paolo.findProductInListByName(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_FALSE(cecilia.findProductInListByName(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_EQ(3, spesa_carlo.getProductQuantity("Saponetta"));
    ASSERT_EQ(4, spesa_carlo.getProductQuantity("Baguette"));
    ASSERT_TRUE(carlo.findProductInListByName(spesa_carlo.getListName(), "Baguette"));
    ASSERT_TRUE(paolo.findProductInListByName(spesa_carlo.getListName(), "Baguette"));
    ASSERT_FALSE(cecilia.findProductInListByName(spesa_carlo.getListName(), "Baguette"));
    paolo.shareList(spesa_paolo, cecilia);
    paolo.addProductToList(spesa_paolo, coca_cola, 5);
    cecilia.addProductToList(spesa_paolo, baguette, 2);
    ASSERT_TRUE(cecilia.findProductInListByName(spesa_paolo.getListName(), "Coca Cola"));
    ASSERT_TRUE(paolo.findProductInListByName(spesa_paolo.getListName(), "Coca Cola"));
    ASSERT_FALSE(carlo.findProductInListByName(spesa_paolo.getListName(), "Coca Cola"));
    ASSERT_EQ(5, spesa_paolo.getProductQuantity("Coca Cola"));
    ASSERT_EQ(2, spesa_paolo.getProductQuantity("Baguette"));
    ASSERT_TRUE(cecilia.findProductInListByName(spesa_paolo.getListName(), "Baguette"));
    ASSERT_TRUE(paolo.findProductInListByName(spesa_paolo.getListName(), "Baguette"));
    ASSERT_FALSE(carlo.findProductInListByName(spesa_paolo.getListName(), "Baguette"));
}

TEST_F(ObserverSuite, RemoveProductFromSharedList) {
    carlo.addProductToList(spesa_carlo, sapone, 3);
    carlo.addProductToList(spesa_carlo, baguette, 3);
    carlo.addProductToList(spesa_carlo, coca_cola, 3);
    carlo.shareList(spesa_carlo, paolo);
    carlo.shareList(spesa_carlo, cecilia);
    ASSERT_TRUE(carlo.findProductInListByName(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_TRUE(carlo.findProductInListByName(spesa_carlo.getListName(), "Baguette"));
    ASSERT_TRUE(carlo.findProductInListByName(spesa_carlo.getListName(), "Coca Cola"));
    ASSERT_TRUE(paolo.findProductInListByName(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_TRUE(paolo.findProductInListByName(spesa_carlo.getListName(), "Baguette"));
    ASSERT_TRUE(paolo.findProductInListByName(spesa_carlo.getListName(), "Coca Cola"));
    ASSERT_TRUE(cecilia.findProductInListByName(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_TRUE(cecilia.findProductInListByName(spesa_carlo.getListName(), "Baguette"));
    ASSERT_TRUE(cecilia.findProductInListByName(spesa_carlo.getListName(), "Coca Cola"));
    cecilia.removeProductFromList(spesa_carlo, "Saponetta");
    paolo.removeProductFromList(spesa_carlo, "Coca Cola");
    carlo.removeProductFromList(spesa_carlo, "Baguette");
    ASSERT_FALSE(carlo.findProductInListByName(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_FALSE(carlo.findProductInListByName(spesa_carlo.getListName(), "Baguette"));
    ASSERT_FALSE(carlo.findProductInListByName(spesa_carlo.getListName(), "Coca Cola"));
    ASSERT_FALSE(paolo.findProductInListByName(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_FALSE(paolo.findProductInListByName(spesa_carlo.getListName(), "Baguette"));
    ASSERT_FALSE(paolo.findProductInListByName(spesa_carlo.getListName(), "Coca Cola"));
    ASSERT_FALSE(cecilia.findProductInListByName(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_FALSE(cecilia.findProductInListByName(spesa_carlo.getListName(), "Baguette"));
    ASSERT_FALSE(cecilia.findProductInListByName(spesa_carlo.getListName(), "Coca Cola"));
}

TEST_F(ObserverSuite, ReduceProductQuantityFromSharedList) {
    carlo.addProductToList(spesa_carlo, sapone, 3);
    carlo.addProductToList(spesa_carlo, baguette, 3);
    carlo.addProductToList(spesa_carlo, coca_cola, 3);
    carlo.shareList(spesa_carlo, paolo);
    carlo.shareList(spesa_carlo, cecilia);
    ASSERT_TRUE(carlo.findProductInListByName(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_TRUE(carlo.findProductInListByName(spesa_carlo.getListName(), "Baguette"));
    ASSERT_TRUE(carlo.findProductInListByName(spesa_carlo.getListName(), "Coca Cola"));
    ASSERT_TRUE(paolo.findProductInListByName(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_TRUE(paolo.findProductInListByName(spesa_carlo.getListName(), "Baguette"));
    ASSERT_TRUE(paolo.findProductInListByName(spesa_carlo.getListName(), "Coca Cola"));
    ASSERT_TRUE(cecilia.findProductInListByName(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_TRUE(cecilia.findProductInListByName(spesa_carlo.getListName(), "Baguette"));
    ASSERT_TRUE(cecilia.findProductInListByName(spesa_carlo.getListName(), "Coca Cola"));
    carlo.reduceProductQuantity(spesa_carlo, "Saponetta", 1);
    paolo.reduceProductQuantity(spesa_carlo, "Baguette", 2);
    cecilia.reduceProductQuantity(spesa_carlo, "Coca Cola", 3);
    ASSERT_EQ(2, carlo.getProductQuantityInList(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_EQ(2, paolo.getProductQuantityInList(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_EQ(2, cecilia.getProductQuantityInList(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_EQ(1, carlo.getProductQuantityInList(spesa_carlo.getListName(), "Baguette"));
    ASSERT_EQ(1, paolo.getProductQuantityInList(spesa_carlo.getListName(), "Baguette"));
    ASSERT_EQ(1, cecilia.getProductQuantityInList(spesa_carlo.getListName(), "Baguette"));
    ASSERT_FALSE(carlo.findProductInListByName(spesa_carlo.getListName(), "Coca Cola"));
    ASSERT_FALSE(cecilia.findProductInListByName(spesa_carlo.getListName(), "Coca Cola"));
    ASSERT_FALSE(paolo.findProductInListByName(spesa_carlo.getListName(), "Coca Cola"));
}

TEST_F(ObserverSuite, SetProductPurchasedToSharedList){
    carlo.addProductToList(spesa_carlo, sapone);
    carlo.shareList(spesa_carlo, cecilia);
    carlo.shareList(spesa_carlo, paolo);
    paolo.addProductToList(spesa_carlo, baguette);
    carlo.setProductBought(spesa_carlo, "Saponetta");
    ASSERT_TRUE(carlo.isProductBought(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_TRUE(paolo.isProductBought(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_TRUE(cecilia.isProductBought(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_FALSE(carlo.isProductBought(spesa_carlo.getListName(), "Baguette"));
    ASSERT_FALSE(paolo.isProductBought(spesa_carlo.getListName(), "Baguette"));
    ASSERT_FALSE(cecilia.isProductBought(spesa_carlo.getListName(), "Baguette"));
    cecilia.setProductNotBought(spesa_carlo, "Saponetta");
    paolo.setProductBought(spesa_carlo, "Baguette");
    ASSERT_FALSE(carlo.isProductBought(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_FALSE(paolo.isProductBought(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_FALSE(cecilia.isProductBought(spesa_carlo.getListName(), "Saponetta"));
    ASSERT_TRUE(carlo.isProductBought(spesa_carlo.getListName(), "Baguette"));
    ASSERT_TRUE(paolo.isProductBought(spesa_carlo.getListName(), "Baguette"));
    ASSERT_TRUE(cecilia.isProductBought(spesa_carlo.getListName(), "Baguette"));
}

