#include <iostream>
#include "Competicao.h"
#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"
#include "CompeticaoSimples.h"
#include "CompeticaoMultimodalidades.h"
#include "TabelaComOrdem.h"
#include "TabelaComPontos.h"
#include "PersistenciaDeCompeticao.h"


using namespace std;

int main () {
    char carregar;
    cout << "Deseja carregar uma competicao? (s/n) ";
    cin >> carregar;
    cout << endl;

    if(carregar == 's') {
        cout << "Digite o nome do arquivo: ";
        string nome;
        cin >> nome;
        cout << endl;

        PersistenciaDeCompeticao* persistencia = new PersistenciaDeCompeticao();
        Competicao* competicao = persistencia->carregar(nome);
        CompeticaoSimples* compSimples = dynamic_cast<CompeticaoSimples*>(competicao);
        if(compSimples == NULL){
            CompeticaoMultimodalidades* compMulti = dynamic_cast<CompeticaoMultimodalidades*>(competicao);
            compMulti->imprimir();
        }
        else
            compSimples->imprimir();
    }

    else if(carregar == 'n') {
        cout << "Informe a quantidade de equipes: ";
        int quantidadeDeEquipes;
        cin >> quantidadeDeEquipes;
        cout << endl;

        Equipe** equipes = new Equipe*[quantidadeDeEquipes];
        for(int i = 0; i < quantidadeDeEquipes; i++) {
            cout << "Informe o nome da equipe " << i + 1 << ":";
            string nomeDaEquipe;
            cin >> nomeDaEquipe;
            equipes[i] = new Equipe(nomeDaEquipe);
            cout << endl;
        }

        cout << "Informe o nome da competicao: ";
        string nomeDaCompeticao;
        cin >> nomeDaCompeticao;
        cout << endl;

        cout << "Competicao simples (s) ou multimodalidades (m): ";
        char categoriaDaCompeticao;
        cin >> categoriaDaCompeticao;
        cout << endl;

        if(categoriaDaCompeticao == 's') {
            cout << "Informe o nome da modalidade: ";
            string nomeDaModalidade;
            cin >> nomeDaModalidade;
            Modalidade* modalidade = new Modalidade(nomeDaModalidade, equipes, quantidadeDeEquipes);
            cout << endl;

            cout << "Tem resultado (s/n): ";
            char resultado;
            cin >> resultado;
            cout << endl;

            if(resultado == 's') {
                Equipe** colocacao = new Equipe*[quantidadeDeEquipes];
                for (int i = 0; i < quantidadeDeEquipes; i++) {
                    cout << "Informe a equipe " << i + 1 << "a colocada: ";
                    string nomeDaEquipe;
                    cin >> nomeDaEquipe;
                    colocacao[i] = new Equipe(nomeDaEquipe);
                }
                modalidade->setResultado(colocacao);
            }
            cout << "Deseja salvar a competicao (s/n)? ";
            char salvar;
            cin >> salvar;
            cout << endl;
            CompeticaoSimples* cs = new CompeticaoSimples(nomeDaCompeticao, equipes, quantidadeDeEquipes, modalidade);

            if(salvar == 's') {
                cout << "Digite o nome do arquivo: ";
                string nomeDoArquivo;
                cin >> nomeDoArquivo;
                cout << endl;
                PersistenciaDeCompeticao* persistencia = new PersistenciaDeCompeticao();
                persistencia->salvar(nomeDoArquivo, cs);
            }
            cs->imprimir();
        }

        else {
            cout << "Informe a quantidade de modalidades: ";
            int quantidadeDeModalidades;
            cin >> quantidadeDeModalidades;
            cout << endl;

            Modalidade** modalidades = new Modalidade*[quantidadeDeModalidades];
            for(int i = 0; i < quantidadeDeModalidades; i++) {
                cout << "Informe o nome da modalidade " << i + 1 << ": ";
                string nomeDaModalidade;
                cin >> nomeDaModalidade;
                cout << endl;
                modalidades[i] = new Modalidade(nomeDaModalidade, equipes, quantidadeDeEquipes);

                cout << "Tem resultado (s/n): ";
                char resultado;
                cin >> resultado;
                cout << endl;

                if(resultado == 's') {
                    Equipe** colocacao = new Equipe*[quantidadeDeEquipes];
                    for(int j = 0; j < quantidadeDeEquipes; j++) {
                        cout << "Informe a equipe " << j + 1<< "a colocada: ";
                        string nomeDaEquipe;
                        cin >> nomeDaEquipe;
                        cout << endl;
                        colocacao[j] = new Equipe(nomeDaEquipe);
                    }
                    modalidades[i]->setResultado(colocacao);
                }
            }
            cout << "Deseja salvar a competicao (s/n)? ";
            char salvar;
            cin >> salvar;
            cout << endl;
            CompeticaoMultimodalidades* cm = new CompeticaoMultimodalidades(nomeDaCompeticao, equipes, quantidadeDeEquipes);
            for(int i=0; i<quantidadeDeModalidades; i++){
                cm->adicionar(modalidades[i]);
            }
            if(salvar == 's') {
                cout << "Digite o nome do arquivo: ";
                string nomeDoArquivo;
                cin >> nomeDoArquivo;
                cout << endl;

                PersistenciaDeCompeticao* persistencia = new PersistenciaDeCompeticao();
                persistencia->salvar(nomeDoArquivo, cm);
            }
            cm->imprimir();
        }
    }
}
