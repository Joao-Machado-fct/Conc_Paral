#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h> 

int main(int argc, char const *argv[])
{
    char *p;

    int n_iter = strtol(argv[1], &p, 10);

    double x;
    double y;
    double circulo = 0;

    int i;
    double pi;

    /* initialize random numbers */
    srand(time(NULL));

    for (i = 0; i < n_iter; i++)
    {

        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        printf("x: %d ||| y: %d\n", x, y);

        if (x * x + y * y <= 1)
        {
            circulo++;
        }
    }
    pi = (double)circulo / n_iter * 4;
    printf("# of trials= %d , estimate of pi is %f \n", n_iter, pi);
    return 0;
}