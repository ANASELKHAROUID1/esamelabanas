#ifndef CONTOCORRENTE_H
#define CONTOCORRENTE_H

#include <vector>
#include <string>
#include "Transazione.h"

class ContoCorrente {
private:
    double saldo;
    std::vector<Transazione> transazioni;

public:
    ContoCorrente();

    void aggiungiTransazione(const Transazione& t);
    void stampaTransazioni() const;
    double getSaldo() const;

    void salvaSuFile(const std::string& nomeFile) const;
    void caricaDaFile(const std::string& nomeFile);
};

#endif