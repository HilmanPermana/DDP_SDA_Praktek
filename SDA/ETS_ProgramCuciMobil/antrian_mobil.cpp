
#include <stdio.h>
#include <windows.h>
#include "waktu.h"
#include "queue.h"
#include "tempatcuci.h"

waktu WaktuBerjalan(waktu sebelumnya){
	/*Kamus Data: */
	waktu berjalan;
	
	do{
		gotoxy(50,1); printf("== Input Waktu Berlangsung ==");
		gotoxy(50,3); printf("\tMasukan Jam: ");
		scanf(" %d", &berjalan.jam);
		gotoxy(50,5); printf("\tMasukan Menit: ");
		scanf(" %d", &berjalan.menit);
			
		if(!IsTimeValid(berjalan)){
			printf("\tInput tidak valid\n");
		}else if(!BandingkanWaktu(berjalan, sebelumnya)){
			printf("\tTidak dapat kembali ke waktu sebelumnya\n");
		}else{
			break;
		}
	}while(1);
	return berjalan;
}

void Menu(tempatcuci loketCuci[JML_TEMPATCUCI], waktu berjalan){
	/*Kamus Data: */

	
	system("cls");
	gotoxy(40,4);printf("=============================================\n");
	gotoxy(40,5);printf("|            Waktu Berjalan : %02d.%02d        |\n", berjalan.jam, berjalan.menit);
	gotoxy(40,6);printf("=============================================\n");
	
	gotoxy(17,1);printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
	gotoxy(17,2);printf("|                                   BERKAH JEMBAR RAHAYU CAR WASH                          |\n");
	gotoxy(17,3);printf("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
	gotoxy(17,7); printf("==============================================================================================\n");
	gotoxy(17,8); printf("|                                                                                            |\n");
	gotoxy(17,9); printf("|                                     1. Input Detail Mobil                                  |\n");
	gotoxy(17,10);printf("|                                     2. Cek Antrian                                         |\n");
	gotoxy(17,11);printf("|                                     3. Set Waktu Berjalan                                  |\n");
	gotoxy(17,12);printf("|                                     0. Keluar                                              |\n");
	gotoxy(17,13);printf("==============================================================================================\n");
	gotoxy(17,14);printf("|                              Waktu Pencucian: 07.00 s/d 17.00                              |\n");
	gotoxy(17,15);printf("|                                Istirahat: 12.00 s/d 13.00                                  |\n");
	gotoxy(17,16);printf("==============================================================================================\n");
	
}


void CheckAntrian(tempatcuci loketCuci[JML_TEMPATCUCI], waktu berjalan){
	/*Kamus Data: */
	DinamisChar noPolisi;
	
	for(int i=0; i < 2; i++){
		while(!ListEmpty(loketCuci[i].antrian)){	//Jika Loket tidak kosong
			if(BandingkanWaktu(berjalan, Selesai(First(loketCuci[i].antrian)))){		
				Dequeue(&loketCuci[i].antrian, &noPolisi);	//keluarkan dari antrean	
			}else{
				break;
			}
		}
	}
}

waktu GetWaktuPelayananMulai(int idxLoketCuci, waktu kedatangan, tempatcuci loketCuci[JML_TEMPATCUCI], waktu sebelumselesai[JML_TEMPATCUCI]){
	/*Kamus Data: */
	waktu dilayani;
	
	if(ListEmpty(loketCuci[idxLoketCuci].antrian) && !WaktuBuka(kedatangan)){
		dilayani.jam = 7;
		dilayani.menit = 0;
	}else if(ListEmpty(loketCuci[idxLoketCuci].antrian) && WaktuIstirahat(kedatangan)){
		dilayani.jam = 13;
		dilayani.menit = 0;
	}else{
		if(BandingkanWaktu(kedatangan, TambahPergantianWaktuCuci(sebelumselesai[idxLoketCuci]))){
			dilayani = kedatangan;
		}else{
			dilayani = TambahPergantianWaktuCuci(sebelumselesai[idxLoketCuci]);
		}
	}
	return dilayani;
}

char GetWaktuPencucian(waktu &lamaPencucian){
	/*Kamus Data: */
	char choice;
	char jenis;
	
	system("cls");
	do{
		
	gotoxy(40,1);   printf("\t         Jenis Mobil          \n");
	gotoxy(40,2); 	printf("\t                              \n");
	gotoxy(40,3); 	printf("\t  1. Mobil Kecil (30 Menit)   \n");
	gotoxy(40,4); 	printf("\t  2. Minibus     (45 Menit)   \n");
	gotoxy(40,5); 	printf("\t  3. Mobil Besar (75 Menit)   \n");
	gotoxy(40,6); 	printf("\t                              \n");
		
		printf("\tPilih Jenis Mobil (1-3): ");
		scanf(" %c", &choice);
		switch(choice){
			case '1':
				lamaPencucian.jam = 0;
				lamaPencucian.menit = 30;
				jenis = 'A';
				break;
			case '2':
				lamaPencucian.jam = 0;
				lamaPencucian.menit = 45;
				jenis = 'B';
				break;
			case '3':
				lamaPencucian.jam = 1;
				lamaPencucian.menit = 15;
				jenis = 'C';
				break;
			default:
				printf("\tInput tidak valid\n");
				Sleep(1000);
		}
	}while(choice != '1' && choice != '2' && choice != '3');
	return jenis;
}

waktu WaktuSelesai(waktu lamaPencucian, waktu dilayani){
	/*Kamus Data: */
	waktu selesai;
	waktu jamDua_Belas;
	waktu jamSatu_Siang;
	waktu hasilPengurangan;
	
	selesai = TambahWaktu(dilayani, lamaPencucian);
	
	hasilPengurangan.jam = 0;
	hasilPengurangan.menit = 0;
	
	jamDua_Belas.jam = 12;
	jamDua_Belas.menit = 0;
	
	jamSatu_Siang.jam = 13;
	jamDua_Belas.menit = 0;
	
	//handle jam istirahat
	if(dilayani.jam < 12 && selesai.jam > 12){ //Jika startTime sebelum jam 12 & finishTime setelah jam 12
		hasilPengurangan = KurangiWaktu(jamDua_Belas, dilayani);
		hasilPengurangan = KurangiWaktu(lamaPencucian, hasilPengurangan);
		selesai = TambahWaktu(jamSatu_Siang, hasilPengurangan);
	}
	
	return selesai;
}

void InputMerkMobil(DinamisChar &MerkMobil){
	printf("\tMasukan Merk Mobil: ");
	scanf(" %[^\n]s", &MerkMobil);
}

void TampilkanData(tempatcuci loketCuci[JML_TEMPATCUCI]){
	system("cls");
	printf("%s:\n\n", loketCuci[0].nama);
	PrintInfo(loketCuci[0].antrian);
	printf("\n\n");
	printf("%s:\n\n", loketCuci[1].nama);
	PrintInfo(loketCuci[1].antrian);
	printf("\n");
	system("Pause");
}

void HapusFile(){
	FILE *Hapus = fopen("Struk_Antrean.txt", "w");
	fclose;
}

void SimpanKeFile(DinamisChar MerkMobil, waktu kedatangan, waktu dilayani, waktu selesai, char jenis, int loket){	
	FILE *Simpan = fopen("Struk_Antrean.txt", "a");
	
	if(Simpan == Nil){
		printf("\nGagal membuka file");
		exit(-1);
	}
	
	fprintf(Simpan, "Merk Mobil: %s\n", &MerkMobil);
	fprintf(Simpan, "Tipe Mobile: %c\n", jenis);
	fprintf(Simpan, "Loket Cuci: %d\n", loket);
	fprintf(Simpan, "Waktu Kedatangan: %02d.%02d\n", kedatangan.jam, kedatangan.menit);
	fprintf(Simpan, "Waktu Mulai Dilayani: %02d.%02d\n", dilayani.jam, dilayani.menit);
	fprintf(Simpan, "Waktu Selesai Dilayani: %02d.%02d\n\n", selesai.jam, selesai.menit);
	
	fclose(Simpan);

}


