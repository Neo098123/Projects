#include "Competicao.h"
#include "CompeticaoMultimodalidades.h"
#include "CompeticaoSimples.h"
#include "Competicao.h"
#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"
#include "TabelaComOrdem.h"
#include "TabelaComPontos.h"
#include <stdexcept>
#include <vector>
#include <list>
#include <algorithm>
#include <stdio.h>
#include <fstream>
#ifndef PERSISTENCIADECOMPETICAO_H
#define PERSISTENCIADECOMPETICAO_H

using namespace std;

class PersistenciaDeCompeticao
{
    public:
        PersistenciaDeCompeticao();
        virtual ~PersistenciaDeCompeticao();
        Competicao* carregar(string arquivo);
        void salvar(string arquivo, Competicao* c);

    protected:

    private:
};

#endif // PERSISTENCIADECOMPETICAO_H
