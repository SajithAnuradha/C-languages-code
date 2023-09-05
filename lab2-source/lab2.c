// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // stdlib includes malloc() and free()

// user-defined header files
#include "mypcm.h"
#include <math.h>

// function prototypes
void run(asignal *inputsignal);
void print_values(int *dsignal)
{
    int endarray = 9999;
    int size = 0;
    while (dsignal[size] != endarray)
    {
        size++;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%i", dsignal[i]);
    }
    printf("\n");
}

int main()
{
    asignal *inputsignal = (asignal *)malloc(sizeof(asignal));
    run(inputsignal);

    // call any other function here

    free(inputsignal);
    return 0;
}

void run(asignal *inputsignal)
{
    int A, omega, sigma, duration, interval, encoderbits;

    scanf("%d %d %d %d %d %d", &A, &omega, &sigma, &duration, &interval, &encoderbits);

    inputsignal->A = A;
    inputsignal->omega = omega;
    inputsignal->sigma = sigma;
    inputsignal->duration = duration;

    float *samples;
    samples = (float *)malloc(9 * sizeof(float));
    int *pcmpulses;
    pcmpulses = (int *)malloc(10 * sizeof(int));
    int *dsignal;
    dsignal = (int *)malloc(20 * sizeof(int));
    asignal signal = *inputsignal;
    int levels = (int)pow(2, encoderbits);

    sampler(samples, interval, signal);
    quantizer(samples, pcmpulses, levels, signal);
    encoder(pcmpulses, dsignal, encoderbits);
    print_values(dsignal);
}
