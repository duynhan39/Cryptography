// Duy Nhan Cao
// File: testEea.c

#include "cryp.h"

int main() {

  mpz_t a, b, u, v, rd, d;
  mpz_init(u);
  mpz_init(v);
  mpz_init(rd);
  mpz_init(d);
  mpz_init(a);
  mpz_init(b);
  gmp_scanf("%Zd", a);
  gmp_scanf("%Zd", b);
  gmp_scanf("%Zd", rd);

  eea(u, v, d, a, b);
  if(mpz_cmp(rd, d)) 
    printf("Incorrect gcd!\n");
  else
    printf("Correct gcd!\n");

  mpz_t ma, mb, result;
  mpz_init(ma);
  mpz_init(mb);
  mpz_init(result);

  mpz_mul(ma, a, u);
  mpz_mul(mb, b, v);
  mpz_add(result, ma, mb);

  if(mpz_cmp(rd, result))
    printf("Incorrect u, v!\n");
  else
    printf("Correct u, v!\n");
  
  return 0;
}

