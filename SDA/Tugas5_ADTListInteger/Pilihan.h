
#inclue
void pilihan(){
/* Kamus Lokal */
 List L1, L2, L3, Lt;
 address P;
 int opt; /* untuk pilihan menu */
 int optlist; /* untuk pilihan list */
 infotype X; /* untuk pencarian alamat elemen dan penambahan elemen */
 infotype Y; /* untuk pengurangan elemen */
 boolean exit; 
 
 /* Algoritma */
 exit = false;
 CreateList(&L1);
 CreateList(&L2);
 CreateList(&L3);
 CreateList(&Lt);
 printf("\t\tPROGRAM LIST LINIER SDA Praktek ");
 printf("\t\t------- ---- ------ ----- --------- ----- -------\n");
 
 
 do {
  Menu();
  scanf("%d",&opt);
  switch (opt) {
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
      scanf("%d",&optlist);
      switch (optlist) {
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
      scanf("%d",&optlist);
      switch (optlist) {
       case 1  : InsVLast(&L1,X);
          break;
       case 2  : InsVLast(&L2,X);
          break;
       case 3  : InsVLast(&L3,X);
          break;
      }
      break;
   case 5  : printf("List yang dipilih (1/2/3) : ");
      scanf("%d",&optlist);
      switch (optlist) {
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
      scanf("%d",&optlist);
      switch (optlist) {
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
      scanf("%d",&optlist);
      switch (optlist) {
       case 1  : DelP(&L1,Y);
          break;
       case 2  : DelP(&L2,Y);
          break;
       case 3  : DelP(&L3,Y);
          break;
      }
      break;
   case 8  : printf("List yang dipilih (1/2/3) : ");
      scanf("%d",&optlist);
      switch (optlist) {
       case 1  : PrintInfo(L1);
          break;
       case 2  : PrintInfo(L2);
          break;
       case 3  : PrintInfo(L3);
          break;
       case 4 : PrintInfo(Lt);
          break;
      }
      break;
   case 9 : printf("List yang dipilih (1/2/3) : ");
      scanf("%d",&optlist);
      switch (optlist) {
       case 1  :  DelAll(&L1);
          break;
       case 2  : DelAll(&L2);
          break;
       case 3  : DelAll(&L3);
          break;
      }
      break;
   case 10 : exit = true; break;
  }
  system("pause");
  }while(!exit);
 DelAll(&L1);
 DelAll(&L2);
 DelAll(&L3);
 DelAll(&Lt);
}
