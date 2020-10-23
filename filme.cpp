#include <cctype>
#include <string>
#include <algorithm>

#include "filme.h"
using namespace std;

ostream &operator<<(ostream & output, const Filme & filme){
  output <<"Nome: "<<filme.nome<<endl
    <<"Produtora: "<<filme.produtora<<endl
    <<"Nota: "<<filme.nota<<endl;
  return output;
}

istream &operator>>(istream & input, Filme & filme){
  getline(input, filme.nome);
  getline(input, filme.produtora);
  input >> filme.nota;
  return input;
}

Filme::Filme(string nome, string produtora, double nota):nome(nome), produtora(produtora), nota(nota){};

string Filme::getNome() const {return nome;}
string Filme::getProdutora() const {return produtora;}
double Filme::getNota() const {return nota;}

bool Filme::operator<(const Filme & filmeRight)const {
  if (toLowerCase(nome) < toLowerCase(filmeRight.nome)){
    return true;
  }else{
    return false;
  }
}

bool Filme::operator>(const Filme & filmeRight)const {
  if (toLowerCase(nome) > toLowerCase(filmeRight.nome)){
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


string Filme::toLowerCase(const string s) const{
  string result;
  for (int i = 0; i < s.length();i++){
    result += tolower(s[i]);
  }
  return result;
}
