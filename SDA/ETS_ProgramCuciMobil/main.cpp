
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "waktu.h"
#include "queue.h"
#include "tempatcuci.h"
#include "antrian_mobil.h"
#include "methodmain.h"

int main() {
	/*Kamus Data: */
	tempatcuci loketCuci[JML_TEMPATCUCI];
	int idxLoketCuci;
	waktu sebelumnya;
	waktu berjalan;
	waktu kedatangan;
	waktu dilayani;
	waktu lamaPencucian;
	waktu selesai;
	char jenis;
	int loket;
	DinamisChar MerkMobil;
	int choice;	
	waktu sebelumselesai[JML_TEMPATCUCI];
	
	//Algoritma
	CreateWaktu(sebelumnya);
	CreateWaktu(sebelumnya);
	CreateTempatCuci(loketCuci);
	HapusFile();
	
	berjalan = WaktuBerjalan(sebelumnya);

	do{
				
				
		Menu(loketCuci, berjalan);
		printf("\tPilih Menu: ");
		scanf(" %d", &choice);
		
		switch(choice){
			case  1 :
				kedatangan = berjalan;
				
				idxLoketCuci = GetTempatCuci(loketCuci, sebelumselesai);
				loket = idxLoketCuci + 1;
				
				dilayani = GetWaktuPelayananMulai(idxLoketCuci, kedatangan, loketCuci, sebelumselesai); 
				
				jenis = GetWaktuPencucian(lamaPencucian);
				
				InputMerkMobil(MerkMobil);
				
				selesai = WaktuSelesai(lamaPencucian, dilayani);
				
				sebelumselesai[idxLoketCuci] = selesai;
				
				if(selesai.jam >= 17 && selesai.menit >= 0){
					printf("\n\tProses pencucian akan melebihi jam tutup\n");
					system("Pause");
				}else{
					Enqueue(&loketCuci[idxLoketCuci].antrian, MerkMobil, kedatangan, dilayani, selesai, jenis, loket);
					SimpanKeFile(MerkMobil, kedatangan, dilayani, selesai, jenis, loket);
					printf("\n\tBerhasil ditambahkan ke antrean");
					Sleep(1000);
				}
				break;
			case 2 :
				TampilkanData(loketCuci);
				break;
			case 3 :
				system("cls");
				sebelumnya = berjalan;
				berjalan = WaktuBerjalan(sebelumnya);
				CheckAntrian(loketCuci, berjalan);
				break;
			case 0 :
				exit(0);
				break;
			default:
				printf("\tInput tidak valid\n");
				Sleep(1000);
		}
	}while(true);
	
	return 0;
 }
