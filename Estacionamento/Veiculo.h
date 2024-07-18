#ifndef VEICULO_H
#define VEICULO_H

#include <string>

using namespace std;

class Veiculo {
protected:
    string placa;
    string tipo;

public:
    Veiculo(string _placa, string _tipo);
    virtual ~Veiculo();

    virtual void registrarEntrada();
    virtual void registrarSaida();
    virtual double calcularTarifa() const = 0;
    virtual void getInfo() const;

    string getPlaca() const;
    string getTipo() const;
};

#endif // VEICULO_H
