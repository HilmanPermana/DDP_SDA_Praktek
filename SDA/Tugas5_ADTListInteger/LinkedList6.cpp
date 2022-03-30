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

     /*==========================*/
	/*======= VALIDATOR ========*/
   /*==========================*/


/**** Predikat untuk test keadaan LIST  ****/
boolean ListEmpty (List L){
	
	return(First(L)==Nil);
}

/**** Manajemen Memory ****/
address Alokasi (infotype X){
	/* Kamus Lokal */
	address P;
	
	/* Algoritma */
	P = (address) malloc (sizeof(ElmtList));
	if(P != Nil){
		Info(P) = X;
		Next(P) = Nil;
		
		return P;
	} else {
		return Nil;
	}
	
}

/**** Pencarian sebuah elemen List ****/
address Search (List L, infotype X){

/* Kamus Lokal */
    address P;
    boolean Found;

    /* Algoritma */
    P = First(L);
    
    Found = false;
    while ((P != Nil) && (!Found)) {
      if (X == Info(P)) {
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

address SearchPrec (List L, infotype X){

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
        if (X == Info(Next(P))) {
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
	

	 /*==========================*/
	/*====== KONSTRUKTUR =======*/
   /*==========================*/

/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List *L){
	
	/* Algoritma */
	First(*L) = Nil;
	
}

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVFirst (List * L, infotype X){

	/* Kamus Lokal */
    address P;
    
    /* Algoritma */
    P = Alokasi(X);
    if (P != Nil) {
      InsertFirst(L,P);
    }

}
 
void InsVLast (List * L, infotype X){

/* Kamus Lokal */
    address P;

    /* Algoritma */
    P = Alokasi(X);
    if (P != Nil) {
      InsertLast(L,P);
    }
 
}
 
 /**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List * L, address P){

	/* Kamus Lokal */

    /* Algoritma */
    Next(P) = First(*L);
    First(*L) = P;

}
 	
void InsertAfter (List * L, address P, address Prec){

  /* Kamus Lokal */

  /* Algoritma */
  Next(P) = Next(Prec);
  Next(Prec) = P;

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
	 /*==========================*/
	/*====== DESTRUCTOR ========*/
   /*==========================*/

void DeAlokasi (address *P){
   
	/* Kamus Lokal */
    
    /* Algoritma */
    free(*P);
}

/**** Penghapusan Elemen ****/
void DelVFirst (List * L, infotype * X){

	/* Kamus Lokal */
    address P;

    /* Algoritma */
    P = First(*L);
    (*X) = Info(P);
    First(*L) = Next(First(*L));
    Next(P) = Nil;
    DeAlokasi(&P);

}

void DelVLast (List * L, infotype * X){
	
 	/* Kamus Lokal */
    address P;

    /* Algoritma */
    DelLast(L,&P);
    (*X) = Info(P);
    DeAlokasi(&P);


}

/**** Penghapusan sebuah elemen ****/
void DelFirst (List * L, address * P){

 	/* Kamus Lokal */

    /* Algoritma */
    *P = First(*L);
    First(*L) = Next(First(*L));

}

void DelP (List * L, infotype X){

 /* Kamus Lokal */
  address P, Prec;
  infotype Y;
  boolean kehapus;
  /* Algoritma*/
  kehapus = false;
  P = First(*L);
  if (Info(P) == X) {
    DelVFirst(L,&Y);
  } else {
    Prec = Nil;
    while ((P != Nil)&&(!kehapus)) {
      if (Info(P) == X) {
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
    if (ListEmpty(L)) {
      printf("List kosong\n");
    } else {
      while (Next(P) != Nil) {
        printf("%d ",Info(P));
        P = Next(P);
      }
      printf("%d\n", Info(P));
    }
}

/* ----- Implementasi Prosedur / Fungsi ----- */
void Menu() {
 /* Kamus Lokal */

 /* Algoritma */
 system("cls");
 printf("\t\t\t\t\t PROGRAM LIST LINIER SDA Praktek ");
 printf("\n\t\t\t\t------- ---- ------ ----- --------- ----- -------\n");
 printf("\t\t\t\t\t\t------ Menu ------\n\n");
 printf("\t\t\t\t1. 	Mencari Alamat Elemen Tertentu\n");
 printf("\t\t\t\t2. 	Mencari Alamat Sebelum Elemen Tertentu\n");
 printf("\t\t\t\t3. 	Memasukkan Suatu Elemen pada Depan List\n");
 printf("\t\t\t\t4. 	Memasukkan Suatu Elemen pada Belakang List\n");
 printf("\t\t\t\t5. 	Menghapus Elemen yang Berada di Depan List\n");
 printf("\t\t\t\t6. 	Menghapus Elemen yang Berada di Belakang List\n");
 printf("\t\t\t\t7. 	Menghapus Alamat Sesuai dengan Elemen yang Ditentukan\n");
 printf("\t\t\t\t8. 	Tampilkan isi list\n");
 printf("\t\t\t\t9. 	Menghapus Seluruh Elemen\n");
 printf("\t\t\t\t10. 	Exit\n");
 printf("\n\n\t\tPilihan : ");
 
}


