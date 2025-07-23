#include <iostream>
#include <string>
#include "ContoCorrente.h"
#include "Transazione.h"

int main() {
    ContoCorrente conto;
    int scelta = 0;

    while (true) {
        std::cout << "\n=== Menu ===\n";
        std::cout << "1. Aggiungi transazione\n";
        std::cout << "2. Visualizza transazioni\n";
        std::cout << "3. Salva su file\n";
        std::cout << "4. Carica da file\n";
        std::cout << "5. Esci\n";
        std::cout << "Scegli: ";
        std::cin >> scelta;

        if (scelta == 5) break;

        if (scelta == 1) {
            std::string tipo, importo, data, descrizione;
            std::cout << "Tipo (ingresso/uscita): ";
            std::cin >> tipo;

            tipo = toLower(tipo);

            if (tipo != "ingresso" && tipo != "uscita") {
                std::cout << "Tipo non valido!\n";
                continue;
            }

            std::cin.ignore();
            std::cout << "Importo: ";
            std::getline(std::cin, importo);

            std::cout << "Data (gg/mm/aaaa): ";
            std::getline(std::cin, data);

            if (data.size() < 8 || data[2] != '/' || data[5] != '/') {
                std::cout << "Data non valida!\n";
                continue;
            }

            std::string giornoStr = data.substr(0, 2);
            std::string meseStr = data.substr(3, 2);
            std::string annoStr = data.substr(6);

            int giorno = std::stoi(giornoStr);
            int mese = std::stoi(meseStr);
            int anno = std::stoi(annoStr);

            if (giorno <= 0 || giorno > 31 ||
                mese <= 0 || mese > 12 ||
                anno < 2000 || anno > 2100) {
                std::cout << "Data non valida!\n";
                continue;
            }

            std::cout << "Descrizione: ";
            std::getline(std::cin, descrizione);

            conto.aggiungiTransazione(Transazione(tipo, importo, data, descrizione));
            std::cout << "Transazione aggiunta!\n";
        }

        else if (scelta == 2) {
            conto.stampaTransazioni();
        }

        else if (scelta == 3) {
            std::string nomeFile;
            std::cout << "Nome file: ";
            std::cin >> nomeFile;
            conto.salvaSuFile(nomeFile + ".txt");
        }

        else if (scelta == 4) {
            std::string nomeFile;
            std::cout << "Nome file (includere .txt): ";
            std::cin >> nomeFile;
            conto.caricaDaFile(nomeFile);
        }

        else {
            std::cout << "Scelta non valida.\n";
        }
    }

    return 0;
}