//
// Created by Carlo Verdi on 31/10/23.
//
#include "gtest/gtest.h"
#include "../Utente.h"
#include "../ProdottiDaBagno.h"
#include "../Bevande.h"
#include "../Forno.h"

class ObserverSuite : public ::testing::Test{
protected:

    Utente carlo = Utente("Carlo", "Verdi");
    Utente paolo = Utente ("Paolo", "Verdi");
    Utente cecilia = Utente("Cecilia", "Verdi");
    ListaDellaSpesa& spesa_carlo = carlo.creaListaDellaSpesa("Spesa Carlo", carlo.getUser());
    ListaDellaSpesa& spesa_paolo = paolo.creaListaDellaSpesa("Spesa Paolo", paolo.getUser());
    std::shared_ptr<Prodotto> sapone = std::make_shared<ProdottiDaBagno>("Saponetta", 2.20);
    std::shared_ptr<Prodotto> coca_cola = std::make_shared<Bevande>("Coca Cola", 1.70);
    std::shared_ptr<Prodotto> baguette = std::make_shared<Forno>("Baguette", 1.20);


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
    ASSERT_TRUE(carlo.findProductInListByName(spesa_carlo.getListName(), sapone));
    ASSERT_TRUE(paolo.findProductInListByName(spesa_carlo.getListName(), sapone));
    ASSERT_FALSE(cecilia.findProductInListByName(spesa_carlo.getListName(), sapone));
    ASSERT_EQ(3, spesa_carlo.getProductQuantity(sapone));
    ASSERT_EQ(4, spesa_carlo.getProductQuantity(baguette));
    ASSERT_TRUE(carlo.findProductInListByName(spesa_carlo.getListName(), baguette));
    ASSERT_TRUE(paolo.findProductInListByName(spesa_carlo.getListName(), baguette));
    ASSERT_FALSE(cecilia.findProductInListByName(spesa_carlo.getListName(), baguette));
    paolo.shareList(spesa_paolo, cecilia);
    paolo.addProductToList(spesa_paolo, coca_cola, 5);
    cecilia.addProductToList(spesa_paolo, baguette, 2);
    ASSERT_TRUE(cecilia.findProductInListByName(spesa_paolo.getListName(), coca_cola));
    ASSERT_TRUE(paolo.findProductInListByName(spesa_paolo.getListName(), coca_cola));
    ASSERT_FALSE(carlo.findProductInListByName(spesa_paolo.getListName(), coca_cola));
    ASSERT_EQ(5, spesa_paolo.getProductQuantity(coca_cola));
    ASSERT_EQ(2, spesa_paolo.getProductQuantity(baguette));
    ASSERT_TRUE(cecilia.findProductInListByName(spesa_paolo.getListName(), baguette));
    ASSERT_TRUE(paolo.findProductInListByName(spesa_paolo.getListName(), baguette));
    ASSERT_FALSE(carlo.findProductInListByName(spesa_paolo.getListName(), baguette));
}

