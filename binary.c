#include <stdio.h>
#include <stdlib.h>

// binary search için arama yapacak fonksiyon tanýmlanýyor
int binarySearch(int dizi[], int boyut, int deger,int baslangic,int bitis){
	
	// while döngüsü ile kontrol yapýlmaya baþlanýr
	while(baslangic <= bitis){
		
		int orta = (baslangic + bitis) / 2 ;
		// dizi ikiye bölünür ve karþýlaþtýrma yapýlmaya baþlanýr 
		if (dizi[orta] == deger)
			return orta; // aradýðýmýz deðer bulunmuþsa deðer döndürülür
			
		// deðer o deðilse ortadaki sayý ile kontrol edilir ve iþlemler yapýlýr
		if (dizi[orta] < deger)
			baslangic  = orta + 1; // bu bloða girerse baþlangýç adýný verdiðimiz deðiþken orta deðiþkeninin bir eksiðine eþitlenir
			
		else 	// bu bloða girerse de bitis deðiþkeni orta deðiþkeninin bir eksiðine eþitlenir
			bitis = orta - 1;
		
	}
	
	
	return -1; // hiçbir bloða girmezse -1 döndürülür ve elemanýn bulunmadýðý anlaþýlýr
}
// diziyi sýralayabilmek için bubble sort algoritmasýný tanýmlanýyor
void bubbleSort(int dizi[], int boyut){
	int i, j;
	// for içine girilerek elemanlar dolaþýlýr ve sýralama yapýlýr
	for(i = 0 ; i < boyut - 1 ; i++){
		for(j = 0 ; j < boyut - i - 1 ; j++){
			if( dizi[j] > dizi[j + 1]){
				int sayi = dizi [j];
				dizi[j] = dizi[j + 1];
				dizi[j + 1] = sayi;
			}
			
		}
	}
}
int main() {
	// dizi tanýmlanýr ve elemanlar atanýr
	int sayilar[] = {4,8,3,84,47,76,9,24,68};
	int boyut, aranan;
	// dizinin boyutu hesaplanýr
	boyut  = sizeof(sayilar)/sizeof(int);
	// elemanlarý daha rahat bulabilmek için bubble sort ile sýralanýr ve indexler deðiþir
	bubbleSort(sayilar,boyut);
	// kullanýcýya gerekli bildirimler yapýlýr 
	printf("**********GIRILEN SAYININ DIZIDE OLUP OLMADIGINI BULMA**********\n\n");
	// kullanýcýdan aranmak istenilen deðer alnýr 
	printf("Aramak istediginiz degeri giriniz\n");
	scanf("%d",&aranan);
	// fonksiyonun sonucu sonuc adýndaki bir deðiþkene atýlýr
	int sonuc = binarySearch(sayilar,boyut,aranan,0,boyut-1);
	
	// sonuc deðiþkenindeki deðere göre bloklara girilir ve uygun çýktýlar yazdýrýlýr
	if(sonuc >= 0)
		printf("\nAradiginiz deger dizide %d. sirada bulunmaktadir\n",sonuc+1);
		
	else
		printf("\nAradaginiz deger dizide bulunmamaktadir\n");
	
	
	return 0;
}
