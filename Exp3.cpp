

#include<iostream>
#pragma warn -inl

using namespace std;
typedef struct node
{
   struct node *LC;
   int data;
   struct node *RC;
}NODE;

class BST
{
	NODE *root;
	int count;
	int lh,rh;
	public:
	//Constructor to initialize the attributes of class
	BST()
	{
		root=NULL;
		count=0;
		lh=rh=0;
	}
	
	//Function to return root address
	NODE* getroot()
	{
		return root;
	}

	
	//i. Insert new node
	void addNode(int v)
	{
		NODE *p,*q,*cur;
		p=new NODE;
		p->data=v;
		p->LC=p->RC=NULL;
		if(root==NULL)
			root=p;
		else
		{
			cur=root; 

			while(cur)
			{
				q=cur;
				if(cur->data == v)
				{ 
					cout<<"\nDuplicate Node!";
					return ;
				}
				if(v<cur->data)
					cur=cur->LC;
				else
					cur=cur->RC;
			}
		
			if(v<q->data)
				q->LC=p;
			else
				q->RC=p;
		}
		return;
	}
	
	//INORDER Traversal of tree
	void displayIN(NODE *T)
	{
		if(T)
		{
			displayIN(T->LC);
			cout<<" "<<T->data;
			displayIN(T->RC);
		}
	}
	
	//ii. Find number of nodes in longest path from root
	int height(NODE *T)
	{

		if(T==NULL)
			return 0;
		if(T->LC ==NULL && T->RC==NULL)
			return 0;
		lh=height(T->LC);
		rh=height(T->RC);
		if(lh>rh) 
			return lh+1;
		else
			return rh+1;
	}
	
	//iii.Minimum data value found in the tree
	void minimumDataValue(NODE *T)
	{
		NODE *q,*t;
		int top=-1;
		t=T;
		if (t==NULL)
			cout<<"\nTree Empty";
		else
		{
			while(t)
			{
				q=t;//'q' follows 't'
				t=t->LC;//Goto left
			}
			cout<<"Minimum data value found is:: "<<q->data;
		}
	}
	
	//iv.Mirror Tree
	void Mirror(NODE *t)
	{
		
		NODE *q;
		if(t) 
		{
			q=t->LC; 
			t->LC=t->RC; 
			t->RC=q; 
			Mirror(t->LC); 
			Mirror(t->RC); 
		}
	}
	
	//v. Search a value, Logic is same as insert node in BST
	
	void searchNode(int v)
	{
		NODE *q,*cur;
		count=0;
		if(root==NULL)
			cout<<"\nTree Empty!!";
		else
		{
			cur=root;
			while(cur)
			{
				count++;
				
				if(cur->data == v)
				{
					cout<<"\nNode Found after "<<count<<" comparisions";;
					return ;
				}
				if(v<cur->data)
					cur=cur->LC;
				else
					cur=cur->RC;
			}
		}
		cout<<"\nNode with "<<v<<" value not found after "<<count<<" comparisions";
		return;
	}
	
};


int main(void)
{
   BST B;
   int val,cho,n;
   cho=0;
   while(cho != 7)
   {
     
     cout<<"\n1-ADD NODE";
     cout<<"\n2-DISPLAY NODE INORDER";
	   cout<<"\n3-NO. OF NODES IN THE LONGEST PATH FROM ROOT";
	   cout<<"\n4-MINIMUM DATA VALUE IN THE TREE";
	   cout<<"\n5-MIRROR IMAGE";
     cout<<"\n6-SEARCH NODE IN NODE";
     cout<<"\n7-EXIT";
     cout<<"\nEnter ur choice:";
     cin>>cho;
     switch(cho)
     {
       case 1:
          cout<<"\nEnte any value to added in tree:";
		      cin>>val;
		      B.addNode(val);
		      break;
       case 2:
		      B.displayIN(B.getroot());
		      break;
       case 3:
		      n=B.height(B.getroot());
		      cout<<"\nNo. of nodes in the longest path are:"<<n+1;
		      break;
       case 4:
		      B.minimumDataValue(B.getroot());
		      break;
       case 5:
		      cout<<"\nThe mirror image of tree"<<endl;
		      B.Mirror(B.getroot());
		      break;
	   case 6:
	        cout<<"\nEnte any value to be searched in tree:";
		      cin>>val;
		      B.searchNode(val);
		      break;
	   case 7:
		      cout<<"\nProgram Exits!!";
		      break;
          default:
		      cout<<"\nWrong choice!";
     }
    }
   
   return 0;
}
