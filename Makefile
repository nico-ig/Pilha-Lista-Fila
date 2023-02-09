CC = gcc
CFLAGS = -g -Wall -std=c90



all: testa_pilha testa_fila testa_lista



testa_pilha: testa_pilha.o libteste.o libpilha.o libfila.o liblista.o
	$(CC) testa_pilha.o libteste.o libpilha.o libfila.o liblista.o -o testa_pilha 

testa_pilha.o: testa_pilha.c
	$(CC) $(CFLAGS) -c testa_pilha.c

libpilha.o: libpilha.c
	$(CC) $(CFLAGS) -c libpilha.c



testa_fila: testa_fila.o libteste.o libpilha.o libfila.o liblista.o
	$(CC)  testa_fila.o libteste.o libpilha.o libfila.o liblista.o -o testa_fila

testa_fila.o: testa_fila.c
	$(CC) $(CFLAGS) -c testa_fila.c

libfila.o: libfila.c
	$(CC) $(CFLAGS) -c libfila.c



testa_lista: testa_lista.o libteste.o libpilha.o libfila.o liblista.o
	$(CC)  testa_lista.o libteste.o libpilha.o libfila.o liblista.o -o testa_lista

testa_lista.o: testa_lista.c
	$(CC) $(CFLAGS) -c testa_lista.c

liblista.o: liblista.c
	$(CC) $(CFLAGS) -c liblista.c



libteste.o: libteste.c libpilha.o libfila.o liblista.o
	$(CC) $(CFLAGS) -c libteste.c



clean:
	rm *.o testa_pilha testa_fila testa_lista
