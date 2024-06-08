#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
using namespace std;

int menu();
string get();
int len(string str);
string upper(string str);
string lower(string str);
string fupper(string str);
string erase(string str, int start, int endpoint);
int lenWord(string str);
string rtrim(string str);
string ltrim(string str);
string trim(string str);
string substring(string str, int start, int endpoint);
string numbcounter(string str);
int random(int start, int endpoint);
string gameNames[] = {"amir", "saeed", "shayan"};
string game();
string money();
string key();
void exit_app();

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

int menu()
{
    system("cls");
    char command;
    string menuText = R"(
++------------------------------------++
++------------------------------------++
|| _   _  ___ _____   _    ____  ___  ||
||| \ | |/ _ \__  /  / \  |  _ \|_ _| ||
|||  \| | | | |/ /  / _ \ | |_) || |  ||
||| |\  | |_| / /_ / ___ \|  _ < | |  ||
|||_| \_|\___/____/_/   \_\_| \_\___| ||
||                                    ||
++------------------------------------++
++------------------------------------++

1.  Menu (this app)
2.  Len String
3.  Upper String
4.  Lower String
5.  Upper String Space
6.  Erase String
7.  Len Word
8.  Right Trim
9.  Left Trim
a.  Trim
b.  SubString
c.  Enter Number & Count
d.  Random Number (start/endpoint)
e.  Game (guess the word)
f.  Money (ATM)
g.  Word Capital (Shift + F3)
0.  EXIT :)

- please select a number : )";
    cout << menuText;
    command = getch();
    // Show Menu to User
    switch (command)
    {
    case '1':
    {
        menu();
        exit_app();
    }
    // Len String
    case '2':
    {
        int strLen = len(get());
        cout << "len your string is : " << strLen;
        exit_app();
    }

    // upper case
    case '3':
    {
        string strUpper = upper(get());
        cout << "upper case your string is : " << strUpper;
        exit_app();
    }

    // lower case
    case '4':
    {
        string strLower = lower(get());
        cout << "lower case your  is : " << strLower;
        exit_app();
    }

    // first word of string upper
    case '5':
    {
        string strFupper = fupper(get());
        cout << "First Upper case your String is : " << strFupper;
        exit_app();
    }

    // erase
    case '6':
    {
        system("cls");
        int start, endpoint;
        string str;
        str = get();
        cout << "Please input start point : ";
        cin >> start;
        cout << "Please input end point : ";
        cin >> endpoint;
        system("cls");
        cout << "New String is : " << erase(str, start, endpoint);
        exit_app();
    }

    // len word
    case '7':
    {
        int lenWord_var = lenWord(get());
        cout << "Len Word is : " << lenWord_var;
        exit_app();
    }
    // r trim
    case '8':
    {
        string rtrim_var = rtrim(get());
        cout << "new string is : " << rtrim_var << endl;
        cout << "new string len is : " << len(rtrim_var);
        exit_app();
    }

    // l trim
    case '9':
    {
        string ltrim_var = ltrim(get());
        cout << "new string is : " << ltrim_var << endl;
        cout << "new string len is : " << len(ltrim_var);
        exit_app();
    }

    // trim
    case 'a':
    {
        string trim_var = trim(get());
        cout << "new string is : " << trim_var << endl;
        cout << "new string len is : " << len(trim_var);
        exit_app();
    }

    // substring
    case 'b':
    {
        system("cls");
        int start, endpoint;
        string str;
        str = get();
        cout << "please input start point : ";
        cin >> start;
        cout << "please input end point : ";
        cin >> endpoint;
        system("cls");
        cout << "exported string is : " << substring(str, start, endpoint);
        exit_app();
    }

    // number counter
    case 'c':
    {
        system("cls");
        numbcounter(get());
        exit_app();
    }

    // random number generator
    case 'd':
    {
        system("cls");
        int start, endpoint, count;
        cout << "please input start point : ";
        cin >> start;
        cout << "please input end point : ";
        cin >> endpoint;
        system("cls");
        cout << "please input number of random numbers : ";
        cin >> count;
        for (int i = 0; i < count; i++)
        {
            cout << "random number [" << i + 1 << "] : " << random(start, endpoint) << endl;
        }

    // game
    case 'e':
    {
        system("cls");
        game();
        exit_app();
    }

        exit_app();
    }

    // money
    case 'f':
    {
        system("cls");
        money();
    }

    // key
    case 'g':
    {
        system("cls");
        key();
        exit_app();
    }
    default:
        menu();
        break;
    }
    return 0;
}

