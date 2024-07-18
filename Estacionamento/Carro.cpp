#include "Carro.h"
#include <iostream>

using namespace std;

Carro::Carro(string _placa)
    : Veiculo(_placa, "Carro") {}

Carro::~Carro() {}

double Carro::calcularTarifa() const {
    // Implementação do cálculo da tarifa para carros
    return 5.0; // Exemplo simplificado
}

void Carro::getInfo() const {
    Veiculo::getInfo();
    cout << "Tipo: Carro" << endl;
}
