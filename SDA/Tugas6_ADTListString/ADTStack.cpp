/* ANGGOTA KELOMPOK */

/* 
	Nama	: Achmadya Ridwan Ilyawan
   	NIM		: 211511001
   	Nama	: Hilman Permana
   	NIM		: 211511015
   	Tgl Pembuatan	: 6 Maret - 9 Maret 2022
*/

#include "SpNRSLL.H"
#include "boolean.h"
#include <stdlib.h>
#include <cstring>

void ADTStack(){
	
	/* Kamus Lokal */
	 List A[5];
	 address P;
	 
	 int pilihan; /* untuk pilihan menu */
	 int pilihlist; /* untuk pilihan list */
	 alfanumerik X[20]; /* untuk pencarian alamat elemen dan penambahan elemen */
	 alfanumerik Y[20]; /* untuk pengurangan elemen */
	 alfanumerik InputKota[15];
	 boolean keluar; 
	 char buff[15];
	 
	 /* Algoritma */
	char buff1[15] = "BANDUNG : ";
    char buff2[15] = "JAKARTA : ";
    char buff3[15] = "SURABAYA : ";
    char buff4[15] = "MALANG : ";
    char buff5[15] = "BALI : ";
    
	 keluar = false;
	CreateList(&A[0], buff1);
    CreateList(&A[1], buff2);
    CreateList(&A[2], buff3);
    CreateList(&A[3], buff4);
    CreateList(&A[4], buff5);
 
	 	do {
		MenuStack();
		scanf("%d",&pilihan);
		switch (pilihan) {
			case 1  : 
				printf("Elemen : ");
				fflush(stdin);
			  	gets(buff);
                strcpy(X, buff);
			  	printf("List yang dipilih (1/2/3/4/5) : ");
			  	scanf("%d",&pilihlist);
			  	switch (pilihlist) {
			   	case 1  : 
						InsVLast(&A[0],X);
			      		break;
			   		case 2  : 
					   	InsVLast(&A[1],X);
			      		break;
			      	case 3 : 
					   	InsVLast(&A[2],X);
			      		break;
			      	case 4  : 
					   	InsVLast(&A[3],X);
			      		break;
			      	case 5  : 
					   	InsVLast(&A[4],X);
			      		break;
			  	}
			  	break;
			case 2  : 
				printf("List yang dipilih (1/2/3/4/5) : ");
			  	scanf("%d",&pilihlist);
			  	switch (pilihlist) {
			   		case 1  : 
					   	DelVLast(&A[0],Y);
			      		break;
			   		case 2  : 
					   	DelVLast(&A[1],Y);
			      		break;
			      	case 3  : 
					   	DelVLast(&A[2],Y);
			      		break;
			   		case 4  : 
					   	DelVLast(&A[3],Y);
			      		break;
			      	case 5  : 
					   	DelVLast(&A[4],Y);
			      		break;
			  	}
			  	break;
			case 3  : 
				printf("List yang dipilih (1/2/3/4/5) : ");
			  	scanf("%d",&pilihlist);
			  	switch (pilihlist) {
				   	case 1  : 
					   	PrintInfo(A[0]);
				    	break;
				   	case 2  : 
					   	PrintInfo(A[1]);
				      	break;
				    case 3  : 
					   	PrintInfo(A[2]);
				    	break;
				   	case 4  : 
					   	PrintInfo(A[3]);
				      	break;
				    case 5  : 
					   	PrintInfo(A[4]);
				    	break;
			  	}
			  	break;
			case 4 : 
				keluar = true; 
				break;
		}
		system("pause");
	}while (!keluar);
	
	DelAll(&A[0]);
	DelAll(&A[1]);
	DelAll(&A[2]);
	DelAll(&A[3]);
	DelAll(&A[4]);
}
