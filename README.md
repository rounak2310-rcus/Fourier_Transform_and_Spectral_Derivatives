# Fourier Transform and Spectral Derivatives

A project exploring the mathematics and implementation of the Fourier Transform, Discrete Fourier Transform (DFT), Fast Fourier Transform (FFT), and Spectral Differentiation.

This repository contains both the mathematical foundations and the corresponding implementations written from scratch in C, together with Python integration for experimentation and visualisation.

---

## Motivation

The goal of this project was not only to implement the FFT algorithm, but also to understand the mathematics behind Fourier analysis and how it naturally leads to spectral methods for numerical differentiation.

Over the course of approximately two months, I studied the underlying mathematics, implemented the algorithms in C, interfaced them with Python, and documented the entire process in a set of lecture-style notes.

---

## Repository Contents

### Documentation

A 21-page document covering

- Fourier Series
- Fourier Transform
- Dirac Delta Function
- Vector Spaces
- Inner Product Spaces
- Hilbert Spaces
- \(L^2\) Spaces
- Discrete Fourier Transform (DFT)
- Fast Fourier Transform (FFT)
- Spectral Differentiation

The document also contains several appendices, including proofs of useful identities and a brief discussion of fractional derivatives.

---

### C Implementation

The following algorithms were implemented from scratch.

#### Discrete Fourier Transform (DFT)

- Direct implementation
- Matrix formulation
- User-defined complex number structure

#### Fast Fourier Transform (FFT)

- Recursive radix-2 Cooley-Tukey FFT
- Corresponding inverse FFT

#### Spectral Differentiation

Implementation of spectral derivatives using

FFT → Frequency-domain multiplication → Inverse FFT

---

### Python Integration

The C implementations were compiled into a shared library and accessed from Python using `ctypes`.

Python notebooks demonstrate

- Calling the C library
- Computing Fourier transforms
- Spectral differentiation
- Visualisation of the numerical results
- Comparison with analytical derivatives

---

## Features

- From-scratch implementation (no external FFT libraries)
- Custom complex number implementation in C
- FFT and inverse FFT
- Spectral differentiation
- Python interface using `ctypes`
- Mathematical documentation
- Numerical verification and visualisation

---

## Future Work

Possible future extensions include

- Convolution
- Fast cosine and sine transforms
- Fractional spectral derivatives
- Higher-dimensional FFTs
- Image processing applications
- Spectral PDE solvers

---

## References

The documentation draws inspiration from

- Stanford EE261 (Prof. Brad Osgood)
- Gilbert Strang
- Sheldon Axler
- MIT OCW
- Various research articles on spectral methods

---

## Author

**Rounak Chattopadhyay**

Engineering Physics Undergraduate  
Indian Institute of Technology (ISM) Dhanbad
