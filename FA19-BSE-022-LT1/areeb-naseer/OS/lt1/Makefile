main: main.o libmymathlib.a
	gcc -o main main.o -L. -lmymathlib -Wl,-rpath=/home/areeb-naseer/OS/lt1 

libmymathlib.a: main.o
	ar cr libmymathlib.a main.o
clean:
	rm *.o libmymathlib.a
