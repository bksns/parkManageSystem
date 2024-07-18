#ifndef SISTEMAESTACIONAMENTO_H
#define SISTEMAESTACIONAMENTO_H

#include "Veiculo.h"
#include "Vaga.h"
#include "Ticket.h"
#include <vector>
#include <string>

using namespace std;

class SistemaEstacionamento {
private:
    vector<Veiculo*> veiculos;
    vector<Vaga*> vagas;
    vector<Ticket*> tickets;

    float calcularOcupacaoVagasDiario() const;
    float calcularReceitaDiario() const;
    float calcularMediaPermanenciaDiario() const;
    float calcularOcupacaoVagasSemanal() const;
    float calcularReceitaSemanal() const;
    float calcularMediaPermanenciaSemanal() const;
    float calcularOcupacaoVagasMensal() const;
    float calcularReceitaMensal() const;
    float calcularMediaPermanenciaMensal() const;

public:
    SistemaEstacionamento();
    ~SistemaEstacionamento();

    void registrarEntrada(Veiculo* veiculo, string tipoVeiculo);
    void registrarSaida(string& placa);
    void gerarRelatorio(string& tipoRelatorio) const;
    void adicionarVaga(Vaga* vaga);
    void adicionarVeiculo(Veiculo* veiculo);

    void listarVeiculos() const;
    void listarVagas() const;
    void listarTickets() const;
};

#endif // SISTEMAESTACIONAMENTO_H
