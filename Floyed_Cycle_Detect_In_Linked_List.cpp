#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;

};
void Insert(node*& head, int x)
{
    node* temp = new node();
    temp->data = x;
    temp->next = head;
    head = temp;
}
void print()
{
    node* temp = new node();


    while(temp!= NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<< endl;
}
bool floyedDetectCycle(node* head)
{
    node* Hare = head;
    node* Tortoise = head;

    while(Hare && Hare->next)
    {
        //cout<<"Check"<< endl;
        Tortoise = Tortoise->next;
        Hare=Hare->next->next;
        if(Hare == Tortoise)
            return true;
    }
    return false;
}
int main()
{
   vector <int> v;
   int n;
   node* head = NULL;
   cout<<"Enter how many elements"<< endl;
   cin >> n;
   cout<<"Enter Elements"<< endl;

   for(int i = 0; i < n; i++)
   {
       int x;
       cin >> x;
       v.push_back(x);
   }
   reverse(v.begin(),v.end());

   for(int i = 0; i < v.size(); i++)
   {
       Insert(head,v[i]);
   }
   head->next->next->next->next = head->next->next;

   if(floyedDetectCycle(head))
    cout<<"Cycle"<< endl;
   else
    cout<<"No"<< endl;
  // print();

}
