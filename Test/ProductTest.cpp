//
// Created by Carlo Verdi on 30/10/23.
//
#include "gtest/gtest.h"
#include "../Prodotto.h"

TEST(Prodotto, DefaultParameterCostructorTest){
    Prodotto maglia("Maglia Nera", "Abbigliamento");
    ASSERT_EQ("Maglia Nera", maglia.getName());
    ASSERT_EQ("Abbigliamento", maglia.getCategory());
    ASSERT_EQ(0, maglia.getQuantity());
    ASSERT_FALSE(maglia.getStatus());
}

TEST(Prodotto, SetQuantityTest){
    Prodotto maglia("Maglia Nera", "Abbigliamento");
    testing::internal::CaptureStdout();
    maglia.setQuantity(-2);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Quantità non accettabile!"), std::string::npos);
    maglia.setQuantity(3);
    ASSERT_EQ(3, maglia.getQuantity());
}

TEST(Prodotto, AddQuantityTest){
    Prodotto maglia("Maglia Nera", "Abbigliamento");
    testing::internal::CaptureStdout();
    maglia.addQuantity(-2);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Quantità non accettabile!"), std::string::npos);
    maglia.addQuantity(2);
    ASSERT_EQ(2, maglia.getQuantity());
}

TEST(Prodotto, RemoveQuantityTest){
    Prodotto maglia("Maglia Nera", "Abbigliamento");
    maglia.setQuantity(5);
    testing::internal::CaptureStdout();
    maglia.removeQuantity(-3);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Quantità non accettabile!"), std::string::npos);
    maglia.removeQuantity(2);
    ASSERT_EQ(3, maglia.getQuantity());
}

TEST(Prodotto, SetNameTest){
    Prodotto maglia("Maglia Nera", "Abbigliamento");
    maglia.setName("T-Shirt Nera");
    ASSERT_EQ("T-Shirt Nera", maglia.getName());
}

TEST(Prodotto, SetCategoryTest){
    Prodotto maglia("Maglia Nera", "Abbigliamento");
    ASSERT_EQ("Abbigliamento", maglia.getCategory());
    maglia.setCategory("Vestiario");
    ASSERT_EQ("Vestiario", maglia.getCategory());
}

TEST(Prodotto, SetBoughtTest){
    Prodotto maglia("Maglia Nera", "Abbigliamento");
    ASSERT_FALSE(maglia.getStatus());
    maglia.setStatus(true);
    ASSERT_TRUE(maglia.getStatus());
    maglia.setStatus(false);
    ASSERT_FALSE(maglia.getStatus());
}