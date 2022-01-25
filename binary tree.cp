/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
    int data;
    node *left=nullptr;
    node*right=nullptr;
    
    node*create()
    {
        node*temp=new node();
        int num;
        cout<<"enter the data"<<endl;
        cin>>num;
        if(num==-1)
        {
            return nullptr ;
        }
        temp->data=num;
        cout<<"For left child"<<endl;
        temp->left=create();
        cout<<"for the right child"<<endl;
        temp->right=create();
        return temp;
        
    }
//----------------------------------------------------//
    /// recursive order
    void preorder(node*root)
    {
        if(root==nullptr)
        {
            return;
        }
        cout<<root->data<<",";
        preorder(root->left);
        preorder(root->right);
    }
    void inorder(node*root)
    {
        if(root==nullptr)
        {
            return;
        }
        inorder(root->left);
        cout<<root->data<<",";
        inorder(root->right);
    }
    void postorder(node*root)
    {
        if(root==nullptr)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<",";
    }
//--------------------------------------------------------------------------//
    void levelorder(node*root)//iterative level order
    {
       queue<node*>que;
       que.push(root);
       while(que.size()>0)
       {
           node*p=que.front();
           que.pop();
           cout<<p->data;
           if(p->left)
           {
               que.push(p->left);
           }
           if(p->right)
           {
               que.push(p->right);
           }
       }
    }
    void iterativepreorder(node*root)//iterative preorder
    {
        stack<node*>st;
        st.push(root);
        while(st.size()>0)
        {
            node*p=st.top();
            st.pop();
            cout<<p->data<<",";
            if(p->right)
            {
                st.push(p->right);
            }
            if(p->left)
            {
                st.push(p->left);
            }
        }
    }
    void iterativeinorder(node*root)//iterative inorder
    {
        stack<node*>st;
        st.push(root);
        
            while(st.size()>0)
            {
                node*p=st.top();
                if(p)
                {
                    st.push(p->left);
                }
                else
                {
                    if(st.size()==0)
                    {
                        break;
                    }
                    node*z=st.top();
                    st.pop();
                    cout<<z->data<<",";
                    st.push(z->right);
                }
            }
    }
    void iterativepostorderwith2stack(node*root)//postorder with 2 stack
    {
        stack<node*>s1;
        stack<node*>s2;
        s1.push(root);
        while(s1.size()>0)
        {
            node*p1=s1.top();
            s1.pop();
            s2.push(p1);
            node*p2=s2.top();
            if(p2->left)
            {
                s1.push(p2->left);
            }
            if(p2->right)
            {
                s1.push(p2->right);
            }
        }
        while(s2.size()>0)
        {
            node*z=s2.top();
            s2.pop();
            cout<<z->data<<",";
            
        }
    }
    int maximumdepth(node*root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int l=maximumdepth(root->left);
        int r=maximumdepth(root->right);
        return 1+max(l,r);
    }
    bool balanced_binary_tree(node*root)
    {
        if(root==nullptr)
        {
            return true;
        }
        int l=maximumdepth(root->left);
        int r=maximumdepth(root->right);
        if(abs(l-r)>1)
        {
            return false;
        }
        bool left=balanced_binary_tree(root->left);
        bool right=balanced_binary_tree(root->right);
        if(left==false || right==false)
        {
            return false;
        }
        return true;
    }
    int maxi=-1;
    int diameter(node*root)// complexity-O(n^2)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int l=maximumdepth(root->left);
        int r=maximumdepth(root->right);
        return maxi=max(maxi,l+r);
        
        int left=diameter(root->left);
        int right=diameter(root->right);
        return max(max(maxi,left),right);
        
        
    }
    int diameter2(node*root)//complexity-O(n)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int l=diameter2(root->left);
        int r=diameter2(root->right);
        maxi=max(maxi,l+r);
        return 1+max(l,r);
    }
    int maxpathsum(node*root, int &maxi)// maximum path sum
    {
        if(root==nullptr)
        {
            return 0;
        }
        int leftsum=maxpathsum(root->left,maxi);
        int rightsum=maxpathsum(root->right,maxi);
         maxi=max(maxi,root->data+(leftsum+rightsum));
         return root->data+max(leftsum,rightsum);
    }
    bool checkidentical(node*root1,node*root2)
    {
        if(root1==nullptr || root2==nullptr)
        {
            return false;
        }
        if(root1==nullptr and root2==nullptr)
        {
            return true;
        }
        if(root1->data!=root2->data)
        {
            return false;
        }
        bool leftcheck=checkidentical(root1->left,root2->left);
        bool rightcheck=checkidentical(root1->right,root2->right);
        if(leftcheck==false or rightcheck==false)
        {
            return false;
        }
        return true;
        
        
    }
    void zigzagtraversal(node*root)///zigzag traversal using 2 stack
    {
        stack<node*>s1,s2;
        s1.push(root);
        bool f1=0;
        while(true)
        {
            if(f1==0)
            {
             if(s1.size()>0)
            {
                while(s1.size()>0)
                {
                    node*p=s1.top();
                    s1.pop();
                    cout<<p->data<<",";
                    if(p->left)
                    {
                        s2.push(p->left);
                    }
                    if(p->right)
                    {
                        s2.push(p->right);
                    }
                }
                f1=1;
            }
            }
            else
            {
                if(s2.size()>0)
                {
                    while(s2.size()>0)
                    {
                        node*p=s2.top();
                        s2.pop();
                        cout<<p->data<<",";
                        if(p->right)
                        {
                            s1.push(p->right);
                        }
                        if(p->left)
                        {
                            s1.push(p->left);
                        }
                    }
                    f1=0;
                }
            }
            if(s1.size()==0 and s2.size()==0)
            {
                break;
            }
            
        }    
        
    }
    void left_view(node*root,int i, int&j)//left view of a binary tree
        {
            
            if(root==nullptr)
            {
                return;
            }
            if(i>j)
            {
                cout<<root->data<<",";
            }
            j=i;
            
            left_view(root->left,i+1,j);
            left_view(root->right,i+1,j);
            
            
        }
        void right_view(node*root,int i, int&j)// right view of a binary tree
        {
            
            if(root==nullptr)
            {
                return;
            }
            if(i>j)
            {
                cout<<root->data<<",";
            }
            j=i;
            
            right_view(root->right,i+1,j);
            right_view(root->left,i+1,j);
            
            
        }
};

int main()
{
    node m;
    node*root;
    root=0;
    root=m.create();
    m.preorder(root);
    m.inorder(root);
    m.postorder(root);
    m.levelorder(root);
    m.iterativepreorder(root);
    m.iterativeinorder(root);
    m.iterativepostorderwith2stack(root);
    cout<<m.maximumdepth(root);
    cout<<m.balanced_binary_tree(root);
    cout<<m.diameter(root);
    cout<<m.diameter2(root);
    int maxi=-1;
    int z=m.maxpathsum(root,maxi);
    cout<<maxi;
    node*root1,*root2;
    root1=root2=0;
    root1=m.create();
    root2=m.create();
    cout<<m.checkidentical(root1,root2);
    m.zigzagtraversal(root);
    if(root)
    {
        cout<<root->data<<",";
    }
    if(root->left)
    {
        int j=-1;
      m.left_view(root->left,0,j);
    }
   
    if(root->right)
    {
        int j=-1;
       m.right_view(root->right,0,j);
    }
    return 0;
}
