#include <iostream>
using namespace std;

int main()
{
    string str;
    cout << "please input string : ";
    cin >> str;
    int count = 0;
    while (str[count])
    {
        count++;
    }
    cout << "len your string is : " << count;
    return 0;
}