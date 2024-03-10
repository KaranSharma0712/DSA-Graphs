#include<bits/stdc++.h>
using namespace std;
const int d = 10;
const int prime = 13;
int hashValue(const string &str,int len){
    int hashcode = 0;
    for(int i=0;i<len;i++){
        hashcode = (hashcode * d + str[i])%prime;
    }
    return hashcode;
}

void rabinKarp(const string &text,const string &pattern){
    int m = text.length();
    int n = pattern.length();
    int textHash = hashValue(text,n);
    int patternHash = hashValue(pattern,n);
    for(int i=0;i<=m-n;i++){
        if(textHash == patternHash){
            int j;
            for(j=0;j<n;j++){
                if(text[i+j]!=pattern[j]){
                    break;
                }
            }
            if(j==n){
                cout<<"found at: "<<i+1<<endl;
                return;
            }
        }
        if(i<m-n){
            textHash = (d*(textHash - text[i]*(int)pow(d,n-1))+text[i+n])%prime;
            if(textHash <0){
                textHash+=prime;
            }
        }
    }
    cout<<"not found"<<endl;
}

int main(){
    string text,pattern;
    getline(cin,text);
    getline(cin,pattern);
    rabinKarp(text,pattern);
}
