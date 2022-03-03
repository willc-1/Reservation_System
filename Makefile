output:main.o login.o
	g++ main.o login.o -o run


main.o: main.cpp
	g++ -c main.cpp

login.o: login.cpp login.h 
	g++ -c login.cpp


clean:
	rm *.o run