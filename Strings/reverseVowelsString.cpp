#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
bool isVowel(char c){
        return c=='a' || c== 'e' || c== 'i' || c=='o' || c=='u' ||
        c=='A' || c== 'E' || c== 'I' || c=='O' || c=='U'; 
    }
    string reverseVowels(string s) {
        int l=0;
        int r=s.size()-1;
        while(l < r){
            if(isVowel(s[l]) && isVowel(s[r])){
                swap(s[l],s[r]);
                l++;
                r--;
            }
            else if(!isVowel(s[l])){
                l++;
            }
            else if(!isVowel(s[r])){
                r--;
            }
        }
        return s;
    }


int main(){
return 0;
}