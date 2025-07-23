#include <gtest/gtest.h>
#include "../ContoCorrente.h"
#include "../Transazione.h"
#include <cstdio>

TEST(TestBase, ToLower) {
    EXPECT_EQ(toLower("CIAO"), "ciao");
    EXPECT_EQ(toLower("TestO"), "testo");
    EXPECT_EQ(toLower("misto"), "misto");
}

TEST(TestBase, AggiuntaTransazione) {
    ContoCorrente conto;
    Transazione t("ingresso", "150", "2025-07-20", "Regalo");
    conto.aggiungiTransazione(t);

    auto trans = conto.getTransazioni();
    ASSERT_EQ(trans.size(), 1);
    EXPECT_EQ(trans[0].getTipo(), "ingresso");
    EXPECT_EQ(trans[0].getImporto(), "150");
    EXPECT_EQ(trans[0].getData(), "2025-07-20");
    EXPECT_EQ(trans[0].getDescrizione(), "Regalo");
}

TEST(TestBase, SalvaCarica) {
    ContoCorrente conto;
    conto.aggiungiTransazione(Transazione("uscita", "30", "2025-07-22", "Pizza"));

    std::string nomeFile = "testfile.txt";
    conto.salvaSuFile(nomeFile);

    ContoCorrente nuovoConto;
    nuovoConto.caricaDaFile(nomeFile);

    auto trans = nuovoConto.getTransazioni();
    ASSERT_EQ(trans.size(), 1);
    EXPECT_EQ(trans[0].getDescrizione(), "Pizza");

    std::remove(nomeFile.c_str());
}
TEST(TestBase, StampaTransazioni) {
    ContoCorrente conto;
    conto.aggiungiTransazione(Transazione("ingresso", "200", "2025-07-25", "Bonus"));

}