string get()
{
    system("cls");

    string str;
    cout << "please input string : ";
    getline(cin, str);
    return str;
}

int len(string str)
{
    int count = 0;
    while (str[count])
    {
        count++;
    }
    return count;
}

string upper(string str)
{
    for (int i = 0; i < len(str); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 'a' + 'A';
        }
    }
    return str;
}

string lower(string str)
{
    for (int i = 0; i < len(str); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] - 'A' + 'a';
        }
    }
    return str;
}

string fupper(string str)
{
    if (str[0] >= 'a' && str[0] <= 'z')
    {
        str[0] -= 32;
    }
    for (int i = 0; i < len(str); i++)
    {
        if (str[i - 1] == ' ' && str[i] != ' ' && str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
    return str;
}

string erase(string str, int start, int endpoint)
{
    string result = "";
    for (int i = 0; i < len(str); i++)
    {
        if (i < start || i > endpoint)
        {
            result += str[i];
        }
    }
    return result;
}

int lenWord(string str)
{
    int count = 1;
    for (int i = 0; i < len(str); i++)
    {
        if (str[i - 1] == ' ' && str[i] != ' ')
        {
            count++;
        }
    }

    return count;
}

string rtrim(string str)
{
    int endpoint;
    for (int i = (len(str) - 1); i >= 0; i--)
    {
        if (str[i] != ' ')
        {
            endpoint = i;
            break;
        }
    }

    string result = "";
    for (int i = 0; i <= endpoint; i++)
    {
        result += str[i];
    }
    return result;
}

string ltrim(string str)
{
    int start;
    for (int i = 0; i < len(str); i++)
    {
        if (str[i] != ' ')
        {
            start = i;
            break;
        }
    }

    string result = "";
    for (int i = start; i < len(str); i++)
    {
        result += str[i];
    }
    return result;
}

string trim(string str)
{
    int start, endpoint;
    for (int i = 0; i < len(str); i++)
    {
        if (str[i] != ' ')
        {
            start = i;
            break;
        }
    }

    for (int i = len(str) - 1; i >= 0; i--)
    {
        if (str[i] != ' ')
        {
            endpoint = i;
            break;
        }
    }

    string result = "";
    for (int i = start; i <= endpoint; i++)
    {
        result += str[i];
    }

    return result;
}

string substring(string str, int start, int endpoint)
{
    string result = "";
    for (int i = start; i < endpoint; i++)
    {
        result += str[i];
    }
    return result;
}

string numbcounter(string str)
{

    int lenstr = len(str), counter;

    for (int i = 0; i < lenstr; i++)
    {
        if (str[i] != '*')
        {
            counter = 1;
            for (int j = i + 1; j < lenstr; j++)
            {
                if (str[i] == str[j])
                {
                    str[j] = '*';
                    counter++;
                }
            }

            cout << str[i] << " : " << counter << endl;
        }
    }
}

int random(int start, int endpoint)
{
    return (rand() % (endpoint - start)) + start;
}

string game()
{
    system("cls");
    char ch;
    int lenNames = sizeof(gameNames) / sizeof(gameNames[0]), randomIndex = random(0, lenNames);
    string starName = "", randName = gameNames[randomIndex];
    int endGame = len(randName) + 2;
    for (int i = 0; i < lenNames; i++)
    {
        cout << gameNames[i] << endl;
    }
    Sleep(1000);
    for (int i = 0; i < len(randName); i++)
    {
        starName += '*';
    }
    system("cls");
    cout << "star rand string is : " << starName << endl;
    for (int i = 1; i <= endGame; i++)
    {
        cout << starName << "-> try to complate with char (" << i << "/" << endGame << ") : ";
        ch = getch();
        cout << endl;
        for (int j = 0; j < len(randName); j++)
        {
            if (randName[j] == ch)
            {
                starName[j] = ch;
            }
        }
        if (starName == randName)
        {
            system("cls");
            cout << "you are winner !!! name is : " << starName;
            break;
        }
        else if (i == endGame)
        {
            system("cls");
            cout << "you are Faild :( name is : " << starName;
            break;
        }
    }
}

string money()
{
    // initialize variables
    bool cflag = true;
    int inventor, total_inventor, ten, five, two;
    int deposit, total_deposit, ten_deposit, five_deposit, two_deposit;
    system("cls");
    cout << "please inter inventor value to charge device [0 to Exit]: ";

    while (true)
    {
        cin >> inventor;
        if (inventor > 0)
        {
            break;
        }
        else if (inventor == 0)
        {
            system("cls");
            menu();
            cflag = false;
            break;
        }
        else
        {
            cout << "not valid !!!" << endl;
        }
    }

    if (cflag)
    {
        // calculate ten, five, two banknotes
        total_inventor = inventor;
        ten = inventor / 10;
        inventor %= 10;
        five = inventor / 5;
        inventor %= 5;
        two = inventor / 2;
        inventor %= 2;

        system("cls");
        cout << "------------ INVENTOR STATUS ------------" << endl;
        cout << "total inventor : " << total_inventor << endl;
        cout << "- ten : " << ten << endl;
        cout << "- five : " << five << endl;
        cout << "- two : " << two << endl;
        cout << "- left over inventor : " << inventor << endl;

        while (true)
        {
            cout << endl
                 << "please inter deposit number : ";
            cin >> deposit;
            if (deposit == 0)
            {
                menu();
            }
            else if (deposit > total_inventor || deposit < 0)
            {
                system("cls");
                cout << "\a::: ERROR ! this diposit number bigger or deposit is < 0" << endl;
                continue;
            }

            total_deposit = deposit;
            ten_deposit = deposit / 10;
            deposit %= 10;
            five_deposit = deposit / 5;
            deposit %= 5;
            two_deposit = deposit / 2;
            deposit %= 2;

            system("cls");
            cout << "------------ DIPOSIT STATUS ------------" << endl;
            cout << "total deposit : " << total_deposit << endl;
            cout << "- ten : " << ten_deposit << endl;
            cout << "- five : " << five_deposit << endl;
            cout << "- two : " << two_deposit << endl;
            cout << "- left over deposit : " << deposit << endl;

            total_inventor -= total_deposit;
            inventor = total_inventor;
            ten = inventor / 10;
            inventor %= 10;
            five = inventor / 5;
            inventor %= 5;
            two = inventor / 2;
            inventor %= 2;

            cout << "------------ INVENTOR STAUS ------------" << endl;
            cout << "total inventor : " << total_inventor << endl;
            cout << "- ten : " << ten << endl;
            cout << "- five : " << five << endl;
            cout << "- two : " << two << endl;
            cout << "- left over inventor : " << inventor << endl;
        }
    }
}

string key()
{
    int counter = 0;
    string str;
    char ch1, ch2;
    system("cls");
    cout << "please input string : ";
    getline(cin, str);
    int lenstr = len(str);
    system("cls");
    cout << str << endl;
    while (counter <= 4)
    {
        ch1 = getch();
        ch2 = getch();
        if (ch1 == 0 && ch2 == 86)
        { // origianl str
            counter++;

            // fupper
            if (counter == 1)
            {
                system("cls");
                cout << fupper(str);
            }

            // upper
            if (counter == 2)
            {
                system("cls");
                cout << upper(str);
            }

            // lower
            if (counter == 3)
            {
                system("cls");
                cout << lower(str);
            }

            if (counter == 4)
            {
                exit_app();
            }
        }
    }
}
void exit_app()
{
    char exit_command;
    cout << endl
         << endl
         << "Press 0 to back to Menu or AnyKey to Exit" << endl;
    exit_command = getch();
    if (exit_command == '0')
    {
        menu();
    }
    else
    {
        cout << "Good Bye My Love :))";
    }
}
