//Name: Shantanu Tyagi
//Id: 201801015
//Date:15/4/19
//Program: Binary Tree Implementation

#include<iostream>
#include<queue>
#include<stdlib.h>
#include<cmath>

using namespace std;

template<typename E>
class BinNode
{
public:
    virtual E& getValue() =0;
    virtual void setValue(const E& e)=0;
    virtual bool isLeaf() =0;
    virtual ~BinNode() {}
};

template <typename E>
class BinaryTreeNode : public BinNode<E>
{
    BinaryTreeNode* root;
    int size;
    E value; // The node's value
    BinaryTreeNode* leftChild; // Pointer to left child
    BinaryTreeNode* rightChild; // Pointer to right child

    public:
    // constructors and destructor
    BinaryTreeNode()
    {
        root=leftChild = rightChild = NULL;
        value=0;size=0;
    }
    BinaryTreeNode(E e, BinaryTreeNode* l =NULL, BinaryTreeNode* r =NULL)
    {
        value = e;
        leftChild = l;
        rightChild = r;
    }
    ~BinaryTreeNode() // Destructor
    {
        leftChild=NULL;
        rightChild=NULL;
        delete leftChild;
        delete rightChild;
    }

    int getsize()
    {
        return size;
    }

    // Functions to set and return the value and key
    E& getValue()
    {
         return value;
    }
    void setValue(const E& e)
    {
         value = e;
    }

    // Functions to set and return the children
    inline BinaryTreeNode* left() const
    {
         return leftChild;
    }
    void setLeft(BinaryTreeNode<E>* b)
    {
         leftChild = b;
    }
    inline BinaryTreeNode* right() const
    {
         return rightChild;
    }
    void setRight(BinaryTreeNode<E>* b)
    {
         rightChild = b;
    }

    BinaryTreeNode<E> * getroot()
    {
        return root;
    }

    BinaryTreeNode<E> * getnode(int i)
    {
        if(i==0)
        {
            return root;
        }
        else
        {
            BinaryTreeNode<E>* n=getnode((i-1)/2);
            if(i%2==0)
            {
                return n->right();
            }
            else
            {
                return n->left();
            }
        }
    }

    // Return true if it is a leaf, false otherwise
    bool isLeaf()
    {
          return (leftChild == NULL) && (rightChild == NULL);
    }


    //inserting a node
    void insert(const E& key)
    {

        BinaryTreeNode<E> *temp=new BinaryTreeNode<E>;
        temp->value=key;
        if(size==0)
        {
            root=temp;
        }
        else
        {
            BinaryTreeNode<E> * parent=getnode((size-1)/2);
            if(size%2==0)
            {
                parent->setRight(temp);
            }
            else
            {
                parent->setLeft(temp);
            }
        }
        size++;

    }

    void deletenode(const E& key)
    {

        int r=size;
        if(size==0)
        {
            cout<<"\nTree is empty.\n";
        }
        else
        {
            queue<BinaryTreeNode<E> *> q1,q2;
            BinaryTreeNode<E> * temp=root;
            q1.push(root);

            while(!q1.empty() && q1.front()!=NULL)
            {
                temp=q1.front();
                q1.pop();
                q2.push(temp);
                q1.push(temp->left());
                q1.push(temp->right());
            }


           do
            {
                BinaryTreeNode<E> *t;
                t=q2.front();
                q2.pop();
                if(t->getValue()==key)
                {
                    BinaryTreeNode<E> *t2=t;
                    while(!q2.empty())
                    {

                        t2=q2.front();
                        q2.pop();

                    }

                    t->setValue(t2->getValue());
                    BinaryTreeNode<E> * t3=new BinaryTreeNode<E>;
                    if(size>=2)
                        {t3=getnode((size-2)/2);}
                    else
                     {t3=getroot();}

                    if(size==1)
                    {
                        root=leftChild = rightChild = NULL;
                        value=0;

                        cout<<"Tree is now empty\n";
                        BinaryTreeNode<E> * root=new BinaryTreeNode<E>;
                        root=leftChild = rightChild = NULL;
                    }

                   else if(size%2==0)
                    {
                        t3->setLeft(NULL);

                    }
                    else
                    {
                        t3->setRight(NULL);
                    }
                    t2=NULL;
                    delete t2; size--;
                }
                else{r--;}

            }
            while(!q2.empty());

            if(r==0)
            {
                cout<<"Element not found.\n";
            }


        }



    }

    void inordertraversal(BinaryTreeNode<E> * x)
    {
       if(x!=NULL)
       {
            inordertraversal(x->left());
            cout<<x->value<<" ";
            inordertraversal(x->right());
       }
       else return;
    }

    void preordertraversal(BinaryTreeNode<E> * x)
    {
       if(x!=NULL)
       {
            cout<<x->value<<" ";
            preordertraversal(x->left());
            preordertraversal(x->right());
       }
       else return;
    }

    void postordertraversal(BinaryTreeNode<E> * x)
    {
       if(x!=NULL)
       {
            postordertraversal(x->left());
            postordertraversal(x->right());
            cout<<x->value<<" ";
       }
       else return;
    }
};


int main()
{
    BinaryTreeNode<int> a;
    int choice,val;
    char ans;

    do
    {
        cout<<endl;
        cout<<"1: Insert\n";
        cout<<"2: Delete\n";
        cout<<"3: Inorder display\n";
        cout<<"4: Postorder display\n";
        cout<<"5: Preorder display\n";
        cout<<"0: Exit\n";
        cout<<"enter choice :";
        cin>>choice;
        switch(choice)
        {
        case 1:
                cout<<"\nEnter value to be inserted: ";
                cin>>val;
                a.insert(val);
                break;
        case 2:
                cout<<"\nEnter value to be deleted";
                cin>>val;
                a.deletenode(val);
                break;
        case 3:
                if(a.getsize()==0)
                {
                    cout<<"Tree is empty.\n";
                }
                else
                {
                    cout<<"\nInorder display : ";a.inordertraversal(a.getroot());
                }
                break;
        case 4:
                if(a.getsize()==0)
                {
                    cout<<"Tree is empty.\n";
                }
                else
                {
                    cout<<"\nPostorder display : ";a.postordertraversal(a.getroot());
                }
                break;
        case 5:
                if(a.getsize()==0)
                {
                    cout<<"Tree is empty.\n";
                }
                else
                {
                    cout<<"\nPreorder display : ";a.preordertraversal(a.getroot());
                }
                break;
        case 0:
            exit(0);
            break;
        default :cout<<"Wrong Choice :"<<endl;
        }

        cout<<"Do you want to continue ?(y/n) :";
        cin>>ans;
    }
    while(ans=='y'||(ans=='Y'));

    return 0;

}

