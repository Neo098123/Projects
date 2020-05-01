#include "Competicao.h"
#include "TabelaComPontos.h"
#include "TabelaComOrdem.h"
#include <list>
#include <vector>
#include <algorithm>
#ifndef COMPETICAOMULTIMODALIDADES_H
#define COMPETICAOMULTIMODALIDADES_H

using namespace std;

class CompeticaoMultimodalidades : public Competicao
{
    public:
        CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade);
        virtual ~CompeticaoMultimodalidades();
        void adicionar(Modalidade* m);
        list<Modalidade*>* getModalidades();
        static void setPontuacao(vector<int>* pontos);
        static int getPontoPorPosicao(int posicao);
        static vector<int>* pontuacao;
        Tabela* getTabela();
        void imprimir();

    private:
        list<Modalidade*>* modalidades;
        TabelaComPontos* tabela;

};

#endif // COMPETICAOMULTIMODALIDADES_H
