#include "Ticket.h"
#include <iostream>
#include <cmath>

using namespace std;

Ticket::Ticket(string _placaVeiculo, int _numeroVaga)
    : placaVeiculo(_placaVeiculo), numeroVaga(_numeroVaga) {
    time(&horaEntrada);
    horaSaida = 0;
}

Ticket::~Ticket(){}

void Ticket::atualizarSaida(){
    time(&horaSaida); // Obtém o horário de saída atual
}

time_t Ticket::getHorarioSaida(){
    return horaSaida;
}

time_t Ticket::getHorarioEntrada(){
    return horaSaida;
}

double Ticket::calcularTarifa(){
    double duracao = difftime(horaSaida, horaEntrada);
    tarifa = std::ceil(duracao / 3600.0) * 2.50;
    return tarifa;
}

void Ticket::getInfo() const {
    cout << "Ticket - Placa do Veículo: " << placaVeiculo << ", Número da Vaga: " << numeroVaga << endl;
}

string Ticket::getPlacaVeiculo(){
    return placaVeiculo;
}

int Ticket::getNumeroVaga(){
    return numeroVaga;
}