// https://youtu.be/wq-Cp3kl1nI?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

// Sol : https://youtu.be/gZp776a-pbQ?list=PL-Jc9J83PIiFj7YSPl2ulcpwy-mwj1SSk

// Print Digits of a number from left to right

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n <= 9)
        cout << n << "\n";
    else
    {
        int temp = 1;
        int cn = n; // to keep a copy of the number

        while (cn >= 9)
        {
            temp *= 10;
            cn /= 10;
        }

        while (temp > 0)
        {
            cout << n / temp << "\n";
            n = n % temp;
            temp /= 10;
        }
    }
}