#include<iostream>
#include <regex> 

bool isSmaller(std::string str1, std::string str2)
{
    int s1 = str1.length(), s2 = str2.length();

    if (s1 < s2)
        return true;
    if (s2 > s1)
        return false;

    for (int i = 0; i < s1; i++)
    {
        if (str1[i] > str2[i])
            return true;
        else if (str1[i] < str2[i])
            return false;
    }
    return false;
}

std::string findDiff(std::string str1, std::string str2)
{
   if (isSmaller(str1, str2))
        swap(str1, str2);

    std::string str = "";

    int s1 = str1.length(), s2 = str2.length();
    int diff = s1 - s2;

    int carry = 0;

    for (int i = s2 - 1; i >= 0; i--)
    {
        int sub = ((str1[i + diff] - '0') - (str2[i] - '0') - carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    for (int i = s1 - s2 - 1; i >= 0; i--)
    {
        if (str1[i] == '0' && carry)
        {
            str.push_back('9');
            continue;
        }
        int sub = ((str1[i] - '0') - carry);
        if (i > 0 || sub > 0) 
            str.push_back(sub + '0');
        carry = 0;
    }

    reverse(str.begin(), str.end());

    return str;
}

int main()
{
    std::string str1, str2;
    std::cin >> str1 >> str2;
    std::cout << findDiff(str1, str2);
    return 0;
}
