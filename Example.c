#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "QCLibs.h"

int main(int argc, char const *argv[]) {

	quBit y = newQubit();

	print(y);

	y = H(y);

	print(y);

	y = H(y);

	print(y);

	y = X(y);

	print(y);

	y = H(y);

	print(y);

	return 0;
}
