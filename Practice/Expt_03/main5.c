#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_EVENT 1000
int ia_idx = 0;
float exponential(float rate){
    float u = (float)rand() / RAND_MAX;
    return -log(1.0 - u) / rate;
}

float expectation(float arr[], int n){
    float sum_ia = 0.0;
    for(int i =0; i < n; i++){
        sum_ia += arr[i];
    }
    return sum_ia / n;
}

float inter_arrival[MAX_EVENT];
int main(){
    srand(time(NULL));

    // parameters
    float lambda = 10.0;
    float mu = 13.0;
    float K = 5.0;
    float sim_time = 10.0;

    // network 
    int buffer = 0;
    int arrival = 0;
    int drop = 0;
    int serviced = 0;

    float t= 0;
    float next_arrival = exponential(lambda);
    float next_service = INFINITY;
    float arrival_time[MAX_EVENT];
    int arr_indx = 0;

    while (t < sim_time){
        // arrival 
        if(next_arrival < next_service){
            t = next_arrival;
            arrival_time[arr_indx++] = t;
            arrival++;

            if (buffer < K){
                buffer++;
                if(buffer == 1){
                    next_service = t + exponential(mu);
                }
                else{
                    drop++;
                }
            }

            next_arrival = t + exponential(lambda);
        }
        
        // service
        else{
            t = next_service;
            if(buffer > 0){
                buffer--;
                serviced++;

            }
            if(buffer > 0){
                next_service = t + exponential(mu);
            }
            else{
                next_service = INFINITY;
            }
        }
    }

    // storing informations
    for(int i = 1; i < arr_indx; i++){
        inter_arrival[ia_idx] = arrival_time[i] - arrival_time[i-1];
        ia_idx++;
    }

    float expected_value = expectation(inter_arrival, arr_indx);
    printf("Expectd value of interarrival time is %0.2f\n", expected_value);
    FILE *fp = fopen("interarrival.txt", "w");
    if (fp == NULL){
        printf("error in opening the file\n");
        return 1;
    }

    for(int i = 0; i < arr_indx; i++){
        fprintf(fp, "%0.6f\n", inter_arrival[i]);
    }
    fclose(fp);


    return 0;
}