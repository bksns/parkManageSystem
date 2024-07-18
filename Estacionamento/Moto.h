#ifndef MOTO_H
#define MOTO_H

#include "Veiculo.h"

using namespace std;

class Moto : public Veiculo {
public:
    Moto(string _placa);
    virtual ~Moto();

    double calcularTarifa() const override;
    void getInfo() const override;
};

#endif // MOTO_H
