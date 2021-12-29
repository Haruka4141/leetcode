int mySqrt(int x)   //submission
{
    unsigned int high = x;
    unsigned int low = 1;
    long int mid;
    while (high >= low)
    {
        mid = (high + low) / 2;

        if (mid * mid == x)
            return mid;

        if (mid * mid > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return high;
}

//Hint1:
//Try exploring all integers. 
//Hint2:
//Use the sorted property of integers to reduced the search space.
//(2^31 - 1)^0.5 = 49340.95...
int mySqrt_v1(int x) 
{
    if (x == 0)
        return 0;

    if (x >= 2147395600)
        return 46340;

    int left = 1;
    int right = 46340;
    int mid = (left + right) / 2;

    while (left < right)
    {
        if (mid * mid > x)
            right = mid;
        else
            left = mid;

        mid = (left + right) / 2;
    }
    return left;
}

int main()
{

    int ans = mySqrt(2147395599);
    return 0;
}