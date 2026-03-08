function [A_served,D_served] = queue_sim(tot_sim_time,buff_size,arr_mean,ser_mean,policy)

buffer = 0;
queue_arr = [];

next_arr = exprnd(arr_mean);
next_ser = Inf;
t = 0;

A_served = [];
D_served = [];

while t < tot_sim_time

    if next_arr < next_ser

        % Arrival event
        t = next_arr;

        if buffer < buff_size
            buffer = buffer + 1;
            queue_arr = [queue_arr t];

            if buffer == 1
                next_ser = t + exprnd(ser_mean);
            end
        end

        next_arr = t + exprnd(arr_mean);

    else

        % Service completion
        t = next_ser;

        if buffer > 0

            if policy == "FCFS"
                idx = 1;

            elseif policy == "LCFS"
                idx = length(queue_arr);

            elseif policy == "RAND"
                idx = randi(length(queue_arr));
            end

            arrival_time = queue_arr(idx);
            queue_arr(idx) = [];

            buffer = buffer - 1;

            A_served = [A_served arrival_time];
            D_served = [D_served t];
        end

        if buffer > 0
            next_ser = t + exprnd(ser_mean);
        else
            next_ser = Inf;
        end
    end

end
