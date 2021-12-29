//leetcode submission:
double myPow_v3(double x, int n)
{
    if (n == 0)
        return 1;
    if (n == -1) 
        return 1 / x;
    if (n % 2) 
        return x * myPow_v3(x, n - 1);      //add more 1 recursive
    else 
    {
        double y = myPow_v3(x, n / 2);
        return y * y;
    }
}

//https://stackoverflow.com/questions/30837922/implement-powx-n
/*
e.g.
                 2^10
                /    \
           2^5*2      2^5*2     
           /  \      /   \
         2^2   2^2  2^2   2^2

*/
double QuickPow(double x, int n)
{
    if (n == 0)
    {
        return 1.0;
    }
    else if (n == 1)
    {
        return x;
    }
    else if (n % 2 == 0 && n > 0)
    {
        double half = QuickPow(x, n / 2);
        return half * half;
        //return QuickPow(x, n / 2) * QuickPow(x, n / 2);         //causing two revursive!!   no need!!
    }
    else if (n % 2 == 1)
    {
        double half = QuickPow(x, n / 2);
        return half * half * x;
        //return QuickPow(x, n / 2) * QuickPow(x, n / 2) * x;
    }
    else if (n == -1)
    {
        return 1 / x;
    }
    else if (n % 2 == 0 && n < 0)
    {
        double half = QuickPow(x, n / 2);
        return half * half;
    }
    else if (n % 2 == -1)
    {
        double half = QuickPow(x, n / 2);
        return half * half / x;
    }
}

double myPow(double x, int n)
{                                                 // v : n == INT_MIN, overflow!
    //return n > 0 ? QuickPow(x, n) : 1 / QuickPow(x, -n);        //<-***
    return QuickPow(x, n);
}

int main()
{

    auto ans = myPow(1, -2147483648);

    return 0;
}
//recursing by 1
double myPow_v1(double x, int n)       //0.00001, 2147483647 Call Stack overflow!!! 
{
    if (n == 0)
        return 1.0;

    if (n > 1)
    {
        return myPow_v1(x, n - 1) * x;
    }
    else if (n == 1)
    {
        return x;
    }
    else if (n == -1)
    {
        return 1 / x;
    }
    else
    {
        return myPow_v1(x, n + 1) / x;
    }
}