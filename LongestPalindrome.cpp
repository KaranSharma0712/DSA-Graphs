#include<iostream>
#include<vector>
using namespace std;

string longestPalindrome(const string &s){
    int n=s.length();
    vector<vector<bool>> table(n,vector<bool>(n,false));
    int start = 0;
    int maxLength = 1;
    for(int i=0;i<n;i++){
        table[i][i] = true;
    }
    for(int i=0;i<n-1;i++){
        if(s[i] == s[i+1]){
            table[i][i+1]=true;
            start=i;
            maxLength=2;
        }
    }
    for(int k=3;k<=n;k++){
        for(int i=0;i<=n-k;i++){
            int j = i+k-1;
            if(table[i+1][j-1] && s[i]==s[j]){
                table[i][j]=true;
                if(k>maxLength){
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    string longPal = s.substr(start,maxLength);
    for(int len=3;len<=maxLength;len++){
        for(int i=0;i<=n-len;i++){
            int j=i+len-1;
            if(table[i][j]){
                cout<<s.substr(i,len)<<endl;
                break;
            }
        }
    }
    cout<<"Longest Palindrome is: "<<longPal <<endl;
    return longPal;
}

int main(){
    string input;
    cout<<"";
    getline(cin,input);
    string result = longestPalindrome(input);
    
}
