data = load("interarrival.txt");
histogram(data, 50, 'Normalization', 'pdf');
hold on;
t = linspace(0, max(data), 100);
plot(t, 10 * exp(-10*t), 'r', 'LineWidth', 2);
hold off;