
float fast_inv_sqrt(float n){
    long i; // The variable on which bit manipulations will happen.
    float y; //the answer.

    i= *(long *)&n; // we trick see the address of n as if its a long, and then get the long value on which we will do bit manipulation.
    i= 0x5f3759df-(i>>1);  //instead of halving, we can bit shift by 1. To see how this equation came, go to wiki.
    y= *(float *)&i; // Now we will read it back as if it was a float.

    //Newton approximation. Check readme for knowing where this equation came.
    y=y*(1.5f - 0.5f*n*y*y);

    return y;
}
