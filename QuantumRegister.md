# Quantum Registers

This feature allows the use to make registers consisting of multiple qubits at a time.

To make the coding of these gates easier, a functionality of short-hand gates is provided. The gates can be applied to the register as follows:-

	quReg *qr = newQuReg(2);

	char gate_string[] = "(T: quReg2 = ), \
							(Pa), \
							{\
								[X, X], [Z, Y], [H, H], [X, Z], [Y, X] \
							},\
							(Pnz)";

	qr = applyGates_reg(gate_string, qr);


OUTPUT:

	./q.out

	quReg2 = 
	[0]:	{1.000000 + 0.000000 i} |00>	100.00 %
	[1]:	{0.000000 + 0.000000 i} |01>	0.00 %
	[2]:	{0.000000 + 0.000000 i} |10>	0.00 %
	[3]:	{0.000000 + 0.000000 i} |11>	0.00 %

	quReg2 = 
	[0]:	{-0.000000 - 0.500000 i} |00>	25.00 %
	[1]:	{-0.000000 + 0.500000 i} |01>	25.00 %
	[2]:	{-0.000000 - 0.500000 i} |10>	25.00 %
	[3]:	{-0.000000 + 0.500000 i} |11>	25.00 %


The above code segment has the following meaning:-
 - Initialize a new quRegister.
 - Display text for the quRegister is "quReg2 = ".
 - (Pa) -> Print all possible combinations of 'n' qubits in the quRegister.
 - Pauli gate 'X' is applied to [qubit[0], qubit[1]] respectively.
 - Pauli gate 'Z' is applied to qubit[0] and 'Y' to qubit[1] respectively, and so on.
 - (Pnz) -> Print only non-zero magnitude values.

## List of short-hand gates
 - Pauli-X gate: **X**
 - Pauli-Y gate: **Y**
 - Pauli-Z gate: **Z**
 - Hadamard gate: **H**
 - Phase gate: **S**
 - Rotation gate: **R_xx.xx** (x = 0, 1,..., 9; AngleMode = degrees)
 - CNOT gate: *(atleast one 'Co' and one 'Cx' should be there in same [.])*
 	- Control gate: **Co**
 	- NOT gate: **Cx**
 - Swap gate: **Sx** *(atleast two should be there in same [.])*
 - Quantum Fourier Transform (QFT): **Q** *(coming soon...)*
 - Inverse QFT: **Qi** *(coming soon...)*

 *For more info, see the examples: https://github.com/AbeerVaishnav13/Quantum-Computing-Library/tree/master/Examples*

*\*Currently, the library supports registers upto 28-qubits with 8GB of memory.*