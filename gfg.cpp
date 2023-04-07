[Graph]
directional edges ne undhi kari jo. 


[Game Theory]
--------------
base state nakki karo.
darek state maate jo
koi pan move losing state ma lai jaay to ee winning state
darek move winning state ma lai jaay to ee losing state

nim hip - koi pan game etli stick lai sake
darek ma stick no xor == 0 to losing state
naitar winning state

Grundy number - losing state = 0
other states = minimum nonnegative number not in its next movements

--------------
dabe jamne thi number kadhvana - dp 
    apdo max score = apdo vaaro => max(dabu kadhine, jamnu kadhine), olano vaaro => min(dabu kadhine, jamnu kadhine)
saav bogas golden ratio vado
motebhage O(1) ma thai jaase. Modulo vaprine, total maths.
simple pattern
xor karine pattern observe kar

[Dynamic Programming]
n=1 no ans, ema i=2 umerie to n=2 no ans kai rite construct thay pachhla jawab parthi?, pachhi haji ek umero n=3, ... jo koi sutr male to, aagla ans. store karavta jao

[string]
s.substr(starting index, length);
// string ne base ma maanine enu decimal long long ma return kares
stoll(string name, nullptr, base); 

[Mod]
2^(2^N) mod M=2^(2^N mod M-1) mod M


[basic]
n pramane jawab kai rite badlay chhe?
pattern

[math]
nCr mod prime ganva mate, i= 1 to r, numerator *= n-i+1; denomenator *= i; dar vakhte mod karta jao, pachhi denomenator no mod inv (deno^(mod-2)%mod) gotine numerator ne guno, eno mod javab
mathematically simplify thaine + - * / % factors divisors ganvano formula ma reduce thai jaay to kari jo
multiplication ma number of zeros ganva hoy to min(number of 2, number of 5) 


[DHYAN MA RAAKH]
SIGABRT abort ave to long long lai le, overflow na lidhe aave chhe.
khabar chhe ke max time atlo j thase ane posay to badhuy check karavi lo
% vadama darek + - * / ma % karvanu nai bhulvanu, jo <0 to +m kari devanu
n%0 naa thavu joi
bau kharab formal karta setting saru
