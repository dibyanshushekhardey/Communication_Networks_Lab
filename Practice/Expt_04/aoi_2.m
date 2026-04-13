clc;
clear;
close all;

T = 100;
lambda = 0.5;
mu = 1;

t = 0;
gen_times = [];

% poisson arrivals
while t < T
    t = t- log(rand)/lambda;
    gen_times = [gen_times, t];

end

n = length(gen_times);
delivery_times = zeros(1, n);

for i = 1:n
    service = -log(rand)/mu;
    if i == 1
        delivery_times(i) = gen_times(i) + service;
    else
        delivery_times(i) = max(gen_times(i), delivery_times(i-1)) + service;
    end
end

% aoi
time = linspace(0, T, 2000);
aoi = zeros(size(time));

idx = 1;

for i = 1:length(time)
    while idx <= n && delivery_times(idx) <= time(i)
        idx = idx + 1;
    end
    if idx == 1
        last_gen = 0
    else
        last_gen = gen_times(idx-1);
    end
    aoi(i) = time(i) - last_gen;
end

plot(time, aoi, 'LineWidth', 2);
grid on;