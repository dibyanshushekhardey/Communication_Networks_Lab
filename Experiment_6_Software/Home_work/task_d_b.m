% TCP CONGESTION CONTROL – THRESHOLD-BASED (ALL ALGORITHMS)

clear; clc; close all;

T = 300;
mu = 50;
K = 100;

q_thresh = 0.7 * K;   % threshold (70% of buffer)

algorithms = {'AIAD', 'MIAD'};

figure;

for a = 1:length(algorithms)

    algo = algorithms{a};

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

        %  Threshold-based event 
        thresh_event = (q > q_thresh);

        %  Algorithms using threshold 
        switch algo

            case 'AIAD'
                if thresh_event
                    cwnd = cwnd - 1;
                else
                    cwnd = cwnd + 1;
                end

            case 'MIAD'
                if thresh_event
                    cwnd = cwnd - 1;
                else
                    cwnd = cwnd * 1.2;
                end

        end

        cwnd = max(cwnd,1);

        cwnd_trace(t) = cwnd;
        q_trace(t) = q;
        drop_trace(t) = drops;

    end

    %  Plotting 
    subplot(3,1,1);
    hold on;
    plot(cwnd_trace, 'DisplayName', algo);

    subplot(3,1,2);
    hold on;
    plot(q_trace, 'DisplayName', algo);

    subplot(3,1,3);
    hold on;
    plot(drop_trace, 'DisplayName', algo);

end

%  Final Plot Formatting 
subplot(3,1,1);
title('cwnd (Threshold-based)');
legend;

subplot(3,1,2);
title('Queue');
legend;

subplot(3,1,3);
title('Drops');
legend;