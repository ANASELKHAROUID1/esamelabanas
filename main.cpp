#include <iostream>
#include "ContoCorrente.h"

int main() {
    ContoCorrente conto;

    // تحميل الملف عند بدء التشغيل
    conto.caricaDaFile("transazioni.txt");

    int scelta = 0;

    while (scelta != 4) {
        std::cout << "\n=== Menu ===" << std::endl;
        std::cout << "1. Aggiungi transazione" << std::endl;
        std::cout << "2. Visualizza transazioni" << std::endl;
        std::cout << "3. Salva su file" << std::endl;
        std::cout << "4. Esci" << std::endl;
        std::cout << "5. Carica da file" << std::endl;
        std::cout << "Scegli: ";
        std::cin >> scelta;

        if (scelta == 1) {
            std::string tipo, data, descrizione;
            double importo;

            std::cout << "Tipo (ingresso/uscita): ";
            std::cin >> tipo;

            if (tipo != "ingresso" && tipo != "uscita") {
                std::cout << "Tipo non valido! Operazione annullata.\n";
                continue;
            }

            std::cout << "Importo: ";
            std::cin >> importo;

            std::cout << "Data: ";
            std::cin >> data;

            std::cout << "Descrizione: ";
            std::cin.ignore(); // مسح السطر المتبقي
            std::getline(std::cin, descrizione);

            Transazione t(tipo, importo, data, descrizione);
            conto.aggiungiTransazione(t);
            std::cout << "✅ Transazione aggiunta!" << std::endl;
        }

        else if (scelta == 2) {
            conto.stampaTransazioni();
        }

        else if (scelta == 3) {
            conto.salvaSuFile("transazioni.txt");
        }

        else if (scelta == 4) {
            std::cout << "👋 Arrivederci!" << std::endl;
        }

        else if (scelta == 5) {
            conto.caricaDaFile("transazioni.txt");
        }

        else {
            std::cout << "Scelta non valida!" << std::endl;
        }
    }

    return 0;
}