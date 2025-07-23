#include "ContoCorrente.h"
#include <iostream>
#include <fstream>
#include <cctype>

void ContoCorrente::aggiungiTransazione(const Transazione& t) {
    transazioni.push_back(t);
}

const std::vector<Transazione>& ContoCorrente::getTransazioni() const {
    return transazioni;
}

int estraiNumero(const std::string& testo) {
    std::string numero = "";
    for (char c : testo) {
        if (c >= '0' && c <= '9') {
            numero += c;
        } else {
            break;
        }
    }
    if (numero != "") {
        return std::stoi(numero);
    }
    return 0;
}

void ContoCorrente::stampaTransazioni() const {
    std::cout << "\n=== Elenco Transazioni ===\n";

    if (transazioni.empty()) {
        std::cout << "Nessuna transazione trovata.\n";
        return;
    }

    int saldo = 0;

    for (const auto& t : transazioni) {
        std::cout << "Data: " << t.getData() << "\n";
        std::cout << "Tipo: " << t.getTipo() << "\n";
        std::cout << "Importo: " << t.getImporto() << "\n";
        std::cout << "Descrizione: " << t.getDescrizione() << "\n";
        std::cout << "-------------------------\n";

        int valore = estraiNumero(t.getImporto());
        if (t.getTipo() == "ingresso") saldo += valore;
        else if (t.getTipo() == "uscita") saldo -= valore;
    }

    std::cout << "Saldo attuale: " << saldo << "\n";
}

void ContoCorrente::salvaSuFile(const std::string& nomeFile) const {
    std::ofstream file(nomeFile);
    if (!file) {
        std::cout << "Errore nel salvataggio del file.\n";
        return;
    }

    for (const auto& t : transazioni) {
        file << t.getTipo() << " "
             << t.getImporto() << " "
             << t.getData() << " "
             << t.getDescrizione() << "\n";
    }
    std::cout << "Salvato su file.\n";
}

void ContoCorrente::caricaDaFile(const std::string& nomeFile) {
    std::ifstream file(nomeFile);
    if (!file) {
        std::cout << "File non trovato!\n";
        return;
    }

    transazioni.clear();

    std::string tipo, importo, data, descrizione;
    while (file >> tipo >> importo >> data) {
        std::getline(file, descrizione);
        if (!descrizione.empty() && descrizione[0] == ' ')
            descrizione.erase(0,1);

        transazioni.emplace_back(tipo, importo, data, descrizione);
    }
    std::cout << "Dati caricati.\n";
}


std::string toLower(const std::string& s) {
    std::string risultato = s;
    for (char& c : risultato) {
        c = std::tolower(c);
    }
    return risultato;
}
