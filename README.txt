Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Engenharia Eletronica e de Computacao
Programa: Exercicio Avaliado 3 - EEL670 - Linguagens de Programacao
Autor:Rodrigo Castanon de Carvalho

Descricao Geral:
  *O programa consiste em um catalogo de filmes com persistencia de dados em um arquivo txt
  *Sao armazenadas as seguintes informacoes de um filme: nome, produtora, nota
  *Sao permitidas as seguintes operacoes:insercao, remocao, busca e edicao de filme, visualizacao de todos os filmes e visualizacao do filme com maior nota

Gerar Executavel:
  *Para gerar o executavel do programa basta rodar o comando "make" na pasta do projeto

Guia de uso:
  *somente numeros devem ser utilizados para a navegacao nos menus.
  *apos a execucao de um comando do menu, eh necessario apertar um numero qualquer(diferente de -1) para voltar ao menu
  *os dados serao persistidos sempre em um arquivo chamado "database.txt".
  *o arquivo "database.txt" pode ser criado previamente pelo usuario caso ele deseje carregar filmes inicias no programa. Para tal, basta utilizar o modelo:
    Nome: <nome_do_filme>
    Produtora: <nome_da_produtora>
    Nota: <nota_do_filme>
  *para que os dados sejam salvos corretamente, eh necessario que o programa seja finalizado por seu menu(utilizar Ctrl-C acarreta em perda de dados)

  INSERIR FILME:
    *apos selecionar essa opcao no menu inicial, sera mostrado o menu de inserir filme
    *no menu de inserir filme, deve ser apertado 1 novamente para continuar com a insercao ou -1 para voltar
    *os dados do filme devem ser inseridos com uma quebra de linha entre cada um de seus campos(nome, produtora, nota), da seguinte forma:
      <nome><Enter>
      <produtora><Enter>
      <nota><Enter>
    *apos a insercao de um filme, pode-se escolher entre continuar inserindo filmes ou voltar para o menu inicial

  REMOVER FILME:
    *basta inserir nome do filme a ser removido
    *caso filme nao exista, sera printado no log

  BUSCAR FILME:
    *basta inserir nome do filme a ser removido
    *caso filme nao exista, sera printado no log

  EDITAR PRODUTORA:
    *inserir primeiro nome do filme e depois novo nome para produtora
    *caso filme nao exista, sera printado no log

  EDITAR NOTA:
    *inserir primeiro nome do filme e depois nova nota para filme
    *caso filme nao exista, sera printado no log

