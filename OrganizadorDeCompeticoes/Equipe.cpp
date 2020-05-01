#include "Equipe.h"

Equipe::Equipe(string nome)
{
    this->nome = nome;
}

Equipe::~Equipe()
{
}

string Equipe::getNome()
{
    return nome;
}

void Equipe::imprimir()
{
    cout << "Equipe " << nome << endl;
}
