#include "Competicao.h"
#ifndef COMPETICAOSIMPLES_H
#define COMPETICAOSIMPLES_H

using namespace std;

class CompeticaoSimples : public Competicao
{
    public:
        CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m);
        virtual ~CompeticaoSimples();
        Modalidade* getModalidade();
        Tabela* getTabela();
        void imprimir();

    private:
        Modalidade* modalidade;
};

#endif // COMPETICAOSIMPLES_H
