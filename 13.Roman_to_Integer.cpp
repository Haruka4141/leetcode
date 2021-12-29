#include <string>
#include <iostream>

int romanToInt(std::string s)
{
    int value = 0;
    
    for (auto it = s.begin(); it != s.end(); it++)
    {
        switch ((char)*it)
        {
        case 'I':
            ++value;
            break;
        case 'V':
            if (it != s.begin() && (char)*(it - 1) == 'I')
                value += 3;
            else
                value += 5;
            break;
        case 'X':
            if (it != s.begin() && (char)*(it - 1) == 'I')
                value += 8;
            else
                value += 10;
            break;
        case 'L':
            if (it != s.begin() && (char)*(it - 1) == 'X')
                value += 30;
            else
                value += 50;
            break;
        case 'C':
            if (it != s.begin() && (char)*(it - 1) == 'X')
                value += 80;
            else
                value += 100;
            break;
        case 'D':
            if (it != s.begin() && (char)*(it - 1) == 'C')
                value += 300;
            else
                value += 500;
            break;
        case 'M':
            if (it != s.begin() && (char)*(it - 1) == 'C')
                value += 800;
            else
                value += 1000;
            break;
        }
    }
    return value;
}


int main()
{
    std::cout << romanToInt("IX") << std::endl;
    return 0;
}