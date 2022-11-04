#include <iostream>
#include <cmath>
using namespace std;
double r(const double x);
int main()
{
    double hp, hk, z;
    int n;
    cout << "hp = "; cin >> hp;
    cout << "hk = "; cin >> hk;
    cout << "n = "; cin >> n;
    double dh = (hk - hp) / n;
    double h = hp;
    while (h <= hk)
    {
        z = r(1 + h * h - 2 * h) + 2 * r(1 + r(h * h) - 2 * r(1) * r(1));
        cout << h << " " << z << endl;
        h += dh;
    }
    return 0;
}
double r(const double x)
{
    if (abs(x) >= 1)
        return (1 - sin(x) * sin(x)) / exp(x);
    else
    {
        double S = 0;
        int j = 0;
        double a = 1. * x / 1;
        S = a;
        do
        {
            j++;
            double R = 1. * x / 2 * j * j + 2 * j;
            a *= R;
            S += a;
        } while (j < 7);
        return (1. / (1 + x)) * S;
    }
}