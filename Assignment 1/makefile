#Duy Nhan Cao

all: testEea testPrimitiveRoot

testEea: testEea.o
	gcc -o testEea testEea.o -lgmp

testPrimitiveRoot: testPrimitiveRoot.o
	gcc -o testPrimitiveRoot testPrimitiveRoot.o -lgmp

testEea.o: testEea.c cryp.h 
	gcc -c testEea.c

testPrimitiveRoot.o: testPrimitiveRoot.c cryp.h 
	gcc -c testPrimitiveRoot.c

clean:
	rm -f *.o tests *~
