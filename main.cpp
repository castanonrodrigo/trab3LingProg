#include "catalogo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
  cout << "Para exibir o filme com maior nota - Digite 7" <<endl;
  cout << "Para finalizar o programa - Digite -1" <<endl;
  cin >> digito;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  if (digito < -1 || digito > 7 || !cin.good()){
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
  if ( !(cin>>opcao1) ){
    cin.clear();
  }
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
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
    ExibirMaiorNota = 7,
  };
  Catalogo catalog;
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
  int inputOption = 0;
  while(inputOption != -1){
    inputOption = selectInputOption();
    switch (inputOption) {
      case FinalizarPrograma:
        {
          cout<<"dados salvos no arquivo database.txt"<<endl;
          ofstream MyWriteFile("database.txt");
          MyWriteFile<<catalog;
          MyWriteFile.close();
        }
        return 1;
      case InserirFilme:
        {
          vector<Filme> filmesTmp;
          inserirFilmeMenu(filmesTmp);
          if(filmesTmp.size()>0){
            catalog.insereOrdenaVector(filmesTmp);
          }
        }
        break;
      case RemoverFilme:
        {
          string n;
          cout<<"Insira o nome do filme a ser removido:"<<endl;
          getline(cin,n);
          catalog-=n;
          break;
        }
      case BuscarFilme:
        {
          string n;
          cout<<"Insira nome do filme a ser buscado:"<<endl;
          getline(cin, n);
          Filme *ptr;
          ptr = catalog(n);
          if(ptr == NULL){
            cout<<"filme nao encontrado!"<<endl;
          }else{
            cout<<*ptr;
          }
        }
        break;
      case EditarProdutora:
        {
          string n;
          string p;
          cout<<"Insira o nome do filme a ser editado:"<<endl;
          getline(cin, n);
          cout<<"Insira o novo nome da produtora:"<<endl;
          getline(cin, p);
          catalog(n,p);
        }
        break;
      case EditarNota:
        {
          string n;
          string notaString;
          double nota;
          cout<<"Insira o nome do filme a ser editado:"<<endl;
          getline(cin, n);
          cout<<"Insira a nova nota do filme:"<<endl;
          cin>>notaString;
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
          nota = stod(notaString);
          catalog(n,nota);
          break;
        }
      case ExibirFilmes:
        cout<<catalog;
        break;
      case ExibirMaiorNota:
        catalog.printMaiorNota();
        break;
      default:
        cout<<"entrando aqui"<<endl;
        cout << "Para sair do programa - Digite -1" << endl;
        cout << "Para retornar ao menu - Digite qualquer numero" << endl;
        cin >> inputOption;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cout << "Para sair do programa - Digite -1" << endl;
    cout << "Para retornar ao menu - Digite qualquer numero" << endl;
    cin >> inputOption;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
  }
  cout<<"dados salvos no arquivo database.txt"<<endl;
  ofstream MyWriteFile("database.txt");
  MyWriteFile<<catalog;
  MyWriteFile.close();
  return 1;
}
