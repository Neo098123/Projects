#include "Competicao.h"

Competicao::Competicao(string nome, Equipe** equipes, int quantidade): nome (nome), equipes (equipes), quantidade (quantidade)
{

    if(quantidade < 2)
    {
        throw new invalid_argument("Numero de equipes invalido");
    }
}

Competicao::~Competicao()
{

}

string Competicao::getNome()
{
    return nome;
}


Equipe** Competicao::getEquipes()
{
    return equipes;
}

int Competicao::getQuantidadeDeEquipes()
{
    return quantidade;
}
