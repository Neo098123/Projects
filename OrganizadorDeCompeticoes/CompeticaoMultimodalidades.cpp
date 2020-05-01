#include "CompeticaoMultimodalidades.h"


CompeticaoMultimodalidades::CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade): Competicao(nome, equipes, quantidade)
{

    if(this->getQuantidadeDeEquipes() < 2)
    {
        throw new invalid_argument("Numero de equipes invalido");
    }
    this->modalidades = new list<Modalidade*>();
    tabela = new TabelaComPontos(equipes, quantidade);
}

CompeticaoMultimodalidades::~CompeticaoMultimodalidades()
{

};

vector<int>* CompeticaoMultimodalidades::pontuacao = new vector<int>({13, 10, 8, 7, 5, 4, 3, 2, 1});

void CompeticaoMultimodalidades::adicionar(Modalidade* m)
{
    modalidades->push_back(m);
};

list<Modalidade*>* CompeticaoMultimodalidades::getModalidades()
{
    return this->modalidades;
}

void CompeticaoMultimodalidades::setPontuacao(vector<int>* pontos)
{

    int quantidadeDePosicoes = 0;
    vector<int>::iterator i = pontos->begin();
    while(i != pontos->end())
    {
        quantidadeDePosicoes++;
        i++;
    }
    if(quantidadeDePosicoes < 3)
        throw new invalid_argument("necessario pelo menos 3 valores para o vetor");
    else
    {
        while (!pontuacao->empty())
        {
            pontuacao->pop_back();
        }
        pontuacao = pontos;
    }
};

int CompeticaoMultimodalidades::getPontoPorPosicao(int posicao)
{
    if(posicao <= CompeticaoMultimodalidades::pontuacao->size()){
        return (*pontuacao)[posicao - 1];
    }
    else
        return 0;
}

Tabela* CompeticaoMultimodalidades::getTabela()
{
    list<Modalidade*>::iterator i = this->getModalidades()->begin();
    while(i != this->getModalidades()->end())
    {
        if((*i)->temResultado())
        {
            for(int j=0; j < (*i)->getQuantidadeDeEquipes(); j++)
            {
                tabela->pontuar(((*i)->getEquipes())[j], getPontoPorPosicao((*i)->getTabela()->getPosicao(((*i)->getEquipes())[j])));
            }
        }
        i++;
    }
    return tabela;
}

void CompeticaoMultimodalidades::imprimir()
{
    cout << this->getNome() << endl;
    if(this->getModalidades()->size() != 0)
    {
        (dynamic_cast<TabelaComPontos*>(this->getTabela()))->imprimir();
    }
}

