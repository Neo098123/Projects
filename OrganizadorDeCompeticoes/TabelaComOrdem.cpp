#include "TabelaComOrdem.h"

TabelaComOrdem::TabelaComOrdem(Equipe** participantes, int quantidade):Tabela(participantes,quantidade)
{

}

TabelaComOrdem::~TabelaComOrdem()
{

}

int TabelaComOrdem::getPosicao(Equipe* participante)
{
    int i;
    if(ordem == NULL)
        throw new logic_error("Resultado n definido");
    for(i=0; (ordem[i]->getNome() != participante->getNome()) && (i < quantidade); i++)
    {
    }
    if(i == quantidade)
        throw new invalid_argument("Participante n encontrado");
    return i + 1;
}

void TabelaComOrdem::setResultado(Equipe** ordem)
{
    this->ordem = ordem;
}

Equipe** TabelaComOrdem::getEquipesEmOrdem()
{
    return this->ordem;
}

void TabelaComOrdem::imprimir()
{
    if(ordem != NULL)
    {
        for(int i=0; i<quantidade; i++)
        {
            cout << "\t" << this->getPosicao(getEquipesEmOrdem()[i]) << "o " << getEquipesEmOrdem()[i]->getNome() << endl;
        }
    }
    else
    {
        for(int i=0; i<quantidade; i++)
        {
            cout << "\t" << participantes[i]->getNome() << endl;
        }
    }
}
