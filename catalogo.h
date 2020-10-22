#include <vector>
#include <string>
#include "filme.h"

#ifndef CATALOGO_H
#define CATALOGO_H
using namespace std;
class Catalogo{
  public:
    Catalogo();
    vector<Filme> & getFilmes();
    void operator+=(const Filme &);
    void operator-=(const Filme &);

  private:
    //lista de filmes no catálogo
    vector<Filme> filmes;
    //numero max de filmes
    int maxFilmes;


};

#endif

