#ifndef TRANSAZIONE_H
#define TRANSAZIONE_H

#include <string>

class Transazione {
private:
    std::string tipo;         // "ingresso" أو "uscita"
    double importo;           // المبلغ
    std::string data;         // التاريخ
    std::string descrizione;  // وصف

public:
    Transazione();
    Transazione(const std::string& tipo, double importo, const std::string& data, const std::string& descrizione);

    void stampa() const;

    // Getters
    std::string getTipo() const;
    double getImporto() const;
    std::string getData() const;
    std::string getDescrizione() const;

    // Setters
    void setTipo(const std::string& t);
    void setImporto(double i);
    void setData(const std::string& d);
    void setDescrizione(const std::string& desc);
};

#endif