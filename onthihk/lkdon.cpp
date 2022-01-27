#include"iostream"
#include <string>
using namespace std;

struct mathang
{
    int mahang;
    string tenhang;
    string loaihang;
	int namsx;
	string xuatxu;
	float giaban;
};

struct node
{
    mathang data;
    node *next;
};

struct list
{
    node *phead;
    node *ptail;
};

void khoitao(list &l)
{
    l.phead=l.ptail=NULL;
}

bool kiemtrarong(list l)
{
    if(l.phead==NULL){
        return true;
    }
    return false;
}

node *taonut(mathang x)
{
    node *p=new node;
    if(p!=NULL){
        p->data=x;
        p->next=NULL;
    }
    else cout<<"khong du bo nho";
    return p;
}

void chendau(list &l,node *p){
    if(l.phead==NULL){
        l.phead=l.ptail=p;
    }
    else{
        p->next=l.phead;
        l.phead=p;
    }
}
void chencuoi(list &l,node *p)
{
    if(kiemtrarong(l)==true){
        l.phead=l.ptail=p;
    }
    else{
        l.ptail->next=p;
        l.ptail=p;
    }
}

void nhap(mathang &mh)
{
    cout<<" nhap ma hang: ";
    cin>>mh.mahang;
    cout<<" nhap ten hang :";
    fflush(stdin);
    getline(cin,mh.tenhang);
    cout<<" nhap loai hang: ";
	fflush(stdin);
    getline(cin,mh.loaihang);
	cout << "Nhap nam san xuat";
	cin >> mh.namsx;
	cout << "Nhap xuat xu: ";
	fflush(stdin);
	getline(cin,mh.xuatxu);
	cout << "Nhap gia ban: ";
	cin >> mh.giaban;
}

void xuat(mathang mh)
{
    cout<<" "<<mh.mahang<<"  "<<mh.tenhang<<"  "<<mh.loaihang << " "<< mh.namsx << " " << mh.xuatxu <<" "<< mh.giaban << endl;
}

void duyet(list l)
{
    for(node *p=l.phead;p!=NULL;p=p->next){
        xuat(p->data);
    }
}

//tim theo dk cho san
void timkiem(list l){
    int dem=0;
    for(node *p=l.phead;p!=NULL;p=p->next){
        if(p->data.loaihang=="gia dung" && p->data.giaban >= 500 && p->data.giaban <= 1000 )
        {
          xuat(p->data);
          //cout << "\n";
          dem++;}
    }
    if(dem==0)
        cout<<" khong co mat hang can tim! ";
    }        

//tim theo tham so dau vao
void search_with_input(list l,string t){
    int dem=0;
    for(node *p=l.phead;p!=NULL;p=p->next){
        if(p->data.loaihang== t )
        {
          xuat(p->data);
          //cout << "\n";
          dem++;}
    }
    if(dem==0)
        cout<<" khong co mat hang can tim! ";
    }   

//xoa cuoi
void XoaCuoi (list &l){
    if(l.phead==NULL)
    return;
    for (node *k=l.phead;k!=NULL;k=k->next){
        if(k->next==l.ptail){
            delete l.ptail;
            k->next=NULL;
            l.ptail=k;
        }
    }
}

//xuat
void XoaDau (list &l){
    if(l.phead==NULL)
    return;
    node *p=l.phead;
    l.phead=l.phead->next;
    delete p;
}

//xoa theo dieu kien
void XoaNode(list &l){
	for(node *k=l.phead;k!=NULL;k=k->next){
		if(k->data.xuatxu=="trung quoc"){
			node *tg = k;
			k=k->next;
			free(tg);
		}
		xuat(k->data);
	}
}

//sap xep nho den lon
void sapxep(list&l)
{
    for (node*p=l.phead;p!=l.ptail;p=p->next)
    {
        for(node*q=l.phead->next;q!=NULL;q=q->next)
        if (p->data.giaban > q->data.giaban)
        swap (p->data,q->data);
    }
}

int length(list l)
{
    int length=0;
    for(node *p=l.phead;p!=NULL;p=p->next)
    {
        length++;
    }
    return length;
} 

float sum(list l){
    float sum = 0;
    for (node *p=l.phead;p!=NULL;p=p->next){
        sum += p->data.giaban;
    }
    return sum;
}

int max(list l){
    float max = 0;
    for (node *p=l.phead;p!=NULL;p=p->next)
    {
        if(p->data.giaban>=max)
        max = p->data.giaban;
    }
    return max;
}

node* maxmh(list& l)
{
    node* max = l.phead;
    for(node *p=l.phead;p!=NULL;p=p->next)
    {
        if (p->data.giaban >= max->data.giaban)
        {
            max = p;
        }
    }
    return max;
}

int main()
{
    list l;
    khoitao(l);
    int n;
    cout<<" nhap so mat hang: ";
    cin>>n;
    for(int i=0;i<n;i++){
        mathang x;
        nhap(x);
        node *p=taonut(x);
    chencuoi(l,p);
    }
    cout<<" THONG TIN MAT HANG: \n";
    duyet(l);

    // cout << "\nDo dai danh sach lien ket: " << length(l) << endl;

    // cout << "* -----------DANH SACH MAT HANG SAU KHI XOA MAT HANG XUAT XU TQ------------*" << endl;
    // XoaNode(l);

    // cout << "\n-----------DANH SACH MAT HANG SAU KHI XOA DAU------------" << endl;
    // XoaDau(l);
    // duyet(l);

    // cout << "\n-----------DANH SACH MAT HANG SAU KHI XOA CUOI------------" << endl;
    // XoaCuoi(l);
    // duyet(l);

    // cout << "\n-----------DANH SACH MAT HANG THOA MAN DK------------" << endl;
    // timkiem(l);

    // string t;
    // cout << "Nhap loai hang:";
    // fflush(stdin);
    // getline(cin,t);
    // cout << "\n-----------DANH SACH MAT HANG LOAI HANG " << t << " ------------" << endl;
    // search_with_input(l,t);

    // {
    //     mathang x;
    //     cout << "\nNhap thong tin chen cuoi: " << endl;
    //     nhap(x);
    //     node *p=taonut(x);
    //     chencuoi(l,p);
    //     cout << "\n======= DANH SACH SAU CHEN CUOI ===========\n";
    //     duyet(l);
    // }

    // {
    //     mathang x;
    //     cout << "\nNhap thong tin chen dau: " << endl;
    //     nhap(x);
    //     node *p=taonut(x);
    //     chendau(l,p);
    //     cout << "\n======= DANH SACH SAU CHEN DAU ===========\n";
    //     duyet(l);
    // }

    // cout << "\n------------DANH SACH SAU SAP XEP-----------" <<endl;
    // sapxep(l);
    // duyet(l); 

    //cout << "Max gia ban: " << max(l);

    cout << "\nThong tin node: " << endl;
    cout << "\n";
    xuat(maxmh(l)->data);

    // cout << "Tong gia ban: " << sum(l) / n << endl;
}