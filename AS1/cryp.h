// Duy Nhan Cao
// File: cryp.h

#ifndef GMP
#define GMP

#include <stdlib.h>
#include <stdio.h>
#include "gmp.h"

void eea(mpz_t u, mpz_t v, mpz_t d, const mpz_t a, const mpz_t b) {
	mpz_t ap;
	mpz_init_set(ap, a);
	mpz_t bp;
	mpz_init_set(bp, b);

	mpz_t up;
	mpz_init_set_ui(up, 1);
	mpz_t vp;
	mpz_init_set_ui(vp, 0);
	
	mpz_set_ui(u,0);
	mpz_set_ui(v,1);
	
	while(1) {
		mpz_t r, u2, v2;
		mpz_init_set(u2, u);
		mpz_init_set(v2, v);
		mpz_init(r);
		mpz_tdiv_r(r, ap, bp);

		if(!mpz_cmp_ui(r, 0)) {
			mpz_init_set(d, bp);
			return;
		}
		mpz_t q, m;
		mpz_init(q);
		mpz_init(m);

		mpz_tdiv_q(q, ap, bp);
		mpz_mul(m, u, q);
		mpz_sub(u, up, m);

		mpz_mul(m, v, q);
                mpz_sub(v, vp, m);

		mpz_set(up, u2);
		mpz_set(vp, v2);

		mpz_set(ap, bp);
		mpz_set(bp, r);
	}
}

void primitive_root(mpz_t rop, const mpz_t p, const int n, const mpz_t* factors) {
	mpz_t i, pm, pow, r, ip;
	mpz_init(pm);
	mpz_sub_ui(pm, p, 1);
	mpz_init(pow);
	mpz_init(r);
	mpz_init(ip);

	int root = 1;
	mpz_init_set_ui(i, 2);
	while(mpz_cmp(pm, i)) {
		root = 1;
		for(int j = 0; j < n; j++) {
			mpz_tdiv_q(pow, pm, factors[j]);
			mpz_powm(r, i, pow, p);
			if(mpz_cmp_ui(r, 1) == 0) {
				root = 0;
				break;
			}
		}
		if(root) {
			mpz_set(rop, i);
			break;
		}
		mpz_add_ui(ip, i, 1);
		mpz_set(i, ip);
	}
}

#endif
