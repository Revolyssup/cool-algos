[https://en.wikipedia.org/wiki/Fast_inverse_square_root](Wiki link to this algorithm's history and what it does.)

## Short Explaination

1. Fact:
floating point numbers are described from their bit representation as per IEEE 754 and no bit manipulation is possible on them.

2. Observation

If we take a log of float number IEEE 754 representation, then it comes out to be approximately some scaled and shifted version of its original bit representation.

3. Trick

So we know it is easy to take logs. Then given , y=1/sqrt(x) => log(y)=-1/2(logx). From here we can calculate logx by above method, hence finding logy. Then from there simply descale/deshift to get original y.

4. Better answer.

What we got from above step was an approximation(close enough). So we can get better approximation by using newton's method.

5. Approximating.

Let,
``` y=f(x)=1/sqrt(x) => y*y=1/x => (1/y*y)-x=0. 
```
here x is the given input, consider that to be constant. We have a function in y :
```
f(y)=(1/y*y)-x ; We want f(y)=0.
```
From Newton approximation, we know, y1=y0-(f(y)/f'(y));

here, 
```
f(y)=(1/y*y)-x
f'(y)=-2/(y*y*y)
f(y)/f'(y)=-(y/2*(1-x*y*y))
y1=y(3/2-(x/2)*y*y)
```

y1 is the better approximation. We can keep going, but mostly y1 is good enough approximation, because our initial approximation was already good.