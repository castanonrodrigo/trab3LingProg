#include "catalogo.h"

Catalogo::Catalogo(){};

vector<Filme> &Catalogo::getFilmes(){
  return filmes;
}
void Catalogo::operator+=(const Filme & filme){
  for(int i = 0; i < filmes.size(); i++){
    if(filme == filmes[i]){
      cout << "O filme "<<filme.getNome()<< " ja existe na lista"<<endl;
      return;
    }
    if(filme < filmes[i]){
      filmes.insert(filmes.begin() + i, filme);
      return;
    }
  }
  filmes.push_back(filme);
}

void Catalogo::operator-=(const Filme & filme){
  for(int i = 0; i < filmes.size(); i++){
    if (filme == filmes[i]){
      filmes.erase(filmes.begin() + i);
      cout << "Filme " << filme.getNome() << " apagado"<<endl;
      return;
    }
  }
  cout<< "Filme " << filme.getNome()<< " nao foi encontrado"<<endl;
}
