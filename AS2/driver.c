// Duy Nhan Cao
// File: driver.c

#include "shanks.h"

#define MAX_STR 10000

int main(int argc, char * argv[]) {
  mpz_t p, g, h, rop;
  mpz_init(p);
  mpz_init(g);
  mpz_init(h);
  mpz_init(rop);
  
  
  if(argc == 2) {
    FILE *file;
    file = fopen(argv[1], "r");
    int n;
    fscanf(file, "%d", &n);
    for(int i=0; i<n; i++) {
      gmp_fscanf(file, "%Zd", p);
      gmp_fscanf(file, "%Zd", g);
      gmp_fscanf(file, "%Zd", h);
      
      shanks(rop, p, g, h);
      gmp_printf("%Zd\n", rop);
    }
    fclose(file);
    return 0;
  }

  if(argc == 4) {
    mpz_set_str(p, argv[1], 10);
    mpz_set_str(g, argv[2], 10);
    mpz_set_str(h, argv[3], 10);

    shanks(rop, p, g, h);
    gmp_printf("%Zd\n", rop);
    
    return 0;
  }

  printf("Invalid number of input!\n");

  return 0;

}
