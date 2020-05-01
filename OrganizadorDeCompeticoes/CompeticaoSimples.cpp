#include "CompeticaoSimples.h"

CompeticaoSimples::CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m) : Competicao(nome, equipes, quantidade), modalidade(m)
{
    if(this->getQuantidadeDeEquipes() < 2){
        throw new invalid_argument("Numero de equipes invalido");
    }
}

CompeticaoSimples::~CompeticaoSimples()
{

}

Modalidade* CompeticaoSimples::getModalidade()
{
    return modalidade;
}


Tabela* CompeticaoSimples::getTabela()
{
    return modalidade->getTabela();
}

void CompeticaoSimples::imprimir()
{
    cout << this->getNome() << endl;
    modalidade->getTabela()->imprimir();
}
