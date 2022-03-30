#ifndef convert_H
#define convert_H

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string.h>
#include <string>

using namespace std;

/* 
File : convert.h
Deskripsi : Header code
Nama : Hilman Permana
NIM : 211511015
Tanggal : 08 February 2022
Mata Kuliah : Struktur Data dan Algoritma
*/ 


typedef struct{
	char Kelas[4];
	char NIM[9]; 
	char Gol_DarahA[2];
	char JK;
}Data_A;

typedef struct{
	char Gol_DarahB[2];
	int Jml_Pria;
	int Jml_Wanita;
}Data_B;

// End Struct

/* Modul declaration */
int pilih();
int pilih_statement();
Data_A entry();
void read();
int show();

/* For EOF and value into variable  */
//Data_A getLineFileA(string data);
//Data_B getLineFileB(string data);

#endif
