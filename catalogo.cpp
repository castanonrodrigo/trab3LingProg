#include "catalogo.h"

Catalogo::Catalogo(){};

vector<Filme> &Catalogo::getFilmes(){
  return filmes;
}
void Catalogo::operator+=(const Filme & filme){
  for(int i = 0; i < filmes.size(); i++){
    if(filme < filmes[i]){
      filmes.insert(filmes.begin() + i, filme);
      break;
    }
  }
  filmes.push_back(filme);
}
