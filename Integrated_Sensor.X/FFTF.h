#ifndef FFTF.h
#define FFTF.h
#include <math.h>

// List of functions
void create_indeces(int *indeces);
void bit_reversal_indeces(int *forward_index, int *reversed_index);
void bit_reversal(double *samples_in, double *samples_out, int *reversed_index, int sample_size);
short FFT(long m, double *x, double *y);
short IFFT(long m, double *x, double *y);
void magnitude(unsigned int size, double *magnitude, double *real, double *complex);
double max(double *input_array, unsigned int size);
void frequency_scaling(int *indeces);
void amplitude_scaling(unsigned int sample_size, double *samples);
void fft_shift(unsigned int sample_size, double *samples);

//Function Bodies

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*  Function:    create_indices				                         *
*  Input:       int pointer			                             *
*  Output:      void                                                *
*  See Funcs:   N/A                                                 *
*  Description: Function that creates indices.						 *
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void create_indeces(int *indeces)
{
	int i = 0;
	for (i = 0; i < MAX_INDEX; i++)
	{
		indeces[i] = i;
	}
}	// End function

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*  Function:    bit_reversal_indeces				                 *
*  Input:       int pointer, int pointer			                 *
*  Output:      void                                                *
*  See Funcs:   N/A                                                 *
*  Description: Bit Mirroring Index Algorithim						 *
*					- Run on initialization once to calculate bit    *
*					  reversed indeces.								 *
*					- pointer to array of indeces in sequential		 *
*					  order.										 *
*		            - pointer to array of indeces to receieve        *
*					  reversed order.								 *
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void bit_reversal_indeces(int *forward_index, int *reversed_index)
{
	// Global constants for function - set before compling
	// Declaration of variables - unsigned short is the only data type
	// Able to do bitwise shifting
	unsigned short i = 0;
	unsigned short j = 0;
	unsigned short k;
	unsigned short temp = 0;
	unsigned short re_index;

	// Set array size to max bit length of index
	unsigned short index_stack[INDEX_BIT_LENGTH];

	for (i = 0; i < MAX_INDEX; i++)
	{
		k = 1;


		for (j = 0; j < INDEX_BIT_LENGTH; j++)
		{
			temp = i & k;			// Mask bits
			temp = temp >> j;		// Shift to zero position
			index_stack[j] = temp;	// Push to array
			k = k << 1;				// Shift mask bit
		}

		re_index = 0;	// Set new index to zero
		for (j = 0; j < INDEX_BIT_LENGTH; j++)
		{
			// Reconstruct mirrored byte and OR with new index
			re_index = re_index | (index_stack[j] << (INDEX_BIT_LENGTH - 1 - j));
		}

		// Set new array to old array
		*(reversed_index + re_index) = *(forward_index + i);
	}
}	// End function

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*  Function:    bit_reversal						                 *
*  Input:       double pointer, double pointer, int pointer, int	 *
*  Output:      void                                                *
*  See Funcs:   N/A                                                 *
*  Description: Bit Mirroring Algorithim							 *
*					- pointer to array of input samples.			 *
*					- pointer to array of output samples.			 *
*					- array of indexes for bit reversed order.		 *
*					- sample size of arrays.						 *
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void bit_reversal(double *samples_in, double *samples_out, int *reversed_index, int sample_size)
{
	int i = 0;
	for (i = 0; i < sample_size; i++)
	{
		*(samples_out + i) = *(samples_in + *(reversed_index + i));
	}
}	// End function

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*  Function:    FFT									             *
*  Input:       long, double pointer, double pointer				 *
*  Output:      Boolean (1/0)                                       *
*  See Funcs:   N/A                                                 *
*  Description: Function that performs FFT.						 *
*					- m = 2^m length of array						 *
*					- x = real										 *
*					- y = imaginary									 *
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
short FFT(long m, double *x, double *y)
{
	// Compute FFT
	long n, i, i1, j, k, i2, l, l1, l2;
	double c1, c2, tx, ty, t1, t2, u1, u2, z;
	short int dir = -1;

	//Calculate the number of points
	n = 1;
	for (i = 0; i < m; i++)
	{
		n *= 2;
	}

	//FFT Computation
	c1 = -1.0;
	c2 = 0.0;
	l2 = 1;

	for (l = 0; l < m; l++)
	{
		l1 = l2;
		l2 <<= 1;
		u1 = 1.0;
		u2 = 0.0;
		for (j = 0; j<l1; j++)
		{
			for (i = j; i<n; i += l2)
			{
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
		if (dir == 1) c2 = -c2;
		c1 = sqrt((1.0 + c1) / 2.0);
	}

	//Scaling for forward transform
	if (dir == 1)
	{
		for (i = 0; i<n; i++)
		{
			x[i] /= n;
			y[i] /= n;
		}
	}

	return(1);
}	// End function

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*  Function:    IFFT									             *
*  Input:       long, double pointer, double pointer				 *
*  Output:      Boolean (1/0)                                       *
*  See Funcs:   N/A                                                 *
*  Description: Function that performs an inverse FFT.				 *
*				 Used for auto correlation.							 *
*					- m = 2^m length of array						 *
*					- x = real										 *
*					- y = imaginary									 *
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
short IFFT(long m, double *x, double *y)
{
	// Comput IFFT
	long n, i, i1, j, k, i2, l, l1, l2;
	double c1, c2, tx, ty, t1, t2, u1, u2, z;
	short int dir = 1;

	//Calculate the number of points
	n = 1;
	for (i = 0; i < m; i++)
	{
		n *= 2;
	}

	//FFT Computation
	c1 = -1.0;
	c2 = 0.0;
	l2 = 1;

	for (l = 0; l < m; l++)
	{
		l1 = l2;
		l2 <<= 1;
		u1 = 1.0;
		u2 = 0.0;
		for (j = 0; j<l1; j++)
		{
			for (i = j; i<n; i += l2)
			{
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
	if (dir == 1)
	{
		for (i = 0; i<n; i++)
		{
			x[i] /= n;
			y[i] /= n;
		}
	}

	return(1);
}	// End function

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*  Function:    magnitude								             *
*  Input:       unsigned int, double pointer, double pointer,		 *
*				 double pointer										 *
*  Output:      void                                                *
*  See Funcs:   N/A                                                 *
*  Description: Function that calculates the magnitude of the		 *
*				 complete vector.									 *
*					- size = length of array						 *
*					- values = array of values to converto to abs val*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void magnitude(unsigned int size, double *magnitude, double *real, double *complex)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		magnitude[i] = (real[i] * real[i]) + (complex[i] * complex[i]);
		magnitude[i] = sqrt(magnitude[i]);
	}
}	// End function

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*  Function:    max									             *
*  Input:       double pointer, unsigned int						 *
*  Output:      double                                              *
*  See Funcs:   N/A                                                 *
*  Description: Function that calculates the max value an array.	 *
*					- input array = array of doubles				 *
*					- size = size of array							 *
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
double max(double *input_array, unsigned int size)
{
	size = size / 2;
	int i = 0;
	double max = 0;
	for (i = 0; i < size - 1; i++)
	{
		if (max < input_array[i]) max = input_array[i];
	}

	return max;
}	// End function

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*  Function:    frequency_scaling									 *
*  Input:       int pointer										 *
*  Output:      void                                                *
*  See Funcs:   N/A                                                 *
*  Description: Function that scales frequencies					 *
*					- input array = array of indices for FFT		 *
*					- sample_size = length of input array			 *
*					- sample_frequency = data sampling frequency     *
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void frequency_scaling(int *indeces)
{
	int i = 0;
	for (i = 0; i < MAX_INDEX; i++)
	{
		indeces[i] = indeces[i] - (MAX_INDEX / 2);
		indeces[i] = (SAMPLE_FREQ * indeces[i]) / MAX_INDEX;
	}
}	// End function

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*  Function:    amplitude_scaling									 *
*  Input:       unsigned int, double pointer						 *
*  Output:      void                                                *
*  See Funcs:   N/A                                                 *
*  Description: Function that scales amplitude						 *
*					- max = max value in input array				 *
*					- sample_size = length of input array			 *
*					- samples = array of sample values			     *
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void amplitude_scaling(unsigned int sample_size, double *samples)
{
	int i = 0;
	double max_val = max(samples, sample_size);

	for (i = 0; i < sample_size; i++)
	{
		samples[i] = samples[i] / max_val;
	}
}	// End function

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*  Function:    fft_shift											 *
*  Input:       unsigned int, double pointer						 *
*  Output:      void                                                *
*  See Funcs:   N/A                                                 *
*  Description: Function that shifts the axis to be zero centered.  *
*				 sample_size = length of sample array				 *
*				 samples = array of sample values					 *
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void fft_shift(unsigned int sample_size, double *samples)
{
	int i = 0;
	double temp1 = 0, temp2 = 0;
	unsigned int N = sample_size / 2;

	for (i = 0; i < N; i++)
	{
		temp1 = samples[i];
		temp2 = samples[i + N];

		samples[i] = temp2;
		samples[i + N] = temp1;
	}
}	// End function




#endif