#pragma once
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning (disable:4996)


int error, debug;

void SolveSystem(int n, double *a, double *c, double *d, double *b, double *x);
void Coeff_46_21(int n, double *x, double *f_x, double *ksi, double *c1, double *c2, double *c3, double x0, double f_x0, double xn1, double f_xn1);
double Value_46_21(double t, int n, double *c1, double *c2, double *c3, double *ksi);


