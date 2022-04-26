output:main.o login.o Reservation.o
	g++ -g main.o login.o Reservation.o -o run


main.o: main.cpp
	g++ -g -c main.cpp

login.o: login.cpp login.h 
	g++ -g -c login.cpp

Reservation.o: Reservation.cpp Reservation.h
	g++ -g -c Reservation.cpp

clean:
	rm *.o run