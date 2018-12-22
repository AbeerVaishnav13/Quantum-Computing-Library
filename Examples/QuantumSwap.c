#include "../QCLibs/QCLibs.h"

int main(int argc, char const *argv[]) {
	quBit *x = newQuRegister(2);

	x[1] = R(PI/4, X(x[1]));
	Qprint("x = %r\n", x);

	quBit qb1 = newQubit(0), qb2 = newQubit(1);
	Qprint("qb1 = %q, qb2 = %q\n", qb1, qb2);

	QSwap(&x[0], &x[1]);
	Qprint("x = %r\n", x);

	QSwap(&qb1, &qb2);
	Qprint("qb1 = %q, qb2 = %q\n", qb1, qb2);

	return 0;
}