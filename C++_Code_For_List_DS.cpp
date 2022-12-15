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
 string getAuthor();
 int getPages();
 int getIdno();
 void setName(string);
 void setAuthor(string);
 void setPages(int);
 void setIdno(int);
 friend istream& operator>>(istream&,Book&);
 friend ostream& operator<<(ostream&,Book&);
};
class A_List
{
 public:
 A_List();
 A_List(Book*,int,int);
 A_List(const A_List&);
 ~A_List();
 int getCap();
 int getSize();
 Book* getArr();
 void setCap(int);
 void setSize(int);
 void setArr(Book*);
 int insertAtFirst(Book);
 int insertAtLast(Book);
 int isFull();
 int isEmpty();
 Book displayList();
 int makeListEmpty();
 int insertByPos(Book,int);
 int deleteAtFirst();
 int deleteAtLast();
 int deleteByPos(int);
 Book searchAtFirst();
 Book searchAtLast();
 private:
 Book *arr;//To hold the list of integer elements
 int cap;//Capacity of the list
 int size;//To find the number of elements currently available in the list
};

BookImp.cpp:

#include"head.h"
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
Book::Book()
{
 pages=0;
 idno=0;
 name=" ";
 author=" ";
}
Book::Book(string n,string a,int p,int id)
{
 pages=p;
 idno=id;
 name=n;
 author=a;
}
Book::Book(const Book&mylist)
{
 pages=mylist.pages;
 idno=mylist.idno;
 name=mylist.name;
 author=mylist.author;
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
 cout<<"Enter the book id:\n";
 cin>>b1.idno;
 b1.setIdno(b1.idno);
 return myin;
}
ostream& operator<<(ostream&myout,Book&b1)
{
 cout<<"--------------------------------------\n";
 cout<<"******BOOK DETAILS******\n";
 cout<<"-------------------------------------\n";
 cout<<"The book name: "<<b1.name<<"\n";
 cout<<"The author name is: "<<b1.author<<"\n";
 cout<<"The number of pages are: "<<b1.pages<<"\n";
 cout<<"The book id is: "<<b1.idno<<"\n";
 return myout;
}
A_List::A_List()
{
 //arr=NULL;
 size=0;//No element is there at first
 cap=10;//capacity is assigned to 10
 arr=new Book[cap];
 for(int i=0;i<10;i++)
 {
 arr[i]=Book();
 }
}
A_List::A_List(Book*a,int s,int c)
{
 size=s;
 cap=c;
 arr=new Book[cap];
 for(int i=0;i<size;i++)
 {
 arr[i]=a[i];
 }
 for(int i=size;i<cap;i++)
 {
 arr[i]=Book();//To fill the remaining nodes by default constructor
 }
}
A_List::A_List(const A_List&myList)
{
 size=myList.size;
 cap=myList.cap;
 arr=new Book[cap];
 for(int i=0;i<size;i++)
 {
 arr[i]=myList.arr[i];//To initialise data with value for given size
 }
 for(int i=size;i<cap;i++)
 {
 arr[i]=Book();//To fill remaining nodes by default constructor
 }
}
A_List::~A_List()
{
 size=-1;
 cap=-1;
 delete[]arr;
 arr=NULL;
}
int A_List::isFull()
{
 if(ngsize==cap)
 return 1;//List is full
 else
 return 0;//List isnot full
}
int A_List::isEmpty()
{
 if(size==0)
 return 1;//List is empty
 else
 return 0;//List isnot empty
}
int A_List::insertAtFirst(Book ele)
{
 if(!isFull())//case 1 Insertion is possible
 {
 if(isEmpty())
 {
 arr[0]=ele;
 size++;
 return 1;
 }
 else//case 2
 {
 for(int i=size;i>0;i--)
 arr[i]=arr[i-1];
 arr[0]=ele;
 size++;
 //return 1;
 }
 return 1;//Insertion is successful
 }
 else//case 3
 return 0;//Insertion isnot possible
}
int A_List::insertAtLast(Book ele)
{
 if(!isFull())//Insertion is possible
 {
 arr[size++]=ele;
 return 1;//Insertion is successful
 }
 else
 return 0;//insertion isnot possible
}
int A_List::insertByPos(Book ele,int pos)
{
 int i;
 if(!isFull())
 {
 if(pos>size+1)//Given position is invalid
 return -2;
 else
 {
 if(isEmpty()&&pos==1)
 {
 insertAtFirst(ele);
 return 1;
 }
 else if(isEmpty()&&pos!=1)
 return -3;//Invalid operatio in empty list
 else
 {
 for(i=size;i>pos-1;i--)
 arr[i]=arr[i-1];
 arr[i]=ele;
 size++;
 }
 return 1;
 }
 }
 else//case 3 List is full
 return 0;
}
int A_List::deleteAtFirst()
{
 if(!isEmpty())
 {
 for(int i=0;i<size;i++)
 {
 arr[i]=arr[i+1];
 size--;
 return 1;//Deletion is successful
 }
 }
 else
 return -1;//Deletion isnot possible
}
int A_List::deleteAtLast()
{
 if(!isEmpty())
 {
 arr[size-1]=Book();
 size--;
 return 1;//Deletion is possible
 }
 else
 return -1;//Deletion not possible
}
int A_List::deleteByPos(int pos)
{
 int i;
 if(!isEmpty())
 {
 if(pos>size+1)//case 1
 {
 return -2;//Invalid operation
 }
 else//case 2
 {
 if(isFull()&&pos==size)
 {
 deleteAtLast();
 }
 else if(!isFull())//Shifting operation
 {
 for(int i=0;i<pos;i++)
 {
 arr[i]=arr[i+1];
 }
 arr[i]=Book();
 size--;
 return 1;//Deletion is successful
 }
 else
 return -2;//Deletion isnot possible
 }
 }
}
int A_List::makeListEmpty()
{
 while(!isEmpty())
 {
 deleteAtFirst();
 }
 return 1;
}
Book A_List::displayList()
{
 if(!isEmpty())//List isnot empty
 {
 for(int i=0;i<size;i++)
 {
 cout<<arr[i]<<"\t";
 }
 cout<<"\n";
 }
}
Book A_List::searchAtFirst()
{
 if(!isEmpty())
 return arr[0];//Element found
 else
 return arr[0];//List is empty
}
Book A_List::searchAtLast()
{
 if(!isEmpty())
 return arr[size-1];//Element found
 else
 return arr[0];//List is empty
}

