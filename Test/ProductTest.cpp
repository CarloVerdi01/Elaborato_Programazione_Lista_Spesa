//
// Created by Carlo Verdi on 30/10/23.
//
#include "gtest/gtest.h"
#include "../Prodotto.h"
#include "../ProdottiDaBagno.h"
#include "../Abbigliamento.h"
#include "../Altro.h"
#include "../Bevande.h"
#include "../Elettronica.h"
#include "../Forno.h"
#include "../FruttaEVerdura.h"
#include "../Igiene.h"
#include "../Macelleria.h"
#include "../Pescheria.h"
#include "../Pulizia.h"


TEST(Abbigliamento, DefaultParameterCostructorTest){
    Abbigliamento maglietta("T-Shirt nera", 15.50);
    ASSERT_EQ(0, maglietta.getQuantity());
    ASSERT_EQ("Abbigliamento", maglietta.getCategory());
    ASSERT_FLOAT_EQ(15.50, maglietta.getPrice());
    ASSERT_EQ("T-Shirt nera", maglietta.getName());
}

TEST(Abbigliamento, ModifyQuantityMethodTest){
    Abbigliamento maglietta("T-Shirt nera", 15.50);
    ASSERT_EQ(0, maglietta.getQuantity());
    maglietta.addQuantity(7);
    ASSERT_EQ(7, maglietta.getQuantity());
    maglietta.removeQuantity(6);
    ASSERT_EQ(1, maglietta.getQuantity());
}

TEST(Altro, DefaultParameterCostructorTest){
    Altro carbonella("Carbonella per Barbeque",9.99);
    ASSERT_EQ(0, carbonella.getQuantity());
    ASSERT_EQ("Altro", carbonella.getCategory());
    ASSERT_FLOAT_EQ(9.99, carbonella.getPrice());
    ASSERT_EQ("Carbonella per Barbeque", carbonella.getName());
}

TEST(Altro, ModifyQuantityMethodTest){
    Altro carbonella("Carbonella per Barbeque",9.99);
    ASSERT_EQ(0, carbonella.getQuantity());
    carbonella.addQuantity(9);
    ASSERT_EQ(9, carbonella.getQuantity());
    carbonella.removeQuantity(1);
    ASSERT_EQ(8, carbonella.getQuantity());
    carbonella.setCategory("Prodotti per Barbeque");
    ASSERT_EQ("Prodotti per Barbeque", carbonella.getCategory());
}

TEST(Bevande, DefaultParameterCostructorTest){
    Bevande coca_cola("Coca Cola", 1.70);
    ASSERT_EQ(0, coca_cola.getQuantity());
    ASSERT_EQ("Bevande", coca_cola.getCategory());
    ASSERT_FLOAT_EQ(1.70, coca_cola.getPrice());
    ASSERT_EQ("Coca Cola", coca_cola.getName());
}

TEST(Bevande, ModifyQuantityMethodTest){
    Bevande coca_cola("Coca Cola", 1.70);
    ASSERT_EQ(0, coca_cola.getQuantity());
    coca_cola.addQuantity(5);
    ASSERT_EQ(5, coca_cola.getQuantity());
    coca_cola.removeQuantity(3);
    ASSERT_EQ(2, coca_cola.getQuantity());
}

TEST(Elettronica, DefaultParameterCostructorTest){
    Elettronica televisore("TV Sony", 249.99);
    ASSERT_EQ(0, televisore.getQuantity());
    ASSERT_EQ("Elettronica", televisore.getCategory());
    ASSERT_FLOAT_EQ(249.99, televisore.getPrice());
    ASSERT_EQ("TV Sony", televisore.getName());
}

TEST(Elettronica, ModifyQuantityMethodTest){
    Elettronica televisore("TV Sony", 249.99);
    ASSERT_EQ(0, televisore.getQuantity());
    televisore.addQuantity(8);
    ASSERT_EQ(8, televisore.getQuantity());
    televisore.removeQuantity(4);
    ASSERT_EQ(4, televisore.getQuantity());
}


TEST(Forno, DefaultParameterCostructorTest){
    Forno baguette("Baguette", 1.20);
    ASSERT_EQ(0, baguette.getQuantity());
    ASSERT_EQ("Forno", baguette.getCategory());
    ASSERT_FLOAT_EQ(1.20, baguette.getPrice());
    ASSERT_EQ("Baguette", baguette.getName());
}

TEST(Forno, ModifyQuantityMethodTest){
    Forno baguette("Baguette", 1.20);
    ASSERT_EQ(0, baguette.getQuantity());
    baguette.addQuantity(2);
    ASSERT_EQ(2, baguette.getQuantity());
    baguette.removeQuantity(2);
    ASSERT_EQ(0, baguette.getQuantity());
}

