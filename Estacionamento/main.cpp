#include <iostream>
#include <vector>
#include "Veiculo.h"
#include "Moto.h"
#include "Carro.h"
#include "Caminhao.h"
#include "Vaga.h"
#include "Ticket.h"
#include "SistemaEstacionamento.h"

using namespace std;

void exibirMenu() {
    cout << "### Sistema de Gerenciamento de Estacionamento ###" << endl;
    cout << "Selecione uma opção:" << endl;
    cout << "1. Registrar entrada de veículo" << endl;
    cout << "2. Registrar saída de veículo" << endl;
    cout << "3. Gerar relatório" << endl;
    cout << "4. Sair" << endl;
}

int main(){

    SistemaEstacionamento sistema;

    // Adicionando vagas ao estacionamento
    int numVagas = 20;

    for(int i = 0; i < numVagas; ++i){
       int gerar = rand() % 3;
       if(gerar == 0){
            sistema.adicionarVaga(new Vaga(i+1, "Carro"));
       }else if(gerar == 1){
            sistema.adicionarVaga(new Vaga(i+1, "Moto"));
       }else{
            sistema.adicionarVaga(new Vaga(i+1, "Caminhao"));
       } 
    }

    int opcao;
    do{
        exibirMenu();
        cin >> opcao;
        cin.ignore(); // Limpar o buffer de entrada

        switch(opcao){
            case 1:{
                string placa, tipoVeiculo;
                cout << "Informe a placa do veículo: ";
                getline(cin, placa);
                cout << "Informe o tipo do veículo (Carro, Moto, Caminhao): ";
                getline(cin, tipoVeiculo);

                Veiculo* veiculo = nullptr;
                if (tipoVeiculo == "Carro") {
                    veiculo = new Carro(placa);
                } else if (tipoVeiculo == "Moto") {
                    veiculo = new Moto(placa);
                } else if (tipoVeiculo == "Caminhao") {
                    veiculo = new Caminhao(placa);
                } else {
                    cout << "Tipo de veículo inválido." << endl;
                    break;
                }

                if(veiculo){
                    sistema.registrarEntrada(veiculo, tipoVeiculo);
                }
                break;
            }
            case 2:{
                string placa;
                cout << "Informe a placa do veículo que deseja registrar a saída: ";
                getline(cin, placa);
                sistema.registrarSaida(placa);
                break;
            }
            case 3:{
                string tipoRelatorio;
                cout << "Informe o tipo de relatório (diario, semanal, mensal): ";
                getline(cin, tipoRelatorio);
                sistema.gerarRelatorio(tipoRelatorio);
                break;
            }
            case 4:{
                cout << "Encerrando o programa." << endl;
                break;
            }
            default:{
                cout << "Opção inválida. Por favor, selecione uma opção válida." << endl;
                break;
            }
        }
    } while (opcao != 4);

    return 0;
}
