#include "mainwindow.h"
#include<iostream>

using namespace std;
int mod(long long int num, long long int a)
{
    // Initialize result
    long long int res = 0;
     string str = to_string(num);
    // One by one process all digits of 'num'
    for (long long int i = 0; i < str.length(); i++)
        res = (res * 10 + (long long int)str[i] - '0') % a;

    return res;
}
void array_queries(long long int *a,long long int *b,long long int n,long long int m,
                   long long int **qin,long long int indx)
{
    long long int i,j,k,sum=0,sum1=0,sum2=0,sum3=0,x,y,tmp,max,min;
    string str;
    int len;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            sum += a[i]*b[j]*(i+1+j+1);
            str =to_string(sum);
            len = str.length();
            if(len>10 && len<=17)
                sum = sum%998244353;
            else if(len>17)
            sum = mod(sum,998244353);
        }
    }
    cout<<sum<<" ";

    for(i=0;i<indx;i++)
    {
        if(qin[i][0]==1)
        {
            x = qin[i][1];
            y = qin[i][2];
            swap(a[x-1],b[y-1]);

            for(k=0;k<n;k++)
            {
                for(j=0;j<m;j++)
                {
                    sum1 += a[k]*b[j]*(k+1+j+1);
                    str =to_string(sum1);
                    len = str.length();
                    if(len>10 && len<=17)
                        sum1 = sum1%998244353;
                    else if(len>17)
                    sum1 = mod(sum1,998244353);
                }
            }
            cout<<sum1<<" ";
        }
        if(n>m)
        {
        if(qin[i][0]==2)
        {
            x = qin[i][1];
            y = qin[i][2];
            swap(a[x-1],a[y-1]);

            for(k=0;k<n;k++)
            {
                for(j=0;j<n;j++)
                {
                    if(j<m)
                    sum2 += a[k]*b[j]*(k+1+j+1);
                    str =to_string(sum2);
                    len = str.length();
                    if(len>10 && len<=17)
                        sum2 = sum2%998244353;
                    else if(len>17)
                    sum2 = mod(sum2,998244353);
                }
            }
            cout<<sum2<<" ";
        }
        if(qin[i][0]==3)
        {
            x = qin[i][1];
            y = qin[i][2];
            swap(b[x-1],b[y-1]);

            for(k=0;k<n;k++)
            {
                for(j=0;j<n;j++)
                {
                    if(j<m)
                    sum3 += a[k]*b[j]*(k+1+j+1);
                    str =to_string(sum3);
                    len = str.length();
                    if(len>10 && len<=17)
                        sum3 = sum3%998244353;
                    else if(len>17)
                    sum3 = mod(sum3,998244353);
                }
            }
            cout<<sum3<<" ";
        }
        }
        else if(m>n)
        {
            if(qin[i][0]==2)
            {
                x = qin[i][1];
                y = qin[i][2];
                swap(a[x-1],a[y-1]);

                for(k=0;k<m;k++)
                {
                    if(k<n)
                    for(j=0;j<m;j++)
                    {

                        sum2 += a[k]*b[j]*(k+1+j+1);
                        str =to_string(sum2);
                        len = str.length();
                        if(len>10 && len<=17)
                            sum2 = sum2%998244353;
                        else if(len>17)
                        sum2 = mod(sum2,998244353);
                    }
                }
                cout<<sum2<<" ";
            }
            if(qin[i][0]==3)
            {
                x = qin[i][1];
                y = qin[i][2];
                swap(b[x-1],b[y-1]);

                for(k=0;k<m;k++)
                {
                     if(k<n)
                    for(j=0;j<m;j++)
                    {

                        sum3 += a[k]*b[j]*(k+1+j+1);
                        str =to_string(sum3);
                        len = str.length();
                        if(len>10 && len<=17)
                            sum3 = sum3%998244353;
                        else if(len>17)
                        sum3 = mod(sum3,998244353);                    }
                }
                cout<<sum3<<" ";
            }

        }



    }
    //cout<<"end function"<<endl;
}

int main(int argc, char *argv[])
{

    //cout<<"welcome c++"<<endl;
    int t,r;
    long long int N,M,Q,indx,x,y,i,j;
    long long int *a,*b;
    cin>>t;
    for(r=0;r<t;r++)
    {
        cin>>N;
        cin>>M;
        a=(long long int*)malloc(sizeof(long long int)*N);
        b=(long long int*)malloc(sizeof(long long int)*M);
        for(i=0;i<N;i++)
        {
            cin>>a[i];
        }

        for(i=0;i<M;i++)
        {
            cin>>b[i];
        }

        //cout<<"input index "<<endl;
        cin>>indx;
        //cout<<"index is "<<indx<<endl;
        long long int **qin = new long long int*[indx];

        for(i=0;i<indx;i++)
        {
            qin[i]=new long long int[3];
            for(j=0;j<3;j++)
            {
                cin>>qin[i][j];
            }
        }
        //cout<<"loop is working "<<endl;

        array_queries(a,b,N,M,qin,indx);
        cout<<endl;
        //cout<<"index is "<<indx<<endl;

        free(a);
        free(b);
        for(i=0;i<indx;i++)
        {
            delete qin[i];
        }
        delete qin;
        qin=NULL;
    }
    return 0;
}
