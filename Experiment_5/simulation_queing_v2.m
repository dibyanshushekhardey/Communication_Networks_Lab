clear;
clc;
close all;

lambda_arr = 1:9;
avg_age_arr = [];
util_arr = [];

%% BUFFER SIZE
buff_size = 5;
tot_sim_time = 1000;
for lambda = lambda_arr
 

    %x = linspace(0, 100, 0.0001);
    %% arrival rate modelling
    %lambda = 10; % arrival rate
    arr_mean = 1 / lambda;
    
    %% service rate modelling
    %mu = 13; % service rate
    mu = 10;
    ser_mean = 1 / mu;
    util_factor = lambda/mu;
    util_arr = [util_arr util_factor];
    [tot_arr, tot_ser, tot_drop] = queue(tot_sim_time, buff_size, arr_mean, ser_mean);
    [arr_array, ser_array] = queue_mod(tot_sim_time, buff_size, arr_mean, ser_mean);
    %disp(length(arr_array));
    x = linspace(0, tot_sim_time,  length(arr_array));
    age = x - arr_array;
    avg_age = mean(age);
    avg_age_arr = [avg_age_arr avg_age];
    figure;
    plot(x, age);
end
disp(avg_age_arr);
plot(util_arr, avg_age_arr);

