#include "Tabela.h"
#include <iostream>
#include <stdexcept>
#ifndef TABELACOMPONTOS_H
#define TABELACOMPONTOS_H

using namespace std;

class TabelaComPontos : public Tabela
{
public:
    TabelaComPontos(Equipe** participantes, int quantidade);
    virtual ~TabelaComPontos();
    int getPosicao(Equipe* participante);
    int getPontos (Equipe* participante);
    void pontuar(Equipe* participante, int pontos);
    Equipe** getEquipesEmOrdem();
    void imprimir();

private:
    int* pontos;
    Equipe** ordem;
};

#endif // TABELACOMPONTOS_H
