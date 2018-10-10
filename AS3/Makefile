#Duy Nhan Cao

LIBS = -lgmp

driver: driver.o factorize.o poh.o
	gcc -o dr driver.o factorize.o poh.o $(LIBS)

driver.o: driver.c poh.h
	gcc -c driver.c

factorize.o: factorize.c factorize.h primes.h
	gcc -c factorize.c

poh.o: poh.c poh.h shanks.h factorize.h
	gcc -c poh.c

clean:
	rm -f *.o driver *~
