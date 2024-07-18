#ifndef CARRO_H
#define CARRO_H

#include "Veiculo.h"

using namespace std;

class Carro : public Veiculo {
public:
    Carro(string _placa);
    virtual ~Carro();

    double calcularTarifa() const override;
    void getInfo() const override;
};

#endif // CARRO_H
