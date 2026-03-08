function [A_serv, D_serv] = queue_sim(tot_sim_time, buffer_size, arr_mean, ser_mean, method)

buffer = 0;
queue_arr = [];

next_arr = exprnd(arr_mean); % arrival rate follows exponenetial Rv, choose a value
next_ser = Inf;              % service time is infinity
t = 0;                       % tie instance initialised

A_serv = []; % array empty to check total number of packets arriving
D_serv = []; % array empty to check total number of packets departing

% check that time is less than total simulation time
while t < tot_sim_time
    if next_arr < next_ser % if arrival time is less than service time
        t = next_arr; % put the arrival time in t variable
        
        % the buffer capacity at current moment is less than buffer
        % capacity
        if buffer < buffer_size
            buffer = buffer + 1;
            queue_arr = [queue_arr t]; % append time in array (queue)

            if buffer == 1
                next_ser = t + exprnd(ser_mean); % total service = arr time + exp rv from service time
            end
        end
        next_arr = t + exprnd(ser_mean); % next arrival = arr time + exp rv from service time
    else
        t = next_ser; % service completion
        if buffer > 0 % buffer is already occupied
            if method == "FCFS"
                idx = 1;
    
            elseif method == "LCFS"
                idx = length(queue_arr);
    
            elseif method == "Random"
                idx = randi(length(queue_arr));
            end
        
        end
        arrival_time = queue_arr(idx); % take first index of arrival queue
        queue_arr(idx) = []; % remove that element from array

        buffer = buffer - 1; % decrease buffer size
        
        A_serv = [A_serv arrival_time]; % append the array for arrival time
        D_serv = [D_serv t]; % append the array for service time
    end
    
    if buffer > 0
        next_ser = t + exprnd(ser_mean); % update the service time if buffer > 0 else keep service time infinity
    else
        next_ser = Inf;
    end
end
end

