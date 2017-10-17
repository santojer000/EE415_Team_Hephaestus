#include <iostream>
#include <math.h>
using namespace std;

void bit_reversal_indeces(int *forward_index, int *reversed_index);
void bit_reversal(double *samples_in, double *samples_out, int *reversed_index, int sample_size);
short FFT(long m, double *x, double *y);
short IFFT(long m, double *x, double *y);
void magnitude(unsigned int size, double *magnitude, double *real, double *complex);


//Global variables
//Frequency = (SAMPLE_FREQ * INDEX) / MAX_INDEX
const int SAMPLE_FREQ = 2000;
const int INDEX_BIT_LENGTH = 4;
const int MAX_INDEX = 16;

// Test driver for "Bit Mirroring Algorithm"
void main()
{
	int indeces[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	int re_index[16];

	double samples_in[16] = { 0, 0.5, 1, 0.5, 0, -0.5, -1, -0.5, 0, 0.5, 1, 0.5, 0, -0.5, -1, -0.5 };
	//double samples_in[16] = { 0, 1, 0, -1, 0, 1, 0, -1, 0, 1, 0, -1, 0, 1, 0, -1 };
	double samples_out[16];

	bit_reversal_indeces(indeces, re_index);
	bit_reversal(samples_in, samples_out, re_index, 16);

	int i = 0;
	for (i = 0; i < 16; i++)
	{
		cout << samples_in[i] << "      " << samples_out[i] << endl;
	}

	cout << "\n\n\n" << endl;

	double imaginary[16] = { 0 };
	FFT(4, samples_out, imaginary);
	
	double mag[16];

	magnitude(16, mag, samples_out, imaginary);

	for (i = 0; i < 16; i++)
	{
		//cout << samples_out[i] << "      " << imaginary[i] << endl;
		cout << mag[i] << endl;
	}

	system("pause");
}

/***********************************************************************
* Bit Mirroring Index Algorithim
* Run on initialization once to calculate bit reversed indeces
* Inputs: pointer to array of indeces in sequential order
*		  pointer to array of indeces to receieve reversed order 
* Outputs: Null
***********************************************************************/
//Global constants for function - set before compling
void bit_reversal_indeces(int *forward_index, int *reversed_index)
{
	//declaration of variables - unsigned short is the only data type
	//able to do bitwise shifting
	unsigned short i = 0;
	unsigned short j = 0;
	unsigned short k;
	unsigned short temp = 0;
	unsigned short re_index;

	//set array size to max bit length of index
	unsigned short index_stack[INDEX_BIT_LENGTH];

	for (i = 0; i < MAX_INDEX; i++)
	{
		k = 1;

		
		for (j = 0; j < INDEX_BIT_LENGTH; j++)
		{
			temp = i & k;			//mask bits
			temp = temp >> j;		//shift to zero position
			index_stack[j] = temp;		//push to array
			k = k << 1;				//shift mask bit
		}

		re_index = 0;		//set new index to zero
		for (j = 0; j < INDEX_BIT_LENGTH; j++)
		{
			//reconstruct mirrored byte and OR with new index
			re_index = re_index | (index_stack[j] << (INDEX_BIT_LENGTH - 1 - j));
		}

		//set new array to old array
		*(reversed_index + re_index) = *(forward_index + i);
	}
}


/***********************************************************************
* Bit Mirroring Algorithim
* Run on initialization once to calculate bit reversed indeces
* Inputs: 1) pointer to array of input samples
*		  2) pointer to array of output samples
*		  3) array of indexes for bit reversed order
*		  4) sample size of arrays
* Outputs: Null
***********************************************************************/
void bit_reversal(double *samples_in, double *samples_out, int *reversed_index, int sample_size)
{
	int i = 0;
	for (i = 0; i < sample_size; i++)
	{
		*(samples_out + i) = *(samples_in + *(reversed_index + i));
	}
}

//Compute the FFT
/********************************************************
* FFT Algoritm
* Inputs: m = 2^m length of array
*		  x = real 
*		  y = imaginary
* Outputs: None
********************************************************/
short FFT(long m, double *x, double *y)
{
	long n, i, i1, j, k, i2, l, l1, l2;
	double c1, c2, tx, ty, t1, t2, u1, u2, z;
	short int dir = -1;

	//Calculate the number of points
	n = 1;
	for (i = 0; i<m; i++)
		n *= 2;

	//FFT Computation
	c1 = -1.0;
	c2 = 0.0;
	l2 = 1;

	for (l = 0; l < m; l++) {
		l1 = l2;
		l2 <<= 1;
		u1 = 1.0;
		u2 = 0.0;
		for (j = 0; j<l1; j++) {
			for (i = j; i<n; i += l2) {
				i1 = i + l1;
				t1 = u1 * x[i1] - u2 * y[i1];
				t2 = u1 * y[i1] + u2 * x[i1];
				x[i1] = x[i] - t1;
				y[i1] = y[i] - t2;
				x[i] += t1;
				y[i] += t2;
			}
			z = u1 * c1 - u2 * c2;
			u2 = u1 * c2 + u2 * c1;
			u1 = z;
		}
		c2 = sqrt((1.0 - c1) / 2.0);
		if (dir == 1)
			c2 = -c2;
		c1 = sqrt((1.0 + c1) / 2.0);
	}

	//Scaling for forward transform
	if (dir == 1) {
		for (i = 0; i<n; i++) {
			x[i] /= n;
			y[i] /= n;
		}
	}

	return(1);
}

//Compute the IFFT
/********************************************************
* IFFT Algoritm
* Inputs: m = 2^m length of array
*		  x = real
*		  y = imaginary
* Outputs: None
********************************************************/
short IFFT(long m, double *x, double *y)
{
	long n, i, i1, j, k, i2, l, l1, l2;
	double c1, c2, tx, ty, t1, t2, u1, u2, z;
	short int dir = 1;

	//Calculate the number of points
	n = 1;
	for (i = 0; i<m; i++)
		n *= 2;

	//FFT Computation
	c1 = -1.0;
	c2 = 0.0;
	l2 = 1;

	for (l = 0; l < m; l++) {
		l1 = l2;
		l2 <<= 1;
		u1 = 1.0;
		u2 = 0.0;
		for (j = 0; j<l1; j++) {
			for (i = j; i<n; i += l2) {
				i1 = i + l1;
				t1 = u1 * x[i1] - u2 * y[i1];
				t2 = u1 * y[i1] + u2 * x[i1];
				x[i1] = x[i] - t1;
				y[i1] = y[i] - t2;
				x[i] += t1;
				y[i] += t2;
			}
			z = u1 * c1 - u2 * c2;
			u2 = u1 * c2 + u2 * c1;
			u1 = z;
		}
		c2 = sqrt((1.0 - c1) / 2.0);
		if (dir == 1)
			c2 = -c2;
		c1 = sqrt((1.0 + c1) / 2.0);
	}

	//Scaling for forward transform
	if (dir == 1) {
		for (i = 0; i<n; i++) {
			x[i] /= n;
			y[i] /= n;
		}
	}

	return(1);
}

/*******************************************************************
* Calculate Magnitude of Compleze Vector
* Inputs: size = length of array
*		  values = array of values to convert to abs value
* Outputs: None
*******************************************************************/
void magnitude(unsigned int size, double *magnitude, double *real, double *complex)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		magnitude[i] = (real[i] * real[i]) + (complex[i] * complex[i]);
		magnitude[i] = sqrt(magnitude[i]);
	}
}

