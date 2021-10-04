#include <bits/stdc++.h>
using namespace std;

bool sito(int liczba){
    bool tab[liczba+1];

    for(int i=0;i<liczba+1; ++i) tab[i]=true;

    for(int i=2; i*i<liczba+1; ++i){
        for(int j=i+i; j<liczba+1; j+=i){
            tab[j] = false;
        }
    }
    return tab[liczba];
}

int main(){
    int liczba;
    cin >> liczba;

    sito(liczba) == false ? cout << "Nie jest to liczba pierwsza!\n\n" : cout << "Jest to liczba pierwsza!\n\n";

    return 0;
}