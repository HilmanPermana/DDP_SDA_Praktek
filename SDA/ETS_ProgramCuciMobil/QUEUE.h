#ifndef QUEUE_H
#define QUEUE_H

#define Nil NULL
#define MerkMobil(P) (P)->merkmobil
#define Lanjut(P) (P)->lanjut
#define Kedatangan(P) (P)->kedatangan
#define Dilayani(P) (P)->dilayani
#define Selesai(P) (P)->selesai
#define Jenis(L) (L)->jenis
#define Loket(L) (L)->loket
#define First(L) (L).First

#include "waktu.h"

typedef const char* DinamisChar;
typedef struct tElmtMobil *Alamat;
typedef struct tElmtMobil {
	 DinamisChar merkmobil;
	 Alamat lanjut;
	 waktu kedatangan;
	 waktu dilayani;
	 waktu selesai;
	 char jenis;
	 int loket;
	 } ElmtMobil;
	 
/* Definisi list : */
/* List kosong ===> First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu info(P) dan Next(P);  */
/* Elemen terakhir list ===> Jika addressnya Last maka Next(Last) = Nil */	 
typedef struct {
      Alamat First;
} List;

/*********** PROTOTYPE ****************/
/**** Predikat untuk test keadaan LIST  ****/
bool ListEmpty (List L);
/* Mengirim true jika List Kosong */

/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List * L);
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */

/**** Manajemen Memory ****/
Alamat Alokasi (DinamisChar X, waktu kedatangan, waktu dilayani, waktu start, char jenis, int loket);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void DeAlokasi (Alamat P);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void Enqueue (List * L, DinamisChar X, waktu kedatangan, waktu dilayani, waktu start, char jenis, int loket);
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */

/**** Penghapusan sebuah elemen ****/
void Dequeue (List * L, DinamisChar * X);
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List * L, Alamat P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */

void InsertAfter (List * L, Alamat P, Alamat Prec);
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertLast (List * L, Alamat P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */

/**** Penghapusan sebuah elemen berdasarkan alamat ****/
void Delete (List * L, Alamat * P);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama *

/**** PROSES SEMUA ELEMEN LIST  ****/
void PrintInfo (List L);
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */

int TotElemenList (List L);
/* Mengembalikan jumlah node pada list L*/

#endif
