#include <iostream>
#include "convert.h"

using namespace std;

/* 
File : pilihmenu.cpp
Deskripsi : Memilih keinginan untuk dilakukan
Nama : Hilman Permana
NIM : 211511015
Tanggal : 09 February 2022
Mata Kuliah : Struktur Data dan Algoritma
*/ 

int pilih(){
	int a;
	cout<<"1. Masukkan Data"<<endl;
	cout<<"2. Resume Data"<<endl;
	cout<<"3. Lihat Hasil Resume"<<endl;
	cout<<"Pilih : ";
	cin>>a;
	while(cin.fail()){
		cin.clear();
		cin.ignore();
		cout<<"Tidak ada pilihan tersebut"<<endl;
		system("pause");
		system("cls");
		pilih_statement();
	}
	return a;
}

int pilih_statement(){
	int a;
	a = pilih();
	
	if(a==1){
		entry();
	}
	else if(a==2){
		read();
	}else if(a==3){
		show();
	} else{
		cout<<"Pilihan tidak ada"<<endl;
		system("pause");
		system("cls");
		pilih_statement();
	}
}
