#include <iostream>
#include "convert.h"

using namespace std;

/* 
File : getfromfile.cpp
Deskripsi : File_A,File_B properties
Nama : Hilman Permana
NIM : 211511015
Tanggal : 09 February 2022
Mata Kuliah : Struktur Data dan Algoritma
*/ 

Data_A getLineFileA(string data){
	Data_A a;
	stringstream ss(data);
	string Kelas, NIM, GolonganDarah, JenisKelamin;

	getline(ss, Kelas, ';');
	getline(ss, NIM, ';');
	getline(ss, GolonganDarah, ';');
	getline(ss, JenisKelamin, ';');
		
	strcpy(a.Kelas, Kelas.c_str());
	strcpy(a.NIM, NIM.c_str());
	strcpy(a.Gol_DarahA, GolonganDarah.c_str());
	strcpy(a.JK, JenisKelamin.c_str());
	
	return a;
}

Data_B getLineFileB(string data){
	Data_B b;
	
	stringstream ss(data);
	string GolonganDarah, JumlahPria, JumlahWanita;

	getline(ss, GolonganDarah, ';');
	getline(ss, JumlahPria, ';');
	getline(ss, JumlahWanita, ';');

	strcpy(b.Gol_DarahB, GolonganDarah.c_str());
	stringstream JumlahP(JumlahPria);
	JumlahP >> b.Jml_Pria;
	stringstream JumlahW(JumlahWanita);
	JumlahW >> b.Jml_Wanita;
	
	
	return b;
}
