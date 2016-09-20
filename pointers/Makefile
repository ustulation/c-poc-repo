objs = main.o

pointers: $(objs)
	cc -o pointers $(objs)

main.o: main.c
	cc -std=c99 -O2 -s -c main.c -o main.o
clean:
	-rm -f pointers $(objs)
