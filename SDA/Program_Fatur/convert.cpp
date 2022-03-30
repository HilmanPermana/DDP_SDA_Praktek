#include <iostream>
#include "convert.h"

using namespace std;

/* 
File : convert.cpp
Deskripsi : Main Modul, membuat modul yang ditugaskan
Nama : Hilman Permana
NIM : 211511015
Tanggal : 09 February 2022
Mata Kuliah : Struktur Data dan Algoritma
*/ 

fstream File_A;
fstream File_B;
	
/*Kamus Data Global */
char Var_Golongan_Darah[2];
int TotalGolDarahPria,
	TotalGolDarahWanita;
	
Data_A entry(){
	Data_A a;
	string data;
	char b;
	
	File_A.open("File_A.DAT", ios::app | ios::binary);
		
	char Kelas[4];
	char NIM[9];
	char Gol_Darah[2];
	char JK;
		
	fflush(stdin);
	cout<<"Masukan Kelas = ";
	gets(a.Kelas);
	cout<<"Masukkan NIM = ";
	gets(a.NIM);
	cout<<"Masukkan Golongan Darah = ";
	gets(a.Gol_DarahA);
	cout<<"Masukkan Jenis Kelamin = ";
	cin >> JK;
	
	File_A<<a.Kelas<<";"<<a.NIM<<";"<<a.Gol_DarahA<<";"<<a.JK<<endl;
	File_A.close();
	cout<<"Input data lagi ? [y/n]";
		cin>>b;
		if(b=='y' || b=='Y'){
			system("cls");
			entry();
		} else {
			system("cls");
			pilih_statement();
		}
	
	return a;
}

void read(){
	Data_A a;
	Data_B b;
	File_A.open("File_A.DAT", ios::in | ios::binary);
	File_B.open("File_B.DAT", ios::in | ios::out | ios::binary);
	string data;
	
	
	getline(File_A, data);
	while(!File_A.eof()){
		a = getLineFileA(data);
		
		strcpy(Var_Golongan_Darah, a.Gol_DarahA);
		TotalGolDarahPria = 0;
		TotalGolDarahWanita = 0;
		
		while (!File_A.eof() && strcmp(a.Gol_DarahA, Var_Golongan_Darah) == 0){		
			if( a.JK == 'P'){
				TotalGolDarahPria += 1;
			} else {
				TotalGolDarahWanita += 1;
			}
			getline(File_A,data);
			a = getLineFileA(data);
		}
		strcpy(b.Gol_DarahB, Var_Golongan_Darah);
		b.Jml_Pria = TotalGolDarahPria;
		b.Jml_Wanita = TotalGolDarahWanita;
		File_B<<b.Gol_DarahB<<";"<<b.Jml_Pria<<endl;
	}
	cout<<"File Dimasukkan !!"<<endl<<endl;
	system("pause");
	system("cls");
	File_A.close();
	File_B.close();
	pilih_statement();
}

int show(){
	File_A.open("File_A.DAT",ios::in | ios::binary);
	File_B.open("File_B.DAT",ios::in | ios::binary);
	string data;
	Data_A a;
	Data_B b;
	cout<<endl;
	cout<<"File A :"<<endl;
	getline(File_A,data);
	cout << "======================================" << endl;
	cout << "|               FILE A               |" << endl;
	cout << "======================================" << endl;
	while(!File_A.eof()){
		a = getLineFileA(data);
		
		cout <<"|" << left << setw(5) << a.Kelas << "|"
			<< left << setw(20) << a.NIM << "|"
			<< left << setw(4) << a.Gol_DarahA << "|"
			<< left << setw(4) << a.JK << "|" <<endl;
		getline(File_A,data);
	}
	cout<<endl;
	cout<<"File B :"<<endl;
	getline(File_B,data);
	cout << "=======================" << endl;
	cout << "|       FILE B        |" << endl;
	cout << "=======================" << endl;
	while(!File_B.eof()){
		b = getLineFileB(data);
		
		cout <<"|" << left << setw(5) << b.Gol_DarahB << "|"
			<< left << setw(4) << b.Jml_Pria << "|"
			<< left << setw(4) << b.Jml_Wanita << "|";
		getline(File_B,data);
	}
	
	File_A.close();
	File_B.close();
	cout<<endl;
	system("pause");
	system("cls");
	pilih_statement();
}

