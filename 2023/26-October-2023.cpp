int minOperation(int n)
{
    //code here.
    int out = -1;
    while (n) {
        if (n % 2)
            ++out;
        n /= 2;
        ++out;
    }
    return out;
}
