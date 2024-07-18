#include "Vaga.h"

using namespace std;

Vaga::Vaga(int _numero, string _tipo)
    : numero(_numero), tipo(_tipo), ocupada(false) {}

Vaga::~Vaga() {}

void Vaga::ocupar() {
    ocupada = true;
}

void Vaga::desocupar() {
    ocupada = false;
}

int Vaga::getNumero() const {
    return numero;
}

string Vaga::getTipo() const {
    return tipo;
}

bool Vaga::isOcupada() const {
    return ocupada;
}
