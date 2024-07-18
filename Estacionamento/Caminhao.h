#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "Veiculo.h"

class Caminhao : public Veiculo {
public:
    Caminhao(std::string _placa);
    virtual ~Caminhao();

    double calcularTarifa() const override;
    void getInfo() const override;
};

#endif // CAMINHAO_H
