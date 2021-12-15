all: main TreeMap

TreeMap: TreeMap.h
	cc -O0 -g -o TreeMap TreeMap.h

main: main.c
	cc -O0 -g -o main main.c

clean:
	rm -rf main *.gch *.o TreeMap




