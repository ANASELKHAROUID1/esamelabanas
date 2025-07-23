#ifndef TRANSAZIONE_H
#define TRANSAZIONE_H

#include <string>

class Transazione {

    std::string tipo;
    std::string importo;
    std::string data;
    std::string descrizione;

public:

    Transazione(std::string t, std::string i, std::string d, std::string desc);

    void stampa() const;

    std::string getTipo() const { return tipo; }
    std::string getImporto() const { return importo; }
    std::string getData() const { return data; }
    std::string getDescrizione() const { return descrizione; }
};

#endif