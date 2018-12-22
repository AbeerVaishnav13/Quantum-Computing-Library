#ifndef QCLIBS_H

#define QCLIBS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>

typedef struct qb {
	float ZCoeff, OCoeff;
}quBit;

void print(quBit x);

#include "QuantumMemAlloc.h"
#include "QuantumGates.h"

#define CHECK(test) ((test) ? 0:1)

void print(quBit x) {
	if(x.ZCoeff == 1 && x.OCoeff == 0)
		printf("1 |0>");
	else if(x.ZCoeff == 0 && x.OCoeff == 1)
		printf("1 |1>");
	else {
		printf("%f |0>", x.ZCoeff);
		if(x.OCoeff < 0)
			printf(" - ");
		else
			printf(" + ");
		printf("%f |1>", fabs(x.OCoeff));
	}
}

void Qprint(const char* format,...) {
	const char *traverse;
    quBit qb;
    quBit *qr;
    int i = 0;

    //Module 1: Initializing Myprintf's arguments 
    va_list arg;
    va_start(arg, format);

    for(traverse = format; CHECK(*traverse == '\n' || *traverse == '\0'); traverse++) {
        while( *traverse != '%') {
            putchar(*traverse);
            traverse++;
        }
        traverse++;

        //Module 2: Fetching and executing arguments
        switch(*traverse) {
            case 'q': qb = va_arg(arg, quBit);
            		  print(qb);
            		  break;

            case 'r': qr = va_arg(arg, quBit*);
            		  while(qr) {
            		  	print(qr[i++]);
            		  }
        }
    }

    putchar(*traverse);

    //Module 3: Closing argument list to necessary clean-up
    va_end(arg); 
}

#endif
