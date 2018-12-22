#include "../QCLibs/QCLibs.h"

int main(int argc, char const *argv[]) {
	quBit x = newQubit(0);

	Qprint("x = %q\n", x);

	// Rotation about X-axis of the Bloch sphere
	quBit qb1 = X(x);
	Qprint("qb1 = %q\n", qb1);

	// Rotation about Y-axis of the Bloch sphere
	quBit qb2 = Y(x);
	Qprint("qb2 = %q\n", qb2);

	// Rotation about Z-axis of the Bloch sphere
	quBit qb3 = Z(x);
	Qprint("qb3 = %q\n", qb3);

	return 0;
}