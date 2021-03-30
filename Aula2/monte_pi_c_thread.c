#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

double *sum = 0;
int n_iter;

void *calc_pi(void *vargp)
{

    printf("Enter the thread\n\n\n");

    double x, y, circulo, quadrado, pi;

    int i;
    for (i = 0; i < n_iter; i++)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        printf("X: %f || Y: %f\n", x, y);

        float result = x * x + y * y;
        printf("Result: %f\n", result);

        if (result <= 1)
        {
            circulo++;
        }
        quadrado++;
    }

    printf("Circulo: %f || Quadrado: %f\n", circulo, quadrado);
    pi = (double)(circulo / quadrado) * 4;
    printf("PI Thread: %f\n", pi);
    *sum = pi;
    return NULL;
}

int main(int argc, char const *argv[])
{
    char *p;

    n_iter = strtol(argv[1], &p, 10);
    int n_threads = strtol(argv[2], &p, 10);
    int n_runs = strtol(argv[3], &p, 10);

    printf("Runs: %d || Threads: %d || Iter: %d\n", n_iter, n_threads, n_runs);

    pthread_t thread_id;

    int i, j;

    for (i = 0; i < n_runs; i++)
    {
        for (j = 0; j < n_threads; j++)
        {
            pthread_create(&thread_id, NULL, calc_pi, (void *)&thread_id);
        }
        for (j = 0; j < n_threads; j++)
        {
            pthread_join(thread_id, NULL);
        }
    }
    *sum = *sum / (double)n_runs;

    double* result = sum;
    printf("PI:%f ", result);
    return 0;
}
