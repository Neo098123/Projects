#include "Modalidade.h"

Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade): nome (nome), participantes (participantes)
{

    if(quantidade < 2)
    {
        throw new invalid_argument("Numero insuficiente de equipes");
    }
    this->quantidade = quantidade;
    tabelaComOrdem = new TabelaComOrdem(participantes, quantidade);
}


Modalidade::~Modalidade()
{
}

string Modalidade::getNome()
{
    return nome;
}


Equipe** Modalidade::getEquipes()
{
    return participantes;
}

int Modalidade::getQuantidadeDeEquipes()
{
    return quantidade;
}

void Modalidade::setResultado(Equipe** ordem)
{
    this->resultado = true;
    this->tabelaComOrdem->setResultado(ordem);
}

bool Modalidade::temResultado()
{
    return this->resultado;
}

TabelaComOrdem* Modalidade::getTabela()
{
    return tabelaComOrdem;
}


void Modalidade::imprimir()
{
    cout << "Modalidade: " << this->nome << endl;
    tabelaComOrdem->imprimir();
}
