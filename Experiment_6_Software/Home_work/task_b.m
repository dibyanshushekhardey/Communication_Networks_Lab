% TCP CONGESTION CONTROL LAB – STARTER CODE
% Vary μ and K (e.g., μ = 30, 50, 70, K = 50, 100, 200). 
% Observe changes in queue and drops. • 
% Introduce slight randomness in arrivals: 
% arrivals = max(cwnd + randi([−1,1]),0);
% Record:
% Maximum and average queue – 
% Maximum and average drops – Maximum and average cwnd

clear; clc; close all;

T = 300;
mu_vals = [30, 50, 70];
K_vals = [50, 100, 200];

figure;

for i = 1:length(mu_vals)
    for j = 1:length(K_vals)
        mu = mu_vals(i);
        K  = K_vals(j);

        cwnd = 1;
        q = 0;

        cwnd_trace = zeros(1,T);
        q_trace = zeros(1,T);
        drop_trace = zeros(1,T);

        for t = 1:T
            arrivals = max(cwnd + randi([-1, 1]), 0);
        
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
        % Plotting
        subplot(3,1,1);
        hold on;
        plot(cwnd_trace, 'DisplayName', ['\mu=' num2str(mu) ', K=' num2str(K)]);
        avg_cwnd = mean(cwnd_trace);
        %disp('The average of the cwnd for ' + num2str(mu) + ' and ' + num2str(K) + ' is ' + num2str(avg_cwnd));
        disp("The average of the cwnd for " + mu + " and " + K + " is " + avg_cwnd);
        max_cwnd = max(cwnd_trace);
        disp("The max of the cwnd for " + mu + " and " + K + " is " + max_cwnd);
        
        subplot(3,1,2);
        hold on;
        plot(q_trace, 'DisplayName', ['\mu=' num2str(mu) ', K=' num2str(K)]);
        avg_queue = mean(q_trace);
        disp("The average of the queue for " + mu + " and " + K + " is " + avg_queue);
        max_queue = max(q_trace);
        disp("The max of the queue for " + mu + " and " + K + " is " + max_queue);
        
        subplot(3,1,3);
        hold on;
        plot(drop_trace, 'DisplayName', ['\mu=' num2str(mu) ', K=' num2str(K)]);
        avg_drop = mean(drop_trace);
        disp("The average of the drops for " + mu + " and " + K + " is " + avg_drop);
        max_drop = max(drop_trace);
        disp("The max of the drops for " + mu + " and " + K + " is " + max_drop);
    end
end

% title and legends
subplot(3,1,1);title('cwnd');legend;
subplot(3,1,2);title('Queue');legend;
subplot(3,1,3);title('Drops');legend;