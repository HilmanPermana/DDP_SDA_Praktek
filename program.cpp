#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

fstream FILE_A;
fstream FILE_B;
//Struk FILE A
struct Data_a{
	
	string jurusan;
	string prodi;
	short jmlwanita;
	short jmlpria;
	
}inputkeFile,tampilFile;

//Struk FILE B (Hasil Resume)
struct Data_b{
	
	string jurusan;
	short TotProdi;
	short JumlahMayoritasPria;
	short TotalMahasiswaJurusan;
	
}resume,tampilB;

//Kamus Data Global

string var_jur;
int Tot_prodi_di_jur,
	Tot_prodi_mayo_p,
	Tot_mhs_di_jur;


void inputdata(){


	FILE_A.open("file_A.DAT",  ios::out | ios::app | ios::binary);
	
	cout << "\t\t\t\t<><><><><><><> MASUKKAN DATA MAHASISWA <><><><><><><>" << endl;
	
	
	//Jurusan JTE
	cout << "Masukkan nama jurusan pertama : ";
	getline(cin,inputkeFile.jurusan);
	
		//Input jumlah prodi
		short tot_prodiJTE;
		cout << "\nJumlah prodi : ";
		cin >> tot_prodiJTE;
	
		//Input nama setiap prodi
		for(short i=1;i<=tot_prodiJTE;i++){
			cout << "\nNama prodi  ke - " << i << " : ";
			fflush(stdin);
			getline(cin,inputkeFile.prodi);
		
			//Input jumlah pria
			cout << "\nJumlah mahasiswa pria = ";
			cin >> inputkeFile.jmlpria;
			
			//Input jumlah wanita
			cout << "\nJumlah mahasiswa wanita = ";
			cin >> inputkeFile.jmlwanita;
			
			FILE_A << inputkeFile.jurusan <<" "<< inputkeFile.prodi <<" "<< inputkeFile.jmlpria <<" "<< inputkeFile.jmlwanita << endl;
		}
	
	
	//Jurusan JTK
	system("cls");
	cout << "\t\t\t\t<><><><><><><> MASUKKAN DATA MAHASISWA <><><><><><><>" << endl;
	cout << "Masukkan nama jurusan kedua : ";
	fflush(stdin);
	getline(cin,inputkeFile.jurusan);
	
		//Input jumlah prodi
		short tot_prodiJTK;
		cout << "\nJumlah prodi : ";
		cin >> tot_prodiJTK;
	
		//Input nama setiap prodi
		for(short j=1;j<=tot_prodiJTK;j++){
			cout << "\nNama prodi ke - " << j << " : ";
			fflush(stdin);
			getline(cin,inputkeFile.prodi);
			
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
	
	FILE_A.open("file_A.DAT", ios::in | ios::binary);
	
	system("cls");
	while(!FILE_A.eof()){
		
		FileKeStruct();
		cout << tampilFile.jurusan << " " << tampilFile.prodi << " "<< tampilFile.jmlpria << " "<< tampilFile.jmlwanita << endl;
		
	}
	FILE_A.close();
}


 void Resume(){
	
	FILE_A.open("file_A.DAT", ios::binary | ios::in );
	FILE_B.open("file_B.DAT", ios::binary | ios::out | ios::in);
	
	
	FileKeStruct();
	
	while(!FILE_A.eof()){
		strcpy(var_jur, tampilFile.jurusan);
		Tot_prodi_di_jur = 0;
		Tot_prodi_mayo_p = 0;
		Tot_mhs_di_jur = 0;
		
		while(!FILE_A.eof() && strcmpy(tampilFile.jurusan,var_jur) == 0){
			
			Tot_prodi_di_jur += 1;
			Tot_mhs_di_jur = Tot_mhs_di_jur + tampilFile.jmlpria + tampilFile.jmlwanita;
			if(tampilFile.jmlwanita < tampilFile.jmlpria){
				Tot_prodi_mayo_p += 1;
			}	
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
		

	
	
	
	
	


