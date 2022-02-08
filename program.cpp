#include <iostream>
#include <fstream>
#include <string.h>
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
	FILE_B.open("file_B.DAT", ios::binary | ios::out | ios::in | ios::app);
	
	
	FileKeStruct();
	
	while(!FILE_A.eof()){
	
	resume.jurusan = tampilFile.jurusan;
	
		while((!FILE_A.eof()) && (resume.jurusan == tampilFile.jurusan)){
			
			resume.TotProdi = resume.TotProdi + 1;
			resume.TotalMahasiswaJurusan = resume.TotalMahasiswaJurusan + tampilFile.jmlwanita + tampilFile.jmlpria;
			cout << resume.TotalMahasiswaJurusan << endl;
			
			if(tampilFile.jmlwanita < tampilFile.jmlpria){
				resume.JumlahMayoritasPria = resume.JumlahMayoritasPria + 1;
			}	
			break;
		}
		
		FILE_B << resume.jurusan << " | " << resume.TotProdi << " | " 
		<< resume.JumlahMayoritasPria << " | " << resume.TotalMahasiswaJurusan;
	
		cout << resume.jurusan << " | " << resume.TotProdi << " | " 
		<< resume.JumlahMayoritasPria << " | " << resume.TotalMahasiswaJurusan << endl;
		
	}
	FILE_A.close();
	FILE_B.close();
	
}
		

	
	
	
	
	


