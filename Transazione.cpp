#include "Transazione.h"
#include <iostream>


Transazione::Transazione() {
    tipo = "";
    importo = 0.0;
    data = "";
    descrizione = "";
}

// Constructor كامل
Transazione::Transazione(const std::string& t, double i, const std::string& d, const std::string& desc) {
    tipo = t;
    importo = i;
    data = d;
    descrizione = desc;
}

// طباعة معلومات العملية
void Transazione::stampa() const {
    std::cout << "Data: " << data << "\n";
    std::cout << "Tipo: " << tipo << "\n";
    std::cout << "Importo: " << importo << "\n";
    std::cout << "Descrizione: " << descrizione << "\n";
}

// Getters
std::string Transazione::getTipo() const { return tipo; }
double Transazione::getImporto() const { return importo; }
std::string Transazione::getData() const { return data; }
std::string Transazione::getDescrizione() const { return descrizione; }

// Setters
void Transazione::setTipo(const std::string& t) { tipo = t; }
void Transazione::setImporto(double i) { importo = i; }
void Transazione::setData(const std::string& d) { data = d; }
void Transazione::setDescrizione(const std::string& desc) { descrizione = desc; }