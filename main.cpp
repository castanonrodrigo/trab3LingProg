#include <iostream>
/* #include "filme.h" */
#include "catalogo.h"
#include <string>
#include <vector>
using namespace std;
int main(){
  Filme f("Asmosis Jones", "deconhecida", 10.0);
  Filme a("Osmosis Jones", "desconheida",5.5);
  Catalogo catalog;
  catalog+= f;
  catalog+= a;
  vector<Filme> filmes = catalog.getFilmes();
  for (Filme f:filmes){
    cout<<f.getNome()<<endl;
  }

  /* Filme a; */
  /* cout << "Insira parametros do filme na ordem: Nome Produtora Nota"<<endl; */
  /* cin>>a; */
  /* cout <<a<<endl; */
  return 1;
}
