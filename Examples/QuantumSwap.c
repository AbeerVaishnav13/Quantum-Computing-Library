#include "../QCLibs/QCLibs.h"

int main(int argc, char const *argv[]) {
	quReg *x = newQuReg(2);

	x = R_reg(PI/4, X_reg(x, 1), 1);
	Qprint("x = %r\n", x);

	quBit qb1 = newQubit(0), qb2 = newQubit(1);
	Qprint("qb1 = %q, qb2 = %q\n", qb1, qb2);

	QSwap_reg(x, 0, 1);
	Qprint("x = %r\n", x);

	QSwap(&qb1, &qb2);
	Qprint("qb1 = %q, qb2 = %q\n", qb1, qb2);

	return 0;
}