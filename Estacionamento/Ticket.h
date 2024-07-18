#ifndef TICKET_H
#define TICKET_H

#include <string>
#include <ctime>

using namespace std;

class Ticket {
private:
    string placaVeiculo;
    time_t horaEntrada;
    time_t horaSaida;
    int numeroVaga;
    double tarifa;

public:
    Ticket(string _placaVeiculo, int _numeroVaga);
    ~Ticket();

    void atualizarSaida();
    time_t getHorarioSaida();
    time_t getHorarioEntrada();
    double calcularTarifa();
    void getInfo() const;
    string getPlacaVeiculo();
    int getNumeroVaga();
};

#endif // TICKET_H
