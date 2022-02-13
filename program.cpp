#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

fstream FILE_A;
fstream FILE_B;
//Struk FILE A
struct Data_A{
	
	char Kelas[4];
	char NIM[10];
	char Gol_Darah[3];
	char JK;
	
}inputkeFile,tampilFile;

//Struk FILE B (Hasil Resume)
struct Data_B{
	
	char Gol_Darah[3];
	int   Jml_Pria,Jml_Wanita;
	
}resume,tampilB;

/*Kamus Data Global*/
char Var_Golongan_Darah[4];
int TotalGolDarahPria,
	TotalGolDarahWanita;
	
void FileKeStruct(){
	
		FILE_A >> tampilFile.Kelas;
		FILE_A >> tampilFile.NIM;
		FILE_A >> tampilFile.Gol_Darah;
		FILE_A >> tampilFile.JK;
	
}

void tampildata(){
	
	system("cls");
	cout << "======================================" << endl;
	cout << "|               FILE A               |" << endl;
	cout << "======================================" << endl;
	
	FILE_A.open("file_A.DAT", ios::in | ios::binary);
	
	while(!FILE_A.eof()){
	
		
		FileKeStruct();
		cout << " | " << tampilFile.Kelas << " | " << tampilFile.NIM 
		<< " | "<< tampilFile.Gol_Darah << " | " << tampilFile.JK << " | ";
		
		cout << endl;
		
	}
	FILE_A.close();
}

void inputdata(){

	int pilih;
	int total_mahasiswa;
	FILE_A.open("file_A.DAT",  ios::out | ios::app | ios::binary);
	
	cout << "\t\t\t\t<><><><><><><> MASUKKAN DATA <><><><><><><>" << endl;
	
	cout << " Total Data Mahasiswa : ";
	cin  >> total_mahasiswa;
	
	for(int i=1;i<=total_mahasiswa;i++){
	
	system("cls");
	cout << " === Input Data Mahasiswa ke - " << i << " ===" << endl;
	fflush(stdin);
	cout<<"Masukan Kelas = ";
	gets(inputkeFile.Kelas);
	cout << endl;
	cout<<"Masukkan NIM = ";
	gets(inputkeFile.NIM);
	cout << endl;
	cout<<"Masukkan Golongan Darah = ";
	gets(inputkeFile.Gol_Darah);
	cout << endl;
	cout<<"Masukkan Jenis Kelamin = ";
	cin >> inputkeFile.JK;
	
	FILE_A << inputkeFile.Kelas <<";"<< inputkeFile.NIM <<";"
	<< inputkeFile.Gol_Darah <<";"<< inputkeFile.JK << endl;
	
	}
	FILE_A.close();
}


void Resume(){
	
	system("pause");
	system("cls");
	cout << "=======================" << endl;
	cout << "|       FILE B        |" << endl;
	cout << "=======================" << endl;
	FILE_A.open("file_A.DAT", ios::binary | ios::in );
	FILE_B.open("file_B.DAT", ios::binary | ios::out | ios::in);
	
	
	FileKeStruct();
	
	while(!FILE_A.eof()){
		
		strcpy(Var_Golongan_Darah,tampilFile.Gol_Darah);
		TotalGolDarahPria = 0;
		TotalGolDarahWanita = 0;
	
		
		while(!FILE_A.eof() && strcmp(tampilFile.Gol_Darah,Var_Golongan_Darah) == 0){
			
			TotalGolDarahPria += 1;
			TotalGolDarahWanita += 1;
			
			if(tampilFile.JK == 'P'){
				TotalGolDarahPria += 1;
			} else if (tampilFile.JK == 'W'){
				TotalGolDarahWanita += 1;
			}
			
			FileKeStruct();
		}
		strcpy(resume.Gol_Darah,Var_Golongan_Darah);
		resume.Jml_Pria = TotalGolDarahPria;
		resume.Jml_Wanita = TotalGolDarahWanita;
		
		FILE_B << resume.Gol_Darah << ";" << resume.Jml_Pria <<  ";"
		<< resume.Jml_Wanita;
		
		cout << " | "<< resume.Gol_Darah << " | " << resume.Jml_Pria << " | " 
		<< resume.Jml_Wanita << " | " << endl;
		}
	FILE_A.close();
	FILE_B.close();
   }

 

	
	
	
	
	


