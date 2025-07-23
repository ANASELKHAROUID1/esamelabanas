#include <gtest/gtest.h>
#include "../ContoCorrente.h"
#include "../Transazione.h"
#include <cstdio>

TEST(ContoCorrenteTest, ToLowerFunziona) {
    EXPECT_EQ(toLower("CIAO"), "ciao");
    EXPECT_EQ(toLower("Testo"), "testo");
    EXPECT_EQ(toLower("GiàMinuscolo"), "giàminuscolo");
}

TEST(ContoCorrenteTest, AggiuntaTransazione) {
    ContoCorrente conto;
    Transazione t("ingresso", "100", "2025-07-01", "Stipendio");
    conto.aggiungiTransazione(t);

    const auto& transazioni = conto.getTransazioni();
    ASSERT_EQ(transazioni.size(), 1);
    EXPECT_EQ(transazioni[0].getTipo(), "ingresso");
    EXPECT_EQ(transazioni[0].getImporto(), "100");
    EXPECT_EQ(transazioni[0].getData(), "2025-07-01");
    EXPECT_EQ(transazioni[0].getDescrizione(), "Stipendio");
}

TEST(ContoCorrenteTest, SalvaECaricaFile) {
    ContoCorrente conto;
    conto.aggiungiTransazione(Transazione("ingresso", "100", "2025-07-01", "Stipendio"));
    conto.aggiungiTransazione(Transazione("uscita", "50", "2025-07-02", "Spesa"));

    std::string nomeFile = "test_transazioni.txt";
    conto.salvaSuFile(nomeFile);

    ContoCorrente nuovoConto;
    nuovoConto.caricaDaFile(nomeFile);

    const auto& trans = nuovoConto.getTransazioni();
    ASSERT_EQ(trans.size(), 2);
    EXPECT_EQ(trans[0].getDescrizione(), "Stipendio");
    EXPECT_EQ(trans[1].getTipo(), "uscita");

    std::remove(nomeFile.c_str());
}

TEST(ContoCorrenteTest, StampaTransazioniOutput) {
    ContoCorrente conto;
    conto.aggiungiTransazione(Transazione("ingresso", "200", "2025-07-10", "Bonus"));

    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(buffer.rdbuf());

    conto.stampaTransazioni();
    std::cout.rdbuf(oldCout);

    std::string output = buffer.str();
    EXPECT_NE(output.find("Bonus"), std::string::npos);
    EXPECT_NE(output.find("200"), std::string::npos);
    EXPECT_NE(output.find("Saldo attuale"), std::string::npos);
}