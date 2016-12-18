#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MN 16123114
using namespace std;
typedef vector<int> BigInt;
BigInt multiplyVectors(BigInt v1, BigInt v2)
    {
    BigInt temp1;
    for(register int i=0;i<v2.size();i++)
        {
        BigInt temp2;
        temp2.assign(v2.size()-1-i,0);
        int multCarry=0;
        for(register int j=v1.size()-1;j>=0;j--)
            {
            int mult=v2[i]*v1[j]+multCarry;
            temp2.push_back(mult%10);
            multCarry=mult/10;
        }
        if(multCarry)
            temp2.push_back(multCarry);
        if(temp1.size()==0)
            temp1=temp2;
        else
        {
            int addCarry=0;
            register int k;
            for(k=0;k<temp2.size();k++)
            { int add=(temp1[k]+temp2[k]+addCarry);
                temp1[k]=add%10;
                addCarry=add/10;
            }
            while(addCarry)
            {
		if(k>=temp1.size())
		{	temp1.push_back(addCarry);addCarry=0;}
		else
		{	
	        int add=temp1[k]+addCarry;
			
                temp1[k++]=add%10;
                addCarry=add/10;
		}
            }            
        }                
    }
    BigInt t;
    for(int i=temp1.size()-1;i>=0;i--)
		t.push_back(temp1[i]);
    
    return t;
}


BigInt getVector(unsigned long int a)
 {   
    BigInt tempv1;
    BigInt tempv2;
    while(a>0){
	       	tempv1.push_back(a%10);
		    a=a/10;	
	   }
	for(int i=tempv1.size()-1;i>=0;i--)
		tempv2.push_back(tempv1[i]);
    return tempv2;
}

unsigned long int fact(int s, int e)
{
    unsigned long int ans=1;
    for(register int i=s;i<=e;i++)
            ans*=i;
    return ans;
}
int main(){
    int n;
    cin >> n;
    if(n<=20)
        cout<<fact(1,n);
    else
       {
        BigInt v1;
	v1.reserve(5000);
	v1=getVector(fact(1,20));
        n-=20;
        int nextIndex=21;
        int iter=n/5;
        for(int j=0;j<iter;j++)
        {
        BigInt v2=getVector(fact(nextIndex,nextIndex+4));
        nextIndex+=5;
        n-=5;
        v1=multiplyVectors(v1, v2);
        }
        if(n)
            {
            BigInt v2=getVector(fact(nextIndex,nextIndex+n-1));
            v1=multiplyVectors(v1, v2);
        }
        
        for(int i=0;i<v1.size();i++) // work upto 32 so far fix it
            cout<<v1[i];
        }
	cout<<endl;
    return 0;
}
//0333147966386144929666651337523200000000
