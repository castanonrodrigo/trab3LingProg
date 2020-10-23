#include "catalogo.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>


Catalogo::Catalogo(){};

ostream &operator<<(ostream & output, const Catalogo & catalogo){
  for (int i=0; i<catalogo.filmes.size();i++){
    output<<catalogo.filmes[i]<<endl;
  }
  return output;
}
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

void Catalogo::insereOrdenaVector(vector<Filme> &vectorFilmes){
  for (int i = 0; i < vectorFilmes.size(); i++){
    (*this)+=vectorFilmes[i];
  }
  vectorFilmes.clear();
}
Filme *Catalogo::operator()(const string nome){
  for (int i = 0; i < filmes.size(); i++){
    if(filmes[i].getNome() == nome){
      return &filmes[i];
    }
  }
  return NULL;
}

void Catalogo::recoverFromDataBase(ifstream &file){
  string nomeTmp;
  string produtoraTmp;
  double notaTmp;
  int i = 0;
  string line;
  while (getline(file, line)) {
    line.erase(line.begin(),line.begin() + line.find_first_of(" ") + 1);
    if(line != ""){
      switch (i) {
        case 0:
          nomeTmp = line;
          i++;
          break;
        case 1:
          produtoraTmp = line;
          i++;
          break;
        case 2:
          notaTmp = stod(line);
          Filme tmp(nomeTmp, produtoraTmp, notaTmp);
          cout<<"adicionando: "<< tmp.getNome()<<endl;
          (*this)+=tmp;
          i = 0;
      }
    }
  }
}

Filme *Catalogo::operator()(const string nome, const string novaProdutora){
  Filme *ptr = (*this)(nome);
  if (ptr != NULL){
    ptr->setProdutora(novaProdutora);
    return ptr;
  }else{
    cout<<"Filme "<<nome <<"nao encontrado"<<endl;
    return NULL;
  }
}

Filme *Catalogo::operator()(const string nome, const double novaNota){
  Filme *ptr = (*this)(nome);
  if (ptr != NULL){
    ptr->setNota(novaNota);
    return ptr;
  }else{
    cout<<"Filme "<<nome <<"nao encontrado"<<endl;
    return NULL;
  }
}



