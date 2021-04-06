evaluate: main.o strategy.o matrix.o reduce.o permutation.o
	g++ -O3 -o evaluate main.o strategy.o matrix.o reduce.o permutation.o -lpthread
main.o: main.cpp strategy.h matrix.h reduce.h
	g++ -O3 -c main.cpp -lpthread
strategy.o: strategy.cpp matrix.h
	g++ -O3 -c strategy.cpp -lpthread
matrix.o: matrix.cpp
	g++ -O3 -c matrix.cpp matrix.h -lpthread
reduce.o:reduce.cpp strategy.h matrix.h
	g++ -O3 -c reduce.cpp -lpthread
permutation.o:permutation.cpp  matrix.h 
	g++ -O3 -c permutation.cpp -lpthread

.PHONY:clean
clean:
	rm *.o evaluate