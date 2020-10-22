#include <iostream>
#include "filme.h"
#include <string>
using namespace std;
int main(){
  Filme f("Asmosis Jones", "deconhecida", 10.0);
  Filme a("Asmosis Jones", "desconheida",5.5);
  cout << "Hello World"<<endl;
  cout <<f<<endl;
  if (a == f){
    cout<<"true"<<endl;
  }
  /* Filme a; */
  /* cout << "Insira parametros do filme na ordem: Nome Produtora Nota"<<endl; */
  /* cin>>a; */
  /* cout <<a<<endl; */
  return 1;
}
