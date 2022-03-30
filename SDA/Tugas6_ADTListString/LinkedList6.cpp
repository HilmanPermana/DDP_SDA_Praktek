/* ANGGOTA KELOMPOK */

/* 
	Nama	: Achmadya Ridwan Ilyawan
   	NIM		: 211511001
   	Nama	: Hilman Permana
   	NIM		: 211511015
   	Tgl Pembuatan	: 6 Maret - 9 Maret 2022
*/

/* ----- File Include ----- */
#include "boolean.h"
#include "SpNRSLL.H"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


     /*==========================*/
	/*======= VALIDATOR ========*/
   /*==========================*/

/**** Predikat untuk test keadaan LIST  ****/
boolean ListEmpty (List L){
	
	return(First(L)==Nil);
}

/**** Manajemen Memory ****/
address Alokasi (alfanumerik X[]){

		/* Kamus Lokal */
	address P;
	
	/* Algoritma */
	P = (address) malloc (sizeof(ElmtList));
	if(P != Nil){
		strcpy(Info(P), X);
		Next(P) = Nil;
		return P;
	} else {
		printf("Alokasi Gagal\n");
		return Nil;
	}
}

/**** Pencarian sebuah elemen List ****/
address Search (List L, alfanumerik X[]){

/* Kamus Lokal */
    address P;
    boolean Found;

    /* Algoritma */
    P = First(L);
    
    Found = false;
    while ((P != Nil) && (!Found)) {
      if (strcmp(X, Info(P))==0){
        Found = true;
      } else {
        P = Next(P);
      }
    }
    return P;

}
	 
boolean FSearch (List L, address P){

/* Kamus Lokal */
    address Pcek;
    boolean ketemu;

    /* Algoritma */
    Pcek = First(L);
    ketemu = false;
    while ((Pcek != Nil) && (!ketemu)) {
		if (Pcek == P) {
			ketemu = true;
		} else {
			Pcek = Next(Pcek);
		}
    }
    return ketemu;

}

address SearchPrec (List L, alfanumerik X[]){

	/* Kamus Lokal */
    address P;
    boolean Found;

    /* Algoritma */
    P = First(L);
    Found = false;
    if (P == Nil) {
      return Nil;
    } else {
      while ((Next(P) != Nil) && (!Found)) {
        if (strcmp(X, Info(Next(P)))==0) {
          Found = true;
        } else {
          P = Next(P);
       }
      }
    }
    if (Next(P) == Nil) {
      return Nil;
    } else {
      return P;
    }
}

int ReturnTotElemen(List L){
	
	/* Kamus Lokal*/
	int jumlah = 0;
	address P;
	
	P = First(L);
	
	while(P != Nil){
		jumlah++;
		P = Next(P);
	}
	
	return jumlah;
}
	

	 /*==========================*/
	/*====== KONSTRUKTUR =======*/
   /*==========================*/

/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List *L, char A[]){
	
	/* Algoritma */
	First(*L) = Nil;
	strcpy(kota(*L), A);
	
}

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVFirst (List * L, alfanumerik X[]){

	/* Kamus Lokal */
    address P;
    
    /* Algoritma */
    P = Alokasi(X);
    if (P != Nil) {
      InsertFirst(L,P);
    }

}
 
void InsVLast (List * L, alfanumerik X[]){

/* Kamus Lokal */
    address P;

    /* Algoritma */
    P = Alokasi(X);
    if (P != Nil) {
      InsertLast(L,P);
    }
 
}

void InsVMiddle (List * L, alfanumerik X[]){
	
	/*Kamus Lokal*/
	address P;
	
	P = Alokasi(X);
	if(P != Nil){
		InsertMiddle(L,P);
	}
}
 
 /**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List * L, address P){

	/* Kamus Lokal */
	
    /* Algoritma */
    Next(P) = First(*L);
    First(*L) = P;
	printf("%s\n", Info(P));
	}
 
 	
void InsertAfter (List * L, address P, address Prec){

  /* Kamus Lokal */

  /* Algoritma */
  Next(P) = Next(Prec);
  Next(Prec) = P;
  printf("%s\n", Info(P));

}
	 
	 	 
void InsertLast (List * L, address P){

	 /* Kamus Lokal */
    address Last;
    
    /* Algoritma */
    Last = First(*L);
    if (First(*L) == Nil) {
      InsertFirst(L,P);
    } else {
      while (Next(Last) != Nil) {
        Last = Next(Last);
      }
      InsertAfter(L,P,Last);
    }
	
}

void InsertMiddle(List * L, address P){
	
	/*Kamus Lokal*/
	address mid;
	int ulang;
	int hitung = 1;
	ulang = ReturnTotElemen(*L);
	
	if(First(*L) == Nil){
		
		InsertFirst(L,P);
		
	} else {
		mid = First(*L);
		while(hitung < ulang/2){
			mid = Next(mid);
			hitung ++;
		}
		
		Next(P) = Next(mid);
		Next(mid) = P;
		
	}
	printf("%s\n", Info(P));
}

	 /*==========================*/
	/*====== DESTRUCTOR ========*/
   /*==========================*/

void DeAlokasi (address *P){
   
	/* Kamus Lokal */
    
    /* Algoritma */
    free(*P);
}

/**** Penghapusan Elemen ****/
void DelVFirst (List * L, alfanumerik  X[]){

	/* Kamus Lokal */
    address P;

    /* Algoritma */
    P = First(*L);
    strcpy(X, Info(P));
    First(*L) = Next(First(*L));
    Next(P) = Nil;
    DeAlokasi(&P);
    printf("Elemen yang dihapus : %s\n", X);

}

