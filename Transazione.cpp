#include "transazione.h"
#include <iostream>

Transazione::Transazione(std::string t, std::string i, std::string d, std::string desc)
    : tipo(t), importo(i), data(d), descrizione(desc) {}

void Transazione::stampa() const {
    std::cout << "Data: " << data << "\n";
    std::cout << "Tipo: " << tipo << "\n";
    std::cout << "Importo: " << importo << "\n";
    std::cout << "Descrizione: " << descrizione << "\n";
}