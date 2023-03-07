
OBJS=test.o print1.o print2.o

CFLAGS=-g -Wall -c

test: $(OBJS)
	gcc $(OBJS) -g -Wall -o test

%.o:%.c
	gcc $^ $(CFLAGS) -o $@

clean:
	rm *.o test -rf
