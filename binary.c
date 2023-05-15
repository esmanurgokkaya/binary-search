#include <stdio.h>
#include <stdlib.h>

// binary search i�in arama yapacak fonksiyon tan�mlan�yor
int binarySearch(int dizi[], int boyut, int deger,int baslangic,int bitis){
	
	// while d�ng�s� ile kontrol yap�lmaya ba�lan�r
	while(baslangic <= bitis){
		
		int orta = (baslangic + bitis) / 2 ;
		// dizi ikiye b�l�n�r ve kar��la�t�rma yap�lmaya ba�lan�r 
		if (dizi[orta] == deger)
			return orta; // arad���m�z de�er bulunmu�sa de�er d�nd�r�l�r
			
		// de�er o de�ilse ortadaki say� ile kontrol edilir ve i�lemler yap�l�r
		if (dizi[orta] < deger)
			baslangic  = orta + 1; // bu blo�a girerse ba�lang�� ad�n� verdi�imiz de�i�ken orta de�i�keninin bir eksi�ine e�itlenir
			
		else 	// bu blo�a girerse de bitis de�i�keni orta de�i�keninin bir eksi�ine e�itlenir
			bitis = orta - 1;
		
	}
	
	
	return -1; // hi�bir blo�a girmezse -1 d�nd�r�l�r ve eleman�n bulunmad��� anla��l�r
}
// diziyi s�ralayabilmek i�in bubble sort algoritmas�n� tan�mlan�yor
void bubbleSort(int dizi[], int boyut){
	int i, j;
	// for i�ine girilerek elemanlar dola��l�r ve s�ralama yap�l�r
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
	// dizi tan�mlan�r ve elemanlar atan�r
	int sayilar[] = {4,8,3,84,47,76,9,24,68};
	int boyut, aranan;
	// dizinin boyutu hesaplan�r
	boyut  = sizeof(sayilar)/sizeof(int);
	// elemanlar� daha rahat bulabilmek i�in bubble sort ile s�ralan�r ve indexler de�i�ir
	bubbleSort(sayilar,boyut);
	// kullan�c�ya gerekli bildirimler yap�l�r 
	printf("**********GIRILEN SAYININ DIZIDE OLUP OLMADIGINI BULMA**********\n\n");
	// kullan�c�dan aranmak istenilen de�er aln�r 
	printf("Aramak istediginiz degeri giriniz\n");
	scanf("%d",&aranan);
	// fonksiyonun sonucu sonuc ad�ndaki bir de�i�kene at�l�r
	int sonuc = binarySearch(sayilar,boyut,aranan,0,boyut-1);
	
	// sonuc de�i�kenindeki de�ere g�re bloklara girilir ve uygun ��kt�lar yazd�r�l�r
	if(sonuc >= 0)
		printf("\nAradiginiz deger dizide %d. sirada bulunmaktadir\n",sonuc+1);
		
	else
		printf("\nAradaginiz deger dizide bulunmamaktadir\n");
	
	
	return 0;
}
