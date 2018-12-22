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
		qb.ZCoeff = 1.0f;
		qb.OCoeff = 0.0f;
	} else if(init_state == 1) {
		qb.ZCoeff = 0.0f;
		qb.OCoeff = 1.0f;
	} else {
		printf("ERROR: Valid initial states are 0 or 1...\n");
		free(&qb);
		exit(0);
	}

	return qb;
}

quBit* newQuRegister(size_t n) {
	quBit *qr = (quBit*) malloc(n * sizeof(quBit));
	for(int i = 0; i <= n; i++) {
		qr[i] = newQubit(0);
		if(i == n) {
			qr[i].ZCoeff = qr[i].OCoeff = 0;
		}
	}

	return qr;
}

#endif