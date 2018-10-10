#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

#include "factorize.h"
#include "shanks.h"
#include "poh.h"

typedef struct factors factors;

void chinese(mpz_t rop, mpz_t *y, mpz_t *g, long n, mpz_t const p);

void dlp(mpz_t rop, const mpz_t p, const mpz_t g, const mpz_t x) {

  mpz_t N, pow, gi, xi, _y;
  
  mpz_init(pow);
  mpz_init(N);
  mpz_init(gi);
  mpz_init(xi);
  mpz_init(_y);

  mpz_sub_ui(N, p, 1);

  factors *facts = malloc(sizeof(factors));
  
  factor(N, facts);

  mpz_sub_ui(N, p, 1);
  
  mpz_t *y = (mpz_t*) malloc (facts->nfactors * sizeof(mpz_t));
  mpz_t *p_e = (mpz_t*) malloc (facts->nfactors * sizeof(mpz_t));
    
  //printf("%ld\n", facts->nfactors);
     
  for(long i = 0; i < facts->nfactors; i++) {
    
    mpz_init(p_e[i]);
    
    mpz_pow_ui(p_e[i], facts->p[i], facts->e[i]);
    
    mpz_tdiv_q(pow, N, p_e[i]);

    mpz_powm(gi, g, pow, p);
    mpz_powm(xi, x, pow, p);
    
    shanks(_y, p, gi, xi, p_e[i]);
    mpz_init_set(y[i], _y);
  }
  
  chinese(rop, y, p_e, facts->nfactors, p);
  //free(y);
  //free(p_e);
}

void chinese(mpz_t rop, mpz_t *y, mpz_t *g, long n, mpz_t const p) {
  
  mpz_t N, pp, _pp;
  mpz_init(N);
  mpz_init(pp);
  mpz_init(_pp);
  mpz_set_ui(rop, 0);
  
  mpz_sub_ui(N, p, 1);

  for(long i=0; i<n ; i++) {
    
    mpz_tdiv_q(pp, N, g[i]);
    mpz_invert(_pp, pp, g[i]);

    mpz_mul(pp, pp, _pp);
    mpz_mul(pp, pp, y[i]);

    mpz_add(rop, rop, pp);
    mpz_tdiv_r(rop, rop, N);
  }
}
