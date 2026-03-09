clear;
clc;
close all;

lambda_arr = 1:9; % various lambda values

avg_age_fcfs = []; % Initialize average age for FCFS
avg_age_lcfs = []; % Initialize average age for LCFS
avg_age_rand = []; % Initialize average age for Random scheduling

util_arr = []; % utilizxation array

%parameters
buff_size = 5;
tot_sim_time = 10000;
mu = 10; % service rate
ser_mean = 1 / mu; % service mean

for lambda = lambda_arr
    arr_mean = 1 / lambda; % arrival mean
    rho = lambda / mu;
    util_arr = [util_arr rho]; % add rho into utilization array
    
    % FCFS
    [A_fcfs, D_fcfs] = queue_sim(tot_sim_time, buff_size, arr_mean, ser_mean, "FCFS"); % calling queue simulaton
    avg_age_fcfs = [avg_age_fcfs compute_aoi(A_fcfs, D_fcfs, tot_sim_time)]; % calling average age function

    % LCFS
    [A_lcfs, D_lcfs] = queue_sim(tot_sim_time, buff_size, arr_mean, ser_mean, "LCFS"); % calling queue simulaton
    avg_age_lcfs = [avg_age_lcfs compute_aoi(A_lcfs, D_lcfs, tot_sim_time)]; % calling average age function

    % Random Scheduling
    [A_rand, D_rand] = queue_sim(tot_sim_time, buff_size, arr_mean, ser_mean, "Random"); % calling queue simulaton
    avg_age_rand = [avg_age_rand, compute_aoi(A_rand, D_rand, tot_sim_time)]; % calling average age function

end

disp(["Average age for FCFS Scheduling - " compute_aoi(A_fcfs, D_fcfs, tot_sim_time)]);
disp(["Average age for LCFS Scheduling - " compute_aoi(A_lcfs, D_lcfs, tot_sim_time)]);
disp(["Average age for Random Scheduling - " compute_aoi(A_rand, D_rand, tot_sim_time)]);

figure;
plot(util_arr,avg_age_fcfs,'-o','LineWidth',2);
hold on;
plot(util_arr,avg_age_lcfs,'-s','LineWidth',2);
plot(util_arr,avg_age_rand,'-d','LineWidth',2);

xlabel('Utilization (\rho = \lambda/\mu)')
ylabel('Average Age')
title('Average AoI vs Utilization')
legend('FCFS','LCFS','Random')
grid on

% plot of the Sawtooth plot
figure;
plot_sawtooth(A_fcfs, D_fcfs, "FCFS");
%plot_sawtooth(A_lcfs, D_lcfs, "LCFS");
%plot_sawtooth(A_rand, D_rand, "Random Scheduling");
hold on;
