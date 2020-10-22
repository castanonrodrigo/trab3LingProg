#include <string>

#include "filme.h"
using namespace std;

Filme::Filme(string nome, string produtora, double nota):nome(nome), produtora(produtora), nota(nota){};

string Filme::getNome() const {return nome;}
string Filme::getProdutora() const {return produtora;}
double Filme::getNota() const {return nota;}
