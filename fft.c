#include "fft.h"
#include <math.h>

complex add(complex a, complex b) {
	complex c;
	c.re = a.re + b.re;
	c.im = a.im + b.im;
	return c;
}

complex sub(complex a, complex b) {
	complex c;
	c.re = a.re - b.re;
	c.im = a.im - b.im;
	return c;
}

complex mul(complex a, complex b) {
	complex c;
	c.re = a.re * b.re - a.im * b.im;
	c.im = a.re * b.im + a.im * b.re;
	return c;
}

void bit_reverse(complex x[], int N) {
	int j = 0;

	for (int i = 1; i < N; i++) {
		int bit = N >> 1;

		while (j & bit) {
			j ^= bit;
			bit >>= 1;
		}

		j ^= bit;

		if (i < j) {
			complex temp = x[i];
			x[i] = x[j];
			x[j] = temp;
		}
	}
}

void fft(complex x[], int N) {
	bit_reverse(x, N);

	for (int len = 2; len <= N; len *= 2) {
		double angle = -2.0 * PI / len;

		for (int i = 0; i < N; i += len) {

			for (int j = 0; j < len / 2; j++) {

				double theta = angle * j;

				complex w;
				w.re = cos(theta);
				w.im = sin(theta);

				complex u = x[i + j];
				complex v = mul(w, x[i + j + len / 2]);

				x[i + j] = add(u, v);
				x[i + j + len / 2] = sub(u, v);
			}
		}
	}
}

void ifft(complex x[], int N) {
	bit_reverse(x, N);

	for (int len = 2; len <= N; len *= 2) {
		double angle = 2.0 * PI / len;

		for (int i = 0; i < N; i += len) {

			for (int j = 0; j < len / 2; j++) {

				double theta = angle * j;

				complex w;
				w.re = cos(theta);
				w.im = sin(theta);

				complex u = x[i + j];
				complex v = mul(w, x[i + j + len / 2]);

				x[i + j] = add(u, v);
				x[i + j + len / 2] = sub(u, v);
			}
		}
	}

	for (int i=0; i<N ; i++) {

		x[i].re /= (double) N;
		x[i].im /= (double) N;

	}
}
