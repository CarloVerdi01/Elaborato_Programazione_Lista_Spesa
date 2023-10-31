//
// Created by Carlo Verdi on 30/10/23.
//
#include "gtest/gtest.h"
#include "../Utente.h"
#include "../ProdottiDaBagno.h"
#include "../Bevande.h"
#include "../Forno.h"

class UserTestSuite : public ::testing::Test{
protected:

    Utente carlo = Utente("Carlo", "Verdi");
    std::shared_ptr<Prodotto> sapone = std::make_shared<ProdottiDaBagno>("Saponetta", 2.20);
    std::shared_ptr<Prodotto> coca_cola = std::make_shared<Bevande>("Coca Cola", 1.70);
    std::shared_ptr<Prodotto> baguette = std::make_shared<Forno>("Baguette", 1.20);
    ListaDellaSpesa& spesa_nonna = carlo.creaListaDellaSpesa("Spesa nonna", carlo.getUser());



};

TEST_F(UserTestSuite, CostructorTest){
    ASSERT_EQ("Carlo", carlo.getName());
    ASSERT_EQ("Verdi", carlo.getSurname());
    ASSERT_EQ("Carlo Verdi", carlo.getUser());
}

TEST_F(UserTestSuite, ListCreationTest){
    ListaDellaSpesa& spesa_casa = carlo.creaListaDellaSpesa("Spesa per casa", carlo.getUser());
    ASSERT_TRUE(&spesa_casa);
    ASSERT_EQ("Carlo Verdi", spesa_casa.getOwner());
}

TEST_F(UserTestSuite, AddProductToListTest){
    carlo.addProductToList(spesa_nonna, sapone, 3);
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, sapone));
    ASSERT_EQ(3, spesa_nonna.getProductQuantity(sapone));
    carlo.addProductToList(spesa_nonna, baguette, 2 );
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, baguette));
    ASSERT_EQ(2, spesa_nonna.getProductQuantity(baguette));
    carlo.addProductToListByName(spesa_nonna.getListName(), coca_cola, 3);
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, coca_cola));
    ASSERT_EQ(3, spesa_nonna.getProductQuantity(coca_cola));
}

TEST_F(UserTestSuite, removeProductFromListTest) {
    carlo.addProductToList(spesa_nonna, sapone, 5);
    carlo.addProductToList(spesa_nonna, baguette, 1);
    carlo.addProductToList(spesa_nonna, coca_cola, 4);
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, sapone));
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, baguette));
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, coca_cola));
    carlo.removeProductFromList(spesa_nonna, sapone);
    ASSERT_FALSE(carlo.findProductInList(spesa_nonna, sapone));
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, baguette));
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, coca_cola));
    carlo.removeProductFromList(spesa_nonna, coca_cola);
    ASSERT_FALSE(carlo.findProductInList(spesa_nonna, sapone));
    ASSERT_FALSE(carlo.findProductInList(spesa_nonna, coca_cola));
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, baguette));
    carlo.removeProductFromListByName(spesa_nonna.getListName(), baguette);
    ASSERT_FALSE(carlo.findProductInList(spesa_nonna, sapone));
    ASSERT_FALSE(carlo.findProductInList(spesa_nonna, coca_cola));
    ASSERT_FALSE(carlo.findProductInList(spesa_nonna, baguette));
}

TEST_F(UserTestSuite, reduceProductQuantityFromListTest){
    carlo.addProductToList(spesa_nonna, sapone, 5);
    carlo.addProductToList(spesa_nonna, baguette, 1);
    carlo.addProductToList(spesa_nonna, coca_cola, 4);
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, sapone));
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, baguette));
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, coca_cola));
    carlo.reduceProductQuantity(spesa_nonna, sapone, 3);
    carlo.reduceProductQuantity(spesa_nonna, coca_cola, 5);
    carlo.reduceProductQuantity(spesa_nonna, baguette, 1);
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, sapone));
    ASSERT_EQ(2, spesa_nonna.getProductQuantity(sapone));
    ASSERT_FALSE(carlo.findProductInList(spesa_nonna, baguette));
    ASSERT_FALSE(carlo.findProductInList(spesa_nonna, coca_cola));
    carlo.reduceProductFromListByName(spesa_nonna.getListName(), sapone, 1);
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, sapone));
    ASSERT_EQ(1, spesa_nonna.getProductQuantity(sapone));
}