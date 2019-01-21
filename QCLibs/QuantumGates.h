#ifndef QUANTUMGATES_H

#define QUANTUMGATES_H

// Quantum NOT Gate:-
// Applies a NOT function to the probabilistic coefficients of the Qubit.
// This can also be assumed as rotation about X-axiz of the Bloch sphere
// For single qubit
quBit X(quBit x);
// For register of qubits
quReg* X_reg(quReg *qr, int idx);

// Rotation about Y-axis of the Bloch sphere
// For single qubit
quBit Y(quBit x);

// For register of qubits
quReg* Y_reg(quReg *qr, int idx);

// Rotation about Z-axis of the Bloch sphere
// For single qubit
quBit Z(quBit x);

// For register of qubits
quReg* Z_reg(quReg *qr, int idx);

// Quantum Hadamard Gate:-
// Applies hadamard Function to the Qubit passed into it.
// Puts the Qubit into superposition of |0> state and |1> state.
//Probability of getting both states after measuring is 50-50.
// For single qubit
quBit H(quBit x);

// For register of qubits
quReg* H_reg(quReg *qr, int idx);

//Quantum Phase Gate:-
// Changes the phase of the qubit
// For single qubit
quBit S(quBit x);

// For register of qubits
quReg* S_reg(quReg *qr, int idx);

// Quantum Rotation Gate:-
// Rotates the Coefficient of Quantum state about Complex Axis.
// angle should be in PI/k format, where k = 1, 2, 3, ...
// For single qubit
quBit R(double angle, quBit x);

// For register of qubits
quReg* R_reg(double angle, quReg *qr, int idx);

// Quantum CNOT Gate (Controlled NOT):-
// if (x1 == |1>) {x2 = X(x2)}
// else {x2 = x2}
// "Generally used for entanglement of the Qubits x1 and x2".
// For two different qubits
void CNOT(quBit *x1, quBit *x2);

// For register of qubits
quReg* CNOT_reg(quReg *qr, int idx1, int idx2);

// Quantum Swap Gate
// Swaps the two qubits
// For two different qubits
void QSwap(quBit *x1, quBit *x2);

// For register of qubits
quReg* QSwap_reg(quReg *qr, int idx1, int idx2);


// Short-hand for applying gates to registers
quReg* applyGates_reg(const char* gate_string, quReg *qr);



// Also some helper functions...
int get_prev_state(quReg *qr, int idx) {
	int prev_state = 0;

	for(int i = qr->size-1; i >= 0; i--) {
		if((fabs(__round(qr->qb[i].ZCoeff.real)) > 0) || (fabs(__round(qr->qb[i].ZCoeff.imag)) > 0)) {
			prev_state |= 0;
		}
		else if((fabs(__round(qr->qb[i].OCoeff.real)) > 0) || (fabs(__round(qr->qb[i].OCoeff.imag)) > 0)) {
			prev_state |= 1;
		}

		if(i > 0)
			prev_state <<= 1;
	}



	return prev_state;
}

int product(int a, int b) {
	int i = a & b;
	for(int j = 16; j > 0; j /= 2)
		i = (i >> j) ^ i;
	return (i % 2);
}

Complex *mat;

void Init_matrix(quReg *qr) {
	mat = (newQuReg(qr->size)->matrix);
}

void updateMatrix(quReg *qr) {
	mat = qr->matrix;
}

// Function Definitions
//
//
//
//
//

quBit X(quBit x) {
	quBit qb = newQubit(0);

	qb.ZCoeff.real = x.OCoeff.real;
	qb.ZCoeff.imag = x.OCoeff.imag;
	
	qb.OCoeff.real = x.ZCoeff.real;
	qb.OCoeff.imag = x.ZCoeff.imag;

	return qb;
}

quReg* X_reg(quReg *qr, int idx) {
	int prev_state = 0, next_state = 0;

	prev_state = get_prev_state(qr, idx);

	next_state = prev_state ^ (1 << idx);

	qr->qb[idx] = X(qr->qb[idx]);

	double temp = qr->matrix[prev_state].real;
	qr->matrix[prev_state].real = qr->matrix[next_state].real;
	qr->matrix[next_state].real = temp;

	return qr;
}

