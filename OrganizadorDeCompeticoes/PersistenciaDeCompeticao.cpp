#include "PersistenciaDeCompeticao.h"

PersistenciaDeCompeticao::PersistenciaDeCompeticao()
{

}

PersistenciaDeCompeticao::~PersistenciaDeCompeticao()
{

}

Competicao* PersistenciaDeCompeticao::carregar(string arquivo)
{
    ifstream entrada;
    entrada.open(arquivo);
    if (entrada.fail())
    {
        entrada.close();
        throw new invalid_argument("Aquivo nao encontrado");
    }
    Competicao* c;
    int quantidadeDeEquipes;
    string nomeDaCompeticao;
    while(entrada)
    {
        entrada >> quantidadeDeEquipes;
        Equipe** equipes = new Equipe*[quantidadeDeEquipes];
        for(int i=0; i<quantidadeDeEquipes; i++)
        {
            string nomeDaEquipe;
            entrada >> nomeDaEquipe;
            equipes[i] = new Equipe(nomeDaEquipe);
        }
        entrada >> nomeDaCompeticao;
        bool tipo;
        entrada >> tipo;
        if(tipo)
        {
            int numeroDeModalidades;
            entrada >> numeroDeModalidades;
            CompeticaoMultimodalidades* competicaoMulti = new CompeticaoMultimodalidades(nomeDaCompeticao, equipes,
                    quantidadeDeEquipes);
            for(int i=0; i<numeroDeModalidades; i++)
            {
                string nomeDaModalidade;
                entrada >> nomeDaModalidade;
                bool temResultado;
                entrada >> temResultado;
                int quantidadeDeParticipantes;
                entrada >> quantidadeDeParticipantes;
                Equipe** participantesDaModalidade = new Equipe*[quantidadeDeParticipantes];
                for(int j=0; j<quantidadeDeParticipantes; j++)
                {
                    string nomeDaEquipe;
                    entrada >> nomeDaEquipe;
                    participantesDaModalidade[j] = new Equipe(nomeDaEquipe);
                }
                Modalidade* m = new Modalidade(nomeDaModalidade, participantesDaModalidade, quantidadeDeParticipantes);
                if(temResultado)
                {
                    m->setResultado(participantesDaModalidade);
                }
                competicaoMulti->adicionar(m);
            }
            c = competicaoMulti;
            string nada;
            while(entrada){
                entrada >> nada;
            }
        }
        else
        {
            string nomeDaModalidade;
            entrada >> nomeDaModalidade;
            bool temResultado;
            entrada >> temResultado;
            int quantidadeDeParticipantes;
            entrada >> quantidadeDeParticipantes;
            Equipe** participantesDaModalidade = new Equipe*[quantidadeDeParticipantes];
            string nomeDaEquipe;
            int j;
            for(j=0; j<quantidadeDeParticipantes; j++)
            {
                entrada >> nomeDaEquipe;
                Equipe* team = new Equipe(nomeDaEquipe);
                participantesDaModalidade[j] = team;
            }
            Modalidade* m = new Modalidade(nomeDaModalidade, participantesDaModalidade, quantidadeDeParticipantes);
            CompeticaoSimples* competicaoSimples = new CompeticaoSimples(nomeDaCompeticao, equipes,
                    quantidadeDeEquipes, m);
            if(temResultado)
            {
                competicaoSimples->getModalidade()->setResultado(participantesDaModalidade);
            }
            c = competicaoSimples;
            string nada;
            while(entrada){
                entrada >> nada;
            }
        }
    }
    if(!entrada.eof())
    {
        entrada.close();
        throw new invalid_argument("Formatacao invalida");
    }
    return c;
}

void PersistenciaDeCompeticao::salvar(string arquivo, Competicao* c)
{
    ofstream saida;
    saida.open(arquivo, ios_base::app);
    saida << c->getQuantidadeDeEquipes() << endl;
    for(int i=0; i<c->getQuantidadeDeEquipes(); i++)
    {
        saida << c->getEquipes()[i]->getNome() << endl;
    }
    saida << c->getNome() << endl;
    CompeticaoSimples* cs = dynamic_cast<CompeticaoSimples*>(c);
    if(cs == NULL)
    {
        CompeticaoMultimodalidades* cm = dynamic_cast<CompeticaoMultimodalidades*>(c);
        saida << 1 << endl;
        saida << cm->getModalidades()->size() << endl;
        list<Modalidade*>::iterator i = cm->getModalidades()->begin();
        while(i != cm->getModalidades()->end())
        {
            saida << (*i)->getNome() << endl;
            if((*i)->temResultado())
            {
                saida << 1 << endl;
                saida << (*i)->getQuantidadeDeEquipes() << endl;
                for(int k=0; k < (*i)->getQuantidadeDeEquipes(); k++)
                {
                    saida << (*i)->getTabela()->getEquipesEmOrdem()[k]->getNome() << endl;

                }
            }
            else
            {
                saida << 0 << endl;
                saida << (*i)->getQuantidadeDeEquipes() << endl;
                for(int k=0; k < (*i)->getQuantidadeDeEquipes(); k++)
                {
                    saida << (*i)->getEquipes()[k]->getNome() << endl;
                }
            }
            i++;
        }
    }
    else
    {
        saida << 0 << endl;
        saida << cs->getModalidade()->getNome() << endl;
        if(cs->getModalidade()->temResultado())
        {
            saida << 1 << endl;
            saida << cs->getModalidade()->getQuantidadeDeEquipes() << endl;
            for(int k=0; k < cs->getModalidade()->getQuantidadeDeEquipes(); k++)
            {
                saida << cs->getModalidade()->getTabela()->getEquipesEmOrdem()[k]->getNome() << endl;

            }
        }
        else
        {
            saida << 0 << endl;
            saida << cs->getModalidade()->getQuantidadeDeEquipes() << endl;
            for(int k=0; k<cs->getModalidade()->getQuantidadeDeEquipes(); k++)
            {
                saida << cs->getModalidade()->getEquipes()[k]->getNome() << endl;
            }
        }
    }
}
