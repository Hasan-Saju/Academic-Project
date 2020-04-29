#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vi vector<int>
#define si set<int>
#define FOR(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

struct node
{
    int data;
    node* left;
    node* right;
};

node* CreateNewNode(int data);
node* BSTinsert(node* root,int data);
bool BSTfind(node* root,int data);
int BSTfindMin(node* root);
int BSTfindMax(node* root);
node* BSTnextLarger(node* root,int value);
node* BSTdelete(node* root,int data);
void BSTbfs(node* root);
void BSTdfs(node* root);
node* findMin(node* root);//for personal use
node* Find(node* root ,int data);//Personal use
void BSTrank(node* root,int value);
//rank



node* CreateNewNode(int data)//tested
{

    node* newNode= new node;
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

node* BSTinsert(node* root,int data)//tested
{

    if(root==NULL)
    {
        root=CreateNewNode(data);
    }
    else if(data<=root->data)
    {
        root->left=BSTinsert(root->left,data);
    }
    else
        {
            root->right=BSTinsert(root->right,data);
        }
    return root;
}

bool BSTfind(node* root,int data)//tested
{
    if(root==NULL)return false;
    else if(root->data==data)return true;
    else if(data<=root->data) return BSTfind(root->left,data);
    else return BSTfind(root->right,data);
}

//int BSTfindMin(node* root) //using while
//{
//    if(root==NULL)
//    {
//        cout<<"Tree is empty";
//        return -1;
//    }
//    node* current=root;
//    while(current->left!=NULL)//jotokkhon bame jawa jay jabo
//    {
//        current=current->left;
//    }
//    return current->data;
//}

int BSTfindMin(node* root)//recursion //tested
{
    if(root==NULL)
    {
        cout<<"Tree is empty";
        return -1;
    }
   else if(root->left==NULL)
   {
     return root->data;
   }
    return BSTfindMin(root->left);
}

int BSTfindMax(node* root)//tested
{
    if(root==NULL)
    {
        cout<<"Tree is empty";
        return -1;
    }
    node *current=root;// na likhleo hoy cz ei root o temporary eikhane, scope eikhanei shesh
    while(current->right!=NULL)
    {
        current=current->right;
    }
    return current->data;
}

node* BSTdelete(node* root,int data)//tested
{
    if(root==NULL)return root;
    else if(data<root->data)root->left=BSTdelete(root->left,data);// value aro bame
    else if(data>root->data)root->right=BSTdelete(root->right,data);//value khujtesi
    else//tar mane ==, value peye gesi
    {   //leaf means No child
        if(root->left==NULL&&root->right==NULL)
        {
            delete root;
            root=NULL;
            return root;// kono ekta value root->left or root->right a NULL return korbe mane value ta delete
        }
        else if(root->left==NULL)
        {
            node* temp=root;//jake delete korbo take arek jaygay rakhlam
            root=root->right;//ami last a gelam root diye
            delete temp;// delete korlam
            return root;//uporer recursion a value return korlam
        }
        else if(root->right==NULL)
        {
            node* temp=root;//jake delete korbo take arek jaygay rakhlam
            root=root->left;//ami last a gelam root diye
            delete temp;// delete korlam
            return root;//uporer recursion a value return korlam
        }
        else
        {
            int nextLarger=BSTfindMin(root->right);//next larger ber korlam
            root->data=nextLarger;//jake delete korte bolse take next larger diye replace
            root->right=BSTdelete(root->right,nextLarger);//khuje next larger ke delete kore dibo
            return root;
        }

    }
    //return root; //eikhane dile ar upore etobar dewa lagbe na
}

node* BSTnextLarger(node* root,int value)
{
    node* current=Find(root,value);
    if(current==NULL)
    {
        cout<<"Tree is empty";
        return NULL;
    }
    else if(current->right!=NULL)//mane dane a child ase
    {
        return findMin(current->right);//mane daner shob cheye choto ta return korbe
    }
    else
        {
            //jodi right child na thake
            ////always node ta jar*** left subtree te shei node hocche ans
            node* successor=NULL;
            node* ancestor=root;
            while(ancestor!=current)
            {
                if(current->data<ancestor->data)
                {
                    successor=ancestor;//successor is updating my answer//jokhon e bame jaitesi tar address save kore rakhtesi karon last left hand wala node e answer
                    ancestor=ancestor->left;
                }
                else if(current->data>ancestor->data)
                {
                    ancestor=ancestor->right;
                }
            }
            return successor;


        }
}

void BSTbfs(node* root)//tested
{
    if(root==NULL)return;
    queue<node*>Q;
    Q.push(root);
    while(!Q.empty())
    {
        node* current=Q.front();
        cout<<current->data<<" ";
        if(current->left!=NULL)Q.push(current->left);
        if(current->right!=NULL)Q.push(current->right);
        Q.pop();
    }
}

void BSTdfs(node* root)//preorder //data - left -right//tested
{
    if(root==NULL)return;
    cout<<root->data<<" ";
    BSTdfs(root->left);
    BSTdfs(root->right);
}

node* findMin(node* root)//personal use , writing new is better than modifying
{//tested
    if(root==NULL)return NULL;
    while(root->left!=NULL)
    {
        root=root->left;
    }
   // cout<<"findMin check";
    return root;
}

node* Find(node* root ,int data)//personal use// better than modifying
{//tested
    if (root==NULL)return NULL;
    else if(root->data==data)return root;
    else if(data<root->data) return Find(root->left,data);
     else return Find(root->right,data);
}

void BSTrank(node* root,int value)
{
    int static kount=0; //bar bar jate kount 0 na hoy
    if(root==NULL)return;
    //modified dfs chalabo
    //i mean inorder chalabo
    BSTrank(root->left,value);
    if(root->data<value)
    {
        kount++;//guntesi koyta choto
        //cout<<root->data<<" ";
    }
    else if(root->data==value)
        cout<<kount+1;// nije shoho
        else;
    BSTrank(root->right,value);
}

//if(root==NULL)return;
//    cout<<root->data<<" ";
//    BSTdfs(root->left);
//    BSTdfs(root->right);

