/****************************************************************\
**				         	SAKARYA ÜNİVERSİTESİ
**				  BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				     BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**					  PROGRAMLAMAYA GİRİŞİ DERSİ
**
**		   	  ÖDEV NUMARASI.............:   2
**			  ÖĞRENCİ ADI...............:   Eren Kara
**			  ÖĞRENCİ NUMARASI..........:   B211210031
**			  DERS GRUBU................:   1-A
*****************************************************************/

#include <iostream>
#include <iomanip>
#include <locale.h>
#include <string>
#include <time.h>
#include <stdlib.h>     

using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");		// Ekrana Türkçe karakterler bastırabilmek için.
	srand(time(0));                     // Rastgele seçimlerin farklı olmasını sağlıyor.

	string sehirler[] = { "adana","adıyaman","afyonkarahisar","ağrı","amasya","ankara","antalya",
	"artvin","aydın","balıkesir","bilecik","bingöl","bitlis","bolu","burdur","bursa",
	"çanakkale","çankırı","çorum","denizli","diyarbakır","edirne","elazığ","erzincan",
	"erzurum","eskişehir","gaziantep","giresun","gümüşhane","hakkari","hatay","ısparta",
	"mersin","istanbul","izmir","kars","kastamonu","kayseri","kırklareli","kırşehir",
	"kocaeli","konya","kütahya","malatya","manisa","kahramanmaraş","mardin","muğla","muş",
	"nevşehir","niğde","ordu","rize","sakarya","samsun","siirt","sinop","sivas","tekirdağ",
	"tokat","trabzon","tunceli","şanlıurfa","uşak","van","yozgat","zonguldak","aksaray",
	"bayburt","karaman","kırıkkale","batman","şırnak","bartın","ardahan","ığdır","yalova",
	"karabük","kilis","osmaniye","düzce" };

	string bulunanSehirler[15];			// Programın sonunda ekrana bulunan şehirleri çıktı olarak yazmak için.	
	string bulunamadi = { "Bulunamadı" };
	string rastgele[20];
	int eslesmeGlobal = 0;				// Yerel olarak sürekli sıfırlanan eslesme durumu göstergemi döngünün dışında da kullanabilmek için oluşturduğum değişken.
	int b = 0;							// For döngüsünde sürekli tekrar tekrar 0 dan başlamasın diye globalde tanımladığım for döngüsünün sayacı.
	int bulunanSayac = 0;				// Kaç tane il eşleşmesi oldu onu sayıyor. Ayrıca döngülerde kolaylık sağlıyor.
	int d = 0;						    // For döngüsünde sürekli tekrar tekrar 0 dan başlamasın diye globalde tanımladığım for döngüsünün sayacı.
	int kisaDizi = 0;
	int uzunDizi = 0;
	int kisaSehir = 0;
	int uzunSehir = 0;
	long deneme[20];

	for (int k = 0; k < 81; k++)    //Buradaki for döngüsü Türkiyenin illerinin en uzununu ve en kısasını buluyor.
	{
		if (kisaSehir == 0)         // Buradaki if zinciri en uzun ve en kısa ili başlangıçta 0 kabul ederek gerçek sonucu buluyor.
		{
			kisaSehir = sehirler[k].length();
			uzunSehir = sehirler[k].length();
		}
		else if (sehirler[k].length() < kisaSehir)
		{
			kisaSehir = sehirler[k].length();
			kisaDizi = k;
		}
		else if (sehirler[k].length() > uzunSehir)
		{
			uzunSehir = sehirler[k].length();
			uzunDizi = k;
		}
	}

	int kisaSehirSabit = kisaSehir;
	cout << "En az  harfli şehir: " << sehirler[kisaDizi] << endl;
	cout << "En çok harfli şehir: " << sehirler[uzunDizi] << endl<<endl;

	for (int i = 0; i < (uzunSehir - kisaSehirSabit + 1); i++)   // Buradaki for döngüsü en çok karakterli il kadar döngüyü terkarlıyor.
	{
		for (int j = 0; j < 100000; j++)      // Buradaki for döngüsü 100.000 defa tekrarlanmasını sağlıyor.
		{
			int secilenKucuk = 0;
			eslesmeGlobal = 0;
			string tahmin = "";

			for (int k = 0; k < kisaSehir; k++)     // Rastgele il seçtiren for döngüsü.
			{
				rastgele[k] = (sehirler[rand() % 81]);

				if (secilenKucuk == 0)
					secilenKucuk = rastgele[k].length();

				else if (rastgele[k].length() < secilenKucuk)
					secilenKucuk = rastgele[k].length();
			}

			for (int a = 0; a < secilenKucuk; a++)       //  Seçilen illerden en az karakterli olan il kadar rasgele kelime oluşturan döngü.
			{
				int eslesme = 0;   //  Eşleşmenin durumunu belirlemek için.

				for (int e = 0; e < kisaSehir; e++)      // Rastgele kelime seçme.
				{
					tahmin += rastgele[e][a];
				}

				for (int t = 0; t < 81; t++)             // Seçilen illeri karşılaştırma. 
				{
					if (tahmin == sehirler[t])           // Herhangi bir eşleşmede daha sonra kullanmak için eşleşme değişkenini 1 yapan yapı.
						eslesme = 1;
				}

				eslesmeGlobal = eslesme;

				if (eslesme == 1)    // Eşleşme durumunda içindekileri çalıştıran yapı.
				{
					bulunanSayac += 1;

					for (d; d < 20;)     // Kaç denemede sonucun bulunduğunu içinde tutan diziyi oluşturmak için kullandığım for döngüsü.
					{
						deneme[d] = j + 1;
						d++;
						break;
					}

					for (b; b < bulunanSayac;)       // Bulunan illeri global bir string altında toplayıp çıktı olarak vermemi sağlayan döngü.
					{
						bulunanSehirler[b] = tahmin;
						cout <<left<<setw(6)<<deneme[b] << ". denemede " << left << setw(3) << b + 3 << "karakterli bulunan şehir ==> " << bulunanSehirler[b] << endl;
						b++;
						break;
					}
					
					break;
				}
				else if (eslesme == 0)     // Eşleşme olmaması durumunda tahmini 0'lıyor.
					tahmin = "";
			}

			if (eslesmeGlobal == 1)  // Eşleşen bir şehir bulduğunda döngünün 100.000 defa tekrar etmesini engelleyen yapı.
				break;

			if (j == 99999 && eslesmeGlobal == 0)  // Eğerki 100.000 defa denemede bir eşleşme olmaz ise ekrana bulunamadı yazmak için.
			{
				for (d; d < 20;)                   // 100.000 . denemede eşleşme olmadığını diziye aktardığım döngü.
				{
					deneme[d] = j + 1;
					d++;
					break;
				}

				bulunanSayac += 1;

				for (b; b < bulunanSayac;)         // Bulunamayan şehirler için bulunamadı yazmamı sağlıyor.
				{
					bulunanSehirler[b] = bulunamadi;
					cout << deneme[b] << ". denemede " << left << setw(3) << b + 3 << "karakterli bulunan şehir ==> " << bulunanSehirler[b] << endl;
					b++;
					break;
				}
			}
		}
		if (kisaSehir < uzunSehir)	 // 3 karakterli illeri bulduktan sonra 4 5 ... karakterli illeri bulmamı sağlayan yapı.
			kisaSehir += 1;
	}
}