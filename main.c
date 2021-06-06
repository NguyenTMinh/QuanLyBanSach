#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#define MAX_ID 20
#define MAX_NAME 50
#define MAX_ADD 100
#define MAX_PH 200

typedef struct Sach
{
    char id_sach[MAX_ID];
    char ten_sach[MAX_NAME];
    char ten_tac_gia[MAX_NAME];
    int nam_xuat_ban;
    char nha_san_xuat[MAX_NAME];
    char the_loai[MAX_NAME];
    long gia_tien;
    int so_luong_ban;
};
//list sach
struct Node_Sach
{
    struct Sach data;
    struct Node_Sach *pNext;
};

struct Sach themDataSach(){
    struct Sach temp;
    fflush(stdin);
    printf("nhap id sach: ");
    fgets(temp.id_sach,sizeof(temp.id_sach),stdin);
    printf("nhap ten sach: ");
    fgets(temp.ten_sach,sizeof(temp.ten_sach),stdin);
    printf("nhap ten tac gia: ");
    fgets(temp.ten_tac_gia,sizeof(temp.ten_tac_gia),stdin);
    fflush(stdin);
    printf("nhap nam san xuat: ");
    scanf("%d",&temp.nam_xuat_ban);
    fflush(stdin);
    printf("Nhap nha san xuat: ");
    fgets(temp.nha_san_xuat,sizeof(temp.nha_san_xuat),stdin);
    printf("nhap the loai: ");
    fgets(temp.the_loai,sizeof(temp.the_loai),stdin);
    printf("nhap gia tien: ");
    scanf("%d",&temp.gia_tien);
    temp.so_luong_ban = 0;
    return temp;
};

struct Node_Sach* taoNode(){
    struct Node_Sach *p = (struct Node_Sach*)malloc(sizeof(struct Node_Sach));
    p->data = themDataSach();
    p->pNext = NULL;
    return p;
}

struct list_sach{
    struct Node_Sach *pHead;
    struct Node_Sach *pTail;
};

void taoList(struct list_sach *l){
    (*l).pHead = NULL;
    (*l).pTail = NULL;
}
//--list sach
struct list_sach listSach;
//-----------lich su mua hang

struct LichSuMuaHang
{
    struct Node_LichSuMuaHang *pHead;
    struct Node_LichSuMuaHang *pTail;
};

struct Node_LichSuMuaHang
{
    char id_sach[MAX_ID];
    char ten_sach[MAX_NAME];
    int so_luong_ban;
    struct Node_Sach *pNext;
};

struct Node_LichSuMuaHang* taoNodeLichSu(struct list_sach *list){
    char key;
    struct Node_LichSuMuaHang *p = (struct Node_LichSuMuaHang*)malloc(sizeof(struct Node_LichSuMuaHang));
    printf("\nnhap lich su mua hang (yeu cau ban nhap chinh xac id sach): \n");
    fflush(stdin);
    printf("\nnhap id: ");
    fgets(p->id_sach,sizeof(p->id_sach),stdin);
    bool check = false;
    struct Node_Sach* p1 = list->pHead;
    do{
        if(strcmpi(p->id_sach,p1->data.id_sach)==0){
            strcpy(p->ten_sach,p1->data.ten_sach);
            printf("nhap so luong mua: ");
            scanf("%d",&p->so_luong_ban);
            p1->data.so_luong_ban += p->so_luong_ban;
            check = true;
            fflush(stdin);
            break;
        }
        p1=p1->pNext;
    }while(p1!=NULL);
    if(!check){
        printf("\nid sach khong khop");
    }
    p->pNext = NULL;
    return p;
}

void taoLichSuMuahang(struct LichSuMuaHang *l){
    (*l).pHead = NULL;
    (*l).pTail = NULL;
}

//---------------lich su mua hang
struct SinhNhat
{
    int ngay;
    int thang;
};

struct KhachHang
{
    char ho_ten[MAX_NAME];
    char sdt[10];
    char dia_chi[MAX_ADD];
    struct SinhNhat sinh_nhat;
    int tuoi;
    struct LichSuMuaHang lsmh;
    char phan_hoi[MAX_PH];
};

//-------------------------------------list khach
struct Node_Khach
{
    struct KhachHang data;
    struct Node_Khach *pNext;
};

