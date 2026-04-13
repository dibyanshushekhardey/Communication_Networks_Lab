clc;
clear;
close all;

T = 300;
mu = 50;
K = 100;

cwnd = 1;
q = 0;

cwnd_trace = zeros(1, T);
q_trace = zeros(1, T);
drop_trace = zeros(1, T);

for t = 1:T
    arrivals = max(cwnd, 0);
    q = q + arrivals;
    served = min(q, mu);
    q = q - served;

    if q > K
        drops = q - K;
        q = K;
    else
        drops = 0;
    end

    loss_event = (drops > 0);

    if loss_event
        cwnd = cwnd / 2;
    else
        cwnd = cwnd + 1;
    end

    cwnd_trace(t) = cwnd;
    drop_trace(t) = drops;
    q_trace(t) = q;
end

figure;
subplot(3, 1, 1); plot(cwnd_trace);
xlabel('Time');
ylabel('CWND');
title('Command Window Over Time');
subplot(3, 1, 2); plot(drop_trace);
xlabel('Time');
ylabel('Drops');
title('Packet Drops Over Time');

subplot(3, 1, 3); plot(q_trace);
xlabel('Time');
ylabel('Queue Length');
title('Queue Length Over Time');
