% TCP CONGESTION CONTROL LAB – STARTER CODE

clear; clc; close all;

T = 300;
mu = 50;
K = 100;

cwnd = 1;
q = 0;

cwnd_trace = zeros(1,T);
q_trace = zeros(1,T);
drop_trace = zeros(1,T);

for t = 1:T

    arrivals = max(cwnd,0);

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

    % BASELINE (no congestion control)
    cwnd = cwnd + 1;

    cwnd = max(cwnd,1);
    cwnd_trace(t) = cwnd;
    q_trace(t) = q;
    drop_trace(t) = drops;

end

figure;
subplot(3,1,1); plot(cwnd_trace); title('cwnd');
subplot(3,1,2); plot(q_trace); title('Queue');
subplot(3,1,3); plot(drop_trace); title('Drops');