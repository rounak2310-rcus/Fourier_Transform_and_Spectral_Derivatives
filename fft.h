#ifndef FFT_H
#define FFT_H

#define PI 3.14159265358979323846

typedef struct {
	double re;
	double im;
} complex;

void fft(complex x[], int N);
void ifft(complex x[], int N);

#endif