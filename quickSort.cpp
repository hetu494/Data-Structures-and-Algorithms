/*
Data Structures and Algorithms
Quicksort
Author: Hetansh Madhani
*/


#include <iostream>
#include <string>
using namespace std;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int x[], int left, int right) {
   if(right-left < 2)
        return;
    //int pivot = x[3];
    int i = left;
    int j = right;
    int pivot = x[(left + right)/2];


    while (i <= j){
        while(x[i]< pivot)
            i++;
        while(x[j] > pivot)
            j--;
        if(i<=j){
            swap(&x[i], &x[j]);
            i++;
            j--;

        }
    };
    if (left< j)
    {
        quickSort(x,left,j);/* code */
    }
    if(i < right){
        quickSort(x,i,right);  
    }
    
    return;

 }

 void print(int x[], int n) {
    for (int i = 0; i < n; ++i)
        cout << x[i] << ' ';
    cout << '\n';
 }

 int main() {
    
    int x1[] = {1,2,3,4,5,6,7,8,9,10};
    int n1 = sizeof(x1)/sizeof(x1[0]); 
    //cout << sizeof(x)/sizeof(x[0]);
    cout<< endl;
    print(x1, n1);
    quickSort(x1, 0, n1-1);
    print(x1, n1);
    cout<< endl;
    

    int x2[] = {10,9,8,7,6,5,4,3,2,1};
    int n2 = sizeof(x2)/sizeof(x2[0]); 
    //cout << sizeof(x)/sizeof(x[0]);
    cout<< endl;
    print(x2, n2);
    quickSort(x2, 0, n2-1);
    print(x2, n2);
    cout << endl;
    
    int x3[] = {62,50,50,50,62};
    int n3 = sizeof(x3)/sizeof(x3[0]); 
    //cout << sizeof(x)/sizeof(x[0]);
    cout<< endl;
    print(x3, n3);
    quickSort(x3, 0, n3-1);
    print(x3, n3);
 }