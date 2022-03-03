output:main.o login.o
	g++ -g main.o login.o -o run


main.o: main.cpp
	g++ -g -c main.cpp

login.o: login.cpp login.h 
	g++ -g -c login.cpp


clean:
	rm *.o run