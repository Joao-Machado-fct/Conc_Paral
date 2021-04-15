#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <omp.h>
#include <windows.h>

int main(int argc, char const *argv[])
{
    //TEST
    char *p;

    long n_iter = strtol(argv[1], &p, 10);
    int n_threads = strtol(argv[2], &p, 10);

    double x;
    double y;
    double circulo = 0;

    int i;
    double pi;

    LARGE_INTEGER frequency; // ticks per second
    LARGE_INTEGER t1, t2;    // ticks
    double elapsedTime;

    struct timeval time;
    gettimeofday(&time, NULL);

    // get ticks per second
    QueryPerformanceFrequency(&frequency);

    omp_set_dynamic(0);
    printf("Number of Threads = %ld\n", n_threads);
    printf("Number of points = %d\n", n_iter);

    /* initialize random numbers */
    srand((time.tv_sec * 1000) + (time.tv_usec / 1000));

#pragma omp parallel num_threads(n_threads)
    {
        int tid = omp_get_thread_num();

        // start timer
        QueryPerformanceCounter(&t1);

#pragma omp for private(x, y) firstprivate(pi) reduction(+ \
                                                         : circulo)
        for (i = 0; i < n_iter; i++)
        {

            x = (double)rand() / RAND_MAX;
            y = (double)rand() / RAND_MAX;

            if (x * x + y * y <= 1)
            {
                circulo++;
            }
        }
    }
    pi = (double)circulo / n_iter * 4;

    QueryPerformanceCounter(&t2);

    printf("Estimated pi = %12.10f\n", pi);

    elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;

    printf("Time to compute = %f\n", elapsedTime);

    return 0;
}