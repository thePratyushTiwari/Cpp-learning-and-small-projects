#include<iostream>
#include<cmath>
using namespace std;

// Binary to Decimal

int convertToDecimal(int);

int main(){
    
    int binary;
    cout << "Enter the binary number: ";
    cin >> binary;

    cout << "The decimal number for the binary number " << binary << " is: " << convertToDecimal(binary) << '\n';

    return 0;

}

int convertToDecimal(int binary){
    int digit, decimal = 0;
    for(int i = 0; binary > 0; i++){
        digit = binary % 10;
        binary/=10;
        if(digit!=0)
            decimal += pow(2, i);
    }

    return decimal;
}
