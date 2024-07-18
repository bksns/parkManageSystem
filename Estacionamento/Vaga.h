#ifndef VAGA_H
#define VAGA_H

#include <string>

using namespace std;

class Vaga {
private:
    int numero;
    string tipo;
    bool ocupada;

public:
    Vaga(int _numero, string _tipo);
    ~Vaga();

    void ocupar();
    void desocupar();
    int getNumero() const;
    string getTipo() const;
    bool isOcupada() const;
};

#endif // VAGA_H
