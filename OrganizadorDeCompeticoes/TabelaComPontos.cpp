#include "TabelaComPontos.h"

TabelaComPontos::TabelaComPontos(Equipe** participantes, int quantidade) : Tabela(participantes, quantidade)
{
    pontos = new int[quantidade];
    ordem = new Equipe*[quantidade];
    for(int i = 0; i < quantidade ; i++)
    {
        pontos[i] = 0;
    }
}

TabelaComPontos::~TabelaComPontos()
{

}

int TabelaComPontos::getPontos(Equipe* participante)
{
    int i;
    for(i = 0; (this->participantes[i] != participante) && (i < this->getQuantidadeDeEquipes()); i++) {}
    if (i == quantidade)
        throw new invalid_argument("Equipe n encontrada");
    return pontos[i];
}


void TabelaComPontos::pontuar(Equipe* participante, int pontos)
{

    int i;
    for(i = 0; (this->participantes[i]->getNome() != participante->getNome()) && (i < this->quantidade); i++)
    {
    }
    if (i < quantidade)
    {
        this->pontos[i] += pontos;
    }
    else
        throw new invalid_argument("Equipe n encontrada");
}

int TabelaComPontos::getPosicao(Equipe* participante)
{
    int posicao = 1;
    int i=0,j=0;
    for(i = 0; i < quantidade; i++)
    {
        if(pontos[i] == 0)
        {
            j++;
        }
    }
    if(j == i)
        throw new logic_error("Resultado n definido");
    for(i = 0; (participantes[i]->getNome() != participante->getNome()) && (i < quantidade); i++)
    {
    }
    if (i == quantidade)
        throw new invalid_argument("Participante n encontrado");
    for (j = 0; j < quantidade; j++)
    {
        if (pontos[i] < pontos[j])
            posicao++;
    }
    return posicao;
}

Equipe** TabelaComPontos::getEquipesEmOrdem()
{
    int posicao=0;
    int* repetidos = new int[this->getQuantidadeDeEquipes()];
    for(int i = 0; i < this->getQuantidadeDeEquipes(); i++){
        repetidos[i] = 0;
    }
    this->ordem = new Equipe*[this->getQuantidadeDeEquipes()];
    for(int i = 0; i < this->getQuantidadeDeEquipes(); i++)
    {
        posicao = (this->getPosicao(participantes[i])) - 1;
        ordem[posicao + repetidos[posicao]] = participantes[i];
        repetidos[posicao]++;
    }
    return ordem;
}

void TabelaComPontos::imprimir()
{
    int zeros=0;
    for (int i=0; i<quantidade; i++)
    {
        if(this->pontos[i] == 0)
        {
            zeros++;
        }
    }
    if(zeros == quantidade)
    {
        for(int i=0; i<quantidade; i++)
        {
            cout << "\t" << participantes[i]->getNome() << endl;
        }
    }
    else
    {
        for(int i=0; i<quantidade; i++)
        {
            cout << "\t" << this->getPosicao(getEquipesEmOrdem()[i]) << "o " << this->getEquipesEmOrdem()[i]->getNome() << " (" << getPontos(this->getEquipesEmOrdem()[i]) << " pontos)" <<endl;
        }
    }
}
