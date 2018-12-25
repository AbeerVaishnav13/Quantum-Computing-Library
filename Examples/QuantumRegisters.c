#include "../QCLibs/QCLibs.h"

int main(int argc, char const *argv[]) {
	quReg *qr1 = newQuReg(3);

	printf("USING DISCRETE GATES:-\n\n");

	// Gives a feeling of conventional coding style of C
	// Preferred by some people.

	Qprint("QuReg1 = %a\n", qr1);

	qr1 = Z_reg(qr1, 0);
	Qprint("QuReg1 = %r\n", qr1);

	qr1 = X_reg(qr1, 1);
	Qprint("QuReg1 = %r\n", qr1);

	qr1 = Y_reg(qr1, 2);
	Qprint("QuReg1 = %r\n", qr1);

	qr1 = Y_reg(qr1, 0);
	Qprint("QuReg1 = %r\n", qr1);

	qr1 = Y_reg(qr1, 1);
	Qprint("QuReg1 = %r\n", qr1);

	qr1 = Y_reg(qr1, 2);
	Qprint("QuReg1 = %r\n", qr1);

	Qprint("QuReg1 = %a\n", qr1);

	////////////////////////////////////////////////////////////////////////////////////////////

	quReg *qr2 = newQuReg(3);

	printf("USING STRING OPERATIONS...\n\n");
	// Using string operations on the registers.
	////////////////////////////////////////////////////////////////////////////////////////////
	// {} - to define starting and ending of the quantum function.
	// [] = to define starting and ending of the gate column.
	// () - to specify extra commands like printing the result midway of the quantum function.
	////////////////////////////////////////////////////////////////////////////////////////////
	// syntax: {(cmd_0), [gate_col_1(cmd_1)], [gate_col_2(cmd_2)], ... , [gate_col_n(cmd_n)]}
	// Additional Commands:-
	// 'P' or 'Pnz': To print non-zero values from the register
	// 'Pa': To print all values present in the register
	////////////////////////////////////////////////////////////////////////////////////////////

	// Good for fast prorotyping of funcitons!
	// Reduces lines of code.
	// makes the code more readable and easy to debug!
	// Maybe not preferred, but looks cool! :D
	char gate_string[] = "{(Pa), [ Z(Pnz), X(P), Y(P) ], [ Y(Pnz), Y(Pnz), Y(Pnz) ], (Pa)}";

	qr2 = applyGates_reg(gate_string, qr2);

	return 0;
}