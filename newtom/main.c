#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define N 2
void Difference(float x[], float y[], int n)
{
    float *f = (float *)malloc((n+1)*sizeof(float));
	int k,i;
	for (k = 1; k <= n; k++) {
		f[0] = y[k];
		for (i = 0; i < k; i++)
			f[i + 1] = (f[i] - y[i]) / (x[k] - x[i]);
		y[k] = f[k];
	}
	free(f);
	return;
}

int main()
{
	int i;
	float b, varx = 50;
	float x[N + 1] = { 30, 45, 60 };
	float y[N + 1] = { 0.5, 0.7071068, 0.8660254 };
	Difference(x, y, N);
	b = y[N];
	for (i = N - 1; i >= 0; i--) {
		b = b * (varx - x[i]) + y[i];
	}
	printf("N2(%f) = %f\n", varx, b);
	return 0;
}
