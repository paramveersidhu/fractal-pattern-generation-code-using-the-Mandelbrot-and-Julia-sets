#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 80

typedef struct Complex
{
	double real, imag;

} Complex;

typedef struct Pixel
{
	int red, green, blue;

} Pixel;

Complex complex_mult(Complex* a, Complex* b) {
	Complex result;
	result.real = a->real * b->real - a->imag * b->imag;
	result.imag = a->real * b->imag + a->imag * b->real;
	return result;
}

Complex complex_add(Complex* a, Complex* b) {
	Complex result;
	result.real = a->real + b->real;
	result.imag = a->imag + b->imag;
	return result;
}

double len_square(Complex* a) {
	double temp;
	temp = (a->real * a->real) + (a->imag * a->imag);
	return temp;
}

static int fractal(Complex* z,const Complex* c,int maxIter)
{
	double lengthSquared;
	int iter = 0;
	while (iter < maxIter) {
		++iter;
		*z = complex_mult(z, z);
		*z = complex_add(z, c);
		lengthSquared = z->real * z->real + z->imag * z->imag;
		if (lengthSquared > 4.0)
			return iter;
	}
	return 0;
}
Pixel convert(int color) {
	Pixel pixel;
	long remainder, quotient;
	int octalNumber[3] = { 0, 0, 0 };
	int i = 0, j;
	quotient = color;
	while (quotient != 0)
	{
		octalNumber[i++] = quotient % 8;
		quotient = quotient / 8;
	}
	pixel.red = octalNumber[2];
	pixel.green = octalNumber[1];
	pixel.blue = octalNumber[0];

	return pixel;
}

int main() {
	int height, width;
	Complex p;
	Complex new, old;
	double pr, pi;                  
	double newRe, newIm, oldRe, oldIm;   
	double moveX = -0.5; 
	int maxIterations = 511;
	FILE* outfileMandel;
	FILE* outfileJulia;
	outfileMandel = fopen("mandelbrot.ppm", "w");
	outfileJulia = fopen("julia.ppm", "w");
	fprintf(outfileMandel, "P3\n");
	fprintf(outfileJulia, "P3\n");
	fprintf(outfileMandel, "#Final Project Paramveer Singh\n");
	fprintf(outfileJulia, "#Final Project Paramveer Singh\n");
	printf("Columns =");
	scanf("%d", &height);
	printf("Rows =");
	scanf("%d", &width);
	printf("Columns %d and rows %d\n", height, width);
	fprintf(outfileMandel, "%d %d\n", height, width);
	fprintf(outfileJulia, "%d %d\n", height, width);
	fprintf(outfileMandel, "7\n");
	fprintf(outfileJulia, "7\n");
	double step_height = 4.0 / (double)height;
	double step_width = 4.0 / (double)width;
	Pixel pixel;
	Complex z, c;
	c.real = -0.8;
	c.imag = 0.156;
	printf("\nDANGER julia file is processing\n\n");
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			z.imag = ((double)y * 4.0 / (double)height) - 2.0;
			z.real = ((double)x * 4.0 / (double)width) - 2.0;
			int index = fractal(&z, &c, maxIterations);
			pixel = convert(index);
			fprintf(outfileJulia, "%d %d %d\n", pixel.red, pixel.green, pixel.blue);
		}
	}
	fclose(outfileJulia);
	printf("DANGER mandelbrot file is processing");
	for (int j = 0; j < height; j++) {
		for (int k = 0; k < width; k++) {
			pr = ((double)k * step_height) - 2.0;
			pi = ((double)j * step_width) - 2.0;

			newRe = newIm = oldRe = oldIm = 0;
			int i;
			for (i = 0; i < maxIterations; i++)
			{
				oldRe = newRe;
				oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + pr;
				newIm = 2 * oldRe * oldIm + pi;
				if ((newRe * newRe + newIm * newIm) > 4) break;
			}
			int color = i;

			pixel = convert(color);
			fprintf(outfileMandel, "%d %d %d\n", pixel.red, pixel.green, pixel.blue);
		}
	}
	fclose(outfileMandel);
	return 0;
}