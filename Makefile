CC = g++
LIBS = `allegro-config --libs`
CFLAGS = -Wall -pedantic -O2 -std=c++17
argon: main.o krystalografia.o wektor3d.o atom.o
		$(CC) -o argon main.o krystalografia.o wektor3d.o atom.o $(CFLAGS) $(LIBS)
main.o:	main.cpp krystalografia.h wektor3d.h atom.h
		$(CC) -o main.o -c main.cpp $(CFLAGS)
krystalografia.o:	krystalografia.cpp krystalografia.h atom.h
		$(CC) -o krystalografia.o -c krystalografia.cpp $(CFLAGS)
wektor3d.o: wektor3d.cpp wektor3d.h
		$(CC) -o wektor3d.o -c wektor3d.cpp $(CFLAGS)
atom.o: atom.cpp wektor3d.h atom.h
		$(CC) -o atom.o -c atom.cpp $(CFLAGS)
clean:
		rm *.o
