#include <bits/stdc++.h>
#include <sys/time.h>
double mysecond()
{
    struct timeval tp;
    struct timezone tzp;
    int i;

    i = gettimeofday(&tp,&tzp);
    return ( (double) tp.tv_sec + (double) tp.tv_usec * 1.e-6);
}
int main()
{
   double start_, end_;
   start_ = mysecond();
   //fun()
   end_ = mysecond();
   cout<<"Final Time = " << end_ - start << endl;

}
