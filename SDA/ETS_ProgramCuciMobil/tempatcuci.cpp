
#include <stdio.h>
#include <windows.h>
#include "tempatcuci.h"
#include "queue.h"
#include "waktu.h"


void CreateTempatCuci(tempatcuci loketCuci[JML_TEMPATCUCI]){
	loketCuci[0].nama = "Loket 1";
	loketCuci[1].nama = "Loket 2";
	CreateList(&loketCuci[0].antrian);
	CreateList(&loketCuci[1].antrian);
}


int GetTempatCuci(tempatcuci loketCuci[JML_TEMPATCUCI], waktu sebelumselesai[JML_TEMPATCUCI]){
	bool loket_Satu = false;
	bool loket_Dua = false;
	if(ListEmpty(loketCuci[0].antrian)){ 
		loket_Satu = true;
	}
	if(ListEmpty(loketCuci[1].antrian)){ 
		loket_Dua = true;
	}
	
	if(loket_Satu == true && loket_Dua == true){ /*jika kedua loket kosong*/
		return 0;
	}else if(loket_Satu == true && loket_Dua == false){ /*jika loket satu kosong dan loket 2 tidak kosong*/
		return 0; 
	}else if(loket_Satu == false && loket_Dua == true){ /*jike loket satu tidak kosong dan loket 2 kosong*/
		return 1;
	}else{ /*jika kedua loket tidak kosong;*/
		if(BandingkanWaktu(sebelumselesai[1], sebelumselesai[0])){
			return 0;
		}else{
			return 1;
		}
	}
}

bool WaktuIstirahat(waktu T){
	if(T.jam == 12){
		return true;
	}else{
		return false;
	}
}

bool WaktuBuka(waktu T){
	if(T.jam >= 7){
		return true;
	}else{
		return false;
	}
}

//Koordinat
void gotoxy(int x, int y) {
    COORD coord;
     
    coord.X = x;
    coord.Y = y;
     
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
