#include "../QCLibs/QCLibs.h"

int main(int argc, char const *argv[]) {
	quBit x = newQubit(0), y = newQubit(0);

	Qprint("x = %q, y = %q\n", x, y);

	// Quantum CNOT Gate (Controlled NOT):-
	// if (x1 == |1>) {x2 = X(x2)}
	// else {x2 = x2}
	// "Generally used for entanglement of the Qubits x1 and x2".
	CNOT(&x, &y);

	Qprint("x = %q, y = %q\n", x, y);

	x = X(x);

	Qprint("x = %q, y = %q\n", x, y);

	CNOT(&x, &y);

	Qprint("x = %q, y = %q\n", x, y);

	return 0;
}