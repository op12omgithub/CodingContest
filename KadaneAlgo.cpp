#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> kadane(int* a, int n)
{
  int sum=0;
  vector<vector<int>>result;
  vector<int>elements;
  for(int i=0;i<n;i++){
      sum+=a[i];
      if(sum>=0){
          elements.push_back(a[i]);
          result.push_back(elements);
      }
      else{
          sum=a[i];
          elements.clear();
          elements.push_back(a[i]);
          result.push_back(elements);
      }
  }
  return result;
}

int main()
{
    int a[]={-4,-10,-1,0,1};
    int sum =0;
    int size =  sizeof(a)/sizeof(a[0]);
    vector<vector<int>>res;
    vector<int> sumRes;
    res = kadane(a,size);
    int resSize = res.size();
    for(int k=0;k<resSize;k++){
        sum=0;
    for(auto it:res[k]){
        //cout<<it<<" ";
        sum+=it;
    }
    sumRes.push_back(sum);
    }
     cout << *max_element(sumRes.begin(), sumRes.end())<<endl;
    //cout<<"Print result"<<endl;
    return 0;
}
