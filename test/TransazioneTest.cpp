#include <gtest/gtest.h>
#include "../Transazione.h"
#include <sstream>
#include <iostream>

TEST(TestTransazione, CostruttoreEGetterFunzionano) {
    Transazione t("ingresso", "100", "2025-07-01", "stipendio");

    EXPECT_EQ(t.getTipo(), "ingresso");
    EXPECT_EQ(t.getImporto(), "100");
    EXPECT_EQ(t.getData(), "2025-07-01");
    EXPECT_EQ(t.getDescrizione(), "stipendio");
}

TEST(TestTransazione, StampaFunzionaSemplice) {
    Transazione t("uscita", "50", "2025-07-02", "Spesa");

    std::streambuf* oldCout = std::cout.rdbuf();
    std::stringstream buffer;
    std::cout.rdbuf(buffer.rdbuf());

    t.stampa();

    std::cout.rdbuf(oldCout);

    std::string output = buffer.str();

    EXPECT_TRUE(output.find("Spesa") != -1);
    EXPECT_TRUE(output.find("50") != -1);
    EXPECT_TRUE(output.find("2025-07-02") != -1);
    EXPECT_TRUE(output.find("uscita") != -1);
}