#include<bits/stdc++.h>
using namespace std;
void three(string str)
{   int j = 0;
    while (!(str[j] >= 65 && str[j] <= 90) && !(str[j] >= 97 && str[j] <= 122))
    {
        j++;
    }
    if (str[j] >= 97 && str[j] <= 122)
    {
        str[j] = str[j] - 32;
        j++;
    }
    for (; str[j] != '\0'; j++)
    {
        if (str[j] == ' ')
        {
            if (str[j + 1] == ' ')
            {
                while (str[j + 1] == ' ')
                {
                    cout << j << " " << str[j] << endl;
                    str.erase(j);
                }
                if (str[j + 1] >= 97 && str[j + 1] <= 122)
                {
                    str[j + 1] = str[j + 1] - 32;
                }
            }
            else
            {
                if (str[j + 1] >= 97 && str[j + 1] <= 122)
                {
                    str[j + 1] = str[j + 1] - 32;
                }
            }
        }
    }
    cout << "required string is: " << str << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Input.txt" , "r" , stdin);
    freopen("Output.txt" , "w" , stdout);
#endif
    string s = "??harry, is  a boy!" ;
    int i = 0;
    for (char c : s) {
        cout << c << " " << i++ << endl;
    }
    three(s);
}