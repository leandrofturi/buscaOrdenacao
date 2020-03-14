FLAGS := -g -w

Eratostenes: EratostenesCOD
	gcc -c Eratostenes.c $(FLAGS)
	gcc -o Eratostenes Eratostenes.o CrivodeEratostenes.o $(FLAGS)
	rm *.o

EratostenesCOD:
	gcc -c cod/CrivodeEratostenes.c $(FLAGS)

Josefo: JosefoCOD
	gcc -c Josefo.c $(FLAGS)
	gcc -o Josefo Josefo.o ProblemadeJosefo.o $(FLAGS)
	rm *.o

JosefoCOD:
	gcc -c cod/ProblemadeJosefo.c $(FLAGS)

Dijkstra: DijkstraCOD
	gcc -c Dijkstra.c $(FLAGS)
	gcc -o Dijkstra Dijkstra.o Dijkstra2-stack.o pilha.o listaEncadeada.o $(FLAGS)
	rm *.o

DijkstraCOD: Pilha
	gcc -c cod/Dijkstra2-stack.c $(FLAGS)

Pilha: ListaEncadeada
	gcc -c TADsC/cod/pilha.c $(FLAGS)

ListaEncadeada:
	gcc -c TADsC/cod/listaEncadeada.c $(FLAGS)

# val:
# 	valgrind --leak-check=full -v --track-origins=yes --show-leak-kinds=all