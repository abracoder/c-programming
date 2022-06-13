#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;


bool isPallindrome(string s, int i){

    int len=s.length();
    if(i>=len/2){
        return true;
    }
    if(s[i]!=s[len-i-1])return false;

    return isPallindrome(s,i+1);




}

int main(){
    string s="MOHOM";
    cout<<isPallindrome(s,0);
}