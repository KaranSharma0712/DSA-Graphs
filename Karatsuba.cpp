#include<bits/stdc++.h>
using namespace std;

int getSize(long n){
    int count=0;
    while(n>0){
        n=n/10;
        count++;
    }
    return count;
}

long long karatsuba(long long x,long long y){
    if(x<10 && y<10){
        return x*y;
    }
    
    int size = fmax(getSize(x),getSize(y));
    cout<<"X:"<<x<<", "<<"Y:"<<y<<endl;
    int n = (int)ceil(size/2.0);
    long p = pow(10,n);
    long a = (long)floor(x/(double)p);
    long b = x % p;
    cout<<"x1="<<a<<" "<<"x2="<<b;
    long c = (long)floor(y/(double)p);
    long d = y % p;
    cout<<"y1="<<c<<" "<<"y2="<<d;
    cout<<endl;
    
    long ac = karatsuba(a,c);
    long bd = karatsuba(b,d);
    long e = karatsuba(a+b,c+d) - ac - bd;
    
    long long jk = (long long)(ac*(pow(10*1L,2*n)) + e*(pow(10*1L,n)) + bd);
    cout<<"a="<<ac<<" "<<"b="<<e<<" "<<"c="<<bd<<endl;
    cout<<"xy="<<jk<<endl;
    cout<<endl;
    
    return (long long)(ac*(pow(10*1L,2*n)) + e*(pow(10*1L,n)) + bd);
}

int main(){
    int x,y;
    cin>>x>>y;
    long long c = karatsuba(x,y);
    cout<<x<<"*"<<y<<"="<<c;
}
