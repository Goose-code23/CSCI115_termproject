#include<iostream>
#include<math.h>
#include "Sorts.h.h"
#define MAXSIZE 1000000
using namespace std;


Array::Array(){
    a = new int [MAXSIZE];
    for(int i=0;i<MAXSIZE;i++){
        a[i]= rand()%10000000;
    }

}
Array::~Array(){
   delete[] a;
}
void Array::Display(){
   for(int i=0;i<MAXSIZE;i++){
    cout<< a[i]<<" ";
   }
cout<<endl;
}
void Array::BubbleSort(){
    for(int i=0;i<MAXSIZE;i++){
        for(int j=0;j< MAXSIZE-i-1;j++){
            if(a[j+1]< a[j]){
                swapNums(j,j+1);
}
}
}
}

void Array::InsertionSort(){
    for(int i =0;i<MAXSIZE;i++){
        int j=i;
     while(j>0 && a[j]< a[j-1]){
         swapNums(j,j-1);
         j--;
     }
}
}

void Array::SelectionSort(){

for(int i=0;i<MAXSIZE;i++){
        int currpos = i;
    for(int j=i+1;j<MAXSIZE;j++){
        if(a[j]<a[currpos]){
            currpos=j;
}
}
        swapNums(currpos,i);
}
}

void Array::swapNums(int x, int y){
    int temp = a[x];
    a[x]=a[y];
    a[y]=temp;
}



void Array::Merge(int l,int mid,int r){
 int left= l;
    int leftEnd = mid;
    int right= mid+1;
    int rightEnd = r;
    int temp[(r-l)+1];
    int indexTemp =0;
 while((left <= leftEnd) && (right <=rightEnd)){
    if (a[left] < a[right]){
        temp[indexTemp++] = a[left++];
    }
    else{
        temp[indexTemp++] = a[right++];
    }
 }
 while(left<=leftEnd){
    temp[indexTemp++] = a[left++];
 }
 while(right<=rightEnd){
    temp[indexTemp++] = a[right++];
 }

 for(int i=l,j=0;i<=r;i++,j++){
    a[i]= temp[j];

 }
 }

void Array::MergeSort(int l,int r){
if(l<r){
    int mid = (l+r)/2;
    MergeSort(l,mid);
    MergeSort(mid+1,r);
    Merge(l,mid,r);

}
}

void Array::buildMaxHeap(){
        int index = (MAXSIZE/2)-1;
        for(int i=index;i>=0;i--){
            max_heapify(i,MAXSIZE);
}
}
void Array::max_heapify(int i,int n){
   int big= i;
   int leftchild = (2*i)+1;
   int rightchild= (2*i)+2;
   if(leftchild<n && a[leftchild]>a[big]){
    big = leftchild;
   }
   if(rightchild<n && a[rightchild]>a[big]){
    big = rightchild;
   }
   if(big !=i){
    swapNums(i,big);
    max_heapify(big,n);
   }
}
void Array::ascendingHeapSort(){
for(int i=MAXSIZE-1;i>=0;i--){
    swapNums(0,i);
    max_heapify(0,i);
}
}


void Array::CS(int x){
    int big=a[0];
    int counter;
    for(int i =1;i<x;i++){
        if(big<a[i]){
            big=a[i];
    }
    }
    int temp[big+1];
    for(int i =0;i<big+1;i++){
        temp[i]=0;
    }
    for(int i=0;i<x;i++){
            counter =a[i];
        temp[counter]= temp[counter] +1 ;
    }

     for(int i=1;i<big+1;i++){
           temp[i]= temp[i] + temp[i-1];
    }
    static int newA[MAXSIZE];
    int val;
    int tempVal;
    for(int i=x-1;i>=0;i--){
            val= a[i];
            temp[val]= temp[val]-1;
           tempVal= temp[val];
           newA[tempVal]=val;

    }
    for(int i=0;i<MAXSIZE;i++){
          a[i]=newA[i];

    }
}

void Array::RCS(int x, int pos){
   int temp[10];
   for(int i=0;i<10;i++){
    temp[i]=0;
}
    int b[x];
    int counter;
    for(int i=0;i<x;i++){
        counter = (a[i]/((int)(pow(10,pos))))%10;
        temp[counter]= temp[counter] +1;
    }
    for(int i=1;i<10;i++){
        temp[i]= temp[i]+temp[i-1];
    }
    for(int i=x-1;i>=0;i--){
        counter = (a[i]/((int)(pow(10,pos))))%10;
        b[temp[counter]-1]= a[i];
        temp[counter]= temp[counter]-1;

    }
    for(int i=0;i<x;i++){
        a[i]= b[i];
    }
}



void  Array::RS(int x){
    int big;
    for(int i =1;i<x;i++){
        if(big<a[i]){
            big=a[i];
    }
    }
    int d=0;
    while(big>0){
        d++;
        big=big/10;
    }

    for(int i=0;i<=d;i++){
        RCS(x,i);
    }
}
