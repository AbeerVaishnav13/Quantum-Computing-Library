#ifndef QCLIBS_H

#define QCLIBS_H

typedef struct qb {
	float ZCoeff, OCoeff;
}quBit;

void print(quBit x);

#include "QuantumMemAlloc.h"
#include "QuantumGates.h"

void print(quBit x) {
	if(x.ZCoeff == 1 && x.OCoeff == 0)
		printf("1 |0>\n");
	else if(x.ZCoeff == 0 && x.OCoeff == 1)
		printf("1 |1>\n");
	else {
		printf("%f |0>", x.ZCoeff);
		if(x.OCoeff < 0)
			printf(" - ");
		else
			printf(" + ");
		printf("%f |1>\n", fabs(x.OCoeff));
	}
}

#endif
