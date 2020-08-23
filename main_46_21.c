#include "metod_46_21.h"
#define exp 2.71828183
size_t stringLength(const char *str)
{
	size_t length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return length;

}

int stringComp(const char *str1, const char *str2)
{

	size_t i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i] || abs((int)(stringLength(str1) - stringLength(str2))) != 0) {
			return -1;
		}
		i++;
	}
	return 1;
}
double func(double x)
{
	//return sin(x);
	//return 1 / x;
	//return (pow(exp, x) + pow(exp, ((-1)*x))) / (pow(exp, x) - pow(exp, ((-1)*x)));
	return pow(exp,x)/(1+0.1*pow(exp,x)+0.01*sin(x*10000));
}

int main(int argc, char* argv[])
{
	int P, n, k, j, res, err;
	clock_t beginTime, endTime;
	int flagP = 0, flagT = 0;
	int i = 1;
	double *f_x, *x, a, b, *ksi, f_x0, x0, f_xn1, xn1;
	double *c1, *c2, *c3;
	double ftemp,temp;
	char *filenameIn = "46_21_in.txt";
	char *filenameOut = "46_21_out.txt";
	FILE *in, *out;


	
	beginTime = clock();
	debug = error = 0;

	if (argc >= 3) {
		if (argv[1][0] != '-')
		{
			filenameIn = argv[1];
			filenameOut = argv[2];
			i = 3;
		}
		else
		{
			i = 1;
		}
	}
	for (; i < argc; i++)
	{
		if (stringComp(argv[i], "-p") == 1)
		{
			flagP = 1;
		}
		else if (stringComp(argv[i], "-h") == 1 || stringComp(argv[i], "-?") == 1)
		{
			printf("Usage: lss [input_file_name] [output_file_name] [options] \nWhere options include : \n-d    print debug messages[default OFF] \n- e    print errors[default OFF] \n- p    print matrix[default OFF] \n- t    print execution time[default OFF] \n- h, -? print this and exit \nDefault input_file_name value is lss_00_00_in.txt, default output_file_name value is lss_00_00_out.txt.");
		}
		else if (stringComp(argv[i], "-d") == 1)
		{
			debug = 1;
		}
		else if (stringComp(argv[i], "-e") == 1)
		{
			err = 1;
		}
		else if (stringComp(argv[i], "-t") == 1)
		{
			flagT = 1;
		}
		else
		{
			if (err)
			{
				printf(stderr, "Parametr zadan ne pravilno\n");
			}
			return -5;
		}
	}

	in = fopen(filenameIn, "r");
	out = fopen(filenameOut, "w");
	if (out == NULL)
	{
		if (err)
		{
			printf(stderr, "Oshibka pri otkritii vhodnogo fayla\n");
		}
		return -4;
	}

	if (in == NULL)
	{
		if (err)
		{
			printf(stderr, "Oshibka pri otkritii vhodnogo fayla\n");
		}
		return -1;
	}
	if (fscanf(in, "%d", &P) != 1)
	{
		fclose(in);
		if (err)
		{
			printf(stderr, "Oshibka pri razmernosti matrici libo razmer matrichi menishe nulya\n");
		}
		return -1;
	}

	if (fscanf(in, "%d", &n) != 1 || n < 0)
	{
		fclose(in);
		if (err)
		{
			printf(stderr, "Oshibka pri razmernosti matrici libo razmer matrichi menishe nulya\n");
		}
		return -1;
	}



	x = (double*)malloc(n * sizeof(double));
	f_x = (double*)malloc(n * sizeof(double));
	ksi = (double*)malloc((n + 1) * sizeof(double));
	c1 = (double*)malloc(n * sizeof(double));
	c2 = (double*)malloc(n * sizeof(double));
	c3 = (double*)malloc(n * sizeof(double));
	if (x == NULL || f_x == NULL || ksi == NULL)
	{
		fclose(in);
		if (err)
		{
			printf(stderr, "Oshibka pri vidilenii pamyati\n");
		}
		return -2;
	}
	if (fscanf(in, "%lf %lf", &x0, &f_x0) != 2)
	{
		fclose(in);
		if (err)
		{
			printf(stderr, "Oshibka pri schitivanii\n");
		}
		return -3;
	}
	for (j = 0; j < n; j++)
	{
		if (fscanf(in, "%lf %lf", &x[j], &f_x[j]) != 2)
		{
			fclose(in);
			if (err)
			{
				printf(stderr, "Oshibka pri schitivanii\n");
			}
			return -3;
		}
	}
	if (fscanf(in, "%lf %lf", &xn1, &f_xn1) != 2)
	{
		fclose(in);
		if (err)
		{
			printf(stderr, "Oshibka pri schitivanii\n");
		}
		return -3;
	}
	if (fscanf(in, "%lf", &a) != 1)
	{
		fclose(in);
		if (err)
		{
			printf(stderr, "Oshibka pri razmernosti matrici libo razmer matrichi menishe nulya\n");
		}
		return -1;
	}

	if (fscanf(in, "%lf", &b) != 1)
	{
		fclose(in);
		if (err)
		{
			printf(stderr, "Oshibka pri razmernosti matrici libo razmer matrichi menishe nulya\n");
		}
		return -1;
	}

	if (fscanf(in, "%d", &k) != 1)
	{
		fclose(in);
		if (err)
		{
			printf(stderr, "Oshibka pri razmernosti matrici libo razmer matrichi menishe nulya\n");
		}
		return -1;
	}
	for (i = 1; i < n; i++)
	{
		ksi[i] = 0.5 * (x[i - 1] + x[i]);
	}
	ksi[0] = x0;
	ksi[n] = xn1;
	fclose(in);

	if (flagP)
	{
		//print(A, B, n);
	}
	Coeff_46_21(n, x, f_x, ksi, c1, c2, c3, x0, f_x0, xn1, f_xn1);

	for (i = 0; i < k; i++)
	{
		temp = a + (b - a) / k*i;
		ftemp = Value_46_21(temp, n, c1, c2, c3, ksi);
		fprintf(out,"%lf %lf %lf %lf\n",temp,ftemp,func(temp),fabs(ftemp-func(temp)));
	}
	if (flagT)
	{
		endTime = clock();
		printf("%lf\n", (double)(endTime - beginTime) / CLOCKS_PER_SEC);
	}
	
	printf("%d %d\n", P, n);
	printf("%lf %lf\n", x0, f_x0);
	for (i = 0; i < n; i++)
	{
		printf("%lf %lf\n", x[i], f_x[i]);
	}
	printf("%lf %lf\n", xn1, f_xn1);
	printf("%lf %lf\n", a, b);
	printf("%d", k);

	/*Освобождение памяти*/
	free(x);
	free(f_x);
	free(ksi);
	fclose(out);


	system("pause");
	return 0;
}
