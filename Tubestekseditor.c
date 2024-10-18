//preprossesor
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"boolean.h"

#define nil NULL
#define info(p) (p)->info
#define next(p) (p)->next
#define first(L) (L).first

//Pembentukan typedata
typedef struct tElmList *address;

typedef struct tElmList{
	char info;
   address next;
}ElmList;

typedef struct{
	address first;
}List;

//Prototype
void CreateList(List *L);
//mebuat first menjadi nil

address Alokasi(char x);
// mengirim sebuah address hasil alokasi

void AddTeks(List *L, char X);
//menambah satu elemen x

void CetakList(List L);
//mencetak semua elemen yang ada di list

int MenghitungVocal(List L);
//Untuk menghitung jumlah huruf vokal

int MenghitungKata(List L);
//Untuk menghitung jumlah kata

void gotoxy(int x, int y);
//untuk posisi abs ord 

void setcolor(unsigned short color);
//Untuk merubah warna tulisan pada program

int cariinfo(List L, char x);
//mencari huruf berada di index

boolean search(List L, char x);
//mencari huruf ada atau tidaknya

boolean katasama(List L,char x);
//Mencari kata sama

int kata(List L,char x);
//Memberi info jumlah kata yang sama

//Main Driver
int main(){
	//kamus global
    List MyList,MyList1;
    char a,b,c,f;
    int i;
    boolean ketemu;
    //algoritma
    CreateList(&MyList);
    CreateList(&MyList1);
    system("cls");
	goto Home;
		Home:
		system("cls");
		setcolor(10);
  	gotoxy(33,2);printf("============ TEXT EDITOR SEDERHANA ==============");
  	gotoxy(33,7);printf("1. Menulis Teks");
  	gotoxy(33,8);printf("2. Tampilkan teks");
  	gotoxy(33,9);printf("3. Hitung teks");
  	gotoxy(33,10);printf("4. Search Teks");
  	gotoxy(33,11);printf("5. Exit");
	gotoxy(33,16);printf("Masukkan pilihan : "); scanf("%d", &i);
		system("cls");

		switch(i){
			case 1:	//Menu Menulis Teks
			setcolor(10);
      	gotoxy(33,1);printf("Tuliskan sebuah teks");
      	gotoxy(33,2);printf("Jika Sudah Selesai Pada Akhir Tulisan Memekai <.> ");
		gotoxy(33,5);scanf("%c",&b);
			while(b != '.'){
				AddTeks(&MyList,b);
				scanf("%c",&b);
			}
			printf("\n\tTekan 0 Untuk Kembali ke menu : "); scanf("%d", &c);
				if(c == 0){
					system("cls");
					goto Home;
				}else{
					break;
				}
			case 2:	//Menu tampil teks
			printf("\tTeks\n");
			CetakList(MyList);
			printf("\n");
			printf("\n\tTekan 0 Untuk Kembali ke menu : "); scanf("%d", &c);
				if(c == 0){
					system("cls");
					goto Home;
				}else{
					break;
				}
			case 3:	//Menu Hitung Teks
			printf("Menghitung Teks\n");
			CetakList(MyList);
			printf("\n");
			printf("Jumlah kata sama : %d",kata(MyList,b));
			printf("\njumlah vokal : %d",MenghitungVocal(MyList));
			printf("\njumlah Kata : %d",MenghitungKata(MyList));
			printf("\n");
			printf("\n\tTekan 0 Untuk Kembali ke menu : "); scanf("%d", &c);
				if(c == 0){
					system("cls");
					goto Home;
				}else{
					break;
				}
			case 4:	//Search Text
			CetakList(MyList);
			printf("\n");
			printf("Masukan Huruf Yang dicari : ");scanf("%s",&a);
			if(search(MyList,a) == true){
				printf("Huruf di index : %d",cariinfo(MyList,a));
				getch();
				system("cls");
			}else{
				printf("Huruf Tidak ada");
				getch();
				system("cls");
			}
			printf("\n");
			printf("\n\tTekan 0 Untuk Kembali ke menu : "); scanf("%d", &c);
				if(c == 0){
					system("cls");
					goto Home;
				}else{
					break;
				}	
			case 5://Exit	
            break;
		}
	getch();
	return 0;
}

