// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // includes malloc(),free()
// Add any necessary headers here
#include <math.h>

// user-defined header files
#include "mypcm.h" // do not modify this file

// put your function prototypes for additional helper functions below:

// implementation

float analog_signal_generator(asignal signal, int t)
{
	float value;
	value = signal.A * (sin(signal.omega * t + signal.sigma));
	return value;
}
void sampler(float *samples, int interval, asignal signal)
{
	int endArray = 9999;
	int j = 0;
	for (int i = 0; i * interval <= signal.duration; i++)
	{
		samples[i] = analog_signal_generator(signal, i * interval);

		j += 1;
	}
	samples[j + 1] = endArray;
}

void quantizer(float *samples, int *pcmpulses, int levels, asignal signal)
{

	int size = 0;
	int endArray = 9999;
	int i = 0;
	while (samples[i] != endArray)
	{
		i++;
	}
	size = i - 1;

	int Amptitude = signal.A;

	for (int i = 0; i < size; i++)
	{
		pcmpulses[i] = (int)(((samples[i] + Amptitude) / (2 * Amptitude)) * levels);
		}
	pcmpulses[size] = endArray;
}

void encoder(int *pcmpulses, int *dsignal, int encoderbits)
{
	int j = 0;
	int length = 0;
	int endarray = 9999;
	while (pcmpulses[length] != endarray)
	{
		length += 1;
	}

	for (int i = 0; i < length; i++)
	{
		int pulse = pcmpulses[i];
		for (int k = encoderbits - 1; k >= 0; k--)
		{
			int bit = (pulse >> k) & 1;
			dsignal[j] = bit;
			j++;
		}
	}
	dsignal[j] = endarray;
}

// int main()
// {

// 	int *pcm;
// 	pcm = (int *)malloc(20 * sizeof(int));

// 	int *sig;
// 	sig = (int *)malloc(9 * sizeof(int));

// 	pcm[0] = 2;
// 	pcm[1] = 3;
// 	pcm[2] = 0;
// 	pcm[3] = 1;
// 	pcm[4] = 3;
// 	pcm[5] = 0;
// 	pcm[6] = 9999;

// 	int bits = 2;
// 	encoder(pcm, sig, bits);

// 	return 0;
// }