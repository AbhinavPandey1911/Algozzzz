/*
 Abhinav Pandey 
 @Copyrighted
*/
/* Problem Link :- https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/F
*/
/* Approach :- 
 Its an dynamic sliding window problem,
 so what we try to do is, initially at the start we slide our window
 until we find the difference between the max element and min element is atleast k in the window
 then once its done we slide that window from left keeping the right as it is and then again slide
 until we find the window with differenct between max and min >=k
 This is the approach that we'll follow now to find the no. of good subarrays we can say that
 once we find a subarray/window all subarrays containing that window will be good, to find that 
 we just do n-(j-i+1) where j and i are the indexes of our first window that satisfies the condition
 we also have to create a multiset to keep track of the max elements and min elements

 Algo-
  input(n,k)
  input(the array)
  i=0,j=0;
  multiset ms;
  while(i<n)
  {
    long long currmax=*ms.rbegin();
    long long currmin=*ms.begin();
    while(currmax-currmin<=k&&j<n)
        {j++; ms.insert(a[j]);
         currmax=*ms.rbegin();
         currmin=*ms.begin();
        }
    ans+=(j-i);
    ms.erase(ms.find(a[i]));
    i++;
;
       
  }
*/
#include <bits/stdc++.h> 

using namespace std; 
int main(){
    long long n,k;
    cin>>n;
    cin>>k;
 long long  a[n];
 for(long long i=0;i<n;i++)
    cin>>a[i];
int i=0,j=0;
multiset<long long> ms;
ms.insert(a[0]);
long long ans=0;
 while(i<n)
 {
    long long currmax=*ms.rbegin();
    long long currmin=*ms.begin();
    while(currmax-currmin<=k&&j<n)
        {j++; ms.insert(a[j]);
         currmax=*ms.rbegin();
         currmin=*ms.begin();
        }
    ans+=(j-i);
    ms.erase(ms.find(a[i]));
    i++;
 }
cout<<ans<<"\n";

}

