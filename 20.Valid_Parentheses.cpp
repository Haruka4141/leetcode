#include <stack>
#include <string>

using namespace std;

bool isValid(string s)
{
    stack<char> parenthese_stack;       //using stack (cleaner)

    for (int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            parenthese_stack.push(s[i]);

        if (parenthese_stack.empty())
            return false;
        
        char stack_top = parenthese_stack.top();
        if (s[i] == ')' && stack_top != '(' ||
            s[i] == ']' && stack_top != '[' ||
            s[i] == '}' && stack_top != '{')
            return false;
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            parenthese_stack.pop();
    }
    return true;
}

int main()
{
    bool ret = isValid("()");
    return 0;
}

/*
bool isValid(string s) {

    stack<char> parenthese_stack;   //using stack!

    for (int i = 0; i < s.size(); ++i)
    {
        switch (s[i])
        {
        case '(':
        case '{':
        case '[':
            parenthese_stack.push(s[i]);
            break;
        case ')':
            if (parenthese_stack.empty())
                return false;
            else if (parenthese_stack.top() != '(')
                return false;
            else
                parenthese_stack.pop();
            break;
        case ']':
            if (parenthese_stack.empty())
                return false;
            else if (parenthese_stack.top() != '[')
                return false;
            else
                parenthese_stack.pop();
            break;
        case '}':
            if (parenthese_stack.empty())
                return false;
            else if (parenthese_stack.top() != '{')
                return false;
            else
                parenthese_stack.pop();
            break;
        }
    }
    if (parenthese_stack.empty())
        return true;
    else
        return false;
}
*/