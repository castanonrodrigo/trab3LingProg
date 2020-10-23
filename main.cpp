#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include "catalogo.h"
#include <string>
#include <vector>
#include <stdlib.h>
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
  vector<Filme> &filmes = catalog.getFilmes();
  vector<Filme> vTest;
  vTest.push_back(d);
  vTest.push_back(e);
  vTest.push_back(g);
  ifstream MyReadFile("database.txt");
  string line;
  if (MyReadFile.is_open() == true){
    catalog.recoverFromDataBase(MyReadFile);
    MyReadFile.close();
    /* string nomeTmp; */
    /* string produtoraTmp; */
    /* double notaTmp; */
    /* vector<Filme> vTemp; */
    /* int i = 0; */
    /* while (getline(MyReadFile, line)) { */
    /*   line.erase(line.begin(),line.begin() + line.find_first_of(" ") + 1); */
    /*   if(line != ""){ */
    /*     switch (i) { */
    /*       case 0: */
    /*         nomeTmp = line; */
    /*         i++; */
    /*         break; */
    /*       case 1: */
    /*         produtoraTmp = line; */
    /*         i++; */
    /*         break; */
    /*       case 2: */
    /*         notaTmp = stod(line); */
    /*         Filme tmp(nomeTmp, produtoraTmp, notaTmp); */
    /*         vTemp.push_back(tmp); */
    /*         i = 0; */
    /*     } */
    /*   } */
    /* } */
    /* for (Filme f:vTemp){ */
    /*   cout<<f.getNome()<<endl; */
    /* } */
  }else {
    cout<<"arquivo não existia"<<endl;
    ofstream MyWriteFile("database.txt");
    MyWriteFile <<catalog;
    MyWriteFile.close();
  }
  MyReadFile.close();
  /* catalog-=b; */

  cout << "MEU CATALOGO"<<endl;
  cout << catalog<<endl;
  /* Filme a; */
  /* cout << "Insira parametros do filme na ordem: Nome Produtora Nota"<<endl; */
  /* cin>>a; */
  /* cout <<a<<endl; */
  return 1;
}
