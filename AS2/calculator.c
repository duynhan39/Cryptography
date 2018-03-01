#include "gmp.h"

int main() {
  mpz_t p, g, a, b, A, B, k, m, c1, c2, num;
  mpz_init_set_ui(p, 1373);
  mpz_init_set_ui(g, 2);
  mpz_init_set_ui(a, 947);
  mpz_init_set_ui(b, 716);
  mpz_init_set_ui(m, 583);
  mpz_init_set_ui(k, 877);
  mpz_init(A);
  mpz_init(B);
  mpz_init(c1);
  mpz_init(c2);
  mpz_init(num);

  mpz_powm(A, g, a, p);

  mpz_powm(B, g, b, p);

  mpz_powm(c1, g, k, p);

  mpz_powm(num, B, k, p);

  mpz_mul(c2, m, num);

  mpz_tdiv_r(c2, c2, p);

  gmp_printf("A: %Zd\n", A);
  gmp_printf("c1: %Zd\n", c1);
  gmp_printf("c2: %Zd\n", c2);
  

  return 0;
}
