#include "stdio.h"
#include "gmp.h"

int main(int argc, char **argv)
{
	mpz_t a, b;

	mpz_init(a);
	mpz_init(b);
	mpz_set_str(a, "1251351453454563", 10);
	mpz_set_str(b, "10101000011111000100000010100001111", 2);

	gmp_printf("a is %Zd\n", a);
	gmp_printf("b is %Zd\n", b);

	return 0;
}

