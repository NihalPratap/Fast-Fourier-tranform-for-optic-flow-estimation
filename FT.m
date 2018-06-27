function a = ft(out)  
n = length(out);
if length(out) == 1                         % if length is 1 then return
    a = out;
return
else m = n/2;
even = ft(out(1:2:n-1));                % divide and conquer
odd  =ft(out(2:2:n));                  % by dividing the array into even and odd parts

    d = exp(-2 * pi * 1i / n) .^ (0:m-1);    % calculate ft
temp = d .* odd;
out = [ even + temp , even - temp ];    % combine the two parts(butterfly algorithm)
end
a = out;
return


function o = ift(out1)
out1 = conj(out1);          %apply conjugate
out1 = ft(out1);            %calculate the ft
out1 = conj(out1);          %apply conjugate on the result
out1 = out1/length(out1);   % scaling the result 
o = out1;
return
