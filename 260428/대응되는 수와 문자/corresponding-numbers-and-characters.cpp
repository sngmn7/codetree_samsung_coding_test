#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

#define MAX_N 100000

int n, m;
string words[MAX_N + 1];
unordered_map<string, int> s;

int main() {
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        cin >> words[i];
        s[words[i]] = i;
    }

    while(m--) {
        string key;
        cin >> key;

        if('0' <= key[0] && key[0] <= '9') //숫자면
            cout << words[stoi(key)] << endl;
        
        else
            cout << s[key] << endl;
    }
    return 0;
}