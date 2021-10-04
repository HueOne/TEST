#include <bits/stdc++.h>
using namespace std;



double odleglosc(double x, double y, double a, double b, double c){
    // fx() = a* x + b*y +c

    double d;
    d = abs(x*a + y*b + c);
    d /= sqrt(pow(a, 2)+pow(b,2)); 

    return d;
}

int main(){
    double x, y, a, b, c;
    ///cin >> x >> y >> a >> b >> c;
    x = 2;
    y = 0;
    a = 0.5;
    b = 1;
    c = 0;
    cout << odleglosc(x, y, a, b, c);
    return 0;
}