TEST_F(ObserverSuite, RemoveProductFromSharedList) {
    carlo.addProductToList(spesa_carlo, sapone, 3);
    carlo.addProductToList(spesa_carlo, baguette, 3);
    carlo.addProductToList(spesa_carlo, coca_cola, 3);
    carlo.shareList(spesa_carlo, paolo);
    carlo.shareList(spesa_carlo, cecilia);
    ASSERT_TRUE(carlo.findProductInListByName(spesa_carlo.getListName(), sapone));
    ASSERT_TRUE(carlo.findProductInListByName(spesa_carlo.getListName(), baguette));
    ASSERT_TRUE(carlo.findProductInListByName(spesa_carlo.getListName(), coca_cola));
    ASSERT_TRUE(paolo.findProductInListByName(spesa_carlo.getListName(), sapone));
    ASSERT_TRUE(paolo.findProductInListByName(spesa_carlo.getListName(), baguette));
    ASSERT_TRUE(paolo.findProductInListByName(spesa_carlo.getListName(), coca_cola));
    ASSERT_TRUE(cecilia.findProductInListByName(spesa_carlo.getListName(), sapone));
    ASSERT_TRUE(cecilia.findProductInListByName(spesa_carlo.getListName(), baguette));
    ASSERT_TRUE(cecilia.findProductInListByName(spesa_carlo.getListName(), coca_cola));
    cecilia.removeProductFromList(spesa_carlo, sapone);
    paolo.removeProductFromList(spesa_carlo, coca_cola);
    carlo.removeProductFromList(spesa_carlo, baguette);
    ASSERT_FALSE(carlo.findProductInListByName(spesa_carlo.getListName(), sapone));
    ASSERT_FALSE(carlo.findProductInListByName(spesa_carlo.getListName(), baguette));
    ASSERT_FALSE(carlo.findProductInListByName(spesa_carlo.getListName(), coca_cola));
    ASSERT_FALSE(paolo.findProductInListByName(spesa_carlo.getListName(), sapone));
    ASSERT_FALSE(paolo.findProductInListByName(spesa_carlo.getListName(), baguette));
    ASSERT_FALSE(paolo.findProductInListByName(spesa_carlo.getListName(), coca_cola));
    ASSERT_FALSE(cecilia.findProductInListByName(spesa_carlo.getListName(), sapone));
    ASSERT_FALSE(cecilia.findProductInListByName(spesa_carlo.getListName(), baguette));
    ASSERT_FALSE(cecilia.findProductInListByName(spesa_carlo.getListName(), coca_cola));
}

TEST_F(ObserverSuite, ReduceProductQuantityFromSharedList) {
    carlo.addProductToList(spesa_carlo, sapone, 3);
    carlo.addProductToList(spesa_carlo, baguette, 3);
    carlo.addProductToList(spesa_carlo, coca_cola, 3);
    carlo.shareList(spesa_carlo, paolo);
    carlo.shareList(spesa_carlo, cecilia);
    ASSERT_TRUE(carlo.findProductInListByName(spesa_carlo.getListName(), sapone));
    ASSERT_TRUE(carlo.findProductInListByName(spesa_carlo.getListName(), baguette));
    ASSERT_TRUE(carlo.findProductInListByName(spesa_carlo.getListName(), coca_cola));
    ASSERT_TRUE(paolo.findProductInListByName(spesa_carlo.getListName(), sapone));
    ASSERT_TRUE(paolo.findProductInListByName(spesa_carlo.getListName(), baguette));
    ASSERT_TRUE(paolo.findProductInListByName(spesa_carlo.getListName(), coca_cola));
    ASSERT_TRUE(cecilia.findProductInListByName(spesa_carlo.getListName(), sapone));
    ASSERT_TRUE(cecilia.findProductInListByName(spesa_carlo.getListName(), baguette));
    ASSERT_TRUE(cecilia.findProductInListByName(spesa_carlo.getListName(), coca_cola));
    carlo.reduceProductQuantity(spesa_carlo, sapone, 1);
    paolo.reduceProductQuantity(spesa_carlo, baguette, 2);
    cecilia.reduceProductQuantity(spesa_carlo, coca_cola, 3);
    ASSERT_EQ(2, carlo.getProductQuantityInList(spesa_carlo.getListName(), sapone));
    ASSERT_EQ(2, paolo.getProductQuantityInList(spesa_carlo.getListName(), sapone));
    ASSERT_EQ(2, cecilia.getProductQuantityInList(spesa_carlo.getListName(), sapone));
    ASSERT_EQ(1, carlo.getProductQuantityInList(spesa_carlo.getListName(), baguette));
    ASSERT_EQ(1, paolo.getProductQuantityInList(spesa_carlo.getListName(), baguette));
    ASSERT_EQ(1, cecilia.getProductQuantityInList(spesa_carlo.getListName(), baguette));
    ASSERT_FALSE(carlo.findProductInListByName(spesa_carlo.getListName(), coca_cola));
    ASSERT_FALSE(cecilia.findProductInListByName(spesa_carlo.getListName(), coca_cola));
    ASSERT_FALSE(paolo.findProductInListByName(spesa_carlo.getListName(), coca_cola));
}