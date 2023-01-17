#include<iostream>

using namespace std;


int getPrefixNum(string s) {
    int num = 0;

    if(s == "IV") {
        num = 4;
    } else if (s == "IX")
    {
        num = 9;
    } else if (s == "XL")
    {
        num = 40;
    } else if (s == "XC")
    {
        num = 90;
    } else if (s == "CD")
    {
        num = 400;
    } else if (s == "CM")
    {
        num = 900;
    } else {
        num = 0;
    }

    return num;
    
}

int romanToInt(string s) {
    
    string str = "", m = "";
    int sum = 0;
    

    for (int  i = 0; i < s.length(); i++)
    {
        m += s[i];
        m += s[i+1];
        int p = getPrefixNum(m);

        if (p != 0)
        {
            i++;
            sum += p;
        } else {
            str += s[i]; 
        }
        
        m = "";
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'I')
        {
            sum += 1;
        } else if (str[i] == 'V')
        {
            sum += 5;
        } else if (str[i] == 'X')
        {
            sum += 10;
        } else if (str[i] == 'L')
        {
            sum += 50;
        } else if (str[i] == 'C')
        {
            sum += 100;
        } else if (str[i] == 'D')
        {
            sum += 500;
        } else if (str[i] == 'M')
        {
            sum += 1000;
        }
        
    }
    

    return sum;
        
 }

int main() {
    string s;

    cin >> s;

   int result = romanToInt(s);

   cout << result << endl;
}