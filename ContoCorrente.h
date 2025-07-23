#ifndef CONTOCORRENTE_H
#define CONTOCORRENTE_H

#include <vector>
#include <string>
#include "Transazione.h"

class ContoCorrente {
    std::vector<Transazione> transazioni;

public:
    void aggiungiTransazione(const Transazione& t);
    void stampaTransazioni() const;
    void salvaSuFile(const std::string& nomeFile) const;
    void caricaDaFile(const std::string& nomeFile);

    const std::vector<Transazione>& getTransazioni() const;
};

std::string toLower(const std::string& s);

#endif
