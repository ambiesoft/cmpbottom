#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    int length = 10;
    int i, j,l,m;
    int my[10][10] = {
                      {0,1,1,1,1,1,1,1,1,1},
                      {0,0,1,1,1,1,1,1,1,1},
                      {0,0,0,1,1,1,1,1,1,1},
                      {0,0,0,0,1,1,1,1,1,1},
                      {0,0,0,0,0,1,1,1,1,1},
                      {0,0,0,0,0,0,1,1,1,1},
                      {0,0,0,0,0,0,0,1,1,1},
                      {0,0,0,0,0,0,0,0,1,1},
                      {0,0,0,0,0,0,0,0,0,1},
                      {0,0,0,0,0,0,0,0,0,0},
                      };

    int** corrects = malloc(length * sizeof(int*));
    time_t t;
    int testlength = 1000;
    int testloopcount = 7000000;
    clock_t ct;

    for(i=0;i<length;++i) {
        corrects[i] = malloc(length * sizeof(int));
        for(j=0;j<length;++j) {
            corrects[i][j] = i < j;
        }
    }

    for(i=0;i<length;++i) {
        for(j=0;j<length;++j) {
            printf("%d,",corrects[i][j]);
        }
        printf("\n");
    }

    /* Intializes random number generator */
    srand((unsigned) time(&t));

    int* testarray1 = malloc(testlength*sizeof(int));
    int* testarray2 = malloc(testlength*sizeof(int));
    /* Print 5 random numbers from 0 to 50 */
    for( i = 0 ; i < testlength ; i++ ) {
        testarray1[i] = rand() % 10;
        testarray2[i] = rand() % 10;
    }

    int* correctResult = malloc(testlength*sizeof(int));
    int* myResult = malloc(testlength*sizeof(int));

    for(m=0 ; m < 10 ; ++m) {
        // normal cmp
        ct = clock();
        for(l=0;l < testloopcount; ++l) {
            for( i = 0 ; i < testlength ; i++ ) {
            correctResult[i] = testarray1[i] < testarray2[i];
            }
        }
        printf("normal cmp %ld\n", (clock()-ct)/CLOCKS_PER_SEC);

        // mycmp
        ct = clock();
        for(l=0;l < testloopcount; ++l) {
            for( i = 0 ; i < testlength ; i++ ) {
            myResult[i] = my[testarray1[i]][testarray2[i]];
            }
        }
        printf("mycmp %ld\n", (clock()-ct)/CLOCKS_PER_SEC);
    }

    // compare two cmps
    if(0==memcmp(correctResult, myResult, testlength*sizeof(int)))
        printf("two cmp is OK\n");
    else
        printf("two cmp is NG\n");
    return 0;
}
