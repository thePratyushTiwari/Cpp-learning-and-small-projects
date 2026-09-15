#include<iostream>
using namespace std;

// 4-bit Binary to Grey Code converter

int main(){

    bool b3, b2, b1, b0;
    bool g3, g2, g1, g0;

    cout << "Enter the 4-bit binary (digits seperated by space): ";
    cin >> b3;
    cin >> b2;
    cin >> b1;
    cin >> b0;

    g3 = b3;
    g2 = (b3 && !b2) || (b2 && !b3);
    g1 = (b1 && !b2) || (b2 && !b1);
    g0 = (b0 && !b1) || (b1 && !b0);

    cout << "The grey-code value is: ";
    cout << g3 << g2 << g1 << g0 << '\n';
    
    return 0;

}
