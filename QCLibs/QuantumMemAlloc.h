#ifndef QUANTUMMEMALLOC_H

#define QUANTUMMEMALLOC_H

// Declaring a new Qubit.
quBit newQubit(int init_state);

// Declaring a new Qubit Register with 'n' Qubits.
quBit* newQuRegister(size_t n);



// Function Definitions
//
//
//
//

quBit newQubit(int init_state) {
	quBit qb;

	if(init_state == 0) {
		qb.ZCoeff.real = 1.0;
		qb.OCoeff.real = 0.0;
		qb.ZCoeff.imag = qb.OCoeff.imag = 0.0;
	} else if(init_state == 1) {
		qb.ZCoeff.real = 0.0;
		qb.OCoeff.real = 1.0;
		qb.ZCoeff.imag = qb.OCoeff.imag = 0.0;
	}

	return qb;
}

quBit* newQuRegister(size_t n) {
	quBit *qr = (quBit*) malloc((n+1) * sizeof(quBit));
	for(int i = 0; i <= n; i++) {
		qr[i] = newQubit(0);
		if(i == n) {
			qr[i].ZCoeff.real = qr[i].OCoeff.real = 0;
			qr[i].ZCoeff.imag = qr[i].OCoeff.imag = 0;
		}
	}

	return qr;
}

#endif