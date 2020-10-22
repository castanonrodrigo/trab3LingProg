#include <string>

#ifndef FILME_H
#define FILME_H
struct Filme{
  public:
  //construtor da struct filme
    Filme(std::string nome, std::string produtora, double nota);
  //retorna nome do filme
    std::string getNome() const;
  //retorna produtora do filme
    std::string getProdutora() const;
  //retorna nota do filme
    double getNota() const;
  private:
    std::string nome;
    std::string produtora;
    double nota;
};
#endif