// realisasi prototype ADT List
void CreateList(List *L){
	first(*L)=nil;
}

address Alokasi(char x){
	//kamus
   	address px;
	//algoritma
	px=(address)malloc(sizeof(ElmList));
	info(px)=x;
    next(px)=nil;
    return px;
}
void AddTeks(List *L, char X){
   //kamus
	address px;
    address awal;
   //algoritma
	px=Alokasi(X);
    awal=first(*L);
    if(awal==nil){
    	first(*L)=px;
	}else{
    	while(next(awal)!=nil){
        	awal=next(awal);
    	}
    next(awal)=px;
	}
}

void CetakList(List L) {
    // kamus
    address awal;
    // algoritma
    awal = first(L);
    while(awal != nil) {
        printf("%c", info(awal));
        awal = next(awal);
    }
    printf("\n");
}

int MenghitungVocal(List L){
    //kamus
	address awal;
	int i;
	//Algoritma
	i=0;
	awal=first(L);
	while(awal!=nil){
		if(info(awal)=='a'||info(awal)=='i'||info(awal)=='u'||info(awal)=='e'||info(awal)=='o'||info(awal)=='A'||info(awal)=='I'||info(awal)=='U'||info(awal)=='E'||info(awal)=='O'){
			i++;
			awal=next(awal);
		}else{
			awal=next(awal);
		}
	}
	return i;
}

int MenghitungKata(List L){
    //kamus
	address awal;
	int i;
	//algoritma
	i=1;
	awal=first(L);
	while(awal!=nil){
		if(info(awal)==' '){
			i++;
			awal=next(awal);
		}else{
			awal=next(awal);
		}
	}
	return i;
}

int cariinfo(List L, char x){
    //kamus
    address awal;
    boolean ketemu;
    int i;
    //algoritma
    i=-1;
    awal = first(L);
    ketemu = false;
    while(awal != nil && ketemu == false){
        if(info(awal) == x ){
            ketemu = true;
        }
        i++;
        awal=next(awal);
    }
    return i;
}

boolean search(List L, char x){
	//kamus
	address awal;
	boolean ketemu;
	//algoritma
	awal = first(L);
	ketemu = false;
	while(awal != nil && ketemu == false){
		if(info(awal) == x ){
			return true;
			ketemu = true;
		}
		awal=next(awal);
	}
}

boolean katasama(List L,char x){
	//kamus
	address awal;
	int i;
	boolean ket,ket1,ket2,ket3,ket4;
	//algoritma
	i=1;
	awal = first(L);
	ket = false;
	ket1 = false;
	ket2 = false;
	ket3 = false;
	ket4 = false;
	while(awal != nil){
		if(info(awal)== x && i == 1){
			ket = true;
		}else if(info(awal) == x && i == 2){
			ket1 = true;
		}else if(info(awal) == x && i == 3){
			ket2 = true;
		}else if(info(awal) == x && i == 4){
			ket3 = true;
		}else if(info(awal) == x && i == 5){
			ket4 = true;
		}
		awal=next(awal);
		i++;
	}
	if(ket == true && ket1 == true && ket2 == true && ket3 == true){
		return true;
	}else if(ket == true && ket1 == true && ket2 == true && ket3 == true && ket4 == true){
		return true;
	}
}

int kata(List L,char x){
	//kamus
	address awal;
	int i;
	//algoritma
	awal = first(L);
	while(awal != nil){
		if(katasama(L,x) == true){
			i=i+1;
		}
		awal=next(awal);
	}
	return i;
}

void gotoxy(int x, int y){
	static HANDLE h = NULL;
	if(!h);
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c={x,y};
	SetConsoleCursorPosition(h,c);
}

void setcolor(unsigned short color){
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}
