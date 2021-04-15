#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

void *myThreadFun(void *vargp)
{
    //TEST
    char *p;

    double x;
    double y;
    double circulo = 0;

    int value;

    int i;
    double pi;

    int n_points = 1000000;

    /* initialize random numbers */
    srand(time(NULL));

    for (i = 0; i < n_points; i++)
    {

        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        printf("x: %d ||| y: %d\n", x, y);

        if (x * x + y * y <= 1)
        {
            circulo++;
        }
    }
    pi = (double)circulo / n_points * 4;
    printf("# of trials= %d , estimate of pi is %f \n", n_points, pi);
     
    return (void *)value;
}

// gcc programa <num_iter> <num_thread> <num_pontos>
int main(int argc, char const *argv[])
{

    void *res;
    int theValue;

    int num_iter = 10;
    int num_thread = 2;

    pthread_t thread_id;

    int i = 0;
    int j = 0;
    for (i=0; i < num_iter; i++) {
        for(j=0; j < num_thread; j++){
            pthread_t thread_id;

            pthread_create(&thread_id, NULL, myThreadFun, NULL);
            pthread_join(thread_id, &res);
            theValue = (int *)res;
        }
    }


    printf("After Thread\n");
    exit(0);
}

