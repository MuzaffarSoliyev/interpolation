#include <math.h>
#include "metod_46_21.h"

void SolveSystem(int n, double *a, double *c, double *d, double *b, double *x)
{
	int i;
	c[0] /= a[0];
	for (i = 1; i < n - 1; i++)
	{
		a[i] -= d[i - 1] * c[i - 1];
		c[i] /= a[i];
	}
	a[n - 1] -= d[n - 2] * c[n - 2];

	x[0] = b[0] / a[0];
	for (i = 1; i < n; i++)
		x[i] = (b[i] - d[i - 1] * x[i - 1]) / a[i];

	for (i = n - 2; i >= 0; i--)
		x[i] -= c[i] * x[i + 1];
}

void Coeff_46_21(int n, double *x, double *f_x, double *ksi, double *c1, double *c2, double *c3,double x0,double f_x0,double xn1,double f_xn1)
{
	int i, j;
	double tmp1;
	double*v, *al, *cl, *dl, *c;
	v = (double*)malloc((n + 1)*sizeof(double));
	al=(double*)malloc((n + 1)*sizeof(double));
	cl = (double*)malloc((n + 1)*sizeof(double));
	dl = (double*)malloc((n + 1)*sizeof(double));
	c=(double*)malloc((n + 1)*sizeof(double));

	for (i = 1; i < n; i++)
	{
		al[i] = 1.0 / (ksi[i] - x[i - 1]) + 1.0 / (ksi[i] - ksi[i - 1]) + 1.0 / (x[i] - ksi[i]) + 1.0 / (ksi[i + 1] - ksi[i]);
		cl[i] = 1.0 / (ksi[i + 1] - x[i]) - 1.0 / (ksi[i + 1] - ksi[i]);
		dl[i - 1] = 1.0 / (x[i - 1] - ksi[i - 1]) - 1.0 / (ksi[i] - ksi[i - 1]);
		c[i] = f_x[i - 1] * (1.0 / (x[i - 1] - ksi[i - 1]) + 1.0 / (ksi[i] - x[i - 1])) +
			f_x[i] * (1.0 / (x[i] - ksi[i]) + 1.0 / (ksi[i + 1] - x[i]));
	}

	al[0] = 1.0;
	cl[0] = 0.0;
	al[n] = 1.0;
	dl[n - 1] = 0.0;

	c[0] = f_x0;
	c[n] = f_xn1;

	SolveSystem(n + 1, al, cl, dl, c, v);



	for (i = 0; i < n; i++)
	{
		c1[i] = v[i];
		tmp1 = ((v[i + 1] - f_x[i]) / (ksi[i + 1] - x[i]) - (f_x[i] - v[i]) / (x[i] - ksi[i])) / (ksi[i + 1] - ksi[i]);
		c2[i] = (f_x[i] - v[i]) / (x[i] - ksi[i]) - (x[i] - ksi[i]) * tmp1;
		c3[i] = tmp1;
	}
}

double Value_46_21(double t, int n, double *c1,double *c2,double *c3, double *ksi)
{
	int i;

	for (i = 0; i < n - 1; i++) if (t <= ksi[i + 1]) break;

	return c1[i] + c2[i] * (t - ksi[i]) + c3[i] * (t - ksi[i]) * (t - ksi[i]);
}
