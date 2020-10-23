#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include "catalogo.h"
#include <limits>
#include <string>
#include <vector>
#include <stdlib.h>
#include <ios>
#include <limits>
using namespace std;
int selectInputOption(){
  int digito;
  cout << "---------------" << "Menu do Programa" << "--------------"<< endl;
  cout << "Para inserir um filme - Digite 1" <<endl;
  cout << "Para remover um filme - Digite 2" <<endl;
  cout << "Para buscar um filme - Digite 3" <<endl;
  cout << "Para editar a produtora de um filme - Digite 4" <<endl;
  cout << "Para editar a nota de um filme - Digite 5" <<endl;
  cout << "Para exibir a lista de filmes - Digite 6" <<endl;
  cout << "Para finalizar o programa - Digite -1" <<endl;
  cin >> digito;
  if (digito < -1 || digito > 6){
    cout << "Opcao nao existente!"<<endl;
    selectInputOption();
  }
  return digito;
};

void inserirFilmeMenu(vector<Filme> &filmesTmp){
  int opcao1;
  cout << "--------------"<<" INSERIR FILME "<<"------------------"<<endl;
  cout<<"Para retornar ao menu inicial - Digite -1"<<endl;
  cout<<"Para inserir um filme - Digite 1"<<endl;
  cin>>opcao1;
  if(opcao1 < -1 || opcao1 > 1){
    cout<<"opcao invalida!"<<endl;
    inserirFilmeMenu(filmesTmp);
  }else{
    switch (opcao1) {
      case -1:
        return;
      case 1:
        {
          cout<<"Digite os dados do filme no seguinte padrao:"<<endl;
          cout<<"<Nome><ENTER>"<<endl;
          cout<<"<Produtora><ENTER>"<<endl;
          cout<<"<Nota><ENTER>"<<endl;
          Filme fTemp;
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
          cin>>fTemp;
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
          filmesTmp.push_back(fTemp);
          inserirFilmeMenu(filmesTmp);
        }
    }
  }

}
int main(){
  enum opcoesMenuPrincipal{
    FinalizarPrograma = -1,
    InserirFilme = 1,
    RemoverFilme = 2,
    BuscarFilme = 3,
    EditarProdutora = 4,
    EditarNota = 5,
    ExibirFilmes = 6,
  };
  Catalogo catalog;
  vector<Filme> &filmes = catalog.getFilmes();
  ifstream MyReadFile("database.txt");
  if (MyReadFile.is_open() == true){
    catalog.recoverFromDataBase(MyReadFile);
    MyReadFile.close();
  }
  else {
    cout<<"arquivo não existia"<<endl;
    ofstream MyWriteFile("database.txt");
    MyWriteFile <<catalog;
    MyWriteFile.close();
  }
  int inputOption;
  while(inputOption != -1){
    cout<<"dentro do while"<<endl;
    inputOption = selectInputOption();
    switch (inputOption) {
      case FinalizarPrograma:
        {
          ofstream MyWriteFile("database.txt");
          MyWriteFile<<catalog;
          MyWriteFile.close();
        }
        break;
      case InserirFilme:
        {
          vector<Filme> filmesTmp;
          inserirFilmeMenu(filmesTmp);
          if(filmesTmp.size()>0){
            catalog.insereOrdenaVector(filmesTmp);
          }
        }
        break;
      case 5:
        cout<<"editar nota"<<endl;
        break;
      case 6:
        cout<<catalog;
        break;
      default:
        cout << "Para sair do programa - Digite -1" << endl;
        cout << "Para retornar ao menu - Digite qualquer numero" << endl;
        cin >> inputOption;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cout << "Para sair do programa - Digite -1" << endl;
    cout << "Para retornar ao menu - Digite qualquer numero" << endl;
    cin >> inputOption;
  }
  return 1;
}
