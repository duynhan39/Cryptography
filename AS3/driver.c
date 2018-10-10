// Duy Nhan Cao
// File: driver.c

// 961748941 2 199

#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>

#include "poh.h"

//#define MAX_STR 10000

int main(int argc, char * argv[]) {
  mpz_t p, g, x, rop;
  mpz_init(p);
  mpz_init(g);
  mpz_init(x);
  mpz_init(rop);
  
  
  if(argc == 2) {
    FILE *file;
    file = fopen(argv[1], "r");
    int n;
    fscanf(file, "%d", &n);
    for(int i=0; i<n; i++) {
      
      gmp_fscanf(file, "%Zd", p);
      gmp_fscanf(file, "%Zd", g);
      gmp_fscanf(file, "%Zd", x);
      
      dlp(rop, p, g, x);
      gmp_printf("%Zd\n", rop);
      
    }
    fclose(file);

    mpz_clear(p);
    mpz_clear(g);
    mpz_clear(x);
    mpz_clear(rop);
    return 0;
  }

  //printf("Hi\n");
  
  if(argc == 4) {
    mpz_set_str(p, argv[1], 10);
    mpz_set_str(g, argv[2], 10);
    mpz_set_str(x, argv[3], 10);

    //printf("Hi23\n");
    
    dlp(rop, p, g, x);
    gmp_printf("%Zd\n", rop);

    //printf("Hi\n");

    mpz_clear(p);
    mpz_clear(g);
    mpz_clear(x);
    mpz_clear(rop);
    return 0;
  }

  printf("Invalid number of input!\n");

  return 0;

}
