function [arr_array, ser_array] = queue_mod(tot_sim_time, buff_size, arr_mean, ser_mean)
    %[tot_arr, tot_ser, tot_drop,     
    tot_arr = 0;
    tot_drop = 0;
    % idx = 0;
    buffer = 0;
    tot_ser = 0;
    next_arr = exprnd(arr_mean);
    next_ser = 9999;
    t = 0;
    arr_array = [];
    ser_array = [];
    % arr_time = t;
    while t < tot_sim_time
        if next_arr < next_ser
            t = next_arr;
            tot_arr = tot_arr + 1;
            if buffer < buff_size
                buffer = buffer + 1;
                if buffer == 1
                        next_ser = t + exprnd(ser_mean);
                end
            else
                tot_drop = tot_drop + 1;
            end
            next_arr = t + exprnd(arr_mean);
            arr_array = [arr_array next_arr];
            %ser_array = [ser_array next_ser];
        else
            t = next_ser;
            if buffer > 0
                buffer = buffer - 1;
                tot_ser = tot_ser +  1;
            end
            ser_array = [ser_array next_ser];
        end
        if buffer > 0
            next_ser = t + exprnd(ser_mean);
        else
            next_ser = 9999;
        end
           
            %arr_array = [arr_array next_arr];
        end 
    end
