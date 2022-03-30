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



void methodmain(){


	/* Kamus Lokal */
	 List L1, L2, L3,L;
	 address P;
	 
	 int pilihan; /* untuk pilihan menu */
	 int pilihlist; /* untuk pilihan list */
	 infotype X; /* untuk pencarian alamat elemen dan penambahan elemen */
	 infotype Y; /* untuk pengurangan elemen */
	 boolean keluar; 
	 boolean kondisional;
	 
	 /* Algoritma */
	 keluar = false;
	 CreateList(&L1);
	 CreateList(&L2);
	 CreateList(&L3);
	 
	 kondisional = ListEmpty(L) ? (true) : (false); //Ternary operator
	
	 
	 
	 do {
	  Menu();
	  scanf("%d",&pilihan);
	  switch (pilihan) {
	   case 1  : printf("Elemen yang dicari : ");
	      scanf("%d",&X);
	      P = Search(L1,X);
	      printf("Di L1 : 0x%x\n",P);
	      P = Search(L2,X);
	      printf("Di L2 : 0x%x\n",P);
	      P = Search(L3,X);
	      printf("Di L3 : 0x%x\n",P);
	      break;
	   case 2  : printf("Elemen yang dicari : ");
	      scanf("%d",&X);
	      P = SearchPrec(L1,X);
	      printf("Di L1 : 0x%d\n",P);
	      P = SearchPrec(L2,X);
	      printf("Di L2 : 0x%d\n",P);
	      P = SearchPrec(L3,X);
	      printf("Di L3 : 0x%d\n",P);
	      break;
	   case 3  : printf("Elemen : ");
	      scanf("%d",&X);
	      printf("List yang dipilih (1/2/3) : ");
	      scanf("%d",&pilihlist);
	      switch (pilihlist) {
	       case 1  : InsVFirst(&L1,X);
	          break;
	       case 2  : InsVFirst(&L2,X);
	          break;
	       case 3  : InsVFirst(&L3,X);
	          break;
	      }
	      break;
	   case 4  : printf("Elemen : ");
	      scanf("%d",&X);
	      printf("List yang dipilih (1/2/3) : ");
	      scanf("%d",&pilihlist);
	      switch (pilihlist) {
	       case 1  : InsVLast(&L1,X);
	          break;
	       case 2  : InsVLast(&L2,X);
	          break;
	       case 3  : InsVLast(&L3,X);
	          break;
	      }
	      break;
	   case 5  : printf("List yang dipilih (1/2/3) : ");
	      scanf("%d",&pilihlist);
	      switch (pilihlist) {
	       case 1  : DelVFirst(&L1,&Y);
	          break;
	       case 2  : DelVFirst(&L2,&Y);
	          break;
	       case 3  : DelVFirst(&L3,&Y);
	          break;
	      }
	      printf("Elemen yang dihapus : %d\n",Y);
	      break;
	   case 6  : printf("List yang dipilih (1/2/3) : ");
	      scanf("%d",&pilihlist);
	      switch (pilihlist) {
	       case 1  : DelVLast(&L1,&Y);
	          break;
	       case 2  : DelVLast(&L2,&Y);
	          break;
	       case 3  : DelVLast(&L3,&Y);
	          break;
	      }
	      printf("Elemen yang dihapus : %d\n",Y);
	      break;
	   case 7  : printf("Elemen : ");
	      scanf("%d",&Y);
	      printf("List yang dipilih (1/2/3) : ");
	      scanf("%d",&pilihlist);
	      switch (pilihlist) {
	       case 1  : DelP(&L1,Y);
	          break;
	       case 2  : DelP(&L2,Y);
	          break;
	       case 3  : DelP(&L3,Y);
	          break;
	      }
	      break;
	   case 8  : printf("List yang dipilih (1/2/3) : ");
	      scanf("%d",&pilihlist);
	      switch (pilihlist) {
	       case 1  : PrintInfo(L1);
	          break;
	       case 2  : PrintInfo(L2);
	          break;
	       case 3  : PrintInfo(L3);
	          break;
	      }
	      break;
	   case 9 : printf("List yang dipilih (1/2/3) : ");
	      scanf("%d",&pilihlist);
	      switch (pilihlist) {
	       case 1  :  DelAll(&L1);
	          break;
	       case 2  : DelAll(&L2);
	          break;
	       case 3  : DelAll(&L3);
	          break;
	      }
	      break;
	   case 10 : keluar = true; 
	   break;
	  }
	  system("pause");
	  }while(!keluar);
	 DelAll(&L1);
	 DelAll(&L2);
	 DelAll(&L3);
	
}