void DelVLast (List * L, alfanumerik  X[]){
	
 	/* Kamus Lokal */
    address P;

    /* Algoritma */
    DelLast(L,&P);
    strcpy(X, Info(P));
    DeAlokasi(&P);
	printf("Elemen yang dihapus : %s\n", X);

}

/**** Penghapusan sebuah elemen ****/
void DelFirst (List * L, address * P){

 	/* Kamus Lokal */

    /* Algoritma */
    *P = First(*L);
    First(*L) = Next(First(*L));

}

void DelP (List * L, alfanumerik X[]){

 /* Kamus Lokal */
  address P, Prec;
  alfanumerik Y;
  boolean kehapus;
  /* Algoritma*/
  kehapus = false;
  P = First(*L);
  if (strcmp(Info(P), X)==0) {
    DelVFirst(L,&Y);
  } else {
    Prec = Nil;
    while ((P != Nil)&&(!kehapus)) {
      if (strcmp(Info(P), X)==0) {
        DelAfter(L,&P,Prec);
        DeAlokasi(&P);
        kehapus = true;
      } else {
        Prec = P;
        P = Next(P);
      }
    }
  }
}

void DelLast (List * L, address * P){

 /* Kamus Lokal */
  address Last, PrecLast;
  
  /* Algoritma */
  Last = First(*L);
  PrecLast = Nil;
  while (Next(Last) != Nil) {
    PrecLast = Last;
    Last = Next(Last);;
  }
  *P = Last;
  if (PrecLast == Nil) {
    First(*L) = Nil;
  } else {
    Next(PrecLast) = Nil;
  }

}

void DelAfter (List * L, address * Pdel, address Prec){

  	/* Kamus Lokal */

    /* Algoritma */
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = Nil;

}

/***************************************/
/*******  PROSES TERHADAP LIST  ********/
/***************************************/

void DelAll (List * L){

 /* Kamus Lokal */
    address P;

    /* Algoritma */
    P = First(*L);
    while (P != Nil) {
      First(*L) = Next(First(*L));
      Next(P) = Nil;
      DeAlokasi(&P);
      P = First(*L);
    }

}

     /*==========================*/
	/*=========== I/O ==========*/
   /*==========================*/
   
/**** PROSES SEMUA ELEMEN LIST  ****/
void PrintInfo (List L){

	/* Kamus Lokal */
    address P;

    /* Algoritma */
    P = First(L);
    First(L);
    if (ListEmpty (L)) {
        printf("%s \n", kota(L));
    } else {
        printf("%s ", kota(L));
        while (Next(P) != Nil) {
            printf("%s, ",Info(P));
            P = Next(P);
        }
        printf("%s\n", Info(P));
    }
}

void input(char ch[15]){
	fgets(ch,15,stdin);
	ch[strlen(ch) - 1] = 0; 
}

void Menu() {
 /* Kamus Lokal */

 /* Algoritma */
 system("cls");
 printf("\t\t\t\t\t PROGRAM LINKED LIST == DEQUEU ==  ");
 printf("\n\t\t\t\t------- ---- ------ ----- --------- ----- -------\n");
 printf("\t\t\t\t\t\t------ Menu ------\n\n");
 printf("\t\t\t\t1. 	Insert Elemen di Depan List\n");
 printf("\t\t\t\t2. 	Insert Elemen di Belakang List\n");
 printf("\t\t\t\t3. 	Insert Elemen di Tengah List\n");
 printf("\t\t\t\t4. 	Mencari Alamat Elemen Tertentu\n");
 printf("\t\t\t\t5. 	Mencari Alamat Sebelum Elemen Tertentu\n");
 printf("\t\t\t\t6. 	Menghapus Elemen yang Berada di Depan List\n");
 printf("\t\t\t\t7. 	Menghapus Elemen yang Berada di Belakang List\n");
 printf("\t\t\t\t8. 	Menghapus Elemen yang Ditentukan\n");
 printf("\t\t\t\t9. 	Menghapus Seluruh Elemen\n");
 printf("\t\t\t\t10. 	Tampilkan isi list\n");
 printf("\t\t\t\t11. 	Exit\n");
 printf("\n\n\t\tPilihan : ");
 
}

void MenuQueue(){
	
	/* Algoritma */
 system("cls");
 printf("\t\t\t\t\t PROGRAM LINKED LIST [  QUEUE  ]  ");
 printf("\n\t\t\t\t------- ---- ------ ----- --------- ----- -------\n");
 printf("\t\t\t\t\t\t------ Menu ------\n\n");
 printf("\t\t\t\t1. 	Insert Queue\n");
 printf("\t\t\t\t2. 	Delete Queue\n");
 printf("\t\t\t\t3. 	Tampilkan QUeue\n");
 printf("\t\t\t\t4. 	Exit\n");
 printf("\n\n\t\tPilihan : ");
 
}

void MenuStack(){
	
	/* Algoritma */
 system("cls");
 printf("\t\t\t\t\t PROGRAM LINKED LIST [  STACK  ] ");
 printf("\n\t\t\t\t------- ---- ------ ----- --------- ----- -------\n");
 printf("\t\t\t\t\t\t------ Menu ------\n\n");
 printf("\t\t\t\t1. 	Insert Stack\n");
 printf("\t\t\t\t2. 	Delete Stack\n");
 printf("\t\t\t\t3. 	Tampilkan Stack\n");
 printf("\t\t\t\t4. 	Exit\n");
 printf("\n\n\t\tPilihan : ");
 
}


