//
// Created by Carlo Verdi on 30/10/23.
//
#include "gtest/gtest.h"
#include "../ListaDellaSpesa.h"
#include "../ProdottiDaBagno.h"
#include "../Bevande.h"
#include "../Utente.h"


class ListaDellaSpesaSuite : public ::testing::Test{
protected:

    ListaDellaSpesa spesa_casa = ListaDellaSpesa("Spesa per casa", "Carlo Verdi");
    std::shared_ptr<Prodotto> sapone = std::make_shared<ProdottiDaBagno>("Saponetta", 2.20);
    std::shared_ptr<Prodotto> coca_cola = std::make_shared<Bevande>("Coca Cola", 1.70);
    Observer* o = new Utente("Paolo", "Verdi");


};


TEST_F(ListaDellaSpesaSuite, costructorTest){
    ASSERT_EQ("Carlo Verdi", spesa_casa.getOwner());
    ASSERT_EQ("Spesa per casa", spesa_casa.getListName());
}

TEST_F(ListaDellaSpesaSuite, addProductTest){
    spesa_casa.addProduct(sapone, 3);
    ASSERT_TRUE(spesa_casa.findProduct(sapone));
    ASSERT_EQ(3, spesa_casa.getProductQuantity(sapone));
    spesa_casa.addProduct(coca_cola, 4);
    ASSERT_TRUE(spesa_casa.findProduct(coca_cola));
    ASSERT_EQ(4, spesa_casa.getProductQuantity(coca_cola));
}

TEST_F(ListaDellaSpesaSuite, removeProductTest){
    spesa_casa.addProduct(sapone, 5);
    spesa_casa.addProduct(coca_cola, 6);
    spesa_casa.removeProduct(sapone);
    ASSERT_TRUE(spesa_casa.findProduct(coca_cola));
    ASSERT_FALSE(spesa_casa.findProduct(sapone));
    ASSERT_EQ(6, spesa_casa.getProductQuantity(coca_cola));
}


TEST_F(ListaDellaSpesaSuite, reduceQuantityTest){
    spesa_casa.addProduct(sapone, 6);
    spesa_casa.addProduct(coca_cola, 2);
    ASSERT_TRUE(spesa_casa.findProduct(sapone));
    ASSERT_TRUE(spesa_casa.findProduct(coca_cola));
    spesa_casa.reduceProductQuantity(sapone, 2);
    spesa_casa.reduceProductQuantity(coca_cola, 2);
    ASSERT_TRUE(spesa_casa.findProduct(sapone));
    ASSERT_EQ(4, spesa_casa.getProductQuantity(sapone));
    ASSERT_FALSE(spesa_casa.findProduct(coca_cola));
    spesa_casa.reduceProductQuantity(sapone, 6);
    ASSERT_FALSE(spesa_casa.findProduct(sapone));
}

TEST_F(ListaDellaSpesaSuite, shareListTest){
    spesa_casa.shareList(o, "Paolo Verdi");
    ASSERT_TRUE(spesa_casa.findSharedUser("Paolo Verdi"));
}


