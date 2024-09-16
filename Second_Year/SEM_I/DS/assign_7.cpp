//============================================================================
// Name        : Omkar Sonawane
// Author      : gaur
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;

struct node
{
    int PRN;
    char name[20];
    node*next;
};
class club
{
    int num,cnt;
    char nm[20];
    node*head;
    public:
        club()
        {
            num=0;
            cnt=0;
            head=NULL;

        }
    node*create();
    void display(node*);
    node* conct(node*, node*);
    void reverse(node*);
    node*insert_president(node*);
    void insert_sect(node*);
    void insert_member(node*);
    node*del_president(node*);
    node*del_secretary(node*);
    node*del_member (node*);
};

node*club::create(){
    node *temp,*n1;
    temp=n1=NULL;
    cout<<"How many student data you want to enter :"<<endl;
    cin>>cnt;
    do{
        n1=new node;
        cout<<"Enter the PRN number of studets :"<<endl;
        cin>>num;
        n1->PRN=num;
        cout<<"Enter the name of students :"<<endl;
        cin>>nm;
        strcpy(n1->name,nm);
        n1->next=NULL;
        if(head==NULL){
            head=n1;
            temp=head;

        }
        else{
            temp=head;
            while(temp->next != NULL){
                temp=temp->next;
            }
            temp->next=n1;
        }
        cnt--;
    }while(cnt>0);
    return head;
}

void club::display(node *head)
{
 node *temp;
 temp=head;
 while(temp!=NULL)
 {
     if(temp->next==NULL)
     {
      cout<<"["<<temp->PRN<<"|"<<temp->name<<"]->NULL";
     }
     else
     {
      cout<<"["<<temp->PRN<<"|"<<temp->name<<"]->";
     }
     temp=temp->next;
 }
}

node*club ::conct(node*head1,node*head2){
    node *head3,*temp,*temp1;
    head3=temp=temp1=NULL;
    temp=head1;
    head3=head1;
    while(temp->next!=NULL){
        temp=temp->next;

    }
    temp1=head2;
    temp->next=temp1;
    return head3;
}
void club::reverse(node*head){
    node*temp;
    temp=head;
    if(temp==NULL)
        return;

    reverse(temp->next);
    cout<<"["<<temp->PRN<<"|"<<temp->name<<"]->";

}
node*club::insert_president(node*head){
    node *temp,*n2;
     temp=n2=NULL;
     temp=head;
     n2=new node;
     cout<<"\nEnter the PRN number of President:";
     cin>>n2->PRN;
     cout<<"\nEnter the name of President:";
     cin>>n2->name;
     n2->next=temp;
     head=n2;
     return head;

}
void club::insert_member(node*head){
    node *temp,*n2;
     int pn;
     temp=head;
     n2=new node;
     cout<<"\nEnter the PRN number of Member: ";
     cin>>n2->PRN;
     cout<<"\nEnter the name of Member: ";
     cin>>n2->name;
     n2->next=NULL;
     cout<<"\nEnter the PRN number after which u want to add this member: ";
     cin>>pn;

     while(temp!=NULL)
     {
      if(temp->PRN==pn)
      {
       n2->next=temp->next;
       temp->next=n2;
       break;
      }
      temp=temp->next;
     }
     cout<<"\n\nMember added sucessfully....!!";
}
void club::insert_sect(node*head){
    node *temp,*n2;
    temp=head;
    n2=new node;
    cout<<"\n Enter the PRN number for secretary"<<endl;
    cin>>n2->PRN;
    cout<<"\n Enter the Name for secretary"<<endl;
    cin>>n2->name;
    n2->next=NULL;
    while(temp->next!=NULL)
     {
      temp=temp->next;
     }
     temp->next=n2;
}
node* club::del_president(node *head)
{
 node *temp;
 temp=head;
 head=temp->next;
 free(temp);
 return head;
}
node* club::del_secretary(node *head)
{
 node *temp,*t1;
 temp=head;
 while(temp->next!=NULL)
 {
  t1=temp;
  temp=temp->next;
 }
 t1->next=NULL;
 free(temp);
 return head;
}
node* club::del_member(node *head)
{
 node *temp,*t1;
 int pn;
 temp=head;
 cout<<"\nEnter the position number after which u want to delete member: ";
 cin>>pn;
 while(temp!=NULL)
 {
  if(temp->PRN==pn)
  {
   t1=temp->next;
   temp->next=t1->next;
   free(t1);
   break;
  }
  temp=temp->next;
 }
 cout<<"\n\nMember removed sucessfully....!!";
 return head;
}
int main(){
    club c1,c2,c3;

    node*h1,*h2,*h3;
    int ch;
        cout << "\n\t!!!Group B:Assignment No:01!!!" << endl; // prints !!!Assignment number and group!!!
       do
       {
        cout<<"\n\n1.Enter data of SE A Division:";
        cout<<"\n2.Enter data of SE B Division:";
        cout<<"\n3.Concatination of List..";
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch){
        case 1:
            cout<<"\n\nPlease enter the student info who is register memeber.."<<endl;
            cout<<"\n\nEnter the Panclub Data of SE A Division:\n"<<endl;
            h1=c1.create();
            cout<<"SE comp Division A list are as follows "<<endl;
            c1.display(h1);
            cout<<"\n\nReverse List of SE Div A:\n\n";
            c1.reverse(h1);
            c1.insert_sect(h1);
            cout<<"\n\n After insertion of secratory";
            c1.display(h1);
            h1=c1.insert_president(h1);
            cout<<"\n\n After insertion of presisdent \n\n ";
            c1.display(h1);
            c1.insert_member(h1);
            cout<<"\n\n After insertion of members\n\n";
            c1.display(h1);
            h1=c1.del_president(h1);
            cout<<"\n\n After deletion of presisdent \n\n ";
            c1.display(h1);
            h1=c1.del_secretary(h1);
            cout<<"\n\n After deletion of secretory \n\n ";
            c1.display(h1);
            h1=c1.del_member(h1);
            cout<<"\n\n After deletion of member \n\n ";
            c1.display(h1);
            break;
        case 2:
            cout<<"\n\nPlease enter the student info who is register memeber.."<<endl;
            cout<<"\n\nEnter the Panclub Data of SE B Division:\n"<<endl;
            h2=c2.create();
            cout<<"SE comp Division B list are as follows "<<endl;
            c2.display(h2);
            cout<<"\n\nReverse List of SE Div B:\n\n";
            c2.reverse(h2);
            c2.insert_sect(h2);
            cout<<"\n\n After insertion of secratory";
            c2.display(h2);
            h2=c2.insert_president(h2);
            cout<<"\n\n After insertion of presisdent \n\n ";
            c2.display(h2);
            c2.insert_member(h2);
            cout<<"\n\n After insertion of members\n\n";
            c2.display(h2);
            h2=c2.del_president(h2);
            cout<<"\n\n After deletion of presisdent \n\n ";
            c2.display(h2);
            h2=c2.del_secretary(h2);
            cout<<"\n\n After deletion of secretory \n\n ";
            c2.display(h2);
            h2=c2.del_member(h2);
            cout<<"\n\n After deletion of member \n\n ";
            c2.display(h2);
            break;
        case 3:
            h3=c3.conct(h1,h2);
                    cout<<"\n\nThe concatenation of Div : A and Div : B of SE Comp Class are as follows.\n\n";
                    c3.display(h3);
                    break;

        }
       }while(ch!=4);

    return 0;
}