function avg_age = compute_aoi(A_serv, D_serv, T)

N = length(D_serv); % total Departure served
avg_age = 0;

for i = 2:N
    % avg_age = avg_age + (A_serv(i) - D_serv(i));
    Y = D_serv(i) - D_serv(i-1); % inter departure time
    T_sys = D_serv(i-1) - A_serv(i-1); % system time for packet i -1
    avg_age = avg_age + (Y^2)/2 + T_sys*Y; % area under curve, trapezoid arae

end
avg_age = avg_age / T;
end