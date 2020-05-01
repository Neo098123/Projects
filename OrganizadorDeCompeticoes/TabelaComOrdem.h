#include "Tabela.h"
#include <iostream>
#include <stdexcept>
#ifndef TABELACOMORDEM_H
#define TABELACOMORDEM_H

using namespace std;

class TabelaComOrdem : public Tabela{

public:
    TabelaComOrdem(Equipe** participantes, int quantidade);
    virtual ~TabelaComOrdem();
    int getPosicao(Equipe* participante);
    void setResultado(Equipe** ordem);
    Equipe** getEquipesEmOrdem();
    void imprimir();

private:
    Equipe** ordem;
};

#endif // TABELACOMORDEM_H
