#include "../QCLibs/QCLibs.h"

int main(int argc, char const *argv[]) {
	quBit x = newQubit(1);

	// x has 100% probability of |1> state
	Qprint("x = %q\n", x);

	// Rotation by PI/2 about the complex axis
	quBit qb1 = R(PI/2, x);
	Qprint("qb1 = %q\n", qb1);

	// Rotation by PI/4 about the complex axis
	quBit qb2 = R(PI/4, x);
	Qprint("qb2 = %q\n", qb2);

	// Rotation by PI/8 about the complex axis
	quBit qb3 = R(PI/8, x);
	Qprint("qb3 = %q\n", qb3);

	// Let's hadamard it!
	x = H(x);

	// Rotation by PI/2 about the complex axis for the new 'x' value
	quBit qb4 = R(PI/2, x);
	Qprint("qb4 = %q\n", qb4);

	// Rotation by PI/4 about the complex axis for the new 'x' value
	quBit qb5 = R(PI/4, x);
	Qprint("qb5 = %q\n", qb5);

	// Rotation by PI/8 about the complex axis for the new 'x' value
	quBit qb6 = R(PI/8, x);
	Qprint("qb6 = %q\n", qb6);

	return 0;
}