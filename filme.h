
#ifndef FILME_H
#define FILME_H
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
struct Filme{
  friend ostream &operator<<(ostream&, const Filme &);
  friend istream &operator>>(istream&, Filme &);
  public:
  //construtor da struct filme
    Filme(string nome = "", string produtora ="", double nota = 0.0);
  //retorna nome do filme
    string getNome() const;
  //retorna produtora do filme
    string getProdutora() const;
  //altera nome da produtora
    void setProdutora(const string);
  //retorna nota do filme
    double getNota() const;
  //altera valor da nota do filme
    void setNota(const double);

    bool operator<(const Filme &) const;
    bool operator>(const Filme &) const;
    bool operator==(const Filme &) const;
  private:
    string nome;
    string produtora;
    double nota;
    string toLowerCase(const string) const;
};
#endif
