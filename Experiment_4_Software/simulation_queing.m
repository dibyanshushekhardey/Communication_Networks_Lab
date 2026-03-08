clear;
clc;
close all;

%% BUFFER SIZE
buff_size = 5;
tot_sim_time = 100;

%% arrival rate modelling
sz = [1 10];
lambda = 10; % arrival rate
arr_mean = 1 / lambda;
arr_arr = exprnd(arr_mean, sz);

%% service rate modelling
mu = 13; % arrival rate
ser_mean = 1 / mu;
arr_ser = exprnd(arr_mean, sz);


%% displaying inofrmation
%disp(arr_arr);
%disp(arr_ser);

[tot_arr, tot_ser, tot_drop] = queue(arr_arr, arr_ser, buff_size);

disp(tot_arr);
disp(tot_ser);
disp(tot_drop);
