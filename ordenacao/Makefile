FLAGS := -g -w

selection:
	g++ -c client.c $(FLAGS)
	g++ -c selection.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o

insertion:
	g++ -c client.c $(FLAGS)
	g++ -c insertion.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o

bubble:
	g++ -c client.c $(FLAGS)
	g++ -c bubble.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o

shaker:
	g++ -c client.c $(FLAGS)
	g++ -c shaker.c $(FLAGS)
	g++ -o main *.o $(FLAGS)
	rm *.o

teste:
	./main 1000 < in/nearly_sorted/1K.txt 
	./main 10000 < in/nearly_sorted/10K.txt
	./main 100000 < in/nearly_sorted/100K.txt
	./main 1000 < in/reverse_sorted/1K.txt 
	./main 10000 < in/reverse_sorted/10K.txt
	./main 100000 < in/reverse_sorted/100K.txt
	./main 1000 < in/sorted/1K.txt 
	./main 10000 < in/sorted/10K.txt
	./main 100000 < in/sorted/100K.txt
	./main 1000 < in/unif_rand/1K.txt 
	./main 10000 < in/unif_rand/10K.txt
	./main 100000 < in/unif_rand/100K.txt
