//#include <QCoreApplication>
#include<iostream>
#define ll unsigned long long int

using namespace std;
int BubbleSort(int *a)
{
    int count=0,n=0,i=0;
    n=sizeof(a);
    bool swapped=true;
    while(swapped !=false)
    {
        swapped=false;
        count = count +1;
        for(i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1])
            {
                swap(a[i],a[i+1]);
                swapped=true;
            }
        }
    }
    return count;
}

int main()
{
    int N,res;
    cin>>N;
    if(N<1 && N>5000)
        return -1;
    int a[N],i=0;
    for(i=0;i<N;i++)
    {
        cin>>a[i];
    }

    res = BubbleSort(a);
  cout<<res<<endl;
    return 0;;
}
