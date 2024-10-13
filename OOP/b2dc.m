t=-10:0.001:10;
y=2*uramp(t,2.5)-5*uramp(t,0)+3*uramp(t,-2)+ustep(t,-4);
[ye,yo]=evenodd(y);
hold on;
plot(t,ye,'m');plot(t,yo,'r');
legend('yo','ye');