struct KhachHang themDataKhach(){
    struct KhachHang temp;
    char key0;
    fflush(stdin);
    printf("nhap ten khach hang: ");
    fgets(temp.ho_ten,sizeof(temp.ho_ten),stdin);
    printf("nhap so dien thoai cua khach: ");
    fgets(temp.sdt,sizeof(temp.sdt),stdin);
    fflush(stdin);
    printf("nhap dia chi khach hang: ");
    fgets(temp.dia_chi,sizeof(temp.dia_chi),stdin);
    fflush(stdin);
    printf("Nhap sinh nhat khach: ");
    printf("nhap ngay sinh: "); scanf("%d",&temp.sinh_nhat.ngay); fflush(stdin);
    printf("nhap thang sinh: "); scanf("%d",&temp.sinh_nhat.thang); fflush(stdin);
    printf("nhap tuoi: ");
    scanf("%d",&temp.tuoi);
    fflush(stdin);
    printf("nhap phan hoi: ");
    fgets(temp.phan_hoi,sizeof(temp.phan_hoi),stdin);
    fflush(stdin);
    printf("khach hang co lich su mua hang khong? [y/n]");
    key0 = getch();
    if(key0 == 'y'){
        struct LichSuMuaHang temp1;
        taoLichSuMuahang(&temp1);
        do{
            printf("\n-----------------------\n");
            printf("\nnhap lich su mua hang: \n");
        if(temp1.pHead==NULL){
            temp1.pHead = taoNodeLichSu(&listSach);
            temp1.pHead->pNext = temp1.pTail;
        }else{
            struct Node_LichSuMuaHang* temp2 = taoNodeLichSu(&listSach);
            temp1.pTail = temp2;
            temp1.pHead->pNext = temp2;
        }
        printf("\nban co muon nhap them lich su mua hang nua khong? [y/n]");
        key0 = getch();
    }while(key0!='n');
    temp.lsmh = temp1;
    }
    return temp;
};

struct Node_Khach* taoNodeKhach(){
    struct Node_Khach *p = (struct Node_Khach*)malloc(sizeof(struct Node_Khach));
    p->data = themDataKhach();
    p->pNext = NULL;
    return p;
}

struct list_khach{
    struct Node_Khach *pHead;
    struct Node_Khach *pTail;
};

void taoListKhach(struct list_khach *l){
    (*l).pHead = NULL;
    (*l).pTail = NULL;
}
//----------------------------list khach

void menu(){
    printf("\t\tMenu tinh nang chuong trinh:\n");
    printf("\t1. hien thi du lieu sach\n");
    printf("\t2. tim kiem sach theo ten tac gia\n");
    printf("\t3. tim kiem sach theo ten the loai\n");
    printf("\t4. liet ke danh sach tieu thu\n");
    printf("\t5. liet ke danh sach khach hang\n");
    printf("\t6. ket thuc chuong trinh\n");
    printf("--------------------------------------------------------------------------\n");
}

