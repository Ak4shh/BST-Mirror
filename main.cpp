#include <iostream>
using namespace std;
class tree;
class node
{
    friend class tree;
private:
    int data;
    node *rchild; //right child
    node *lchild; //left child
};
class tree
{
public:
    node *root;
    void inorder(node *);
    void mirror(node *);
    void insert();
    tree()
    {
        root=NULL;
    }
    void indriver();
    void mirror1();
};
void tree::insert() //inserting ele. in BST
{
    int n,i,item;
    node *q,*p;
    cout<<"Enter no. of Elements "<<endl;
    cin>>n;
    for(i=1;i<=n;i++){
        p=new node;
        cout<<"Enter "<<i<<" Item"<<endl;
        cin>>item;
        p->data = item;
        p->lchild = p->rchild = NULL;
        if(i==1)
            root=p;
        else {
            q = root;
            while (1) {
                if (p->data > q->data)
                {
                    if (q->rchild == NULL)
                    {
                        q->rchild = p;
                        break;
                    }
                    else
                        q = q->rchild;
                }
               else if(p->data<q->data)
                {
                    if (q->lchild == NULL)
                    {
                        q->lchild = p;
                        break;
                    } else
                        q = q->lchild;
                }
                else
                {
                    cout<<"given element already exists"<<endl;
                    return;
                }
            }
        }
    }
}


void tree::inorder(node *r)
{
    if(r==NULL)
        return;

    inorder(r->lchild);
    cout<<r->data<<"\t";
    inorder(r->rchild);

}

void tree::indriver() //recursive call of Inorder Func.
{
    inorder(root);
}

void tree::mirror1() //recursive call of mirror Func.
{
    mirror(root);
}
void tree::mirror(node *r) //converting BST to it's mirror
{
    node *t;
    if(r==NULL)
        return;
    else{
    mirror(r->lchild);
    mirror(r->rchild);
    t=r->lchild; //swapping left child with right child
    r->lchild=r->rchild;
    r->rchild=t;
}
}
int main()
{
    tree t;
    int ch;
    while(1){
        cout<<"1)Insert."<<endl<<"2)Display Mirror."<<endl<<"3)Exit."<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                t.insert();
                break;
            case 2:
                cout<<"Inorder of Tree"<<endl;
                t.indriver();
                cout<<endl<<"Mirror of Tree"<<endl;
                t.mirror1();
                t.indriver();
                cout<<endl;
                break;
            case 3: exit(0);
        }
    }
}