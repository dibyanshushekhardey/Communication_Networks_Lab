function plot_sawtooth(A,D, method)

t_plot = [];
age_plot = [];

arrival_age = [];
departure_age = [];

current_age = 0;
last_dep = 0;

for i = 1:length(D)

    % age growth between two departures
    t = linspace(last_dep, D(i), 100);
    age = current_age + (t - last_dep);

    t_plot = [t_plot t];
    age_plot = [age_plot age];

    % age at arrival instant
    if A(i) >= last_dep && A(i) <= D(i)
        arr_age = current_age + (A(i) - last_dep);
        arrival_age = [arrival_age arr_age];
    else
        arrival_age = [arrival_age NaN];
    end

    % Age just before packet reception by system
    dep_age = current_age + (D(i) - last_dep);
    departure_age = [departure_age dep_age];

    % Age reset after reception by system
    current_age = D(i) - A(i);
    last_dep = D(i);

end

% plotting the functions
figure
plot(t_plot, age_plot, 'b', 'LineWidth', 2)
hold on

% plotting arrivals
%scatter(A, arrival_age, 120, 'r', 'filled')

% plotting departures
%scatter(D, departure_age, 120, 'g', 's', 'filled')

xlabel('Time (seconds)')
ylabel('Age')
title(['Age Evolution - ' method])
legend('Age','Arrivals','Departures')

grid on

end