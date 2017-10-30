/*Trie Dictioonary*/


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class trie{
private:
    class node{
    public:
        char x;
        bool word;
        node* alpha[26];
        node(){
            x = 0;
            for (int i = 0; i < 26; i++)
                alpha[i] = NULL;
            word = false;
        }

        void addchar(char c, node* a, int i){
            int pos = c - i;
            if (a->alpha[pos] != NULL)
                return;
            node* temp = new node();
            temp->x = c;
            a->alpha[pos] = temp;
        }
    };
    node* head;
public:
    trie(){
        head = new node();
    }

    void addWord(const string& x){
        node* cur;
        int t;
        cur = head;
        for (int i = 0; i < x.size(); i++){
            if (x[i] >= 65 && x[i] <= 90)
                t = 65;
            else if (x[i] >= 97 && x[i] <= 122)
                t = 97;
            cur->addchar(x[i], cur, t);
            cur = cur->alpha[x[i] - t];
        }
        cur->word = true;
    }

    bool find(const string& x){
        node* cur;
        int t;
        cur = head;
        for (int i = 0; i < x.size(); i++){
            if (x[i] >= 65 && x[i] <= 90)
                t = 65;
            else if (x[i] >= 97 && x[i] <= 122)
                t = 97;
            if (cur->alpha[x[i] - t] == NULL)
                return false;
            cur = cur->alpha[x[i] - t];
        }
        if (cur->word)
            return true;
        else
            return false;
    }

};

int main()
{
    trie ab;
    string s;
    char k[15];
    std::ifstream reader;
    reader.open("dict.txt", ios::in);
    if (!reader.is_open()){
        reader.close();
        cout<<"Failed to open"<<endl;
    }
    while (getline(reader, s)) {
        ab.addWord(s);
    }
    reader.close();

    reader.open("test.txt", ios::in);
    if (!reader.is_open()){
        reader.close();
        cout<< "test file failed to open" << endl;
    }

    while (getline(reader, s)) {
        if (ab.find(s))
        {
            cout<<s<<"\ntrue\n";
        }
        else {
            cout<<s<<"\nfalse\n";
        }
    }
    reader.close();
    return 0;
}