quBit Z(quBit x) {
	quBit qb = newQubit(0);

	qb.ZCoeff = x.ZCoeff;

	qb.OCoeff.real = x.OCoeff.real;
	qb.OCoeff.imag = -1 * x.OCoeff.imag;

	return qb;
}

quReg* Z_reg(quReg *qr, int idx) {
	int prev_state = 0, next_state = 0;

	prev_state = get_prev_state(qr, idx);

	next_state = prev_state ^ (1 << idx);

	double mod_p = sqrt(pow(qr->matrix[prev_state].real, 2) + pow(qr->matrix[prev_state].imag, 2));
	double mod_n = sqrt(pow(qr->matrix[next_state].real, 2) + pow(qr->matrix[next_state].imag, 2));;

	qr->qb[idx] = Z(qr->qb[idx]);

	if(fabs(__round(qr->qb[idx].OCoeff.real)) > 0 || fabs(__round(qr->qb[idx].OCoeff.imag)) > 0) {
		if(mod_n > 0) {
			qr->matrix[next_state].real *= -1;
			qr->matrix[next_state].imag *= -1;
		}
		else if(mod_p > 0) {
			qr->matrix[prev_state].real *= -1;
			qr->matrix[prev_state].imag *= -1;
		}
	}

	return qr;
}

quBit Y(quBit x) {
	quBit qb = newQubit(0);

	qb.ZCoeff.real = x.OCoeff.imag;
	qb.ZCoeff.imag = -1 * x.OCoeff.real;

	qb.OCoeff.real = -1 * x.ZCoeff.imag;
	qb.OCoeff.imag = x.ZCoeff.real;

	return qb;
}

quReg* Y_reg(quReg *qr, int idx) {
	int prev_state = 0, next_state = 0;

	prev_state = get_prev_state(qr, idx);
	next_state = prev_state ^ (1 << idx);

	qr->qb[idx] = Y(qr->qb[idx]);

	double t = qr->matrix[prev_state].real;
	qr->matrix[prev_state].real = -1 * qr->matrix[next_state].imag;
	qr->matrix[next_state].imag = t;

	t = qr->matrix[prev_state].imag;
	qr->matrix[prev_state].imag = -1 * qr->matrix[next_state].real;
	qr->matrix[next_state].real = t;

	return qr;
}

quBit H(quBit x) {
	quBit qb = newQubit(0);

	qb.ZCoeff.real = (x.ZCoeff.real + x.OCoeff.real) / sqrt(2);
	qb.OCoeff.real = (x.ZCoeff.real - x.OCoeff.real) / sqrt(2);

	qb.ZCoeff.imag = (x.ZCoeff.imag + x.OCoeff.imag) / sqrt(2);
	qb.ZCoeff.imag = (x.ZCoeff.imag - x.OCoeff.imag) / sqrt(2);

	return qb;
}

quReg* H_reg(quReg *qr, int idx) {

	qr->qb[idx] = H(qr->qb[idx]);

	int increment = 1;
	static int len = 0;
	len = pow(2, len);
	int mat_size = pow(2, qr->size);
	int offset = pow(2, idx);
	int next_state = 0;
	int count = 0;

	double temp_ps_real, temp_ns_real, temp_ps_imag, temp_ns_imag;

	for(int prev_state = get_prev_state(qr, idx); count < len; count++) {
		next_state = prev_state + offset;

		temp_ps_real = qr->matrix[prev_state].real;
		temp_ps_imag = qr->matrix[prev_state].imag;

		temp_ns_real = qr->matrix[next_state].real;
		temp_ns_imag = qr->matrix[next_state].imag;
		
		qr->matrix[prev_state].real = (temp_ps_real + temp_ns_real) / sqrt(2);
		qr->matrix[next_state].real = (temp_ps_real - temp_ns_real) / sqrt(2);

		qr->matrix[prev_state].imag = (temp_ps_imag + temp_ns_imag) / sqrt(2);
		qr->matrix[next_state].imag = (temp_ps_imag - temp_ns_imag) / sqrt(2);

		prev_state = ((prev_state + increment) % mat_size);
	}
	return qr;
}

