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

	char gate_string[] = "(T: quReg2 = ), (Pa), { [ Z(Pnz), X(P), Y(P) ], [ Y(Pnz), Y(Pnz), Y(Pnz) ] }, (Pa)";

	qr2 = applyGates_reg(gate_string, qr2);
	// Using string operations on the registers.
	////////////////////////////////////////////////////////////////////////////////////////////
	// {} - to define starting and ending of the quantum function.
	// [] = to define starting and ending of the gate column  qubit sequence: [<n> <n-1> <n-2> ... <2> <1> <0>].
	// () - to specify extra commands like printing the result mid-way of the quantum function.
	////////////////////////////////////////////////////////////////////////////////////////////
	// syntax: {(cmd_0), [gate_col_1(cmd_1)], [gate_col_2(cmd_2)], ... , [gate_col_n(cmd_n)]}
	// Additional Commands:-
	// 'P' or 'Pnz': To print non-zero values from the register
	// 'Pa': To print all values present in the register
	// 'T': To specify a text to be printed while priting the state of the qubit register
	////////////////////////////////////////////////////////////////////////////////////////////

	// Good for fast prorotyping of functions!
	// Reduces lines of code.
	// Makes the code more readable and easy to debug!
	// Maybe not preferred, but looks cool! :D

	// gate_string decomposition:-
	// gate_string =  "(Text: quReg2 = ),
	//
	//				  ( Qprint("%a\n", qr2) ),
	//
	//				  {  
	// 				  	[
	//					 Z_reg(qr, 2) ( Qprint("%r\n", qr2) ),
	//					 X_reg(qr, 1) ( Qprint("%r\n", qr2) ),
	//					 Y_reg(qr, 0) ( Qprint("%r\n", qr2) )
	//					],
	//
	//					[
	//					 Y_reg(qr, 2) ( Qprint("%r\n", qr2) ),
	//					 Y_reg(qr, 1) ( Qprint("%r\n", qr2) ),
	//					 Y_reg(qr, 0) ( Qprint("%r\n", qr2) )
	//					],
	//				  },
	//
	//				 ( Qprint("%a\n", qr2) )"

	return 0;
}