

#include "waktu.h"

void CreateWaktu(waktu &T){
	T.jam = 0;
	T.menit = 0;
}

bool IsTimeValid(waktu T){
	if(0 <= T.jam && T.jam <= 24){
		if(0 <= T.menit && T.menit < 60){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}

void CekWaktu(waktu &T){
	while(IsTimeValid(T)==false){
		T.jam++;
		T.menit = T.menit - 60;	
	}		
}

waktu TambahWaktu(waktu T1, waktu T2){
	/*Kamus Data: */
	waktu hasil;
	
	hasil.jam = T1.jam + T2.jam;
	hasil.menit = T1.menit + T2.menit;
	CekWaktu(hasil);
	
	return hasil;
}

waktu KurangiWaktu(waktu T1, waktu T2){
	/*Kamus Data: */
	waktu hasil;
	
	if(T1.menit < T2.menit){
		T1.menit = T1.menit + 60;
		T1.jam--;
	}
	
	hasil.jam = T1.jam - T2.jam;
	hasil.menit = T1.menit - T2.jam;
	
	CekWaktu(hasil);
	return hasil;
}

bool BandingkanWaktu(waktu T1, waktu T2){
	if(T1.jam > T2.jam){
		return true;
	}else if(T1.jam == T2.jam){
		if(T1.menit > T2.menit){
			return true;
		}else if(T1.menit == T2.menit){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}		
}

waktu TambahPergantianWaktuCuci(waktu T){
	/*Kamus Data: */
	waktu hasil;
	
	hasil.jam = hasil.jam;
	hasil.menit = hasil.menit + 5;
	CekWaktu(hasil);
	
	return hasil;
}