TEST(FruttaEVerdura, DefaultParameterCostructorTest){
    FruttaEVerdura pomodori("Pomodori ciliegini", 2.20);
    ASSERT_EQ(0, pomodori.getQuantity());
    ASSERT_EQ("Frutta e Verdura", pomodori.getCategory());
    ASSERT_FLOAT_EQ(2.20, pomodori.getPrice());
    ASSERT_EQ("Pomodori ciliegini", pomodori.getName());
}

TEST(FruttaEVerdura, ModifyQuantityMethodTest) {
    FruttaEVerdura pomodori("Pomodori ciliegini", 2.20);
    ASSERT_EQ(0, pomodori.getQuantity());
    pomodori.addQuantity(6);
    ASSERT_EQ(6, pomodori.getQuantity());
    pomodori.removeQuantity(1);
    ASSERT_EQ(5, pomodori.getQuantity());
}

TEST(Igiene, DefaultParameterCostructorTest){
    Igiene dentifricio("Dentifricio mentadent", 2.99);
    ASSERT_EQ(0, dentifricio.getQuantity());
    ASSERT_EQ("Igiene", dentifricio.getCategory());
    ASSERT_FLOAT_EQ(2.99, dentifricio.getPrice());
    ASSERT_EQ("Dentifricio mentadent", dentifricio.getName());
}

TEST(Igiene, ModifyQuantityMethodTest) {
    Igiene dentifricio("Dentifricio mentadent", 2.99);
    ASSERT_EQ(0, dentifricio.getQuantity());
    dentifricio.addQuantity(15);
    ASSERT_EQ(15, dentifricio.getQuantity());
    dentifricio.removeQuantity(10);
    ASSERT_EQ(5, dentifricio.getQuantity());
}

TEST(Macelleria, DefaultParameterCostructorTest){
    Macelleria bistecca("Bistecca fiorentina", 20.00);
    ASSERT_EQ(0, bistecca.getQuantity());
    ASSERT_EQ("Macelleria", bistecca.getCategory());
    ASSERT_FLOAT_EQ(20.00, bistecca.getPrice());
    ASSERT_EQ("Bistecca fiorentina", bistecca.getName());
}

TEST(Macelleria, ModifyQuantityMethodTest) {
    Macelleria bistecca("Bistecca fiorentina", 20.00);
    ASSERT_EQ(0, bistecca.getQuantity());
    bistecca.addQuantity(3);
    ASSERT_EQ(3, bistecca.getQuantity());
    bistecca.removeQuantity(2);
    ASSERT_EQ(1, bistecca.getQuantity());
}

TEST(Pescheria, DefaultParameterCostructorTest){
    Pescheria orata("Orata", 40.00);
    ASSERT_EQ(0, orata.getQuantity());
    ASSERT_EQ("Pescheria", orata.getCategory());
    ASSERT_FLOAT_EQ(40.00, orata.getPrice());
    ASSERT_EQ("Orata", orata.getName());
}

TEST(Pescheria, ModifyQuantityMethodTest) {
    Pescheria orata("Orata", 40.00);
    ASSERT_EQ(0, orata.getQuantity());
    orata.addQuantity(6);
    ASSERT_EQ(6, orata.getQuantity());
    orata.removeQuantity(3);
    ASSERT_EQ(3, orata.getQuantity());
}

TEST(ProdottiDaBagno, DefaultParameterCostructorTest){
    ProdottiDaBagno sapone("saponetta",5.8);
    ASSERT_EQ(0, sapone.getQuantity());
    ASSERT_EQ("Prodotti da Bagno", sapone.getCategory());
    ASSERT_FLOAT_EQ(5.8, sapone.getPrice());
    ASSERT_EQ("saponetta", sapone.getName());
}

TEST(ProdottiDaBagno, ModifyQuantityMethodTest){
    ProdottiDaBagno sapone("saponetta",5.8);
    ASSERT_EQ(0, sapone.getQuantity());
    sapone.addQuantity(10);
    ASSERT_EQ(10, sapone.getQuantity());
    sapone.removeQuantity(3);
    ASSERT_EQ(7, sapone.getQuantity());
}

TEST(Pulizia, DefaultParameterCostructorTest){
    Pulizia spugna("Spugna da cucina", 0.50);
    ASSERT_EQ(0, spugna.getQuantity());
    ASSERT_EQ("Pulizia", spugna.getCategory());
    ASSERT_FLOAT_EQ(0.50, spugna.getPrice());
    ASSERT_EQ("Spugna da cucina", spugna.getName());
}

TEST(Pulizia, ModifyQuantityMethodTest){
    Pulizia spugna("Spugna da cucina", 0.50);
    ASSERT_EQ(0, spugna.getQuantity());
    spugna.addQuantity(20);
    ASSERT_EQ(20, spugna.getQuantity());
    spugna.removeQuantity(1);
    ASSERT_EQ(19, spugna.getQuantity());
}
