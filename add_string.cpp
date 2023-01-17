#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 string addStrings(string num1, string num2) {
        int i = 0,j = 0, c = 0, p = 0, q = 0;
        string sum = "";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        while (i < num1.size() && j < num2.size())
        {
            p = num1[i] - 48;
            q = num2[j] - 48;

            sum += ((p+q+c) % 10) + 48;
            c = (p+q+c) / 10;
            
            i++;
            j++;
        }

        while (i < num1.size())
        {
             p = num1[i] - 48;
             sum += ((p+c) % 10) + 48;
             c = (p+c) / 10;
            i++;
        }

        while (j < num2.size())
        {
             q = num2[j] - 48;
             cout << q << " " << c << endl;
             sum += ((q+c) % 10) + 48;
             c = (q+c) / 10;
            j++;
        }

        if (c != 0)
        {
            sum += c + 48;
        }
        
        
        reverse(sum.begin(), sum.end());

        return sum;
}

int main() {
    string s1, s2;

    cout << "Enter two nums" << endl;

    cin >> s1;
    cin >> s2;

    string s = addStrings(s1,s2);

    cout << s << endl;

    return 0;
}