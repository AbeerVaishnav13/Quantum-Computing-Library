#include "../QCLibs/QCLibs.h"

int main(int argc, char const *argv[]) {
	quBit *x = newQuRegister(4);

	Qprint("x = %r\n", x);

	x[0] = H(x[0]);

	x[1] = X(x[1]);

	CNOT(&x[1], &x[2]);

	x[3] = S(PI/2, x[3]);

	Qprint("x = %r\n", x);

	return 0;
}