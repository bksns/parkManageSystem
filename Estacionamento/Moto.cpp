#include "Moto.h"
#include <iostream>

using namespace std;

Moto::Moto(string _placa)
    : Veiculo(_placa, "Moto") {}

Moto::~Moto() {}

double Moto::calcularTarifa() const {
    // Implementação do cálculo da tarifa para motos
    return 3.0; // Exemplo simplificado
}

void Moto::getInfo() const {
    Veiculo::getInfo();
    cout << "Tipo: Moto" << endl;
}
