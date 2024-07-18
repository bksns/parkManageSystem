#include "Veiculo.h"
#include <iostream>

using namespace std;

Veiculo::Veiculo(string _placa, string _tipo)
    : placa(_placa), tipo(_tipo) {}

Veiculo::~Veiculo() {}

void Veiculo::registrarEntrada() {
    cout << "Veículo de placa " << placa << " registrado na entrada do estacionamento." << endl;
}

void Veiculo::registrarSaida() {
    cout << "Veículo de placa " << placa << " registrado na saída do estacionamento." << endl;
}

void Veiculo::getInfo() const {
    cout << "Veículo - Placa: " << placa << ", Tipo: " << tipo << endl;
}

string Veiculo::getPlaca() const {
    return placa;
}

string Veiculo::getTipo() const {
    return tipo;
}
