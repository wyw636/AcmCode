#include<iostream>
using namespace std;
struct LNode{
	int data;
	LNode *next;
};
void insert(LNode *&head,int num){
	LNode *p=head,*q=new LNode;
	q->data=num;
	if(head==NULL || head->data>=num){
		head=q;
		q->next=p;
	}
	else{
		while(p){
			if(p->next==NULL || p->next->data>=num){
				q->next=p->next;
				p->next=q;
				break;
			}
			p=p->next;
		}
	}
	return ;
}
LNode *create(){
	int num;
	LNode *h=NULL,*p;
	p=new LNode;
	cout<<"输入链表数据(以-1结束): "<<endl;
	while(cin>>num && num!=-1)
		insert(h,num);
	return h;
}
void print(LNode *head){
	LNode *p=head;
	cout<<"当前链表数据: "<<endl;
	while(p){
		cout<<p->data<<' ';
		p=p->next;
	}
	cout<<endl;
	return ;
}
int main(){
	int num;
	LNode *head;
	head=create();
	print(head);
	cout<<"输入插入数据: "<<endl;
	while(cin>>num){
		insert(head,num);
		print(head);
		cout<<"输入插入数据: "<<endl;
	}
	return 0;
}
