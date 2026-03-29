clear;
clc;
close all;

T = 300; % number of time steps
mu = 50; % service rate
K = 100; % buffer size

figure;

for case_id = 1:4

    % initialise congestion window
    cwnd1 = 1;
    cwnd2 = 1;
    q = 0;

    cwnd1_trace = zeros(1, T);
    cwnd2_trace = zeros(1, T);
    q_trace =  zeros(1, T);
    drop_trace = zeros(1, T);

    for t = 1:T

        arrivals1 = max(cwnd1,0);
        arrivals2 = max(cwnd2,0);
        total_arrivals = arrivals1 + arrivals2;

        q = q + total_arrivals;

        served = min(q, mu);
        q = q - served;

        if q > K
            drops = q - K;
            q = K;
        else
            drops = 0;
        end

        % proportional drops
        if total_arrivals > 0
            p1 = arrivals1 / total_arrivals;
            p2 = arrivals2 / total_arrivals;
        else
            p1 = 0;
            p2 = 0;
        end

        loss_event1 = (drops > 0) && (rand < p1);
        loss_event2 = (drops > 0) && (rand < p2);

        %  SWITCH CASE 
        switch case_id

            % Case 1: cwnd1 = AIMD, cwnd2 = MIMD
            case 1
                % cwnd1 AIMD
                if loss_event1
                    cwnd1 = cwnd1 / 2;
                else
                    cwnd1 = cwnd1 + 1;
                end

                % cwnd2 MIMD
                if loss_event2
                    cwnd2 = cwnd2 / 2;
                else
                    cwnd2 = cwnd2 * 2;
                end

            % Case 2: cwnd1 AI (no decrease), cwnd2 AIMD
            case 2
                % cwnd1 additive increase only
                cwnd1 = cwnd1 + 0.5;

                % cwnd2 AIMD
                if loss_event2
                    cwnd2 = cwnd2 / 2;
                else
                    cwnd2 = cwnd2 + 1;
                end

            % Case 3: cwnd1 MIMD, cwnd2 AIMD
            case 3
                % cwnd1 MIMD
                if loss_event1
                    cwnd1 = cwnd1 / 2;
                else
                    cwnd1 = cwnd1 * 2;
                end

                % cwnd2 AIMD
                if loss_event2
                    cwnd2 = cwnd2 / 2;
                else
                    cwnd2 = cwnd2 + 1;
                end
            % Case 4: example given in the report
            case 4
                if loss_event1
                    cwnd1 = max(1, cwnd1 - 1); 
                else
                    cwnd1 = cwnd1 + 0.5; 
                end
            
                if loss_event2
                    cwnd2 = max(1, cwnd2 - 1);
                else
                    cwnd2 = cwnd2 + 0.5;
                end
        end

        cwnd1 = max(1, cwnd1);
        cwnd2 = max(1, cwnd2);

        cwnd1_trace(t) = cwnd1;
        cwnd2_trace(t) = cwnd2;
        q_trace(t) = q;
        drop_trace(t) = drops;

    end

    %  PLOTTING 
    subplot(4,1,case_id);
    plot(cwnd1_trace, 'r', 'LineWidth', 1.5); hold on;
    plot(cwnd2_trace, 'b', 'LineWidth', 1.5);

    xlabel('Time');
    ylabel('cwnd');
    title(['Case ' num2str(case_id)]);
    legend('Flow 1', 'Flow 2');
    grid on;

    disp("Total packets drop: ");
    disp(sum(drop_trace));
    x1 = mean(cwnd1_trace);
    x2 = mean(cwnd2_trace);
    J = ((x1 + x2)^2)/(2*(x1^2 + x2^2));
    disp("Jain fairness index: ");
    disp(J);

end