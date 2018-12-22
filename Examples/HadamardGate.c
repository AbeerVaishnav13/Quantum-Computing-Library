#include "../QCLibs/QCLibs.h"

int main(int argc, char const *argv[]) {
	quBit x = newQubit(0);

	Qprint("x = %q\n", x);

	// Quantum Hadamard Gate:-
	// Applies hadamard Function to the Qubit passed into it.
	x = H(x);

	Qprint("x = %q\n", x);	

	return 0;
}