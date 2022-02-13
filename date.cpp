/* File        : date.cpp */
/* Deskripsi   : Unit untuk keperluan ADT Date */

/***************************/
/*  BODY PRIMITIF DATE     */
/***************************/

#include <stdio.h>
#include <math.h>
#include "date.h"


/*********** Operasi Primitif ************/
void CreateDate (date * D)
/* Constructor Membentuk sebuah DATE, dengan nilai default adalah 01/01/1900 */
{
		SetTgl ((* D).Tgl, &(* D));
		SetBln ((* D).Bln, &(* D));
		SetThn ((* D).Thn, &(* D));
}

/******* Selector komponen **********/
int GetTgl (date D)
/* Mengambil bagian Tgl dari date */
{
	return(D.Tgl);
}

int GetBln (date D)
/* Mengambil bagian Bln dari date */
{
	return(D.Bln);
}


int GetThn (date D)
/* Mengambil bagian Thn dari date */
{
	return(D.Thn);
}


/****** Pengubah komponen ******/
void SetTgl (int NewTgl, date * D)
/* Memberi nilai untuk Tgl */
{
	(* D).Tgl = NewTgl;
}

void SetBln (int NewBln, date * D)
/* Memberi nilai untuk Bln */
{
	(* D).Bln = NewBln;
}


void SetThn (int NewThn, date * D)
/* Memberi nilai untuk Thn */
{
	(* D).Thn = NewThn;
}


/****** Kelompok Interaksi dengan I/O device, BACA/TULIS ******/
void BacaDate (date * D)
/* Membentuk DATE dari iTgl, iBln dan iThn yang dibaca dari keyboard */
{
	int InTgl,InBln,InThn;
	
	printf(" Masukkan Tgl  : ");
	scanf("%d",&InTgl);
	SetTgl(InTgl, D);
	
	printf("\n Masukkan Bulan (Dengan angka) : ");
	scanf("%d",&InBln);
	SetBln(InBln, D);
	
	printf("\n Masukkan Tahun : ");
	scanf("%d",&InThn);
	SetThn(InThn, D);
	
}

bool isValid(date D)
/* Memeriksa apakah suatu tanggal valid, yaitu dengan memperhatikan batas akhir per bulan */
{
	if ((GetThn(D) < 1900)||(GetThn(D) > 30000)||(GetBln(D) < 1) ||(GetBln(D) > 12)||(GetTgl(D) < 1)||(GetTgl(D) > TglAkhir(D)))
		return (false);
	else
		return (true);
}

void PrintObj (date D)
/* Print nilai D dengan format dd/mm/yyyy */
{
		
    if ((isKabisat(D)) && isValid(D) && (D.Tgl == 29)){
    	
    	printf(" TAHUN KABISAT <><><><> %d/%d/%d <><><><>\n", GetTgl(D), GetBln(D), GetThn(D));
    	
    } else if (isValid(D)){
		
		printf("\n   <><><> %d/%d/%d <><><>\n", GetTgl(D), GetBln(D), GetThn(D));
		
	} else {
		
		printf(" ERROR 'Data yang dimasukkan tidak sesuai' !!!");
		
	}
}

/****** Operator Relasional ******/
bool isKabisat(date D)
/* Memeriksa apakah suatu tanggal adalah kabisat; Dipakai untuk bulan == 2 saja
Harusnya kabisat adalah thn yang habis dibagi 4, atau habis dibagi 100 dan 400, tapi implementasinya seringkali hanya menggunakan 4 sebagai pembagi */
{
	if((D.Bln == 2)&&((D.Thn % 4 == 0)||(D.Thn % 100 == 0)||(D.Thn % 400 == 0))){ 
		return (true);
	} else {
		return (false);
	}
}

/***** Predikat lain *******/
int TglAkhir (date D)
/* Memberikan tanggal terakhir dari sebuah bulan */
{
	int TAkhir;
	
	if((D.Bln % 2 == 0) && (D.Bln != 2) && (D.Bln != 12)){ //Bulan Genap kecuali februari dan februari
		TAkhir = 30;	
	} else if((D.Bln % 2 == 1) || (D.Bln == 12)){ //Bulan Ganjil
		TAkhir = 31;
	} else if((D.Bln == 2) && (D.Thn % 4 != 0)){
		TAkhir = 28;
	} else if(isKabisat(D)){
		TAkhir = 29;
	} 
	
	return TAkhir;
	
}

