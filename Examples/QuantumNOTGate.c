#include "../QCLibs/QCLibs.h"

int main(int argc, char const *argv[]) {
	quBit x = newQubit();

	Qprint("x = %q\n", x);

	// Quantum NOT Gate:-
	// Applies a NOT function to the probabilistic coefficients of the Qubit.
	x = X(x);

	Qprint("x = %q\n", x);

	// Adding Hadamard gate
	x = H(x);

	Qprint("x = %q\n", x);

	x = X(x);

	Qprint("x = %q\n", x);

	return 0;
}