quBit S(quBit x) {
	quBit qb = newQubit(0);

	qb.ZCoeff = x.ZCoeff;

	qb.OCoeff.real = -1 * x.OCoeff.imag;
	qb.OCoeff.imag = x.OCoeff.real;

	return qb;
}

quReg* S_reg(quReg *qr, int idx) {
	qr->qb[idx] = S(qr->qb[idx]);

	int prev_state = (1 << idx);
	int next_state;
	int count = 0;


	// for(int i = prev_state; count < pow(2, qr->size-1); i = next_state) {
	// 	double temp = qr->matrix[i].real;
	// 	qr->matrix[i].real = -1 * qr->matrix[i].imag;
	// 	qr->matrix[i].imag = temp;

	// 	next_state = (((prev_state >> (idx+1)) + 1) << (idx + 1)) + 1;
	// 	prev_state = next_state;
	// 	count++;
	// }

	// for()

	return qr;
}

quBit R(double angle, quBit x) {
	quBit qb = newQubit(0);

	qb.ZCoeff = x.ZCoeff;

	qb.OCoeff.real = x.OCoeff.real * cos(angle) - x.OCoeff.imag * sin(angle);
	qb.OCoeff.imag = x.OCoeff.real * sin(angle) + x.OCoeff.imag * cos(angle);

	return qb;
}

quReg* R_reg(double angle, quReg *qr, int idx) {
	// int prev_state = get_prev_state(qr, idx);
	// int next_state = prev_state ^ (1 << idx);

	// printf("prev_state = %d, next_state = %d\n", prev_state, next_state);

	qr->qb[idx] = R(angle, qr->qb[idx]);

	int len = pow(2, qr->size);

	// for(int i = 0; i < )

	// if(prev_state & (1 << idx)) {
	// 	qr->matrix[prev_state].real = qr->qb[idx].OCoeff.real;
	// 	qr->matrix[prev_state].imag = qr->qb[idx].OCoeff.imag;

	// 	qr->matrix[next_state].real = qr->qb[idx].ZCoeff.real;
	// 	qr->matrix[next_state].imag = qr->qb[idx].ZCoeff.imag;
	// } else {
	// 	qr->matrix[prev_state].real = qr->qb[idx].ZCoeff.real;
	// 	qr->matrix[prev_state].imag = qr->qb[idx].ZCoeff.imag;

	// 	qr->matrix[next_state].real = qr->qb[idx].OCoeff.real;
	// 	qr->matrix[next_state].imag = qr->qb[idx].OCoeff.imag;
	// }

	return qr;
}

void CNOT(quBit *x1, quBit *x2) {
	quBit qb = newQubit(0);

	if(x1->OCoeff.real == 1 && x1->OCoeff.imag == 0)
		qb = X(*x2);

	*x2 = qb;
}

quReg* CNOT_reg(quReg *qr, int idx1, int idx2) {
	int prev_state1, next_state1, prev_state2, next_state2;

	prev_state1 = get_prev_state(qr, idx1);
	prev_state2 = get_prev_state(qr, idx2);

	// next_state1;
	// next_state2;

	CNOT(&qr->qb[idx1], &qr->qb[idx2]);

	return qr;
}

void QSwap(quBit *x1, quBit *x2) {
	quBit temp = *x1;
	*x1 = *x2;
	*x2 = temp;
}

quReg* QSwap_reg(quReg *qr, int idx1, int idx2) {
	int next_state, prev_state;
	printf("idx1 = %d, idx2 = %d\n", idx1, idx2);

	prev_state = get_prev_state(qr, idx1);

	int test_idx1 = (prev_state ^ (1 << idx1)) >> idx1;
	int test_idx2 = (prev_state ^ (1 << idx2)) >> idx2;
	printf("test_idx1 = %d, test_idx2 = %d\n", test_idx1, test_idx2);

	if(!(test_idx1 ^ test_idx2))
		next_state = prev_state;
	else if(test_idx1 ^ test_idx2)
		next_state = (prev_state ^ (1 << idx1)) ^ (1 << idx2);

	printf("prev_state = %d, next_state = %d\n", prev_state, next_state);

	QSwap(&qr->qb[idx1], &qr->qb[idx2]);

	Complex temp = qr->matrix[prev_state];
	qr->matrix[prev_state] = qr->matrix[next_state];
	qr->matrix[next_state] = temp;

	return qr;
}


