pid_txt = 'output.txt';
pi_txt = 'output_PI.txt';
p_txt = 'output_P.txt';

tempereture = read_txt(pid_txt);
tempereture_PI = read_txt(pi_txt);
tempereture_P = read_txt(p_txt);

subplot(3,1,1);
plot(tempereture)
title("PID Temperature Controller w/ SetPoint = 40C")
xlabel("time");
ylabel("Tempereture in C");

subplot(3,1,2); 
plot(tempereture_PI)
title("PI Temperature Controller w/ SetPoint = 40C")
xlabel("time");
ylabel("Tempereture in C");

subplot(3,1,3); 
plot(tempereture_P)
title("P Temperature Controller w/ SetPoint = 40C")
xlabel("time");
ylabel("Tempereture in C");

function tempereture = read_txt(txt_file)
% read txt file and save the data
file = fopen(txt_file,'r');
tline = fgetl(file);
tempereture = [];
while ischar(tline)
    if contains(tline,"Temperature:")
        get = strsplit(tline,' ');
        tempereture = [tempereture, str2double(get(3))];
    end
    tline = fgetl(file);
end
fclose(file);

end