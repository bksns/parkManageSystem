#include "Caminhao.h"
#include <iostream>

using namespace std;

Caminhao::Caminhao(string _placa)
    : Veiculo(_placa, "Caminhao") {}

Caminhao::~Caminhao() {}

double Caminhao::calcularTarifa() const {
    // Implementação do cálculo da tarifa para caminhões
    return 8.0; // Exemplo simplificado
}

void Caminhao::getInfo() const {
    Veiculo::getInfo();
    cout << "Tipo: Caminhao" << endl;
}
