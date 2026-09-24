#include<bits/stdc++.h>
using namespace std;

//	Input any text and you will get the text without any duplicates in it .


string removeDuplicate( string text, bool *arr, string cleanText = "", int index = 0 ) {
	
	if(index == text.length())
		return cleanText;
	
	else if( !arr[text[index] - 'a'] ) {
		cleanText += text[index];
		arr[text[index] - 'a'] = true;
	}

	return removeDuplicate(text, arr, cleanText, index + 1);
}

string removeDupl( string text ) {
	bool arr[26] = {false};
	return removeDuplicate(text, arr);
}

int main()
{
	string text;
	getline(cin >> ws, text);
	cout << removeDupl(text) << '\n';
	return 0;
}
