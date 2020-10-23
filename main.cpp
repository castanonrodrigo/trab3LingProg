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
  Filme d("Pequena Miss Sunshine", "Disney", 5.8);
  Filme e("Ozark", "Netflix", 6.9);
  Filme g("Fluminense", "Disney", 4.7);
  Catalogo catalog;
  catalog+= f;
  catalog+= a;
  vector<Filme> &filmes = catalog.getFilmes();
  catalog+= b;
  vector<Filme> vTest;
  vTest.push_back(d);
  vTest.push_back(e);
  vTest.push_back(g);
  /* catalog-=b; */

  /* Filme a; */
  /* cout << "Insira parametros do filme na ordem: Nome Produtora Nota"<<endl; */
  /* cin>>a; */
  /* cout <<a<<endl; */
  return 1;
}