quReg* applyGates_reg(const char* gate_string, quReg *qr) {
	int start_col = 0;
	int start_func = 0;
	int text_start = 0;

	int gate_num = 0;

	char msg[25] = "\0";
	int msg_idx = 0;

	int prev_H = 0;

	Init_matrix(qr);

	for(int i = 0; gate_string[i] != '\0'; i++) {
		if(gate_string[i] == '(') {
			i++;
			if(gate_string[i] == 'T') {
				i++;
				while(gate_string[i] != ')') {
					if((gate_string[i] == ' ' || gate_string[i] == ':') && text_start == 0) {
					}
					else {
						msg[msg_idx] = gate_string[i];
						msg_idx++;
						text_start = 1;
					}
					i++;
				}
				msg[msg_idx] = '\0';
			}
			else if(gate_string[i] == 'P') {
				i++;
				if(gate_string[i] == 'a') {
					printf("%s", msg);
					Qprint("%a\n", qr);
				}
				else if(gate_string[i] == ')' || (gate_string[i] == 'n' && gate_string[++i] == 'z')) {
					printf("%s", msg);
					Qprint("%r\n", qr);
				}
			}
		}
		else if(gate_string[i] == '{')
			start_func = 1;
		else if(gate_string[i] == '}')
			start_func = 0;

		else if(start_func) {
			if(start_col == 0 && gate_string[i] == '[')
				start_col = 1;
			else if(gate_string[i] == ']') {
				start_col = 0;
				gate_num = 0;
			}

			if(start_col) {
				if(gate_string[i] == ',' || gate_string[i] == ' ') {

				}
				else if(gate_string[i] == 'X') {
					qr = X_reg(qr, gate_num);
					gate_num = (gate_num+1) % qr->size;
				}
				else if(gate_string[i] == 'Y') {
					qr = Y_reg(qr, gate_num);
					gate_num = (gate_num+1) % qr->size;
				}
				else if(gate_string[i] == 'Z') {
					qr = Z_reg(qr, gate_num);
					gate_num = (gate_num+1) % qr->size;
				}
				else if(gate_string[i] == 'H') {
					qr = H_reg(qr, gate_num);
					gate_num = (gate_num+1) % qr->size;
				}
				else if(gate_string[i] == 'S') {
					if(gate_string[++i] == 'x') {
						i += 2;
						int idx1, idx2;
						int switch_idx = 0;
						for(int j = 0; ; i++) {
							if(gate_string[i] == '/')
								switch_idx = 1;
							if(isalnum(gate_string[i])) {
								if(!switch_idx)
									idx1  = idx1 * 10 + (gate_string[i] - '0');
								else if(switch_idx)
									idx2  = idx2 * 10 + (gate_string[i] - '0');
							}

							if(gate_string[i] == '(' || gate_string[i] == ',')
								break;
						}
						QSwap_reg(qr, 0, 1);
					}
					else {
						qr = S_reg(qr, gate_num);
						i--;
					}
					gate_num = (gate_num+1) % qr->size;
				}
				else if(gate_string[i] == 'R') {
					i += 2;
					int count = 0;
					double angle;
					int decimal = 0;
					for(int j = 0; ; j++, i++) {
						if(isalnum(gate_string[i])) {
							if(!decimal) {
								angle = angle * 10 + (gate_string[i] - '0');
							}
							else if(decimal) {
								count++;
								double summand = (double) (gate_string[i] - '0') / pow(10, count);
								angle = angle + summand;
							}
						}
						else if(gate_string[i] == '.') {
							decimal = 1;
						}

						if(gate_string[i] == '(' || gate_string[i] == ',')
							break;
					}
					i--;
					angle = angle * PI / 180;
					qr = R_reg(angle, qr, gate_num);
					gate_num = (gate_num+1) % qr->size;
				}
				else if(gate_string[i] == '1') {
					gate_num = (gate_num+1) % qr->size;
				}
			}
		}

		else {
			
		}
	}

	return qr;
}

#endif
