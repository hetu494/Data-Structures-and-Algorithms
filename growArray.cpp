/*
Grow Array
Author: Hetansh Madhani
*/
#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class growarray{
    int* data;
    int size;
    int used;
public:
    growarray(){ 
        data=new int[1];
        size=0;
        used=0;
    }
    ~growarray(){ 
        delete [] data;
        size = 0;
        used = 0;
    }
    void addStart(int a){
        int i;
        if(size-used<=1){
            int* temp = data;
            if(size=0){
                data=new int[1];
                size=1;
            }
            else{
                data = new int[2*size];
                size*=2;
                for (i=0;i<used;i++)
                    data[i+1]=temp[i];
                delete temp;
            }
            data[0]=a;
            used++;
        }
        else{
            for(i=0;i<used;i++)
                data[i+1]=data[i];
            data[0]=a;
            used++;
        }
    }
    void addEnd(int x){
        int i;
        if(size-used<=1){
            int* temp = data;
            data = new int[2*size];
            for (i=0;i<used;i++)
                data[i]=temp[i];
            delete temp;
        }
        data[i]=x;
        used++;
    }
    void removestart(){
        if(used<0){
            cout<<"\n\nNothing to Remove\n\n";
            return;
        }
        int i=0;
        for(;i<used;i++)
            data[i]=data[i+1];
        --used;
    }
    void removeend(){
        if(used<0){
            cout<<"\n\nNothing to Remove\n\n";
            return;
        }
        --used;
    }
    void display(){
        cout<<'\n';
        for(int i=0;i<used;i++)
            cout<<'\t'<<data[i];
        cout<<"\n\n\n";
        return;
    }
};

int main(){
    growarray a;
    std::ifstream reader;
    int i,j,k;
    char x[13],b;
    reader.open("HW4b.txt",ios::in);
    while(!reader.eof()){
        reader >> x;
        if(strcmp(x,"ADD_FRONT")==0){
            reader>> i>> b>> j>> b>> k;
            for(;i<=k;i+=j)
                a.addStart(i);
            cout<<i<<'\t';

        }
        else if(strcmp(x,"ADD_BACK")==0){
            reader >> i>> b>> j>> b>> k;
            for(;i<=k;i+=j)
                a.addEnd(i);
        }
        else if(strcmp(x,"REMOVE_FRONT")==0){
            reader>> i;
            while(i>0){
                a.removestart();
                --i;
            }
        }
        else if(strcmp(x,"REMOVE_BACK")==0){
            reader>> i;
            while(i>0){
                a.removeend();
                --i;
            }
        }
        else if(strcmp(x,"OUTPUT")==0){
            cout<<"\n\nDisplaying the GrowArray\n\n";
            a.display();
        }
    }
    reader.close();
    cout<<" \n ";

    a.~growarray();
    return 0;
}