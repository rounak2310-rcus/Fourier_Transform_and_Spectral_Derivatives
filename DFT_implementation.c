#define USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct complex {
	double re;
	double im;
} complex;

complex* DFT(complex x[], int N) {

	complex* X = malloc(N* sizeof(complex));

	if (X==NULL) {
		exit(-1);
	}

	double p = -1*2*M_PI/((double)N);

	complex w = {cos(p), sin(p)};

	complex W[N];
	
	W[0].re = 1;
	W[0].im = 0;

	for (int k=1; k<N; k++) {
		W[k].re = W[k-1].re*w.re - W[k-1].im*w.im;
		W[k].im = W[k-1].re*w.im + W[k-1].im*w.re;
	}

	for (int i=0; i<N; i++) {
		complex z = {0, 0};
		for (int j=0; j<N; j++) {

			int P = (i*j)%N;
			z.re += x[j].re*W[P].re - x[j].im*W[P].im;
			z.im += x[j].re*W[P].im + x[j].im*W[P].re;

		}
		X[i] = z;
	}

	return X;

}

int main() {

	complex x[4] = {{1, 0}, {2, 0}, {0, 0}, {-1, 0}};

	complex* X = DFT(x, 4);

	for (int k=0; k<4; k++) {
		printf("%lf + %lf i\n", X[k].re, X[k].im);
	}

	free(X);

	return 0;
}