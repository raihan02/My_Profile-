#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *next[10];
    bool endmark;
    node()
    {
        for(int i = 0; i < 10; i++) next[i] = NULL;
        endmark = false;
    }
};
void Build_Trie (char *str , int len , node *curr)
{
    for(int i = 0; i < len; i++)
    {
        int id = str[i] - '0';
        if(curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}
bool searc (char *str , int len , node *curr)
{
    for(int i = 0; i < len; i++)
    {
        int id = str[i] - '0';
        if(curr->next[id] == NULL) return false;
        curr = curr-> next[id];
    }
    return curr->endmark;
}
void del(node *cur) {
    for(int i=0;i<10;i++)
        if(cur->next[i])
            del(cur->next[i]);
    delete(cur);
}
int main()
{
   char s[10001][13];
   node *root = new node();
    for(int i = 0; i < 5; i++)
    {
        scanf(" %s" , s[i]);
        Build_Trie(s[i] , strlen(s[i]) , root);

    }
    int q;
    cin >> q;
    char s1[100];
    for(int i =0 ; i < q; i++)
    {
        scanf(" %s", s1);
        bool k = searc(s1 , strlen(s1) , root);
        cout<< k << endl;
    }
    del(root);
}
