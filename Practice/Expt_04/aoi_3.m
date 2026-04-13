clc;
clear;
close all;

T = 100;
lambda = 0.5;
mu = 1;

t = 0;
gen_arr = [];
del_times = [];
gen_used = [];

while t < T
    t = t - log(rand)/lambda;
    gen_arr = [gen_arr, t];
end

n = length(gen_arr);

for i = 1:n
    service = -log(rand)/mu;
    
    start_time = gen_arr(i);
    finish_time = start_time + service;
    
    % check if next arrival preempts this one
    if i < n && gen_arr(i+1) < finish_time
        continue;   % packet is preempted → discarded
    else
        del_times = [del_times, finish_time];
        gen_used = [gen_used, gen_arr(i)];
    end
    
end

% aoi
time = linspace(0, T, 2000);
aoi = zeros(size(time));

idx = 1;

for i = 1:length(time)
    while idx <= n && del_times(idx) <= time(i)
        idx = idx + 1;
    end

    if idx == 1
        last_gen = 0;
    else
        last_gen = gen_used(idx - 1);
    end tr
    aoi(i) = aoi(i) + (time(i) - last_gen);
end

plot(time, aoi, 'LineWidth', 2);
grid on;