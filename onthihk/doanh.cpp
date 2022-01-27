//bai 1
#include<iostream>
#include<string>
using namespace std;

struct hanghoa
{
	int mahang;
	string tenhang;
	float gianhap;
	float giaxuat;
};

struct node
{
	hanghoa data;
	node *next;
	node *prev;
};

struct list
{
	node *head;
	node *tail;
};

void khoitao(list &l)
{
	l.head=l.tail=NULL;
}

node *taonode(hanghoa x)
{
	node *p =new node;
	if(p==NULL)cout<<"\nKhong du bo nho";
	else{
		p->data=x;
		p->prev=NULL;
		p->next=NULL;
	}
	return p;
}

void chencuoi(list &l,node *p)
{
	if(l.head==NULL)
	{
		l.head=l.tail=p;
	}
	else{
		l.tail->next=p;
		p->prev=l.tail;
		l.tail=p;
	}
}

void nhap(hanghoa &hh)
{
	cout << "\nNhap ma hang: ";
	cin >> hh.mahang;
	cout << "Nhap ten hang: ";
	fflush(stdin);
	getline(cin,hh.tenhang);
	cout << "Nhap gia nhap: ";
	cin >> hh.gianhap;
	cout << "Nhap gia xuat: ";
	cin >> hh.giaxuat;
}

void xuat(hanghoa hh)
{
	cout << "Ma hang: " << hh.mahang << endl;
	cout << "Ten hang: " << hh.tenhang << endl;
	cout << "Gia nhap: " << hh.gianhap << endl;
	cout << "Gia xuat: " << hh.giaxuat << endl;	
}

void duyet(list l)
{
    int i = -1;
	for(node *k=l.head;k!=NULL;k=k->next)
	{
        i++;
		cout<<"\nHang hoa thu "<<i+1<<": \n";
        xuat(k->data);
	}
}

int main()
{
	list l;
	khoitao(l);
	int n;
	
	cout<<"Nhap so luong hang hoa: ";cin>>n;
	for(int i=0;i<n;i++){
		hanghoa x;
		cout<<"\nNhap thong tin hang hoa thu "<<i+1<<": \n";
		nhap(x);
		node *p=taonode(x);
		chencuoi(l,p);
	}

	cout<<"\n======= Thong tin " << n << " hang hoa =======\n";
	duyet(l);
}