#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <string>

using namespace std;

string solve(string str);
int main() {
    string a;
    cin >> a;
    cout << solve(a);


}
string solve(string str) {
    // write code here
    int i = 0;
    int a = str.size() - 1;
    while (i < a) {
        char temp = str[a];
        str[a] = str[i];
        str[i] = temp;
        i++;
        a--;
    }
    return str;
}