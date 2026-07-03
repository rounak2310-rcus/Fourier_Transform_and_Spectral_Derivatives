#include "spectral_diff.h"
#include <math.h>

void spectral_derivative(complex x[], int N, double L) {
    fft(x, N);

    for (int m = 0; m < N; m++) {
        int k;

        if (m < N/2)
            k = m;
        else
            k = m - N;

        double factor = 2.0 * PI * k / L;

        double a = x[m].re;
        double b = x[m].im;

        x[m].re = -factor * b;
        x[m].im =  factor * a;
    }

    ifft(x, N);
}