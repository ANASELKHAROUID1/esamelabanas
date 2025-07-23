#include <gtest/gtest.h>
#include "../Transazione.h"

TEST(TestTransazione, CostruttoreEGetterFunzionano) {
    Transazione t("ingresso", "100", "2025-07-01", "stipendio");

    EXPECT_EQ(t.getTipo(), "ingresso");
    EXPECT_EQ(t.getImporto(), "100");
    EXPECT_EQ(t.getData(), "2025-07-01");
    EXPECT_EQ(t.getDescrizione(), "stipendio");
}


TEST(TestTransazione, StampaFunziona) {
    Transazione t("uscita", "50", "2025-07-02", "Spesa");

}
