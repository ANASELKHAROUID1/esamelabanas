#include "ContoCorrente.h"
#include <iostream>
#include <fstream>

ContoCorrente::ContoCorrente() {
    saldo = 0.0;
}

void ContoCorrente::aggiungiTransazione(const Transazione& t) {
    transazioni.push_back(t);
    if (t.getTipo() == "ingresso") saldo += t.getImporto();
    else if (t.getTipo() == "uscita") saldo -= t.getImporto();
}

void ContoCorrente::stampaTransazioni() const {
    std::cout << "=== Elenco Transazioni ===" << std::endl;
    for (const auto& t : transazioni) {
        t.stampa();
        std::cout << "-------------------------" << std::endl;
    }
    std::cout << "Saldo attuale: " << saldo << std::endl;
}

double ContoCorrente::getSaldo() const {
    return saldo;
}

void ContoCorrente::salvaSuFile(const std::string& nomeFile) const {
    std::ofstream file(nomeFile);
    if (!file) {
        std::cerr << "Errore nell'aprire il file per scrivere!" << std::endl;
        return;
    }
    for (const auto& t : transazioni) {
        file << t.getData() << ";" << t.getTipo() << ";" << t.getImporto() << ";" << t.getDescrizione() << "\n";
    }
    file.close();
    std::cout << "✅ Dati salvati su file." << std::endl;
}

void ContoCorrente::caricaDaFile(const std::string& nomeFile) {
    std::ifstream file(nomeFile);
    if (!file) {
        std::cerr << "Nessun file trovato, si parte da zero." << std::endl;
        return;
    }

    std::string data, tipo, descrizione, importoStr;
    double importo;

    while (std::getline(file, data, ';')) {
        std::getline(file, tipo, ';');
        std::getline(file, importoStr, ';');
        std::getline(file, descrizione);

        importo = std::stod(importoStr);
        Transazione t(tipo, importo, data, descrizione);
        aggiungiTransazione(t);
    }
    file.close();
    std::cout << "✅ Dati caricati dal file." << std::endl;
}