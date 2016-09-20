objs = target/main.o

target/pointers: $(objs)
	cc -o target/pointers $(objs)

target/main.o: main.c
	cc -std=c99 -O2 -s -c main.c -o target/main.o

.PHONY: clean
clean:
	-rm -f target/*
