#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

fstream FILE_A;
fstream FILE_B;
//Struk FILE A
struct Data_a{
	
	char jurusan[4];
	char prodi[20];
	short jmlwanita;
	short jmlpria;
	
}inputkeFile,tampilFile;

//Struk FILE B (Hasil Resume)
struct Data_b{
	
	char jurusan[4];
	short TotProdi;
	short JumlahMayoritasPria;
	short TotalMahasiswaJurusan;
	
}resume,tampilB;

/*Kamus Data Global*/
char var_jur[4];
int Tot_prodi_di_jur,
	Tot_prodi_mayo_p,
	Tot_mhs_di_jur;

void inputdata(){


	FILE_A.open("file_A.DAT",  ios::out | ios::app | ios::binary);
	
	cout << "\t\t\t\t<><><><><><><> MASUKKAN DATA MAHASISWA <><><><><><><>" << endl;
	
	
	//Jurusan JTE
	cout << "Masukkan nama jurusan pertama : ";
	gets(inputkeFile.jurusan);
	
		//Input jumlah prodi
		short tot_prodiJTE;
		cout << "\nJumlah prodi : ";
		cin >> tot_prodiJTE;
	
		//Input nama setiap prodi
		for(short i=1;i<=tot_prodiJTE;i++){
			cout << "\nNama prodi  ke - " << i << " : ";
			fflush(stdin);
			gets(inputkeFile.prodi);
		
			//Input jumlah pria
			cout << "\nJumlah mahasiswa pria = ";
			cin >> inputkeFile.jmlpria;
			
			//Input jumlah wanita
			cout << "\nJumlah mahasiswa wanita = ";
			cin >> inputkeFile.jmlwanita;
			
		FILE_A << inputkeFile.jurusan <<" "<< inputkeFile.prodi <<" "
			<< inputkeFile.jmlpria <<" "<< inputkeFile.jmlwanita << endl;
		}
	
	
	//Jurusan JTK
	system("cls");
	cout << "\t\t\t\t<><><><><><><> MASUKKAN DATA MAHASISWA <><><><><><><>" << endl;
	cout << "Masukkan nama jurusan kedua : ";
	fflush(stdin);
	gets(inputkeFile.jurusan);
	
		//Input jumlah prodi
		short tot_prodiJTK;
		cout << "\nJumlah prodi : ";
		cin >> tot_prodiJTK;
	
		//Input nama setiap prodi
		for(short j=1;j<=tot_prodiJTK;j++){
			cout << "\nNama prodi ke - " << j << " : ";
			fflush(stdin);
			gets(inputkeFile.prodi);
			
			//Input jumlah pria
			cout << "\nJumlah mahasiswa pria = ";
			cin >> inputkeFile.jmlpria;
			
			//Input jumlah wanita
			cout << "\nJumlah mahasiswa wanita = ";
			cin >> inputkeFile.jmlwanita;
			
			FILE_A << inputkeFile.jurusan <<" "<< inputkeFile.prodi <<" "
			<< inputkeFile.jmlpria <<" "<< inputkeFile.jmlwanita << endl;
		}

	FILE_A.close();
}

void FileKeStruct(){
	
		FILE_A >> tampilFile.jurusan;
		FILE_A >> tampilFile.prodi;
		FILE_A >> tampilFile.jmlpria;
		FILE_A >> tampilFile.jmlwanita;
	
}

//Prosedur tampil data ke console
void tampildata(){
	
	system("cls");
	cout << "======================================" << endl;
	cout << "|               FILE A               |" << endl;
	cout << "======================================" << endl;
	
	FILE_A.open("file_A.DAT", ios::in | ios::binary);
	
	while(!FILE_A.eof()){
	
		
		FileKeStruct();
		cout << " | " << tampilFile.jurusan << " | " << tampilFile.prodi 
		<< " | "<< tampilFile.jmlpria << " | " << tampilFile.jmlwanita << " | ";
		
		cout << endl;
		
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
		
		strcpy(var_jur,tampilFile.jurusan);
		Tot_prodi_di_jur = 0;
		Tot_prodi_mayo_p = 0;
		Tot_mhs_di_jur = 0;
		
		while(!FILE_A.eof() && strcmp(tampilFile.jurusan,var_jur) == 0){
			
			Tot_prodi_di_jur += 1;
			Tot_mhs_di_jur = Tot_mhs_di_jur + tampilFile.jmlpria + tampilFile.jmlwanita;
			
			if(tampilFile.jmlwanita<tampilFile.jmlpria){
				Tot_prodi_mayo_p += 1;
			}	
			FileKeStruct();
		}
	
		strcpy(resume.jurusan,var_jur);
		resume.TotProdi = Tot_prodi_di_jur;
		resume.JumlahMayoritasPria = Tot_prodi_mayo_p;
		resume.TotalMahasiswaJurusan = Tot_mhs_di_jur;
		
		FILE_B << resume.jurusan << ";" << resume.TotProdi <<  ";"
		<< resume.JumlahMayoritasPria <<  ";" << resume.TotalMahasiswaJurusan;
		
		cout << resume.jurusan << " | " << resume.TotProdi << " | " 
		<< resume.JumlahMayoritasPria << " | " << resume.TotalMahasiswaJurusan << endl;
    }
	FILE_A.close();
	FILE_B.close();
}
 

	
	
	
	
	


