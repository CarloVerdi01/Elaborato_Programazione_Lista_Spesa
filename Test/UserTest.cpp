//
// Created by Carlo Verdi on 30/10/23.
//
#include "gtest/gtest.h"
#include "../Utente.h"


class UserTestSuite : public ::testing::Test{
protected:

    Utente carlo = Utente("Carlo", "Verdi");
    Prodotto matita = Prodotto("Lapis", "Prodotti Disegno");
    Prodotto baguette = Prodotto("Baguette", "Forno");
    Prodotto spazzolino = Prodotto("Spazzolino", "Igiene");
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
    carlo.addProductToList(spesa_nonna, matita, 3);
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, "Lapis"));
    ASSERT_EQ(3, spesa_nonna.getProductQuantity("Lapis"));
    carlo.addProductToList(spesa_nonna, baguette, 2 );
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, "Baguette"));
    ASSERT_EQ(2, spesa_nonna.getProductQuantity("Baguette"));
    carlo.addProductToListByName(spesa_nonna.getListName(), spazzolino, 3);
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, "Spazzolino"));
    ASSERT_EQ(3, spesa_nonna.getProductQuantity("Spazzolino"));
    testing::internal::CaptureStdout();
    carlo.addProductToList(spesa_nonna, matita, -2);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Quantità non accettabile!"), std::string::npos);
}

TEST_F(UserTestSuite, removeProductFromListTest) {
    carlo.addProductToList(spesa_nonna, matita, 5);
    carlo.addProductToList(spesa_nonna, baguette, 1);
    carlo.addProductToList(spesa_nonna, spazzolino, 4);
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, "Lapis"));
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, "Baguette"));
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, "Spazzolino"));
    carlo.removeProductFromList(spesa_nonna, "Lapis");
    ASSERT_FALSE(carlo.findProductInList(spesa_nonna, "Lapis"));
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, "Baguette"));
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, "Spazzolino"));
    carlo.removeProductFromList(spesa_nonna, "Spazzolino");
    ASSERT_FALSE(carlo.findProductInList(spesa_nonna, "Lapis"));
    ASSERT_FALSE(carlo.findProductInList(spesa_nonna, "Spazzolino"));
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, "Baguette"));
    carlo.removeProductFromListByName(spesa_nonna.getListName(), "Baguette");
    ASSERT_FALSE(carlo.findProductInList(spesa_nonna, "Lapis"));
    ASSERT_FALSE(carlo.findProductInList(spesa_nonna, "Spazzolino"));
    ASSERT_FALSE(carlo.findProductInList(spesa_nonna, "Baguette"));
    carlo.addProductToList(spesa_nonna, spazzolino);
    testing::internal::CaptureStdout();
    carlo.removeProductFromList(spesa_nonna, "spazzolino");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Prodotto spazzolino non presente nella lista!"), std::string::npos);
}



TEST_F(UserTestSuite, reduceProductQuantityFromListTest){
    carlo.addProductToList(spesa_nonna, matita, 5);
    carlo.addProductToList(spesa_nonna, baguette, 1);
    carlo.addProductToList(spesa_nonna, spazzolino, 4);
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, "Lapis"));
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, "Baguette"));
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, "Spazzolino"));
    carlo.reduceProductQuantity(spesa_nonna, "Lapis", 3);
    carlo.reduceProductQuantity(spesa_nonna, "Spazzolino", 5);
    carlo.reduceProductQuantity(spesa_nonna, "Baguette", 1);
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, "Lapis"));
    ASSERT_EQ(2, spesa_nonna.getProductQuantity("Lapis"));
    ASSERT_FALSE(carlo.findProductInList(spesa_nonna, "Baguette"));
    ASSERT_FALSE(carlo.findProductInList(spesa_nonna, "Spazzolino"));
    carlo.reduceProductFromListByName(spesa_nonna.getListName(), "Lapis", 1);
    ASSERT_TRUE(carlo.findProductInList(spesa_nonna, "Lapis"));
    ASSERT_EQ(1, spesa_nonna.getProductQuantity("Lapis"));
    testing::internal::CaptureStdout();
    carlo.reduceProductQuantity(spesa_nonna, "Lapis", -2);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Quantità non accettabile!"), std::string::npos);
}
