#include<iostream>
#include<string>
#include<vector>
#include<ctime>
using namespace std;

int editDistance(string s, string t) {
    int n=s.size(), m=t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=0; i<n+1; i++)
        dp[i][0] = i;

    for(int j=0; j<m+1; j++)
        dp[0][j] = j;
    
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(s[i-1]==t[j-1]) {
                dp[i][j] = 0 + dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
            }
        }
    }

    return dp[n][m];
}

void getWords(string&s, string&t) {
    vector<string> first = {"horse","hair", "there","here", "time", "cosvo"};
    vector<string> second = {"house", "here","where","rose","vine", "ros"};
    int numOfWords = first.size();
    srand(time(NULL));
    s = first[rand()%numOfWords];
    t = second[rand()%numOfWords];
}

void submit(string&s, string&t, int ops, string&og) {
    if(s!=t) {
        cout << "=======>\tFAILED\t<=======\n";
        cout << "--> THE STRINGS DO NOT MATCH\n";
    } else {
        cout << "=======>\tPASSED\t<=======\n";
        int n = editDistance(s, og);
        if(ops==n) cout << "You did it in minimum operations!!\n";
        else cout << "Can you do it in " << n << " operations? \n";
    }
    
    cout << "Your Answer: " << s << "\nTarget: " << t << '\n';
    cout << "Number of operations: " << ops << '\n';
}

void insert(string&s) {
    int n = s.size();
    cout << "==============================\n";
    cout << ' ' << '\t';
    for(char c : s) {
        cout << c << '\t';
    }
    cout << '\n';
    int i=0;
    while(i<=n) {
        cout << i << '\t';
        i++;
    }
    cout << '\n';
    int idx;
    cout << "Enter the index where you want to insert: ";
    cin >> idx;
    if(idx>=0 && idx<=n) {
        char ch;
        cout << "Enter character to insert: ";
        cin >> ch;
        if(idx==0) {
            s = ch + s;
            return;
        }
        s = s.substr(0, idx) + ch + s.substr(idx, n);
        return;
    }
    cout  << "Index is not valid\n";
    return;
}

void replace(string&s) {
    cout << "==============================\n";
    for(char c : s) {
        cout << c << '\t';
    }
    cout << '\n';
    for(int i=0; i<s.size(); i++) {
        cout << i+1 << '\t';
    }

    int idx;
    cout <<"\n\nEnter index to replace: ";
    cin >> idx;
    
    if(!(idx>0 && idx<=s.size())) {
        cout << "index is not valid\n";
        return;
    }
    char ch;
    cout << "Enter character to replace: ";
    cin >> ch;
    s = s.substr(0, idx-1) + ch + s.substr(idx, s.size());
}

void Delete(string&s, int&ops) {
    cout << "==============================\n";
    for(char c : s) {
        cout << c << '\t';
    }
    cout << '\n';
    for(int i=0; i<s.size(); i++) {
        cout << i+1 << '\t';
    }

    int idx;
    cout <<"\n\nEnter index to delete: ";
    cin >> idx;
    
    if(!(idx>0 && idx<=s.size())) {
        cout << "index is not valid\n";
        return;
    }
    s = s.substr(0, idx-1) + s.substr(idx, s.size());
    ops++;
}

int main()
{
    cout << "==============================\n";
    cout << "          STRING GAME         \n";
    cout << "==============================\n";
    string first;
    string second;
    getWords(first, second);

    string og = first;
    
    int ask = -1;
    int ops = 0;
    while(ask!=0) {
        cout << "\n==============================\n";
        cout << "Given Word: " << first << '\n';
        cout << "Target Word: " << second << '\n';
        cout << "\n1. Insert\t2. Replace\t3. Delete\t0. Submit\nUser Choice: ";
        cin >> ask;
        if(!(ask<=3 && ask>=0)) continue;
        getchar();
        switch(ask) {
            case 0:
                cout << "\n============================\n";
                submit(first, second, ops, og);
                break;
            case 1:
                insert(first);
                ops++;
                break;
            case 2:
                replace(first);
                ops++;
                break;
            case 3:
                Delete(first, ops);
                break;
        }
    }
    
    return 0;
}
