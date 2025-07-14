#ifndef TRANSAZIONE_H
#define TRANSAZIONE_H

#include <string>

// كلاس يمثل معاملة مالية
class Transazione {
    // بيانات المعاملة
    std::string tipo;
    std::string importo;
    std::string data;
    std::string descrizione;

public:
    // منشئ المعاملة
    Transazione(std::string t, std::string i, std::string d, std::string desc);

    // طباعة بيانات المعاملة
    void stampa() const;

    // getters
    std::string getTipo() const { return tipo; }
    std::string getImporto() const { return importo; }
    std::string getData() const { return data; }
    std::string getDescrizione() const { return descrizione; }
};

#endif