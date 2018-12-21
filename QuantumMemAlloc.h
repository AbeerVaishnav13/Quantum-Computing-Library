#ifndef QUANTUMMEMALLOC_H

#define QUANTUMMEMALLOC_H

// Declaring a new Qubit.
quBit newQubit();

// Declaring a new Qubit Register with 'n' Qubits.
quBit* newQuRegister(size_t n);



// Function Definitions
//
//
//
//

quBit newQubit() {
	quBit *qb = (quBit*) malloc(sizeof(quBit));
	qb->ZCoeff = 1.0f;
	qb->OCoeff = 0.0f;

	return *qb;
}

quBit* newQuRegister(size_t n) {
	quBit *qr = (quBit*) malloc(n * sizeof(quBit));
	for(int i = 0; i < n; i++) {
		qr[i] = newQubit();
	}

	return qr;
}

#endif