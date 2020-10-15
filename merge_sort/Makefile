FLAGS := -g -w

classico:
	g++ -c client.c $(FLAGS)
	g++ -c classico.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o

cutoff:
	g++ -c client.c $(FLAGS)
	g++ -c cutoff.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o

mergeskip:
	g++ -c client.c $(FLAGS)
	g++ -c mergeskip.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o

cutoff_mergeskip:
	g++ -c client.c $(FLAGS)
	g++ -c cutoff_mergeskip.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o

bottonup:
	g++ -c client.c $(FLAGS)
	g++ -c bottonup.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o

bottonup_cutoff:
	g++ -c client.c $(FLAGS)
	g++ -c bottonup_cutoff.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o

bottonup_mergeskip:
	g++ -c client.c $(FLAGS)
	g++ -c bottonup_mergeskip.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o

teste:
	./main 100000 < input/nearly_sorted/100000.txt
	./main 1000000 < input/nearly_sorted/1000000.txt
	./main 100000 < input/reverse_sorted/100000.txt
	./main 1000000 < input/reverse_sorted/1000000.txt
	./main 100000 < input/sorted/100000.txt
	./main 1000000 < input/sorted/1000000.txt
	./main 100000 < input/unif_rand/100000.txt
	./main 1000000 < input/unif_rand/1000000.txt
