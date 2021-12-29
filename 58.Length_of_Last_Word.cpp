#include <string>

using namespace std;

int lengthOfLastWord(string s)
{
    int pos = s.size() - 1;
    int len = 0;

    while (s[pos] == ' ')
        --pos;

    while (pos >= 0 && s[pos] != ' ')
    {
        ++len;
        --pos;
    }

    return len;
}

int main()
{
    //int ans = lengthOfLastWord("hello world");
    int ans = lengthOfLastWord("a");

    return 0;
}