#include <string>

#include "filme.h"
using namespace std;

ostream &operator<<(ostream & output, const Filme & filme){
  output <<"Nome: "<<filme.nome<<endl
    <<"Produtora: "<<filme.produtora<<endl
    <<"Nota: "<<filme.nota<<endl;
  return output;
}

istream &operator>>(istream & input, Filme & filme){
  input >> filme.nome;
  input >> filme.produtora;
  input >> filme.nota;
  return input;
}

Filme::Filme(string nome, string produtora, double nota):nome(nome), produtora(produtora), nota(nota){};

string Filme::getNome() const {return nome;}
string Filme::getProdutora() const {return produtora;}
double Filme::getNota() const {return nota;}

bool Filme::operator<(const Filme & filmeRight)const {
  if (nome < filmeRight.nome){
    return true;
  }else{
    return false;
  }
}

bool Filme::operator>(const Filme & filmeRight)const {
  if (nome > filmeRight.nome){
    return true;
  }else{
    return false;
  }
}

bool Filme::operator==(const Filme & filmeRight)const {
  if (nome == filmeRight.nome){
    return true;
  }else{
    return false;
  }
}

