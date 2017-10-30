/*
Linked List Class
Author: Hetansh Madhani
*/


#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


	
class LinkedList{
private:
	struct Node{
		int val;
		Node* prev;
		Node* next;
	};
	Node* node = NULL;
	Node* first = NULL;				//head pointer
	Node* last = NULL;				//tail pointer
	Node* node1 = NULL;
	Node* node2 = NULL;
	void clear() {
		Node* q;
		for (Node* p = first; p != NULL; p = q) {
			q = p->next;  // NOTE: Never look at memory after deleting
			delete p;
		}
	}
public:
	LinkedList() : first(NULL){}
	~LinkedList(){
		clear();
	}
	void insertStart(int v){
		Node* temp = new Node();
		if(first == NULL)
		{
			temp->next=NULL;
			temp->prev=NULL;
			temp->val = v;
			first = temp;
			last = temp;
		}
		else
		{
			temp->prev = NULL;
			temp->next = first;
			temp->val = v;
			first->prev = temp;
			first = temp;
		}
	}

	void insertEnd(int v){
		Node* temp = new Node();
		if (first == NULL)
		{
			temp->prev = NULL;
			temp->next = NULL;
			temp-> val = v;
			first = temp;
			last = temp;
		}
		else
		{
			temp->next=NULL;
			last->next=temp;
			temp->prev=last;
			temp->val = v;
			last= temp;
		}
	}

	void deleteStart(){
		Node* temp = new Node();
		if (first == NULL)
		{
			return;
		}
		else{
			temp = first;
			first = first->next;
			first->prev = NULL;
			delete temp;
		}
	}
	void deleteEnd(){
		if (first == NULL)
		{
			return;
		}
		Node* temp = new Node();
		temp = first;
		while(temp->next->next!=NULL)
			temp = temp->next;
		last = temp;
		delete temp->next;
		temp->next = NULL;
		return;
	}

	void display(){
		node = first;
		while(node!= NULL){
			cout<< node->val << ' ';
			node = node->next;
		}
		cout << endl;
	}

	void displayReverse(){
		node = last;
		while(node!=NULL){
			cout<<node->val << ' ';
			node = node->prev;
		}
		cout<< endl;
	}

};

int main(){
	LinkedList a;
	int i,j,k;
	char x[13];
	char b;
	std::ifstream reader;
    reader.open("HW4b.txt",ios::in);
    while(!reader.eof()){
        reader >> x;
        if(strcmp(x,"ADD_FRONT")==0){
            reader>> i>> b>> j>> b>> k;
            for(;i<=k;i+=j)
                a.insertStart(i);
           // cout<<i<<'\t';

        }
        else if(strcmp(x,"ADD_BACK")==0){
            reader >> i>> b>> j>> b>> k;
            for(;i<=k;i+=j)
                a.insertEnd(i);
        }
        else if(strcmp(x,"REMOVE_FRONT")==0){
            reader>> i;
            while(i>0){
                a.deleteStart();
                --i;
            }
        }
        else if(strcmp(x,"REMOVE_BACK")==0){
            reader>> i;
            while(i>0){
                a.deleteEnd();
                --i;
            }
        }
        else if(strcmp(x,"OUTPUT")==0){
            cout<<"The Doubly Linked List is:\n";
            a.display();
        }
    }
    reader.close();
    cout<<" \n ";
	return 0;
}