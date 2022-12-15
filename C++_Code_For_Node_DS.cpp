Head.h:

#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class Book
{
 private:
 string name;
 string author;
 int pages;
 int idno;
 public:
 Book();
 Book(string,string,int,int);
 Book(const Book&);
 ~Book();
 string getName();
 void setName(string);
 string getAuthor();
 void setAuthor(string);
 int getPages();
 void setPages(int);
 int getIdno();
 void setIdno(int);
 friend istream& operator>>(istream&,Book&);
 friend ostream& operator<<(ostream&,Book&);
};
class Node
{
 public:
 Node();
 Node(Book,Node*);
 Node(const Node&);
 ~Node();
 Book getDetails();
 void displayDetails();
 friend class L_List;
 private:
 Book data;
 Node *next;//Self referencing pointer
};
class L_List
{
 public:
 L_List();
 L_List(Node*);
 L_List(const L_List&);
 ~L_List();
 int insertAtFirst(Node*);
 int insertAtLast(Node*);
 int insertByPos(Node*,int);
 int deleteAtFirst();
 int deleteAtLast();
 int deleteByPos(int);
 void displayList();
 int makeListEmpty();
 int isEmpty();
 private:
 Node *first;//Address of first node in the chain
};

BookImp.cpp:

#include<string.h>
#include<stdlib.h>
#include"head.h"
#include<iostream>
using namespace std;
Node::Node()
{
 data=Book();
 next=NULL;//Initially no info will be available for next node
}
Node::Node(Book d,Node *n)
{
 data=d;
 next=n;
}
Node::Node(const Node&n)
{
 data=n.data;
 next=n.next;
}
Node::~Node()
{
 data=Book();
 next=NULL;
}
Book Node::getDetails()
{
 cout<<"Enter the data part value\n";
 cin>>data;
}
void Node::displayDetails()
{
 cout<<data;
}
Book::Book()
{
 name=" ";
 author=" ";
 pages=0;
 idno=0;
}
Book::Book(string n,string a,int p,int id)
{
 name=n;
 author=a;
 pages=p;
 idno=id;
}
Book::Book(const Book&mylist)
{
 name=mylist.name;
 author=mylist.author;
 pages=mylist.pages;
 idno=mylist.idno;
}
Book::~Book()
{
}
string Book::getName()
{
 return name;
}
string Book::getAuthor()
{
 return author;
}
int Book::getPages()
{
 return pages;
}
int Book::getIdno()
{
 return idno;
}
void Book::setName(string n)
{
 name=n;
}
void Book::setAuthor(string a)
{
 author=a;
}
void Book::setPages(int p)
{
 pages=p;
}
void Book::setIdno(int id)
{
 idno=id;
}
istream& operator>>(istream&myin,Book&b1)
{
 cout<<"Enter the book name:\n";
 cin>>b1.name;
 b1.setName(b1.name);
 cout<<"Enter the author name:\n";
 cin>>b1.author;
 b1.setAuthor(b1.author);
 cout<<"Enter the number of pages:\n";
 cin>>b1.pages;
 b1.setPages(b1.pages);
 cout<<"Enter the id:\n";
 cin>>b1.idno;
 b1.setIdno(b1.idno);
 return myin;
}
ostream& operator<<(ostream&myout,Book&b1)
{
 cout<<"******BOOK DETAILS******\n";
 cout<<"The book name is:"<<b1.name<<"\n";
 cout<<"The author name is:"<<b1.author<<"\n";
 cout<<"The number of pages are:"<<b1.pages<<"\n";
 cout<<"The book id is:"<<b1.idno<<"\n";
 return myout;
}
L_List::L_List()
{
 first=NULL;//At first list is empty
}
L_List::L_List(Node *f)
{
 first=f;
}
L_List::L_List(const L_List&ref)
{
 first=ref.first;
}
L_List::~L_List()
{
 first=NULL;
}
int L_List::isEmpty()
{
 if(first==NULL)
 return 1;//List is empty
 else
 return 0;//List is not empty
}
int L_List::insertAtFirst(Node *newNode)
{
 if (isEmpty())//case 1
 {
 first=newNode;
 }
 else//case 2
 {
 newNode->next=first;
 first=newNode;
 }
 return 1;//Insertion is successful
}
int L_List::insertAtLast(Node *newNode)
{
 if (isEmpty())//case 1
 {
 first=newNode;
 }
 else//case 2
 {
 Node *temp=first;//Traversing the singly linked list to find last node
 while(temp->next!=NULL)
 {
 temp=temp->next;
 }
 temp->next=newNode;
 }
 return 1;//Insertion is successful
}
int L_List::insertByPos(Node *newNode,int pos)
{
 if(!isEmpty())
 {
 int i=1;
 Node *temp=first;
 while(temp->next!=NULL&&i!=pos-1)
 {
 temp=temp->next;
 i++;
 }
 if(i==pos-1)
 {
 newNode->next=temp->next;
 temp->next=newNode;
 return 1;//Insertion successful
 }
 return -2;//Insertion not successful
 }
 else//Empty list
 {
 if(pos==1)
 {
 first=newNode;
 return 1;//Insertion successful
 }
 else
 return -1;//Insertion unsuccessful
 }
}
int L_List::deleteAtFirst()
{
 if(isEmpty())
 return 0;//Deletion not possible
 else
 {
 Node *temp=first;
 first=first->next;
 delete temp;
 temp=NULL;
 }
 return 1;//Deletion is possible
}
int L_List::deleteAtLast()
{
 if(isEmpty())
 return 0;//Deletion not possible
 else
 {
 Node *temp=first;
 Node *prev=first;
 while(temp->next!=NULL)
 {
 prev=temp;
 temp=temp->next;
 }//As temp is the last node,temp->next=Null,prev is last before node
 prev->next=NULL;
 delete temp;
 temp=NULL;
 return 1;
 }
 return 1;//Deletion is possible
}
int L_List::deleteByPos(int pos)
{
 if(!isEmpty())//List is not empty
 {
 int i=1;
 Node *temp=first;
 Node *prev=first;
 while(temp->next!=NULL && i!=pos)
 {
 prev=temp;
 temp=temp->next;
 i++;
 }
 if(i==pos)
 {
 prev->next=temp->next;
 delete temp;
 temp=NULL;
 return 1;//Deletion is possible
 }
 else
 return -2;//Position is invalid
 }
 else
 return -1;//List is empty
}
void L_List::displayList()
{
 Node *temp=first;
 while(temp->next!=NULL)
 {
 cout<<temp->data<<"\t";
 temp=temp->next;//temp will be pointing to last node
 }
 cout<<temp->data<<"\n";
}
int L_List::makeListEmpty()
{
 Node *temp=first;
 while(temp!=NULL)
 {
 first=first->next;
 delete temp;
 temp=first;
 }
 first=NULL;//List is made empty
  
BookApp.cpp:
  
#include<string.h>
#include<stdlib.h>
#include"head.h"
#include<iostream>
using namespace std;
int main()
{
 Book b1,b2,m,n;
 L_List l;
 Node *newNode;
 Book data;
 int ch,res,result,r,ans,answer,a;
 int pos,position;
 int i;
 int pages,idno;
 string name,author;
 do
 {
 cout<<"Enter your 
choice:\n1.InsertAtFirst\n2.InsertAtLast\n3.InsertByPosition\n4.DeleteAtFirst\n5.DeleteAtLast\n6.Delet
eByPosition\n7.DisplayList\n8.Makelistempty\n9.Exit\n";
 cin>>ch;
 switch(ch)
 {
 case 1:cout<<"Enter the data\n";
 cin>>data;
 newNode=new Node(data,NULL);
 res=l.insertAtFirst(newNode);
 if(res==1)
 cout<<"Insertion is successful\n";
 else
 cout<<"Insertion is unsuccessful\n";
 l.displayList();
 break;
 case 2:cout<<"Enter the data\n";
 cin>>data;
 newNode=new Node(data,NULL);
 result=l.insertAtLast(newNode);
 if(result==1)
 cout<<"Insertion is successful\n";
 else
 cout<<"Insertion is unsuccessful\n";
 l.displayList();
 break;
 case 3:cout<<"Enter the data\n";
 cin>>data;
 newNode=new Node(data,NULL);
 cout<<"Enter the position to be inserted\n";
 cin>>pos;
 r=l.insertByPos(newNode,pos);
 if(a==1)
 cout<<"Insertion is successful\n";
 else
 cout<<"Insertion is unsuccessful\n";
 l.displayList();
 break;
 case 4:ans=l.deleteAtFirst();
 if(ans==1)
 cout<<"Deletion is successful\n";
 else
 cout<<"Deletion is unsuccessful\n";
 l.displayList();
 break;
 case 5:answer=l.deleteAtLast();
 if(answer==1)
 cout<<"Deletion is successful\n";
 else
 cout<<"Deletion is unsuccessful\n";
 l.displayList();
 break;
 case 6:cout<<"Enter the position to be deleted\n";
 cin>>position;
 a=l.deleteByPos(pos);
 if(a==1)
 cout<<"Deletion is successful\n";
 else
 cout<<"Deletion is unsuccessful\n";
 l.displayList();
 break;
 case 7:l.displayList();
 break;
 case 8:l.makeListEmpty();
 break;
 case 9:exit(0);
 break;
 }
 }while(ch<=10);
}
  
Makefile:
  
out.exe:bookImp.o bookApp.o
 g++ -o out.exe bookImp.o bookApp.o
bookImp.o:bookImp.cpp
 g++ -c bookImp.cpp
bookApp.o:bookApp.cpp
 g++ -c bookApp.cpp
