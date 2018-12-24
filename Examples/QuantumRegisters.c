#include "../QCLibs/QCLibs.h"

int main(int argc, char const *argv[]) {
	quReg *x = newQuReg(4);

	// To print only the states which have non-zero probability
	Qprint("x = %r\n", x);
	// To print all states
	Qprint("x = %a\n", x);

	// x = H_reg(x, 0);

	x = X_reg(x, 1);

	// x = CNOT_reg(x, 1, 2);

	// x = R_reg(PI/2, x, 3);

	// To print only the states which have non-zero probability
	Qprint("x = %r\n", x);
	// To print all states
	Qprint("x = %a\n", x);

	return 0;
}