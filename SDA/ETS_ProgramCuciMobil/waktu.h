

#ifndef WAKTU_H
#define WAKTU_H

typedef struct{
	int jam;
	int menit; 
}waktu;

//Prosedur dan fungsi
void CreateWaktu(waktu &T);
bool IsTimeValid(waktu T);
void CekWaktu(waktu &T);
bool BandingkanWaktu(waktu T1, waktu T2);
waktu TambahWaktu(waktu T1, waktu T2);
waktu KurangiWaktu(waktu T1, waktu T2);
waktu TambahPergantianWaktuCuci(waktu T);



#endif
