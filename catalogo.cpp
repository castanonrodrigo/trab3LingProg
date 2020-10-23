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

Filme *Catalogo::operator()(const string nome){
  for (int i = 0; i < filmes.size(); i++){
    if(filmes[i].getNome() == nome){
      return &filmes[i];
    }
  }
  return NULL;

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