BookApp.cpp:

#include<string.h>
#include<stdlib.h>
#include"head.h"
#include<iostream>
using namespace std;
int main()
{
 Book b1,b2,b3,b4,b5,z;
 Book m,n;
 A_List al;
 int i,ch,element,res,pos,key,result,r,ans,answer,x;
 int cap,size;
 int pages,id;
 string name,author;
 do
 {
 cout<<"*****Possible Operations*****\nEnter your 
choice\n1.InsertAtfirst\n2.InsertAtLAst\n3.InsertByPosition\n4.DeleteAtFirst\n5.DeleteAtLast\n6.Delete
ByPosition\n7.DisplayList\n8.MakeListEmpty\n9.SearchAtFirst\n10.SearchAtLast\n11.Exit\n";
 cin>>ch;
 switch(ch)
 {
 case 1:cout<<"Enter a book to be inserted at first\n";
 cin>>b1;
 res=al.insertAtFirst(b1);
 if(res==1)
 cout<<"Insertion is successful\n";
 else
 cout<<"Insertion is not possible\n";
 break;
 case 2:cout<<"Enter the book to be inserted at last\n";
 cin>>b2;
 result=al.insertAtLast(b2);
 if(result==1)
 cout<<"Insertion is successful\n";
 else
 cout<<"Insertion is not possible\n”;
 break;
 case 3:cout<<"Enter a book and the position to be inserted\n";
 cin>>b3>>pos;
 r=al.insertByPos(b3,pos);
 if(r==1)
 cout<<"Insertion is possible\n";
 else
 cout<<"Insertion is not possible\n";
 break;
 case 4:ans=al.deleteAtFirst();
 if(ans==1)
 cout<<"Deletion is successful\n";
 else
 cout<<"Deletion is not possible\n";
 break;
 case 5:answer=al.deleteAtLast();
 if(answer==1)
 cout<<"Deletion is successful\n";
 else
 cout<<"Deletion is not possible\n";
 break;
 case 6:int position,a;
 cout<<"Enter the position of element to be deleted\n";
 cin>>position;
 a=al.deleteByPos(position);
 if(a==1)
 cout<<"Deletion is successful\n";
 else
 cout<<"Deletion is not possible\n";
 break;
 case 7:z=al.displayList();
 break;
 case 8:int t;
 t=al.makeListEmpty();
 if(t==1)
 cout<<"Array is empty\n";
 else
 cout<<"Array is not empty\n";
 break;
 case 9:m=al.searchAtFirst();
 cout<<"Element at first position is \t"<<m;
 break;
 case 10:n=al.searchAtLast();
 cout<<"Element at last position is \t"<<n;
 break;
 case 11:exit(0);
 break;
 }
 }while(ch<=11);
}

Makefile:

out.exe:bookImp.o bookApp.o
 g++ -o out.exe bookImp.o bookApp.o
bookImp.o:bookImp.cpp
 g++ -c bookImp.cpp
bookApp.o:bookApp.cpp
 g++ -c bookApp.cpp