int main()
{
    char key0;
    char key1;
    char key2;
    taoList(&listSach);
    struct list_khach listKhach;
    taoListKhach(&listKhach);

    printf("khoi tao du lieu sach...\n");
    do{
        printf("\n-----------------------\n");
        printf("\nnhap du lieu sach: \n");
        if(listSach.pHead==NULL){
            listSach.pHead = taoNode();
            listSach.pHead->pNext = listSach.pTail;
        }else{
            struct Node_Sach* temp = taoNode();
            listSach.pTail = temp;
            listSach.pHead->pNext = temp;
        }
        printf("ban co muon nhap them nua khong? [y/n]");
        key0 = getch();
    }while(key0!='n');
    printf("\n-----------------------\n");
    printf("\nkhoi tao du lieu khach hang...\n");
    do{
        printf("\n-----------------------\n");
        printf("\nnhap du lieu khach hang: \n");
        if(listKhach.pHead==NULL){
            listKhach.pHead = taoNodeKhach();
            listKhach.pHead->pNext = listKhach.pTail;
        }else{
            struct Node_Khach* temp = taoNodeKhach();
            listKhach.pTail = temp;
            listKhach.pHead->pNext = temp;
        }
        printf("\nban co muon nhap them khach hang nua khong? [y/n]");
        key0 = getch();
    }while(key0!='n');
    printf("\n-----------------------\n");
    Sleep(500);
    do{
        system("cls");
        menu();
        printf("\nmoi ban chon chuc nang: \n");
        key1 = getch();
        switch(key1)
        {
        case '1':
            {
                printf("\n----------------------------------------------------------------------------\n");
                struct Node_Sach* p = listSach.pHead;
                do{
                    printf("-----------\n");
                    printf("ID Sach: %s\n",p->data.id_sach);
                    printf("Ten Sach: %s\n",p->data.ten_sach);
                    printf("Ten Tac Gia: %s\n",p->data.ten_tac_gia);
                    printf("The Loai: %s\n",p->data.the_loai);
                    printf("Nam Xuat Ban: %d\n",p->data.nam_xuat_ban);
                    printf("Nha Xuat Ban: %s\n",p->data.nha_san_xuat);
                    printf("Gia Tien: %d\n",p->data.gia_tien);
                    printf("-----------\n");
                    p = p->pNext;
                }while(p != NULL);
                printf("----------------------------------------------------------------------------\n");
                break;
            }
        case '2':
            {
                printf("\n----------------------------------------------------------------------------\n");
                char ten[MAX_NAME];
                bool check = false;
                fflush(stdin);
                printf("\nnhap ten tac gia can tim kiem: ");
                fgets(ten,sizeof(ten),stdin);
                struct Node_Sach* p = listSach.pHead;
                do{
                    if(strcmpi(ten,p->data.ten_tac_gia)==0){
                        printf("thong tin sach ban can:\n");
                        printf("-----------\n");
                    printf("ID Sach: %s\n",p->data.id_sach);
                    printf("Ten Sach: %s\n",p->data.ten_sach);
                    printf("Ten Tac Gia: %s\n",p->data.ten_tac_gia);
                    printf("The Loai: %s\n",p->data.the_loai);
                    printf("Nam Xuat Ban: %d\n",p->data.nam_xuat_ban);
                    printf("Nha Xuat Ban: %s\n",p->data.nha_san_xuat);
                    printf("Gia Tien: %d\n",p->data.gia_tien);
                    printf("-----------\n");
                    check = true;
                    }
                    p = p->pNext;
                }while(p!=NULL);
                if(!check){
                    printf("khong tim thay sach cua tac gia tren!!\n");
                }
                printf("----------------------------------------------------------------------------\n");
                break;
            }
        case '3':
            {
                printf("----------------------------------------------------------------------------\n");
                char ten[MAX_NAME];
                bool check = false;
                fflush(stdin);
                printf("\nnhap ten the loai can tim kiem: ");
                fgets(ten,sizeof(ten),stdin);
                struct Node_Sach* p = listSach.pHead;
                do{
                    if(strcmpi(ten,p->data.the_loai)==0){
                        printf("thong tin sach ban can:\n");
                        printf("-----------\n");
                    printf("ID Sach: %s\n",p->data.id_sach);
                    printf("Ten Sach: %s\n",p->data.ten_sach);
                    printf("Ten Tac Gia: %s\n",p->data.ten_tac_gia);
                    printf("The Loai: %s\n",p->data.the_loai);
                    printf("Nam Xuat Ban: %d\n",p->data.nam_xuat_ban);
                    printf("Nha Xuat Ban: %s\n",p->data.nha_san_xuat);
                    printf("Gia Tien: %d\n",p->data.gia_tien);
                    printf("-----------\n");
                    check = true;
                    }
                    p = p->pNext;
                }while(p!=NULL);
                if(!check){
                    printf("khong tim thay sach thuoc the loai tren!!\n");
                }
                printf("----------------------------------------------------------------------------\n");
                break;
            }
        case '4':
            {
                printf("----------------------------------------------------------------------------\n");
                bool check = false;
                struct Node_Sach* p = listSach.pHead;
                printf("\ndanh sach tieu thu: \n");
                do{
                    if(p->data.so_luong_ban!=0){
                        printf("Ten sach: %s, so luong ban: %d\n",p->data.ten_sach,p->data.so_luong_ban);
                        check = true;
                    }
                    p = p->pNext;
                }while(p!=NULL);
                if(!check){
                    printf("chua co sach nao duoc ban!!\n");
                }
                printf("----------------------------------------------------------------------------\n");
                break;
            }
        case '5':
            {
                printf("\n----------------------------------------------------------------------------\n");
                printf("danh sach khach hang:\n");
                struct Node_Khach* p = listKhach.pHead;
                do{
                    printf("-----------\n");
                    printf("Ho ten: %s\n",p->data.ho_ten);
                    printf("Dia chi: %s\n",p->data.dia_chi);
                    printf("So dien thoai: %s\n",p->data.sdt);
                    printf("Sinh nhat: %d/%d\n",p->data.sinh_nhat.ngay,p->data.sinh_nhat.thang);
                    printf("Tuoi: %d\n",p->data.tuoi);
                    printf("Phan hoi: %s\n",p->data.phan_hoi);
                    printf("Lich su mua hang: \n");
                    struct Node_LichSuMuaHang *p1 = p->data.lsmh.pHead;
                    do{
                        printf("- ID: %s\n",p1->id_sach);
                        printf("- Ten sach: %s\n",p1->ten_sach);
                        printf("- So luong: %d\n",p1->so_luong_ban);
                        printf("-----------\n");
                        p1=p1->pNext;
                    }while(p1!=NULL);
                    printf("-----------\n");
                    p = p->pNext;
                }while(p != NULL);
                printf("----------------------------------------------------------------------------\n");
                break;
            }
        }
        printf("\nbam phim bat ki de tiep tuc hoac bam 6 de thoat\n");
        key2 = getch();
    }while(key1!='6' && key2 != '6');
    printf("\nKET THUC CHUONG TRINH");
}
