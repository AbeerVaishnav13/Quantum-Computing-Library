#ifndef QUANTUMGATES_H

#define QUANTUMGATES_H

// Quantum NOT Gate:-
// Applies a NOT function to the probabilistic coefficients of the Qubit.
void X(quReg *x);

// Quantum Hadamard Gate:-
// Applies hadamard Function to the Qubit passed into it.
void H(quReg *x);

// Quantum V Gate:-
// Rotates the Coefficient of Quantum state about Complex Axis.
void V(float angle, quReg *x);

// Quantum CNOT Gate (Controlled NOT):-
// if (x1 == 1) {x2 = X(x2)}
// else {x2 = x2}

// "Generally used for entanglement of the Qubits x1 and x2".
void CNOT(quReg *x1, quReg *x2);

#endif