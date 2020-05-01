#include "Tabela.h"

Tabela::Tabela(Equipe** participantes, int quantidade): participantes (participantes), quantidade(quantidade)
{

    if(quantidade < 2)
    {
        throw new invalid_argument("Numero insuficiente de equipes");
    }
}

Tabela::~Tabela()
{

}

int Tabela::getQuantidadeDeEquipes()
{
    return this->quantidade;
}
