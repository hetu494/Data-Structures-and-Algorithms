#include <iostream>
#include <string>
using namespace std;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int x[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int min = i;
        for (int j = i+1; j< n; j++)
        {
            if (x[j]<x[min])
            {
                min = j;
            }
            swap(x[i],x[min])
        }
    }
    return;

}

 void print(int x[], int n) {
    for (int i = 0; i < n; ++i)
        cout << x[i] << ' ';
    cout << '\n';
 }

 int main() {
    

    

    int x2[] = {10,9,8,7,6,5,4,3,2,1};
    int n2 = sizeof(x2)/sizeof(x2[0]); 
    //cout << sizeof(x)/sizeof(x[0]);
    cout<< endl;
    print(x2, n2);
    bubbleSort(x2, n2);
    print(x2, n2);
    cout << endl;
    

 }