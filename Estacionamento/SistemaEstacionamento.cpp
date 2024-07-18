#include "SistemaEstacionamento.h"
#include <iostream>
#include <iomanip>

using namespace std;

SistemaEstacionamento::SistemaEstacionamento() {}

SistemaEstacionamento::~SistemaEstacionamento() {
    // Limpar a memória alocada dinamicamente
    for (auto& veiculo : veiculos) {
        delete veiculo;
    }
    for (auto& vaga : vagas) {
        delete vaga;
    }
    for (auto& ticket : tickets) {
        delete ticket;
    }
}

void SistemaEstacionamento::registrarEntrada(Veiculo* veiculo, string tipoVeiculo){
    
    // Procurar por uma vaga disponível do tipo especificado
    Vaga* vagaSelecionada = nullptr;
    for (int i = 0; i < 20; ++i){
        if (!vagas[i]->isOcupada() && vagas[i]->getTipo() == tipoVeiculo) {
            vagaSelecionada = vagas[i];
            break;
        }
    }

    if(vagaSelecionada){
        vagaSelecionada->ocupar();
        veiculo->registrarEntrada();
        // Gerar um ticket para o veículo
        Ticket* ticket = new Ticket(veiculo->getPlaca(), vagaSelecionada->getNumero());
        tickets.push_back(ticket);
        cout << "Veículo registrado com sucesso na vaga " << vagaSelecionada->getNumero() << endl;
    }else{
        cout << "Não há vagas disponíveis para o tipo de veículo selecionado." << endl;
        return;
    }
}

void SistemaEstacionamento::registrarSaida(string& placa){
    // Lógica para registrar a saída de um veículo
    bool encontrado = false;
    for (auto& ticket : tickets) {
        if(ticket->getPlacaVeiculo() == placa){
            ticket->atualizarSaida();
            cout << "Tarifa a ser paga: " << ticket->calcularTarifa() << endl;
            for (auto& vaga : vagas) {
                if (vaga->getNumero() == ticket->getNumeroVaga()) {
                    vaga->desocupar();
                    break;
                }
            }
            encontrado = true;
            cout << "Veículo saiu do estacionamento." << endl;
            break;
        }
    }

    if(!encontrado){
        cout << "Veículo não encontrado no estacionamento." << endl;
    }
}

void SistemaEstacionamento::gerarRelatorio(string& tipoRelatorio) const{
    if (tipoRelatorio == "diario") {
        cout << "Relatório Diário:" << endl;
        cout << "-----------------" << endl;
        cout << "- Ocupação das vagas: " << fixed << setprecision(2) << calcularOcupacaoVagasDiario() << "%" << endl;
        cout << "- Receita gerada: R$ " << fixed << setprecision(2) << calcularReceitaDiario() << endl;
        cout << "- Média de permanência dos veículos: " << fixed << setprecision(2) << calcularMediaPermanenciaDiario() << " horas" << endl;
        cout << "-----------------" << endl;
    } else if (tipoRelatorio == "semanal") {
        cout << "Relatório Semanal:" << endl;
        cout << "-----------------" << endl;
        cout << "- Ocupação das vagas: " << fixed << setprecision(2) << calcularOcupacaoVagasSemanal() << "%" << endl;
        cout << "- Receita gerada: R$ " << fixed << setprecision(2) << calcularReceitaSemanal() << endl;
        cout << "- Média de permanência dos veículos: " << fixed << setprecision(2) << calcularMediaPermanenciaSemanal() << " horas" << endl;
        cout << "-----------------" << endl;
    } else if (tipoRelatorio == "mensal") {
        cout << "Relatório Mensal:" << endl;
        cout << "-----------------" << endl;
        cout << "- Ocupação das vagas: " << fixed << setprecision(2) << calcularOcupacaoVagasMensal() << "%" << endl;
        cout << "- Receita gerada: R$ " << fixed << setprecision(2) << calcularReceitaMensal() << endl;
        cout << "- Média de permanência dos veículos: " << fixed << setprecision(2) << calcularMediaPermanenciaMensal() << " horas" << endl;
        cout << "-----------------" << endl;
    } else {
        cout << "Tipo de relatório inválido." << endl;
    }
}

float SistemaEstacionamento::calcularOcupacaoVagasDiario() const {
    int vagasOcupadas = 0;
    for (const auto& vaga : vagas) {
        if (vaga->isOcupada()) {
            vagasOcupadas++;
        }
    }
    return static_cast<float>(vagasOcupadas) / vagas.size() * 100.0;
}

float SistemaEstacionamento::calcularReceitaDiario() const {
    float receita = 0.0;
    for(const auto& ticket : tickets){
        if(ticket->getHorarioSaida() != 0){
            receita += ticket->calcularTarifa();
        }
    }
    return receita;
}

float SistemaEstacionamento::calcularMediaPermanenciaDiario() const {
    float totalPermanencia = 0.0;
    int numTickets = 0;
    for(const auto& ticket : tickets){
        if (ticket->getHorarioSaida() != 0){
            double duracao = difftime(ticket->getHorarioSaida(), ticket->getHorarioEntrada());
            totalPermanencia += duracao;
            numTickets++;
        }
    }
    if(numTickets > 0){
        return totalPermanencia / numTickets;
    }
    return 0.0;
}

float SistemaEstacionamento::calcularOcupacaoVagasSemanal() const {
    return calcularOcupacaoVagasDiario() * 7 / 100.0; // Simulação de ocupação semanal
}

float SistemaEstacionamento::calcularReceitaSemanal() const {
    return calcularReceitaDiario() * 7; // Simulação de receita semanal
}

float SistemaEstacionamento::calcularMediaPermanenciaSemanal() const {
    return calcularMediaPermanenciaDiario(); // Simulação de média de permanência semanal
}

float SistemaEstacionamento::calcularOcupacaoVagasMensal() const {
    return calcularOcupacaoVagasDiario() * 30 / 100.0; // Simulação de ocupação mensal
}

float SistemaEstacionamento::calcularReceitaMensal() const {
    return calcularReceitaDiario() * 30; // Simulação de receita mensal
}

float SistemaEstacionamento::calcularMediaPermanenciaMensal() const {
    return calcularMediaPermanenciaDiario(); // Simulação de média de permanência mensal
}


void SistemaEstacionamento::adicionarVaga(Vaga* vaga) {
    vagas.push_back(vaga);
}

void SistemaEstacionamento::adicionarVeiculo(Veiculo* veiculo) {
    veiculos.push_back(veiculo);
}
