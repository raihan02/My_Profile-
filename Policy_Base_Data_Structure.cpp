/**

   Topics Name: Policy base data structure
   Name: Mohd. Raihan Uddin
   iOS Developer in twinbit limited
**/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;


void printList(ordered_set x)
{
    for (auto it =  x.begin(); it != x.end(); it++)
    {
        cout<<*it << " ";
    }

    cout<< endl;
}
int main()
{
    ordered_set x;
    /// 1. Insert a number in the list
    x.insert(10);
    x.insert(20);
    x.insert(30);
    x.insert(30);
    x.insert(40);
    x.insert(50);
    x.insert(60);
    printf("1 -----------\n");
    printList(x);
    /// 2. Delete a given number from the list
    x.erase(30);
    printf("2 -----------\n");
    printList(x);
    /// 3. check the list is empty
    printf("3 -----------\n");

    if(x.empty())
    {

        printf("List is empty\n");
    }

    else
    {
        printf("Not Empty\n");
    }
    /// 4. clear the list
    // x.clear();

    /// 5. Distinct number in the list
    printf("4 -----------\n");
    printf("List size is %d\n", x.size());
    /// 6. Smallest element in the list
    printf("5 -----------\n");
    printf("Smallest element : %d\n", *x.begin());
    /// 7. Greatest number of the list
    printf("6 -----------\n");
    printf("Greatest element : %d\n", *x.rbegin());
    /// 8. find a number if it is in the list or not
    printf("7 -----------\n");
    printList(x);
    if(x.find(10) == x.end())
    {
        printf("Value is not found\n");
    }
    else
    {
        printf("Value is found\n");
    }
    /// 9. How many numbers are smaller than given value
    printf("9 -----------\n");
    printf("Smaller than 40? : %d\n",x.order_of_key(40));
    /// 10. How many numbers are smaller or equal to a given value
    printf("10 -----------\n");
    if(x.find(40) != x.end())
    {
        int cnt = x.order_of_key(40);
        cnt++;
        printf("Smaller or equal than 40 ? :  %d\n", cnt);

    }
    else
    {
        printf("Value not found\n");
    }

    /// 11. How many numbers are greater than given value
    printf("11 -----------\n");
    printf("Greater than 40? : %d\n",x.size() - x.order_of_key(40) - 1);
    /// 12. How many numbers are greater than or equal to a given value
    printf("12 -----------\n");
    if(x.find(40) != x.end())
    {
        int cnt = x.size() - x.order_of_key(40);
        printf("greater or equal than 40 ? :  %d\n", cnt);
    }
    else
    {
        printf("Value not found\n");
    }

    /// 13.If the list is sorted in ascending order , what is the k'th number ?
    printf("13 -----------\n");
    printf("Find by order of 2 ascending: %d\n", *x.find_by_order(2));
    /// 14. If the number is sorted in descending order, what is the k'th number ?
    printf("14 -----------\n");
    printf("Find by order of 3 descending: %d\n", *x.find_by_order(x.size() - 1 - 3));
    /// 15. Delete the k'th smallest number.
    printf("15 -----------\n");
    x.erase(x.find_by_order(2));
    printList(x);

    /// 16. Delete the k'th greatest number.
    printf("16 -----------\n");
    x.erase(x.find_by_order(x.size() - 1 - 2));
    printList(x);

    /// 17. Delete the smallest number from the list
    printf("17 -----------\n");
    x.erase(x.begin());
    printList(x);

    /// 18. Delete the greatest number from the list
    printf("18 -----------\n");
    x.erase(x.rbegin());
    printList(x);
    /// 19. Print all the number in ascending order
    printf("19 -----------\n");
    x.insert(10);
    x.insert(20);
    x.insert(30);
    x.insert(30);
    x.insert(40);
    x.insert(50);
    x.insert(60);
    printList(x);

    /// 20. Print all the number in descending order
     printf("20 -----------\n");
     auto p = x.rend();
    for(auto it = x.rbegin(); it != p; it++){
        cout << *it <<" ";
    }
    cout<< endl;

    /// 21. What is the smallest number which is greater or equal to a given number
     printf("21 -----------\n");
     printf("%d\n", *x.lower_bound(40));
    /// 22. What is smallest number which is greater than a given value
    printf("22 -----------\n");
     printf("%d\n", *x.upper_bound(40));


}
