#include <vector>
#include <string>
#include "filme.h"

#ifndef CATALOGO_H
#define CATALOGO_H
using namespace std;
class Catalogo{
  friend ostream &operator<<(ostream&, const Catalogo &);
  public:
    Catalogo();
    vector<Filme> & getFilmes();
    void operator+=(const Filme &);
    void operator-=(const Filme &);
    void insereOrdenaVector(vector<Filme>&);
    void recoverFromDataBase(ifstream &);
    void printMaiorNota()const;
    Filme *operator()(const string);
    Filme *operator()(const string, const string);
    Filme *operator()(const string, const double);

  private:
    //lista de filmes no catálogo
    vector<Filme> filmes;
};

#endif

