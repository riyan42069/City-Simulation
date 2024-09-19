sims: main.o simcity.o 
	g++ main.o simcity.o -o sims

main.o: main.cpp
	g++ -c main.cpp

simcity.o: simcity.cpp
	g++ -c simcity.cpp

clean:
	rm *.o sims