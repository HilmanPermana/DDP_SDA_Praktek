
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


/*********** PROTOTYPE ****************/
/**** Predikat untuk test keadaan LIST  ****/
bool ListEmpty (List L) {
    return (First(L)==Nil);
}

/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List * L) {
	First(*L)=Nil;
}

/**** Manajemen Memory ****/
Alamat Alokasi (DinamisChar X, waktu kedatangan, waktu dilayani, waktu selesai, char jenis, int loket) {
	/*Kamus Data: */
    Alamat P;

    P = (Alamat)malloc(sizeof(ElmtMobil));
    if (P!=Nil){
        MerkMobil(P) = X;
        Jenis(P) = jenis;
        Loket(P) = loket;
        Kedatangan(P) = kedatangan;
        Dilayani(P) = dilayani;
        Selesai(P) = selesai;
        Lanjut(P) = Nil;
    }
    return P;
}

void DeAlokasi (Alamat P) {
	free(P);
}

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void Enqueue (List * L, DinamisChar X, waktu kedatangan, waktu dilayani, waktu selesai, char jenis, int loket) {
	/*Kamus Data: */
	Alamat P;
	
	P = Alokasi(X, kedatangan, dilayani, selesai, jenis, loket);
	if(P != Nil){
		InsertLast(L,P);
	}
}

/**** Penghapusan Elemen ****/
void Dequeue (List * L, DinamisChar * X) {
	/*Kamus Data: */
	Alamat P;
	
	Delete(L, &P);
	*X = MerkMobil(P);
	Lanjut(P) = Nil;
	DeAlokasi(P);
}

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List * L, Alamat P) {
	Lanjut(P) = First(*L);
	First(*L) = P;
}

void InsertAfter (List * L, Alamat P, Alamat Prec) {
    Lanjut(P) = Lanjut(Prec);
    Lanjut(Prec) = P;
}

void InsertLast (List * L, Alamat P) {
	/*Kamus Data: */
    Alamat Last;

    if (First(*L)==Nil){
        InsertFirst(L,P);
    }else{
        Last = First(*L);
        while (Lanjut(Last)!=Nil){
            Last = Lanjut(Last);
        }
        InsertAfter(L, P, Last);
    }
}

/**** Penghapusan sebuah elemen berdasarkan alamat ****/
void Delete (List * L, Alamat * P) {
	*P = First(*L);
	First(*L) = Lanjut(First(*L));
}

/**** PROSES SEMUA ELEMEN LIST  ****/
void PrintInfo (List L) { 
	/*Kamus Data: */
	Alamat P;
	
	if(ListEmpty(L) == true){
		printf("Antrean kosong\n");
	}else{
		P = First(L);
		while(P != Nil){
			printf("\nMerkMobil: %s", &MerkMobil(P));
			printf("||Tipe Mobil: %c", Jenis(P));
			printf("||Loket Cuci: %d", Loket(P));
			printf("||Waktu Kedatangan: %02d.%02d", Kedatangan(P).jam, Kedatangan(P).menit);
			printf("||Waktu Mulai Dilayani: %02d.%02d", Dilayani(P).jam, Dilayani(P).menit);
			printf("||Waktu Selesai Dilayani: %02d.%02d", Selesai(P).jam, Selesai(P).menit);

			P = Lanjut(P);
		}
	}
}

int TotElemenList(List L){
	/*Kamus Data: */
    int jumlah;
    Alamat P;
    
    jumlah = 0;
    P = First(L);

    while(P!=Nil){
        jumlah++;
        P = Lanjut(P);
    }

    return jumlah;
}
