#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_EVENTS 1000
float inter_arrival[MAX_EVENTS];
int ia_idx = 0;
// generating exponential RV
float exponential(float rate) {
    float u = (float)rand() / RAND_MAX;
    return -log(1.0 - u) / rate;
}

float expectation(float arr[], int n){
    
    float sum_ia = 0.0;
    for(int i = 0; i < n; i++){
        sum_ia += arr[i];
    }
    return sum_ia / n; 

}
int main() {

    srand(time(NULL));

    // parameters
    float lambda = 10.0;     // arrival rate
    float mu = 13.0;         // service rate
    int K = 5;               // finite buffer size
    float SIM_TIME = 10.0;  // total simulation time

    // variables
    int buffer = 0;
    int arrivals = 0;
    int dropped = 0;
    int serviced = 0;

    // event times
    float t = 0.0;
    float next_arrival = exponential(lambda);
    float next_service = INFINITY;
    float arrival_time[MAX_EVENTS];
    //float inter_arrival[1000];
    int arr_idx = 0;
    //int ia_idx = 0;

    // loop being less than the total simulation timew
    while (t < SIM_TIME) {

        if (next_arrival < next_service) {
            // arrival process
            t = next_arrival;
            arrival_time[arr_idx++] = t;
            arrivals++;

            if (buffer < K) {
                buffer++;

                //If server is idle, schedule service 
                if (buffer == 1) {
                    next_service = t + exponential(mu);
                }
            } else {
                dropped++;
            }

            next_arrival = t + exponential(lambda);

        } else {
            // service
            t = next_service;

            if (buffer > 0) {
                buffer--;
                serviced++;
            }

            if (buffer > 0) {
                next_service = t + exponential(mu);
            } else {
                next_service = INFINITY;
            }
        }
        //printf("Event Time next arrival : %0.2f\n", t);
        //printf("----------------------------------\n");
    }

    

    // result
    printf("Simulation Time           : %.2f\n", SIM_TIME);
    printf("Arrival rate (lambda)     : %.2f\n", lambda);
    printf("Service rate (mu)         : %.2f\n", mu);
    printf("Buffer size (K)           : %d\n", K);
    printf("----------------------------------\n");
    printf("Total Arrivals            : %d\n", arrivals);
    printf("Total Serviced            : %d\n", serviced);
    printf("Total Dropped             : %d\n", dropped);
    printf("Packet Drop Probability   : %f\n", (float)dropped / arrivals);
    printf("----------------------------------\n");
    
    
    printf("Storing Interaarival Times\n");
    for (int i = 1; i < arr_idx; i++) 
    {   
        inter_arrival[ia_idx] = arrival_time[i] - arrival_time[i-1];
        printf("Inter-arrival[%d] = %.3f\n", i, inter_arrival[ia_idx]);
        ia_idx++;
    }
    printf("%d\n", ia_idx);
    float expected_value = expectation(inter_arrival, ia_idx);
    printf("The expected value of interaarival time is %0.2f\n", expected_value);

    FILE *fp = fopen("inter_arrival.txt", "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (int i = 0; i < ia_idx; i++) {
        fprintf(fp, "%.6f\n", inter_arrival[i]);
    }

    fclose(fp);

    printf("Inter-arrival times written to inter_arrival.txt\n");

    return 0;
}
