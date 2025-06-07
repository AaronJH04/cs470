all: test

test: Aaron_testFS.o Aaron_libFS.o
	gcc -o test Aaron_testFS.o Aaron_libFS.o

Aaron_testFS.o: Aaron_testFS.c Aaron_libFS.h
	gcc -c Aaron_testFS.c

Aaron_libFS.o: Aaron_libFS.c Aaron_libFS.h
	gcc -c Aaron_libFS.c

clean:
	del *.o test.exe
