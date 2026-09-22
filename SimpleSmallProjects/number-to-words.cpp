#include<bits/stdc++.h>
using namespace std;

/*
    word = ["zero" ... "nine"]
    INPUT : 1947
    OUTPUT : one nine four seven
*/

string typeing(vector<string> word, int num){
    if(num == 0) return "";
    string sans = typeing(word, num/10);
    string ans = sans + " " + word[num%10];
    return ans;
}

int main()
{
    vector<string> word = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    cout << typeing(word, 1947);
    return 0;
}