void DateBefore (date D)
/* Menampilkan tanggal sebelumnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal sebelumnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika jan, thn-1 */
{
	
	if(isValid(D)){
		
	
	
		if((D.Bln == 1) && (D.Tgl == 1)){ // Tanggal sebelum tahun baru
		
			printf(" \nTanggal sebelumnya %d/%d/%d\n", GetTgl(D) + 30, GetBln(D) + 11, GetThn(D) - 1);
		
		} else if ((D.Thn % 4 == 0) && (D.Bln == 3) && (D.Tgl == 1 )){  //Tahun kabisat, tgl diketahui 1 maret
	
		 	printf(" \nTanggal sebelumnya %d/%d/%d\n", GetTgl(D) + 28, GetBln(D) - 1, GetThn(D));
		
    	} else if ((D.Bln != 2) && (D.Bln % 2 == 0) && (D.Tgl == 1)){ //Bulan genap tgl 1
    		
    		printf(" \nTanggal sebelumnya %d/%d/%d\n", GetTgl(D) + 30 , GetBln(D) - 1, GetThn(D));
    
		} else if ((D.Thn % 4 != 0) && (D.Bln % 2 == 1) && (D.Tgl == 1)){ //Bulan ganjil tgl 1
    		
    		printf(" \nTanggal sebelumnya %d/%d/%d\n", GetTgl(D) + 29 , GetBln(D) - 1, GetThn(D));
    	
		} else { //Semua bulan Tgl 2 s/d akhir bulan
		
			printf(" \nTanggal sebelumnya %d/%d/%d\n", GetTgl(D) - 1 , GetBln(D), GetThn(D));
		
		}
		
	} else {
		
			printf(" ");
		
	}
}


void NextDate (date D)
/* Menampilkan tanggal berikutnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal berikutnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika des, thn+1 */

{
	
	if(isValid(D)){
		
		if((D.Bln == 12) && (D.Tgl == 31)){ //Akhir tahun
			
			printf(" \nTanggal selanjutnya %d/%d/%d\n", GetTgl(D) - 30 , GetBln(D) - 11, GetThn(D) + 1);
			
		} else if ((D.Bln == 2) && (D.Tgl == 29)){ //Tahun kabisat
				
			printf(" \nTanggal selanjutnya %d/%d/%d\n", GetTgl(D) - 28 , GetBln(D) + 1, GetThn(D));
				
		} else if ((D.Bln != 2) && (D.Bln != 12) && ((D.Tgl == 31) || (D.Tgl == 30))){ //Akhir bulan ganjil atau genap
			
			printf(" \nTanggal selanjutnya %d/%d/%d\n", 1 , GetBln(D) + 1, GetThn(D));
			
		} else if ((!(isKabisat(D))) && (D.Tgl == 28)){ //februari bukan tahun kabisat
			
			printf(" \nTanggal selanjutnya %d/%d/%d\n", 1 , GetBln(D) + 1, GetThn(D));
			
		} else {
			
			printf(" \nTanggal selanjutnya %d/%d/%d\n", GetTgl(D) + 1, GetBln(D), GetThn(D));
			
		}
		
		
	}
	
}


void SelisihDate (date D1, date D2)
/* Menampilkan selisih dua tanggal
	I.S = 2 buah Tanggal tertentu diketahui
	F.S = Tampil selisih dua buah tanggal
	Asumsi : 1 tahun = 365 hari */
{

	int SelisihHari;
	if(isValid(D1) && isValid(D2)){
		
		
			SelisihHari = (GetTgl(D2) + (TglAkhir(D2) * GetBln(D2)) + (365 * GetThn(D2)))
			- (GetTgl(D1) + ( TglAkhir(D1) * GetBln(D1)) + (365 * GetThn(D1)));
			

	}
	
	
	printf(" \n\n\n\n\n\n\t\t\t\tSelisih hari dari tanngal %d/%d/%d <-----> " , GetTgl(D1) , GetBln(D1) , GetThn(D1));
	printf(" %d/%d/%d ", GetTgl(D2), GetBln(D2), GetThn(D2));
	printf(" adalah : %d hari \n\n\n\n\n", SelisihHari);
		
	
}

