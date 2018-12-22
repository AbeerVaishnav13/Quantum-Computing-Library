#ifndef QUANTUMGATES_H

#define QUANTUMGATES_H

// Quantum NOT Gate:-
// Applies a NOT function to the probabilistic coefficients of the Qubit.
quBit X(quBit x);

// Quantum Hadamard Gate:-
// Applies hadamard Function to the Qubit passed into it.
quBit H(quBit x);

// Quantum V Gate:-
// Rotates the Coefficient of Quantum state about Complex Axis.
quBit S(float angle, quBit x);

// Quantum CNOT Gate (Controlled NOT):-
// if (x1 == |1>) {x2 = X(x2)}
// else {x2 = x2}
// "Generally used for entanglement of the Qubits x1 and x2".
void CNOT(quBit *x1, quBit *x2);


// Function Definitions
//
//
//
//

quBit X(quBit x) {
	float temp = x.ZCoeff;
	x.ZCoeff = x.OCoeff;
	x.OCoeff = temp;

	return x;
}

quBit H(quBit x) {
	int threshold = 1000000;

	if(x.ZCoeff == 1 && x.OCoeff == 0) {
		x.ZCoeff = (float)1/sqrt(2);
		x.OCoeff = (float)1/sqrt(2);
	} 
	else if (x.ZCoeff == 0 && x.OCoeff == 1) {
		x.ZCoeff = (float)1/sqrt(2);
		x.OCoeff = (float)-1/sqrt(2);
	}
	else {
		x.ZCoeff = round(x.ZCoeff * (H(newQubit()).ZCoeff + H(X(newQubit())).ZCoeff) * threshold) / threshold;
		x.OCoeff = round(x.OCoeff * (H(newQubit()).OCoeff + H(X(newQubit())).OCoeff) * threshold) / threshold;
	}

	return x;
}

quBit S(float angle, quBit x) {
	return x;
}

void CNOT(quBit *x1, quBit *x2) {
	if((*x1).OCoeff == 1)
		*x2 = X(*x2);
	else {}
}

#endif
