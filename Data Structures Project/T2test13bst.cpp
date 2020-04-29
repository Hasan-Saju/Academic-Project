#include"MHSbst.h"
using namespace std;

int main()
{
    //fast
    node* root=NULL;
    node* ans;

    int n,x;
    cout<<"How many nodes you want to insert: ";
    cin>>n;
    cout<<"Input the nodes: "<<endl;
    while(n--)
    {
     cin>>x;
         root = BSTinsert(root,x);
     cout<<x<<" is inserted"<<endl;

    }


  //  int x;
    cout<<endl<<"Let's check search function"<<endl<<"Enter the number you want to search: ";
    cin>>x;
    if(BSTfind(root,x))cout<<"Yes, "<<x<<" exists in the BST"<<endl;
    else cout<<x<<" doesn't exist in the BST"<<endl;

    cout<<endl<<"Let's check the findMin function"<<endl;
    cout<<"The Minimum number is: "<<BSTfindMin(root)<<endl;

     cout<<endl<<"Let's check the findMax function"<<endl;
      cout<<"The Maximum number is: "<<BSTfindMax(root)<<endl;
   // cout<<"checkingMax: "<<BSTfindMax(root)<<endl;

   cout<<endl<<"Let's check delete function."<<endl;
   cout<<"Give the number you want to delete: ";cin>>x;
    BSTdelete(root,x);
    cout<<x<<" is deletd."<<endl;

    cout<<endl<<"Let's visit the tree with BFS: ";
     //cout<<"BFS"<<endl;
     BSTbfs(root);

     cout<<endl<<endl<<"Let's check DFS: "<<endl;
     BSTdfs(root);

     cout<<endl<<endl<<"Let's find Next Larger."<<endl;
     cout<<"Give your input: ";
     cin>>x;
    // cout<<"next Larger of 11 ";
     ans=BSTnextLarger(root,x);
     cout<<endl<<"Here's your nextLarger: "<<ans->data<<endl<<endl;



    cout<<"You want to test again? Let's go."<<endl;
    cout<<"Give another input: ";
     //cout<<"nextLa15 :";
     cin>>x;
     ans=BSTnextLarger(root,x);
    cout<<ans->data<<" is the next larger of "<<x<<endl;

    cout<<endl<<"Let's check rank.";
    cout<<endl<<"Give your desired number: ";
    cin>>x;
    cout<<"Rank of "<<x<<" is: ";
    BSTrank(root,x);

    cout<<endl<<"We successfully checked all the function :)"<<endl;
}
