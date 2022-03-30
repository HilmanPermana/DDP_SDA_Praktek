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



void ADTDeque(){


	/* Kamus Lokal */
	 List Tempat1, Tempat2;
	 Alamat P;
	 
	 int pilihan; /* untuk pilihan menu */
	 int pilihlist; /* untuk pilihan list */
	 DinamisChar X; /* untuk pencarian alamat elemen dan penambahan elemen */
	 DinamisChar Y; /* untuk pengurangan elemen */

	 boolean keluar;
	 
	 /* Algoritma */
	
    
	keluar = false;
	CreateList(&Tempat1, buff1);
	CreateList(&Tempat2, buff2);
 
	 	do {
		Menu();
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
						InsVFirst(&A[0],X);
			      		break;
			   		case 2  : 
					   	InsVFirst(&A[1],X);
			      		break;
			      	case 3 : 
					   	InsVFirst(&A[2],X);
			      		break;
			      	case 4  : 
					   	InsVFirst(&A[3],X);
			      		break;
			      	case 5  : 
					   	InsVFirst(&A[4],X);
			      		break;
			  	}
			  	break;
			case 2  : 
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
			case 3 	:
				printf("Elemen : ");
				fflush(stdin);
			  	gets(buff);
                strcpy(X, buff);
			  	printf("List yang dipilih (1/2/3/4/5) : ");
			  	scanf("%d",&pilihlist);
			  	switch (pilihlist) {
			   	case 1  : 
						InsVMiddle(&A[0],X);
			      		break;
			   		case 2  : 
					   	InsVMiddle(&A[1],X);
			      		break;
			      	case 3 : 
					   	InsVMiddle(&A[2],X);
			      		break;
			      	case 4  : 
					   	InsVMiddle(&A[3],X);
			      		break;
			      	case 5  : 
					   	InsVMiddle(&A[4],X);
			      		break;
			  	}
			  	break;
			case 4  : 
				printf("Elemen yang dicari : ");
				fflush(stdin);
			  	gets(buff);
                strcpy(X, buff);
			  	P = Search(A[0],X);
			  	printf("Di BANDUNG	: 0x%x\n",P);
			  	P = Search(A[1],X);
			  	printf("Di JAKARTA 	: 0x%x\n",P);
			  	P = Search(A[2],X);
			  	printf("Di SURABAYA : 0x%x\n",P);
			  	P = Search(A[3],X);
			  	printf("Di MALANG	: 0x%x\n",P);
			  	P = Search(A[4],X);
			  	printf("Di BALI 	: 0x%x\n",P);
                break;
			case 5  : 
				printf("Elemen yang dicari : ");
				fflush(stdin);
			  	gets(buff);
                strcpy(X, buff);				
                P = SearchPrec(A[0],X);
				printf("Di BANDUNG 	: 0x%x\n",P);
				P = SearchPrec(A[1],X);
				printf("Di JAKARTA 	: 0x%x\n",P);
				P = SearchPrec(A[2],X);
				printf("Di SURABAYA	: 0x%x\n",P);
				P = SearchPrec(A[3],X);
				printf("Di MALANG	: 0x%x\n",P);
				P = SearchPrec(A[4],X);
				printf("Di BALI		: 0x%x\n",P);
                break;
			case 6  : 
				printf("List yang dipilih (1/2/3/4/5) : ");
			  	scanf("%d",&pilihlist);
			  	switch (pilihlist) {
			   		case 1  : 
					   	DelVFirst(&A[0],Y);
			      		break;
			   		case 2  : 
			   			DelVFirst(&A[1],Y);
			      		break;
			      	case 3  : 
					   	DelVFirst(&A[2],Y);
			      		break;
			   		case 4  : 
			   			DelVFirst(&A[3],Y);
			      		break;
			      	case 5  : 
					   	DelVFirst(&A[4],Y);
			      		break;
			  	}
			  	break;
			case 7  : 
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
            case 8  : 
				printf("Elemen : ");
				fflush(stdin);
		  		gets(buff);
                strcpy(Y, buff);
		  		printf("List yang dipilih (1/2/3/4/5) : ");
		  		scanf("%d",&pilihlist);
		  		switch (pilihlist) {
		   			case 1  : 
						DelP(&A[0],Y);
		      			break;
		   			case 2  : 
					   	DelP(&A[1],Y);
		      			break;
		      		case 3  : 
						DelP(&A[2],Y);
		      			break;
		   			case 4  : 
					   	DelP(&A[3],Y);
		      			break;
		      		case 5  : 
						DelP(&A[4],Y);
		      			break;
		  		}
			  	break;
			case 9 : 
				printf("List yang dipilih (1/2/3/4/5) : ");
			  	scanf("%d",&pilihlist);
			  	switch (pilihlist) {
			   		case 1  :  
					   	DelAll(&A[0]);
			      		break;
			   		case 2  : 
				   		DelAll(&A[1]);
				      	break;
				    case 3  :  
					   	DelAll(&A[2]);
			      		break;
			   		case 4  : 
				   		DelAll(&A[3]);
				      	break;
				    case 5  :  
					   	DelAll(&A[4]);
			      		break;
			  	}
			  	break;
			case 10  : 
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
			case 11 : 
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
