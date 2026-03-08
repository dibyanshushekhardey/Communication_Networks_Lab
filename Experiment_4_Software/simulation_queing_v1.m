clear;
clc;
close all;

lambda_arr = 1:10;
mu_arr = 11:20;
%% BUFFER SIZE
buff_size = 5;
tot_sim_time = 10;
%x = linspace(0, 100, 0.0001);
%% arrival rate modelling
lambda = 10; % arrival rate
arr_mean = 1 / lambda;

%% service rate modelling
mu = 13; % service rate
ser_mean = 1 / mu;

[tot_arr, tot_ser, tot_drop] = queue(tot_sim_time, buff_size, arr_mean, ser_mean)
[arr_array, ser_array] = queue_mod(tot_sim_time, buff_size, arr_mean, ser_mean);
%disp(length(arr_array));
x = linspace(0, tot_sim_time,  length(arr_array));
age = x - arr_array;


