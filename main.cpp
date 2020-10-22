#include <iostream>
#include "filme.h"
using namespace std;
int main(){
  Filme f("Osmosis Jones", "deconhecida", 10.0);
  cout << "Hello World"<<endl;
  cout <<f.getNome()<<endl;
  return 1;
}
