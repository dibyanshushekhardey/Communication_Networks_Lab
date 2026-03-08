clear;
clc;
close all;

lambda_arr = 1:5;
avg_age_arr = [];
util_arr = [];

%% PARAMETERS
buff_size = 5;
tot_sim_time = 10;     % IMPORTANT: large simulation time
mu = 10;                 % service rate
ser_mean = 1/mu;

for lambda = lambda_arr

    %% Arrival parameters
    arr_mean = 1/lambda;
    util_factor = lambda/mu;
    util_arr = [util_arr util_factor];

    %% Run queue simulation
    [A_served, D_served] = queue_mod_v1(tot_sim_time, buff_size, arr_mean, ser_mean);

    N = length(D_served);

    %% ----- Compute Average AoI -----
    avg_age = 0;

    for i = 2:N
        Y = D_served(i) - D_served(i-1);          % inter-departure time
        T = D_served(i-1) - A_served(i-1);        % system delay

        avg_age = avg_age + (Y^2)/2 + T*Y;
    end

    avg_age = avg_age / tot_sim_time;
    avg_age_arr = [avg_age_arr avg_age];

    %% ----- Generate AoI Sawtooth for Plotting -----
    t_plot = [];
    age_plot = [];

    current_age = 0;
    last_dep = 0;

    for i = 1:N

        % linear increase until next departure
        t_segment = linspace(last_dep, D_served(i), 100);
        age_segment = current_age + (t_segment - last_dep);

        t_plot = [t_plot t_segment];
        age_plot = [age_plot age_segment];

        % drop at departure
        current_age = D_served(i) - A_served(i);
        last_dep = D_served(i);
    end

    figure;
    plot(t_plot, age_plot, 'LineWidth', 1.5);
    xlabel('Time');
    ylabel('Age of Information');
    title(['AoI vs Time (lambda = ', num2str(lambda), ')']);
    grid on;

end

%% ----- Plot Average AoI vs Utilization -----
figure;
plot(util_arr, avg_age_arr, '-o', 'LineWidth', 2);
xlabel('Utilization (\rho = \lambda / \mu)');
ylabel('Average AoI');
title('Average AoI vs Utilization');
grid on;

disp('Average AoI values:');
disp(avg_age_arr);