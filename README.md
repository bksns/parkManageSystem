# parkManageSystem

User Story:

   Descrição: 

Como usuário, desejo poder gerenciar as entradas e saídas de veículos no estacionamento, calcular as tarifas de estacionamento e gerar relatórios detalhados de uso para uma gestão eficiente.

   Critérios de Aceitação:

- Posso registrar a entrada de um veículo, atribuindo uma vaga disponível.
- Posso registrar a saída de um veículo, calculando a tarifa correspondente.
- Posso visualizar a ocupação atual das vagas.
- Posso gerar relatórios diários, semanais e mensais sobre a utilização do estacionamento e receitas geradas.

Requisitos do Projeto:

1. Veículos:

O sistema deve ser capaz de representar diferentes tipos de veículos (por exemplo, carros, motos, caminhões) através de classes que incorporem conceitos de encapsulamento. Cada veículo deve ter uma placa e a capacidade de ser registrado na entrada e saída do estacionamento.

2. Vagas:

O sistema deve gerenciar as vagas disponíveis no estacionamento, rastreando quais estão ocupadas ou livres. As vagas podem ser de diferentes tamanhos para acomodar diferentes tipos de veículos.

3. Tickets:
   
Para cada veículo que entra no estacionamento, um ticket deve ser gerado. O ticket deve registrar a hora de entrada, o número da vaga e a placa do veículo. Na saída, o ticket deve ser atualizado com a hora de saída e o valor da tarifa calculada com base no tempo de permanência.

4. Relatórios:
   
O sistema deve ser capaz de gerar relatórios diários, semanais e mensais sobre a utilização do estacionamento, incluindo informações como a ocupação das vagas, receita gerada e média de permanência dos veículos.

Levantamento de Requisitos:

  Requisitos Funcionais:
  
  - O sistema deve ser capaz de representar vários tipos de veículos (carros, motos, caminhões, etc.).Cada veículo deve ter uma placa única e a capacidade de ser registrado na entrada e saída do estacionamento.
  - O sistema deve permitir ao usuário registrar a entrada de um veículo, gerando um ticket com informações relevantes. Deve ser possível registrar a saída de um veículo, atualizando o ticket com a hora de saída e calculando a tarifa correspondente.
  - O sistema deve gerenciar as vagas de estacionamento, indicando quais estão ocupadas e quais estão livres.
  - O sistema deve oferecer a capacidade de gerar relatórios detalhados sobre a utilização do estacionamento.

  Requisitos Não Funcionais:
  
  - O sistema deve ser fácil de usar e ter uma interface intuitiva.
  - O código deve ser bem organizado e seguir boas práticas de programação.
  - O sistema deve ser robusto e capaz de lidar com erros ou situações excepcionais (opcional).
    
Modelagem Básica do Sistema:

Com base nos requisitos, podemos criar uma modelagem básica do sistema. Vamos considerar as seguintes classes principais: Veiculo, Vaga, Ticket e SistemaEstacionamento.

Classe Veiculo:

  Atributos:
  
  - placa (String): A placa do veículo.
  - tipo (String): O tipo do veículo (carro, moto, caminhão).
    
  Métodos:
  
  - registrarEntrada(): Registra a entrada do veículo no estacionamento.
  - registrarSaida(): Registra a saída do veículo do estacionamento.
  - getPlaca(): Retorna a placa do veículo.
  - getTipo(): Retorna o tipo do veículo.

Classe Vaga:

  Atributos:
  
  - numero (int): O número da vaga.
  - tipo (String): O tipo de veículo que a vaga pode acomodar.
  - ocupada (boolean): Indica se a vaga está ocupada ou não.

  Métodos:

  - ocupar(): Marca a vaga como ocupada.
  - desocupar(): Marca a vaga como livre.
  - getNumero(): Retorna o número da vaga.
  - getTipo(): Retorna o tipo de veículo que a vaga pode acomodar.
  - isOcupada(): Retorna o estado da vaga (ocupada ou livre).

Classe Ticket:

  Atributos:

  - placaVeiculo (String): A placa do veículo associado ao ticket.
  - horaEntrada (DateTime): A hora de entrada do veículo.
  - horaSaida (DateTime): A hora de saída do veículo.
  - numeroVaga (int): O número da vaga onde o veículo está estacionado.
  - tarifa (double): O valor da tarifa calculada.

  Métodos:

  - gerar(): Gera um novo ticket na entrada do veículo.
  - atualizarSaida(): Atualiza o ticket com a hora de saída e calcula a tarifa.
  - calcularTarifa(): Calcula a tarifa com base no tempo de permanência do veículo.
  - getInfo(): Retorna as informações do ticket.

Classe SistemaEstacionamento:

  Atributos:
  
  - veiculos (List<Veiculo>): Uma lista para armazenar todos os veículos registrados.
  - vagas (List<Vaga>): Uma lista para armazenar todas as vagas do estacionamento.
  - tickets (List<Ticket>): Uma lista para armazenar todos os tickets emitidos.

  Métodos:

  - registrarEntrada(veiculo): Registra a entrada de um veículo, atribuindo uma vaga e gerando um ticket.
  - registrarSaida(placa): Registra a saída de um veículo, atualizando o ticket e liberando a vaga.
  - gerarRelatorio(tipo): Gera relatórios (diários, semanais, mensais) sobre a utilização do estacionamento.
  - adicionarVaga(vaga): Adiciona uma nova vaga ao estacionamento.
  - adicionarVeiculo(veiculo): Adiciona um novo veículo ao sistema.


### Cartões CRC

Os Cartões CRC (Classe, Responsabilidade e Colaboração) são usados para identificar e organizar as classes no sistema. Cada cartão contém informações sobre as responsabilidades da classe e suas colaborações com outras classes.

- [Veiculo](Veiculo.pdf)
- [Vaga](Vaga.pdf)
- [Ticket](Ticket.pdf)
- [SistemaEstacionamento](SistemaEstacionamento.pdf)
- [Relatorio](Relatorio.pdf)
