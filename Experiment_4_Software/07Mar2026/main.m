clear;
clc;
close all;

lambda_arr = 1:5;
avg_age_fcfs = [];
avg_age_lcfs = [];
avg_age_rand = [];
util_arr = [];

%% PARAMETERS
buff_size = 5;
tot_sim_time = 1000;
mu = 10;
ser_mean = 1/mu;

for lambda = lambda_arr

    arr_mean = 1/lambda;
    rho = lambda/mu;
    util_arr = [util_arr rho];

    %% FCFS
    [A,D] = queue_sim(tot_sim_time,buff_size,arr_mean,ser_mean,"FCFS");
    avg_age_fcfs = [avg_age_fcfs compute_aoi(A,D,tot_sim_time)];

    %% LCFS
    [A,D] = queue_sim(tot_sim_time,buff_size,arr_mean,ser_mean,"LCFS");
    avg_age_lcfs = [avg_age_lcfs compute_aoi(A,D,tot_sim_time)];

    %% RANDOM
    [A,D] = queue_sim(tot_sim_time,buff_size,arr_mean,ser_mean,"RAND");
    avg_age_rand = [avg_age_rand compute_aoi(A,D,tot_sim_time)];

end

%% Plot Average AoI vs Utilization
figure;
plot(util_arr,avg_age_fcfs,'-o','LineWidth',2);
hold on
plot(util_arr,avg_age_lcfs,'-s','LineWidth',2);
plot(util_arr,avg_age_rand,'-d','LineWidth',2);

xlabel('Utilization (\rho = \lambda/\mu)')
ylabel('Average Age')
title('Average AoI vs Utilization')
legend('FCFS','LCFS','Random')
grid on

%% plot of the Sawtooth plot
plot_sawtooth(A,D);
