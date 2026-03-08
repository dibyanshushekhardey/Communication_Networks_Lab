function [A_served, D_served] = queue_mod_v1(tot_sim_time, buff_size, arr_mean, ser_mean)

    buffer = 0;
    queue_arr = [];          % stores arrival times in FIFO order
    
    next_arr = exprnd(arr_mean);
    next_ser = Inf;
    t = 0;

    A_served = [];
    D_served = [];

    while t < tot_sim_time

        if next_arr < next_ser

            % ARRIVAL
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

            % SERVICE COMPLETION
            t = next_ser;

            if buffer > 0
                arrival_time = queue_arr(1);
                queue_arr(1) = [];

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
end