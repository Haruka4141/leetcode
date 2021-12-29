#include <vector>

using namespace std;

//https://en.wikipedia.org/wiki/Gray_code
//https://stackoverflow.com/questions/47981/how-do-you-set-clear-and-toggle-a-single-bit

vector<int> grayCode(int n)     //submission
{
    vector<int> ret(1 << n);    //ret size is known 
    ret[0] = 0;
    ret[1] = 1;

    int pos = 2;

    for (int bit = 2; bit <= n; ++bit)
    {
        for (int index = (1 << (bit - 1)) - 1; index >= 0; --index)
        {
            ret[pos++] = ret[index] + (1 << (bit - 1));
            //ret[pos++] = ret[index] ^ (1U << (bit - 1));     //toggling is also ok
        }
    }
    return ret;
}

vector<int> grayCode_reflect(int n)
{
    vector<int> ret = { 0, 1 };
    int curr = 1;

    while (curr < n)
    {
        for (int i = ret.size() - 1; i >= 0; --i)
        {
            int temp = ret[i];
            temp ^= 1U << curr;
            ret.push_back(temp);
        }
        ++curr;
    }

    return ret;

}

vector<int> grayCode_direct(int n)     //Directly construct, but it is slow when n is large
{
    vector<int> ret;
    uint16_t i = 1;
    int num_count = 1 << n;
    uint16_t num = 0;
    const uint16_t one = 1;

    ret.push_back(0);

    while (i < num_count)
    {
        if (i % 2 == 1)
        {
            num ^= one;            
        }
        else
        {
            unsigned int shift = 0;
            while ((num & one << shift) == 0)
            {
                ++shift;
            }
            num ^= one << ++shift;
        }
        ret.push_back(num);
        ++i;
    }
    return ret;
}

int main()
{

    auto ans = grayCode(16);

    return 0;
}

