//bai 1
#include<iostream>
#include<string>
#include<cstdlib>
#include<stdio.h>
using namespace std;

struct hanghoa{
	int mahang;
	string tenhang;
	float gianhap;
	float giaxuat;
};

struct node{
	hanghoa data;
	node *next;
	node *prev;///
};

struct list{
	node *head;
	node *tail;
};

void khoitao_ds(list &l){
	l.head=l.tail=NULL;
}
node *khoitao_node(hanghoa x){
	node *p =new node;
	if(p==NULL)cout<<"khong du bo nho";
	else{
		p->data=x;
		p->prev=NULL;///
		p->next=NULL;
	}
	return p;
}
void them_cuoi(list &l,node *p){
	if(l.head==NULL){
		l.head=l.tail=p;
	}
	else{
		l.tail->next=p;
		p->prev=l.tail;//
		l.tail=p;
	}
}

void chendau(list &l, node *p)
{
    if(l.head==NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        p->next = l.head ;
        l.head = p;
    }
}

void nhap(hanghoa &hh){
	cout << "Nhap ma hang: ";
	cin >> hh.mahang;
	cout << "Nhap ten hang: ";
	fflush(stdin);
	getline(cin,hh.tenhang);
	cout << "Nhap gia nhap: ";
	cin >> hh.gianhap;
	cout << "Nhap gia xuat: ";
	cin >> hh.giaxuat;
}
void xuat(hanghoa hh){
	cout << "Ma hang: " << hh.mahang << endl;
	cout << "Ten hang: " << hh.tenhang << endl;
	cout << "Gia nhap: " << hh.gianhap << endl;
	cout << "Gia xuat: " << hh.giaxuat << endl;	
}

void duyet(list l)
{
	for(node *k=l.head;k!=NULL;k=k->next){
		xuat(k->data);
		cout << "\n";
	}
}

void timkiem(list l){
    int dem=0;
    for(node *p=l.head;p!=NULL;p=p->next){
        if(p->data.mahang==2 )
        {
          xuat(p->data);
          cout << "\n";
          dem++;}
    }
    if(dem==0)
        cout<<" khong co mat hang can tim! ";
    }   

void XoaNode(list &l)
{
	for(node *k=l.head;k!=NULL;k=k->next)
	{
		if(k->data.tenhang=="trung quoc")
		{
			node *tg = k;
			k=k->next;
			free(tg);
		}
		xuat(k->data);
	}
}

int main(){
	list l;
	khoitao_ds(l);
	int n;
	
	cout<<"nhap so luong hang hoa:= ";cin>>n;
	for(int i=0;i<n;i++){
		hanghoa x;
		cout<<"\nnhap thong tin hang hoa "<<i+1<<": \n";
		nhap(x);
		node *p=khoitao_node(x);
		them_cuoi(l,p);
	}

	cout<<"\nThong tin cac hang hoa:\n";
	duyet(l);
	
	{
		hanghoa x;
		cout<<"\nnhap thong tin hang hoa can chen cuoi \n";
		nhap(x);
		node *p=khoitao_node(x);
		them_cuoi(l,p);
		cout<<"\nThong tin cac hang hoa:\n";
		duyet(l);
	}

	// {
	// 	hanghoa x;
	// 	cout<<"\nnhap thong tin hang hoa can chen dau \n";
	// 	nhap(x);
	// 	node *p=khoitao_node(x);
	// 	chendau(l,p);
	// 	cout<<"\nThong tin cac hang hoa:\n";
	// 	duyet(l);
	// }

	// 	cout<<"\nThong tin cac mat hang gia dung co gia 500.000-1.000.000\n";
	// 	search(l);
	// 	cout<<"\nCac mat hang con lai sau khi bo nha xuat xu trung quoc:\n";
	// 	xoapt(l);

	// cout << "\n======= DANH SACH HANG HOA CO MA HANG THOA MAN DK =========\n";
	// timkiem(l);

	cout << "\n======= DANH SACH HANG HOA SAU KHI XOA =========\n";
	XoaNode(l);


}