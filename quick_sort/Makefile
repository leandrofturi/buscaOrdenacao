FLAGS := -g -w -lm


top_down:
	g++ -c client.c $(FLAGS)
	g++ -c top_down.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o

top_down_cutoff:
	g++ -c client.c $(FLAGS)
	g++ -c top_down_cutoff.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o

top_down_med3:
	g++ -c client.c $(FLAGS)
	g++ -c top_down_med3.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o

top_down_med3_cutoff:
	g++ -c client.c $(FLAGS)
	g++ -c top_down_med3_cutoff.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o

bottom_up:
	g++ -c client.c $(FLAGS)
	g++ -c stack/stack.c $(FLAGS)
	g++ -c bottom_up.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o

bottom_up_cutoff:
	g++ -c client.c $(FLAGS)
	g++ -c stack/stack.c $(FLAGS)
	g++ -c bottom_up_cutoff.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o

top_down_med3_cutoff_shuffle:
	g++ -c client.c $(FLAGS)
	g++ -c top_down_med3_cutoff_shuffle.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o

Dijkstra_3way:
	g++ -c client.c $(FLAGS)
	g++ -c Dijkstra_3way.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o

teste_que_vai:
	./main 100000 < input/nearly_sorted/100000.txt
	./main 100000 < input/reverse_sorted/100000.txt
	./main 100000 < input/sorted/100000.txt
	./main 100000 < input/unif_rand/100000.txt
	./main 1000000 < input/unif_rand/1000000.txt

teste:
	./main 100000 < input/nearly_sorted/100000.txt
	./main 1000000 < input/nearly_sorted/1000000.txt
	./main 100000 < input/reverse_sorted/100000.txt
	./main 1000000 < input/reverse_sorted/1000000.txt
	./main 100000 < input/sorted/100000.txt
	./main 1000000 < input/sorted/1000000.txt
	./main 100000 < input/unif_rand/100000.txt
	./main 1000000 < input/unif_rand/1000000.txt