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

void khoitao(list &l){
	l.head=l.tail=NULL;
}
node *taonode(hanghoa x)
{
	node *p =new node;
	if(p==NULL)cout<<"khong du bo nho";
	else{
		p->data=x;
		p->prev=NULL;///
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

void nhap(hanghoa &hh)
{
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
void xuat(hanghoa hh)
{
	cout << "Ma hang: " << hh.mahang << endl;
	cout << "Ten hang: " << hh.tenhang << endl;
	cout << "Gia nhap: " << hh.gianhap << endl;
	cout << "Gia xuat: " << hh.giaxuat << endl;	
}

void duyet(list l)
{
	for(node *k=l.head;k!=NULL;k=k->next)
	{
		xuat(k->data);
		cout << "\n";
	}
}

void timkiem(list l)
{
    int dem=0;
    for(node *p=l.head;p!=NULL;p=p->next)
	{
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
void XoaDau (list &l)
{
    if(l.head==NULL)
    return;
    node *p=l.head;
    l.head=l.head->next;
    delete p;
}

void XoaCuoi (list &l)
{
    if(l.head==NULL)
    return;
    for (node *k=l.head;k!=NULL;k=k->next)
	{
        if(k->next==l.tail)
		{
            delete l.tail;
            k->next=NULL;
            l.tail=k;
        }
    }
}
void search_with_input(list l,string t)
{
    int dem=0;
    for(node *p=l.head;p!=NULL;p=p->next)
	{
        if(p->data.tenhang== t )
        {
          xuat(p->data);
          //cout << "\n";
          dem++;
		  }
    }
    if(dem==0)
        cout<<" khong co mat hang can tim! ";
    }   

void sapxep(list&l)
{
    for (node*p=l.head;p!=l.tail;p=p->next)
    {
        for(node*q=l.head->next;q!=NULL;q=q->next)
        if (p->data.gianhap > q->data.gianhap)
        swap (p->data,q->data);
    }
}

//do dai node
int Length(list l)
{
    int length = 0;
    for(node *p=l.head;p!=NULL;p=p->next)
    {
        ++length;
    }
    return length;
}

//lay gia tri node
node* GetNode(list& l, int index)
{
	node* node = l.head;
	int i = 0;
	while (node != NULL && i != index)
	{
		node = node->next;
		i++;
	}
	if (i == index && node != NULL)
		return node;
	return NULL;
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

	// cout<<"\nThong tin cac hang hoa:\n";
	// duyet(l);

    // cout << "\nDo dai danh sach lien ket: " << Length(l) << endl;
	
	// {
	// 	hanghoa x;
	// 	cout<<"\nnhap thong tin hang hoa can chen cuoi \n";
	// 	nhap(x);
	// 	node *p=taonode(x);
	// 	chencuoi(l,p);
	// 	cout<<"\nThong tin cac hang hoa:\n";
	// 	duyet(l);
	// }

	// {
	// 	hanghoa x;
	// 	cout<<"\nnhap thong tin hang hoa can chen dau \n";
	// 	nhap(x);
	// 	node *p=taonode(x);
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

	// cout << "\n======= DANH SACH HANG HOA SAU KHI XOA =========\n";
    // XoaNode(l);

	// cout << "\n-----------DANH SACH MAT HANG SAU KHI XOA DAU------------" << endl;
	//     XoaDau(l);
	//     duyet(l);

	// cout << "\n-----------DANH SACH MAT HANG SAU KHI XOA CUOI------------" << endl;
    // XoaCuoi(l);
    // duyet(l);

	// string t;
    // cout << "Nhap ten hang:";
    // fflush(stdin);
    // getline(cin,t);
    // cout << "\n-----------DANH SACH HANG HOA VOI TEN HANG " << t << " LA ------------" << endl;
    // search_with_input(l,t);

	// cout << "\n------------DANH SACH SAU SAP XEP-----------" <<endl;
    // sapxep(l);
    // duyet(l); 

    // int d;
    // cout << "\nNhap vi tri node: ";
    // cin >> d;
    // if(d>=Length(l) || d <0)
    // cout << "\nVi tri node khong ton tai = NULL" << endl;
    // else 
    // {   
    //     node* index = GetNode(l, d);
	//     cout << "\nThong tin node: " << endl;
    //     cout << "\n";
    //     xuat(GetNode(l,d)->data);
    // }
}