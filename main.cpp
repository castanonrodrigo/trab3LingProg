#include <iostream>
#include "catalogo.h"
#include <string>
#include <vector>
using namespace std;
int main(){
  Filme f("asmosis Jones", "deconhecida", 10.0);
  Filme a("Osmosis Jones", "desconheida",5.5);
  Filme b("aaaaaa", "desconheida",5.5);
  Filme c;
  Catalogo catalog;
  catalog+= f;
  catalog+= a;
  vector<Filme> &filmes = catalog.getFilmes();
  catalog+= b;

  cout<<catalog;
  /* catalog-=b; */

  /* Filme a; */
  /* cout << "Insira parametros do filme na ordem: Nome Produtora Nota"<<endl; */
  /* cin>>a; */
  /* cout <<a<<endl; */
  return 1;
}
