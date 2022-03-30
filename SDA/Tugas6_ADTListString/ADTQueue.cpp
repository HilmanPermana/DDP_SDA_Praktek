
#include "HeaderFile.H"
#include "boolean.h"
#include <stdlib.h>
#include <cstring>

void ADTQueue(){
	
	/* Kamus Lokal */
	 Loket Tempat1,Tempat2;
	 ElmMobil MobilTes;
	 
	 int pilihan; /* untuk pilihan menu */
	 int pilihlist; /* untuk pilihan list */
	 DinamisChar X; /* untuk pencarian alamat elemen dan penambahan elemen */
	 DinamisChar Y; /* untuk pengurangan elemen */
	 boolean keluar; 
	 int N;
	 
	 /* Algoritma */
	
	char buff1[16] = "Tempat Cuci 1";
    char buff2[16] = "Tempat Cuci 2";
    
	keluar = false;
	CreateList(&Tempat1, buff1);
	CreateList(&Tempat2, buff2);
	
	/*Alokasi Dinamis Huruf Merk Mobil*/
	printf(" Input Jumlah Huruf Merek Mobil : ");
	scanf("%d",&N);
	
	MobilTes.MerkMobil = (DinamisChar) malloc(N * sizeof(char));
	if(MobilTes.MerkMobil == NULL){
	
		
 		printf("Error on malloc\n");
 		exit(0);
 		
	} else {
		printf("Alokasi Huruf Dari Merk Mobil Berhasil\n");

	}

   
 
	 	do {
		MenuQueue();
		scanf("%d",&pilihan);
		switch (pilihan) {
			case 1  : 						/*Input data mobil*/
				printf("Merk Mobil : \n");
				fflush(stdin);
				gets(MobilTes.MerkMobil);
			  	printf("Tempat Cuci Yang Dipilih (1/2) : ");
			  	scanf("%d",&pilihlist);
			  	switch (pilihlist){
			   	case 1  : 
						InsVLast(&Tempat1, MobilTes.MerkMobil);
			      		break;
			   		case 2  : 
					   	InsVLast(&Tempat2, MobilTes.MerkMobil);
			      		break;
			  	}
			  	break;
//				case 2  : 
//					printf("List yang dipilih (1/2/3/4/5) : ");
//				  	scanf("%d",&pilihlist);
//				  	switch (pilihlist) {
//				   		case 1  : 
//						   	DelVFirst(&A[0],Y);
//				      		break;
//				   		case 2  : 
//				   			DelVFirst(&A[1],Y);
//				      		break;
//				      	case 3  : 
//						   	DelVFirst(&A[2],Y);
//				      		break;
//				   		case 4  : 
//				   			DelVFirst(&A[3],Y);
//				      		break;
//				      	case 5  : 
//						   	DelVFirst(&A[4],Y);
//				      		break;
//				  	}
//				  	break;
			case 3  : 
				printf("Tempat Cuci yang dipilih (1/2) : ");
			  	scanf("%d",&pilihlist);
			  	switch (pilihlist) {
				   	case 1  : 
					   	PrintInfo(Tempat1);
				    	break;
				   	case 2  : 
					   	PrintInfo(Tempat2);
				      	break;
			case 4 : 
				keluar = true; 
				break;
		}
		system("pause");
	}while (!keluar);
	
	DelAll(&Tempat1);
	DelAll(&Tempat2);

}
