function avg_age = compute_aoi(A_served,D_served,T)

N = length(D_served);
avg_age = 0;

for i = 2:N
    Y = D_served(i) - D_served(i-1);
    Tsys = D_served(i-1) - A_served(i-1);

    avg_age = avg_age + (Y^2)/2 + Tsys*Y;
end

avg_age = avg_age/T;

end