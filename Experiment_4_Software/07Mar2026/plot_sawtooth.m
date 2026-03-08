function plot_sawtooth(A,D)

t_plot=[];
age_plot=[];

current_age=0;
last_dep=0;

for i=1:length(D)

    t=linspace(last_dep,D(i),100);
    age=current_age+(t-last_dep);

    t_plot=[t_plot t];
    age_plot=[age_plot age];

    current_age=D(i)-A(i);
    last_dep=D(i);
end

figure
plot(t_plot,age_plot,'LineWidth',2)
xlabel('Time')
ylabel('Age of Information')
title('AoI Sawtooth Evolution')
grid on

end