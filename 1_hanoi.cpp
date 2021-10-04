#include <bits/stdc++.h>
using namespace std;

void hanoi(int liczba, char a, char b, char c){
    if(liczba > 0){
        hanoi(liczba-1, a, b, c);
        cout << a << "--->" << c <<endl;
        hanoi(liczba-1, b, a, c);
    }
}

int main(){
    int liczba;
    cin >> liczba;
    hanoi(liczba, 'a', 'b', 'c');
    return 0;
}