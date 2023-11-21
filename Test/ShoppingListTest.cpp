//
// Created by Carlo Verdi on 30/10/23.
//
#include "gtest/gtest.h"
#include "../ListaDellaSpesa.h"
#include "../Utente.h"


class ListaDellaSpesaSuite : public ::testing::Test{
protected:

    ListaDellaSpesa spesa_casa = ListaDellaSpesa("Spesa per casa", "Carlo Verdi");
    Prodotto sapone = Prodotto("Saponetta", "Igiene");
    Prodotto coca_cola = Prodotto("Coca Cola", "Bevande");
    Prodotto frusta = Prodotto ("Frusta", "Forno");
    Observer* o = new Utente("Paolo", "Verdi");


};



TEST_F(ListaDellaSpesaSuite, costructorTest){
    ASSERT_EQ("Carlo Verdi", spesa_casa.getOwner());
    ASSERT_EQ("Spesa per casa", spesa_casa.getListName());
}



TEST_F(ListaDellaSpesaSuite, addProductTest){
    spesa_casa.addProduct(sapone, 3);
    ASSERT_TRUE(spesa_casa.findProduct("Saponetta"));
    ASSERT_EQ(3, spesa_casa.getProductQuantity("Saponetta"));
    spesa_casa.addProduct(coca_cola, 4);
    ASSERT_TRUE(spesa_casa.findProduct("Coca Cola"));
    ASSERT_EQ(4, spesa_casa.getProductQuantity("Coca Cola"));
    testing::internal::CaptureStdout();
    spesa_casa.addProduct(frusta, -2);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Quantità non accettabile!"), std::string::npos);
}



TEST_F(ListaDellaSpesaSuite, removeProductTest){
    spesa_casa.addProduct(sapone, 5);
    spesa_casa.addProduct(coca_cola, 6);
    spesa_casa.removeProduct("Saponetta");
    ASSERT_TRUE(spesa_casa.findProduct("Coca Cola"));
    ASSERT_FALSE(spesa_casa.findProduct("Saponetta"));
    ASSERT_EQ(6, spesa_casa.getProductQuantity("Coca Cola"));
    testing::internal::CaptureStdout();
    spesa_casa.removeProduct("saponetta");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Prodotto saponetta non presente nella lista!"), std::string::npos);

}



TEST_F(ListaDellaSpesaSuite, reduceQuantityTest){
    spesa_casa.addProduct(sapone, 6);
    spesa_casa.addProduct(coca_cola, 2);
    ASSERT_TRUE(spesa_casa.findProduct("Saponetta"));
    ASSERT_TRUE(spesa_casa.findProduct("Coca Cola"));
    spesa_casa.reduceProductQuantity("Saponetta", 2);
    spesa_casa.reduceProductQuantity("Coca Cola", 2);
    ASSERT_TRUE(spesa_casa.findProduct("Saponetta"));
    ASSERT_EQ(4, spesa_casa.getProductQuantity("Saponetta"));
    ASSERT_FALSE(spesa_casa.findProduct("Coca Cola"));
    spesa_casa.reduceProductQuantity("Saponetta", 6);
    ASSERT_FALSE(spesa_casa.findProduct("Saponetta"));
    spesa_casa.addProduct(coca_cola, 5);
    testing::internal::CaptureStdout();
    spesa_casa.reduceProductQuantity("Coca Cola", -2);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Quantità non accettabile!"), std::string::npos);
    testing::internal::CaptureStdout();
    spesa_casa.reduceProductQuantity("saponetta", 2);
    std::string output2 = testing::internal::GetCapturedStdout();
    EXPECT_NE(output2.find("Prodotto saponetta non presente nella lista!"), std::string::npos);
}

TEST_F(ListaDellaSpesaSuite, NumberOfProductTest){
    ASSERT_EQ(0, spesa_casa.getNumberOfProduct());
    spesa_casa.addProduct(coca_cola, 3);
    spesa_casa.addProduct(sapone, 2);
    ASSERT_EQ(2, spesa_casa.getNumberOfProduct());
}

TEST_F(ListaDellaSpesaSuite, SetPurchasedProductTest){
    spesa_casa.addProduct(coca_cola, 2);
    spesa_casa.addProduct(sapone, 1);
    ASSERT_EQ(0, spesa_casa.getNumberOfPurchasedProduct());
    spesa_casa.setProductBought("Coca Cola");
    ASSERT_EQ(1, spesa_casa.getNumberOfPurchasedProduct());
    spesa_casa.setProductBought("Saponetta");
    ASSERT_EQ(2, spesa_casa.getNumberOfPurchasedProduct());
    spesa_casa.setProductNotBought("Saponetta");
    ASSERT_EQ(1, spesa_casa.getNumberOfPurchasedProduct());
    testing::internal::CaptureStdout();
    spesa_casa.setProductBought("saponetta");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Prodotto saponetta non presente nella lista!"), std::string::npos);
}


TEST_F(ListaDellaSpesaSuite, shareListTest){
    spesa_casa.shareList(o, "Paolo Verdi");
    ASSERT_TRUE(spesa_casa.isSharedUser("Paolo Verdi"));
}


