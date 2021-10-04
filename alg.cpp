#include <bits/stdc++.h>
using namespace std;

template <typename T>
void iter(vector<T> v){
    for(int i=0; i<v.size(); ++i){
        cout << v[i];
    }
    cout << endl << endl;
}

void wczytanie(string &a, string &b);
vector<char> f_alfabet(string klucz);

string szyfrowanie();
string odszyfrowanie();

int main(){
    string s;
    s = odszyfrowanie();
    cout << "Odszyfrowany tekst: "<<s<< endl;
    s = szyfrowanie();
    cout << "Zaszyfrowany tekst: "<<s << endl;
    s = szyfrowanie();
    cout << "Zaszyfrowany tekst: ";
    for(int i=s.length()-1; i>=0; --i)
        cout << s[i];
    cout <<endl <<endl;
    return 0;
}

void wczytanie(string &a, string &b){
    string tekst;
    string klucz;

    cout << "Podaj tekst:\n>";
    getline(cin, tekst);
    cout << "Podaj klucz:\n>";
    getline(cin, klucz);

    // zamiana na wielkie litery:
    string backup = "";
    for(int i=0; i<tekst.size(); ++i){
        backup+=toupper(tekst[i]);
    }
    tekst = backup;
    backup ="";
    for(int i=0; i<klucz.size(); ++i){
        backup+=toupper(klucz[i]);
    }
    klucz = backup;

    a = tekst;
    b = klucz;
}

vector<char> f_alfabet(string klucz){

    map<char, bool> mapa;
    for(int i=0; i<klucz.size(); ++i){
       if(klucz[i] != ' ') mapa[klucz[i]] = false;
    }

    vector<char> alfabet;
    // tworzenie alfabetu
  

    for(int i=0; i<klucz.size(); ++i){
        if(mapa[klucz[i]] == false and klucz[i]!=' '){
            alfabet.push_back(klucz[i]);
            mapa[klucz[i]] = true;
        }
    }

    for(int i=65; i<91; ++i){
        if(mapa[(char)i] == false){
            alfabet.push_back((char)i);
            mapa[(char)i] = true;
        }
    }
    return alfabet;
}


string szyfrowanie(){
    string tekst;
    string klucz;

    wczytanie(tekst,  klucz);

    vector<char> alfabet;
    alfabet = f_alfabet(klucz);

    // szyfrowanie
    string nowy = "";
    int poz;
    for(int i=0; i<tekst.size(); ++i){
        poz = (int)tekst[i];
        poz -= 65;
        if(tekst[i]!=' ')nowy += alfabet[poz];
        else nowy += ' ';
    }    

   return nowy;
}

string odszyfrowanie(){
    string tekst;
    string klucz;

    wczytanie(tekst, klucz);

    vector<char> alfabet;
    alfabet = f_alfabet(klucz);

    // odszyfrowanie
    string nowy ="";
    int poz;
    for(int i=0; i<tekst.size(); ++i){
        if(tekst[i] == ' ') nowy += ' ';
        else
            for(int j=0; j<alfabet.size(); ++j){
                if(tekst[i] == alfabet[j]){
                    nowy += (char)((int)j+65);
                }
            
        }
    }
    return nowy;
}