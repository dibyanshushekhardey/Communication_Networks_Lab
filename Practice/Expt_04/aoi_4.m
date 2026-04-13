clc; clear; close all;

T = 200;
mu = 1;

lambda_list = linspace(0.1, 0.9, 20);   % offered load range
rho_list = lambda_list / mu;

aoi_mm1 = zeros(size(lambda_list));

for k = 1:length(lambda_list)
    
    lambda = lambda_list(k);
    
    % ----- generate arrivals -----
    t = 0;
    gen_arr = [];
    while t < T
        t = t - log(rand)/lambda;
        gen_arr = [gen_arr, t];
    end
    
    n = length(gen_arr);
    del_times = zeros(1,n);
    
    % ----- M/M/1 service -----
    for i = 1:n
        service = -log(rand)/mu;
        if i == 1
            del_times(i) = gen_arr(i) + service;
        else
            del_times(i) = max(gen_arr(i), del_times(i-1)) + service;
        end
    end
    
    % ----- AoI -----
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
            last_gen = gen_arr(idx-1);
        end
        
        aoi(i) = time(i) - last_gen;
    end
    
    % store average AoI
    aoi_mm1(k) = mean(aoi);
end

% ----- Plot -----
plot(rho_list, aoi_mm1, 'o-', 'LineWidth', 2);
xlabel('\rho (Offered Load)');
ylabel('Average AoI');
title('AoI vs Offered Load (M/M/1)');
grid on;