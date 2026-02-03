#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define upper_bound 0
#define lower_bound 10

float interArrival(int, float);
float interService(int, float);

float interArrival(int lambda, float t){
	float T;
	T = lambda * exp((-lambda) * t);
	return T;

}

float interService(int mu, float t){
	float T;
	T = mu * exp((-mu) * t);
	return T;

}

int main() {
    /* code */
    srand(time(NULL));
    int lambda = 10;
    int mu = 13;
    int N = 50;
    float sum_a = 0.0;
    float sum_s = 0.0;

    int counter_arrPack = 0;
    int counter_serPack = 0;

	while(sum_a < 15.0){
    	// arrival
    	printf("--------------------------\n");
    	int value = rand() %(N+1);
    	float t_a = value / 100.0;
    	float T_A = interArrival(lambda, t_a);
    	printf("Interarrival time T is %0.3f\n", T_A);
    	sum_a += T_A;
    	counter_arrPack+=1;
    	printf("Arrival time is %0.3f\n", sum_a);


        // service
    	int serVal = rand() %(N+1);
    	float t_s = serVal / 100.0;
    	float T_S = interService(mu, t_s);
    	printf("Interservice time T is %0.3f\n", T_S);
    	sum_s += T_S;
    	counter_serPack+=1;
    	printf("Service time is %0.3f\n", sum_s);
    	printf("--------------------------\n");
    }
    printf("--------------------------\n");
    printf("Total Packets generated is %d\n", counter_arrPack);
    printf("Total Packets serviced is %d\n", counter_serPack);
    return 0;
}