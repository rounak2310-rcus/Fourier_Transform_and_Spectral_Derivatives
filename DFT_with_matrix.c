#define USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct complex {
	double re;
	double im;
} complex;

complex complex_number(double arg) {
	complex z;

	z.re = cos(arg);
	z.im = sin(arg);

	return z;
}

complex** dft(int N) {

	double p = -1*2*M_PI/((double)N);
	complex **matrix = malloc(N*sizeof(complex *));
	
	if (matrix==NULL){
	    exit(-1);
	}

	for (int i=0; i<N; i++) {
		matrix[i] = malloc(N*sizeof(complex));
	}

	for (int i=0; i<N; i++) {
		for (int j=i; j<N; j++) {

			complex z = complex_number(p*i*j);
			matrix[i][j] = z;
		}
	}

	for (int i=1; i<N; i++) {
		for (int j=0; j<i; j++) {
			matrix[i][j] = matrix[j][i];
		}
	}

	return matrix;
}

complex* DFT(complex x[], int N) {

	complex* X = malloc(N* sizeof(complex));
	
	if (X==NULL){
	    exit(-1);
	}
	
	complex **F = dft(N);

	for (int i=0; i<N; i++) {
		complex h = {0, 0};
		for (int j=0; j<N; j++) {
			complex k = F[i][j];
			h.re += x[j].re*k.re - x[j].im*k.im;
			h.im += x[j].re*k.im + x[j].im*k.re;
		}
		X[i] = h;
	}

	for (int i = 0; i < N; i++) {
		free(F[i]);
	}
	free(F);

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