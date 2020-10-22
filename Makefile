CC=g++

trabalho3: main.o filme.o catalogo.o
	$(CC) -o trabalho3 main.o filme.o catalogo.o

