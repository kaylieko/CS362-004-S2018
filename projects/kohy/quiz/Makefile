CFLAGS = -Wall -fpic -coverage -lm

testme: testme.c
	gcc -o testme -g  testme.c $(CFLAGS)

clean:
	-rm -f *.gcda *.gcno testme
	-rm -r testme.dSYM