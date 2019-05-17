#include "../QCLibs/QCLibs.h"

int main(int argc, char const *argv[]) {
	quBit x = newQubit(0);

	Qprint("x = %q\n", x);

	// Quantum Hadamard Gate:-
	// Applies hadamard Function to the Qubit passed into it.
	// Puts the Qubit into superposition of |0> state and |1> state.
	//Probability of getting both states after measuring is 50-50.
	x = H(x);
	Qprint("x = %q\n", x);	

	//Using quRegisters
	quReg *qr = newQuReg(2);

	char gate_string[] = "(T: quReg2 = ), \
							(Pa), \
							{\
								[H, H] \
								(Pa) \
								[H, 1] \
								(Pa) \
								[1, H] \
							}, \
							(Pa)";

	qr = applyGates_reg(gate_string, qr);

	return 0;
}