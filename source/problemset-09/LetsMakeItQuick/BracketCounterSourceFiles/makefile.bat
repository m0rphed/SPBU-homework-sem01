SOURCES = task-62-counting-brackets.cpp LastInFirstOut.cpp test.cpp
BracketCounter: LastInFirstOut.o task62.o test.o
	g++ -o BracketCounter LastInFirstOut.o task62.o test.o

LastInFirstOut.o: LastInFirstOut.cpp LastInFirstOut.h
	g++ -c LastInFirstOut.cpp

test.o: test.cpp LastInFirstOut.h
	g++ -c test.cpp

task62.o: task-62-counting-brackets.h LastInFirstOut.h
	g++ -c task-62-counting-brackets.cpp

clean:
	rm -rf *.o BracketCounter