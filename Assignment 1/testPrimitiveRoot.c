// Duy Nhan Cao
// File: testPrimitiveRoot.c

#include "cryp.h"

int main (int argc, char * argv[]) {
  FILE* file;
  if(argc != 2) {
    printf("Not valid amount of arguments!\n");
    return 0;
  }
  file = fopen(argv[1], "r");
  
  int n;
  mpz_t p;
  mpz_init(p);
  mpz_t *factors;
  factors = malloc(sizeof(mpz_t) * n);
  
  gmp_fscanf(file, "%Zd", p);
  fscanf(file, "%d", &n);
  
  for(int i=0; i<n; i++) {
    gmp_fscanf(file, "%Zd", factors[i]);
  }
	
  mpz_t rAns;
  mpz_init(rAns);
  gmp_fscanf(file, "%Zd", rAns);

  mpz_t rop;
  mpz_init(rop);
  primitive_root(rop, p, n, factors);

  if(mpz_cmp(rAns, rop))
		printf("Incorrect!\n");
	else
		printf("Correct!\n");

  fclose(file);
  return 0;
}
