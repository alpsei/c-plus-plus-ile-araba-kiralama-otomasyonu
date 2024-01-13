/*Ad Soyad: Alper Serin 
  Numara: 2312729001 
  Proje: Ara� kiralama otomasyonu */

#include <iostream>
#include <locale.h>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct bilgi
{
  char ad[80];
  char cinsiyet;
  int yas;
  char aracmarka[80];
  char aracmodel[80];
  int aracyil;
  char aracplaka[80];
  char alinacakkonum[80];
  char birakilacakkonum[80];
  int arackm;
  int sure;
  char calistigikonum[80];
  int isebaslamayil;
  int saatlikfiyat;
  int toplamfiyat;
  //float kdv = 18/100;
};


int musterikayit()
{
	char secim;
	bilgi musteri;
  ofstream dosya("musteri.dat", ios::binary);
  do
  {
  	cout<<"\nAd: ";
  	cin>>musteri.ad;
  	cout<<"Cinsiyet (E/K): ";
  	musteri.cinsiyet = getche();
  	cout<<"\nYa�: ";
  	cin>>musteri.yas;
  	if(musteri.yas<18)
  	{
  		cout<<"Ara� kiralamas� yap�lamaz!";
  		return 0;
	  }
	cout<<"Kiralanacak arac�n markas�n� giriniz: ";
	cin>>musteri.aracmarka; cout<<endl;
	cout<<"Kiralanacak arac�n modelini giriniz: ";
	cin>>musteri.aracmodel; cout<<endl;
	cout<<"Kiralanacak arac�n �retim y�l�n� giriniz: ";
	cin>>musteri.aracyil; cout<<endl;
	cout<<"Kiralanacak arac�n teslim edilmeden �nceki km bilgisini giriniz: ";
	cin>>musteri.arackm; cout<<endl;
	cout<<"Kiralanacak arac�n plakas�n� giriniz: ";
	cin>>musteri.aracplaka; cout<<endl;
	cout<<"Kiralanacak arac�n teslim verilece�i konum bilgisini giriniz: ";
	cin>>musteri.alinacakkonum; cout<<endl;
	cout<<"Kiralanacak arac�n teslim al�naca�� konum bilgisini giriniz: ";
	cin>>musteri.birakilacakkonum; cout<<endl;
	cout<<"Arac�n ne kadar s�re kiralanaca��n� giriniz (saat cinsinden): ";
	cin>>musteri.sure; cout<<endl;
	cout<<"Arac�n saatlik kira �creti: ";
	cin>>musteri.saatlikfiyat; cout<<endl;
	musteri.toplamfiyat = (musteri.saatlikfiyat * musteri.sure * 0.18) + (musteri.saatlikfiyat * musteri.sure);
	cout<<"M��terinin �deyece�i toplam �cret (%18 KDV Dahil): "<<musteri.toplamfiyat;
	
	dosya.write(reinterpret_cast<char*>(&musteri), sizeof(musteri));
	cout<<"\nBa�ka kay�t eklemek istiyor musunuz?(E/H)"; secim = getch();
	if(secim == 'h' || secim == 'H')
	{
		system("cls");
		return 0;
	}
  }
  while(secim =='E' || secim == 'e');
  dosya.close();
}

int musteriguncelle()
{
	bilgi musteri;
	char isim[80];
	char secim;
	bool var =false;
	
	ifstream dosya;
	dosya.open("musteri.dat",ios::binary);
	cout<<"\n\nKayd�n� d�zeltece�iniz m��terinin ad�n� giriniz: ";
	cin>>isim;
	dosya.seekg(0, ios::end);
	int kayitsayisi = dosya.tellg()/sizeof(musteri);
	for(int i=0; i<kayitsayisi; i++)
	{
		dosya.seekg(i*sizeof(musteri));
		dosya.read(reinterpret_cast<char*>(&musteri), sizeof(musteri));
		if(strcmp(musteri.ad, isim)==0);
		{
			var=true;
			cout<<endl;
			cout<<"M��teri";
			cout<<"\nAd�: "<<musteri.ad;
			cout<<"\nCinsiyeti: ";
			if(musteri.cinsiyet == 'e' || musteri.cinsiyet == 'e')
			{
				cout<<"Erkek";
			}
			if (musteri.cinsiyet == 'K' || musteri.cinsiyet == 'k')
			{
				cout<<"Kad�n";
			}
			cout<<"\nYa��: "<<musteri.yas;
			cout<<"\nAra� markas�: "<<musteri.aracmarka;
			cout<<"\nAra� modeli: "<<musteri.aracmodel;
			cout<<"\nAra� �retim y�l�: "<<musteri.aracyil;
			cout<<"\nAra� plakas�: "<<musteri.aracplaka;
			cout<<"\nArac�n al�naca�� konum: "<<musteri.alinacakkonum;
			cout<<"\nArac�n b�rak�laca�� konum: "<<musteri.birakilacakkonum;
			cout<<"\nAra� KM'si: "<<musteri.arackm;
			cout<<"\nKira s�resi: "<<musteri.sure;
			cout<<"\nArac�n saatlik �creti: "<<musteri.saatlikfiyat;
			cout<<"\nM��terinin �deyece�i toplam �cret: "<<musteri.toplamfiyat;
			cout<<"D�zeltmek istedi�iniz kay�t bu mu? (E/H): ";
			secim=getche();
			cout<<endl;
			if(secim=='H'||secim=='h')
			{
				bilgi y_musteri;
				ofstream y_dosya("yedek.dat", ios::binary);
				strcpy(y_musteri.ad,musteri.ad);
				y_musteri.yas = musteri.yas;
				y_musteri.cinsiyet = musteri.cinsiyet;
				strcpy(y_musteri.aracmarka,musteri.aracmarka);
				strcpy(y_musteri.aracmodel,musteri.aracmodel);
				y_musteri.aracyil = musteri.aracyil;
				strcpy(y_musteri.aracplaka,musteri.aracplaka);
				strcpy(y_musteri.alinacakkonum,musteri.alinacakkonum);
				strcpy(y_musteri.birakilacakkonum,musteri.birakilacakkonum);
				y_musteri.arackm = musteri.arackm;
				y_musteri.sure = musteri.sure;
				y_musteri.saatlikfiyat = musteri.saatlikfiyat;
				y_musteri.toplamfiyat = musteri.toplamfiyat;
				y_dosya.write(reinterpret_cast<char*>(&y_musteri), sizeof(y_musteri));
				y_dosya.close();
			}
			else if(secim =='E' || secim =='e')
			{
				ofstream dosya;
				dosya.open("yedek.dat", ios::app | ios::binary);
				cout<<"Ad�: ";
				cin>>musteri.ad;
			cout<<"\nCinsiyeti (E/K): ";
			musteri.cinsiyet = getche();
			cout<<"\nYa��: ";
			cin>>musteri.yas;
			cout<<"\nAra� markas�: ";
			cin>>musteri.aracmarka;
			cout<<"\nAra� modeli: ";
			cin>>musteri.aracmodel;
			cout<<"\nAra� �retim y�l�: ";
			cin>>musteri.aracyil;
			cout<<"\nAra� plakas�: ";
			cin>>musteri.aracplaka;
			cout<<"\nArac�n al�naca�� konum: ";
			cin>>musteri.alinacakkonum;
			cout<<"\nArac�n b�rak�laca�� konum: ";
			cin>>musteri.birakilacakkonum;
			cout<<"\nAra� KM'si: ";
			cin>>musteri.arackm;
			cout<<"\nKira s�resi: ";
			cin>>musteri.sure;
			cout<<"\nArac�n saatlik �creti: ";
			cin>>musteri.saatlikfiyat;
			musteri.toplamfiyat = (musteri.saatlikfiyat * musteri.sure * 0.18) + (musteri.saatlikfiyat * musteri.sure);
			cout<<"\nToplam �cret: "<<musteri.toplamfiyat;
			dosya.write(reinterpret_cast<char*>(&musteri), sizeof(musteri));
			dosya.close();
				
			}
			else
			{
				bilgi y_musteri;
				ofstream y_dosya("yedek.dat", ios::binary);
				strcpy(y_musteri.ad,musteri.ad);
				y_musteri.yas = musteri.yas;
				y_musteri.cinsiyet = musteri.cinsiyet;
				strcpy(y_musteri.aracmarka,musteri.aracmarka);
				strcpy(y_musteri.aracmodel,musteri.aracmodel);
				y_musteri.aracyil = musteri.aracyil;
				strcpy(y_musteri.aracplaka,musteri.aracplaka);
				strcpy(y_musteri.alinacakkonum,musteri.alinacakkonum);
				strcpy(y_musteri.birakilacakkonum,musteri.birakilacakkonum);
				y_musteri.arackm = musteri.arackm;
				y_musteri.sure = musteri.sure;
				y_musteri.saatlikfiyat = musteri.saatlikfiyat;
				y_musteri.toplamfiyat = musteri.toplamfiyat;
				y_dosya.write(reinterpret_cast<char*>(&y_musteri), sizeof(y_musteri));
				y_dosya.close();
			}
		}
		
	}
	dosya.close();
		if(var)
		{
			remove("musteri.dat");
			rename("yedek.dat","musteri.dat");
			cout<<"\nKay�t d�zeltildi"<<endl;
		}
		else
		{
			remove("yedek.dat");
			cout<<"Kay�t bulunamad�"<<endl;
		}
	getch();
}

int musterisil()
{
	char isim[80];
	char secim =' ';
	bilgi musteri;
	bool var=false;
	ifstream dosya;
	dosya.open("musteri.dat", ios::binary);
	cout<<"\n\nKayd�n� silece�iniz m��terinin ad�n� giriniz: ";
	cin>>isim;
	dosya.seekg(0, ios::end);
	int kayitsayisi = dosya.tellg()/sizeof(musteri);
	for(int i=0; i<kayitsayisi; i++)
	{
		dosya.seekg(i*sizeof(musteri));
		dosya.read(reinterpret_cast<char*>(&musteri), sizeof(musteri));
		if(strcmp(musteri.ad, isim)==0)
		{
			cout<<endl;
			cout<<"M��terinin";
			cout<<"\nAd: "<<musteri.ad;
			cout<<"\nYa��: "<<musteri.yas;
			cout<<"\nAra� plakas�: "<<musteri.aracplaka;
			
			cout<<"\n\nSilmek istedi�iniz kay�t bu mu? (E/H): ";
			secim=getch();
			if(secim == 'H' || secim == 'h')
			{
				bilgi y_musteri;
				ofstream y_dosya("yedek.dat", ios::binary);
				strcpy(y_musteri.ad,musteri.ad);
				y_musteri.yas = musteri.yas;
				y_musteri.cinsiyet = musteri.cinsiyet;
				strcpy(y_musteri.aracmarka,musteri.aracmarka);
				strcpy(y_musteri.aracmodel,musteri.aracmodel);
				y_musteri.aracyil = musteri.aracyil;
				strcpy(y_musteri.aracplaka,musteri.aracplaka);
				strcpy(y_musteri.alinacakkonum,musteri.alinacakkonum);
				strcpy(y_musteri.birakilacakkonum,musteri.birakilacakkonum);
				y_musteri.arackm = musteri.arackm;
				y_musteri.sure = musteri.sure;
				y_musteri.saatlikfiyat = musteri.saatlikfiyat;
				y_musteri.toplamfiyat = musteri.toplamfiyat;
				y_dosya.write(reinterpret_cast<char*>(&y_musteri), sizeof(y_musteri));
				y_dosya.close();
				
			}
			if(secim == 'e' || secim == 'E')
			{
				var = true;
			}
		}	
		else
		{
			bilgi y_musteri;
				ofstream y_dosya("yedek.dat", ios::binary);
				strcpy(y_musteri.ad,musteri.ad);
				y_musteri.yas = musteri.yas;
				y_musteri.cinsiyet = musteri.cinsiyet;
				strcpy(y_musteri.aracmarka,musteri.aracmarka);
				strcpy(y_musteri.aracmodel,musteri.aracmodel);
				y_musteri.aracyil = musteri.aracyil;
				strcpy(y_musteri.aracplaka,musteri.aracplaka);
				strcpy(y_musteri.alinacakkonum,musteri.alinacakkonum);
				strcpy(y_musteri.birakilacakkonum,musteri.birakilacakkonum);
				y_musteri.arackm = musteri.arackm;
				y_musteri.sure = musteri.sure;
				y_musteri.saatlikfiyat = musteri.saatlikfiyat;
				y_musteri.toplamfiyat = musteri.toplamfiyat;
				y_dosya.write(reinterpret_cast<char*>(&y_musteri), sizeof(y_musteri));
				y_dosya.close();
			}	
	}
	dosya.close();
	if(var)
	{
		remove("musteri.dat");
		rename("yedek.dat","musteri.dat");
		cout<<"\nKay�t silindi"<<endl;
	}
	else
	{
		remove("yedek.dat");
		cout<<"\nKay�t bulunamad�"<<endl;
	}
}

int musterilistele()
{
	bilgi musteri;
	ifstream dosya("musteri.dat", ios::binary);
	dosya.seekg(0, ios::end);
	int kayitsayisi = dosya.tellg()/sizeof(musteri);
	cout<<"\nDosyada "<<kayitsayisi<<" tane kay�tl� m��teri bulunmaktad�r.\n";
	if(kayitsayisi>0)
	{
		for(int i=0; i<kayitsayisi; i++)
		{
			cout<<endl;
			cout<<i+1<<".m��teri"<<endl;
			dosya.seekg(i*sizeof(musteri));
			dosya.read(reinterpret_cast<char*>(&musteri), sizeof(musteri));
			cout<<endl;
			cout<<"M��TER�N�N:"<<endl;
			cout<<"Ad�: "<<musteri.ad;
			cout<<"\nCinsiyeti: ";
			if(musteri.cinsiyet == 'e' || musteri.cinsiyet == 'e')
			{
				cout<<"Erkek";
			}
			if (musteri.cinsiyet == 'K' || musteri.cinsiyet == 'k')
			{
				cout<<"Kad�n";
			}
			cout<<"\nYa��: "<<musteri.yas;
			cout<<"\nAra� markas�: "<<musteri.aracmarka;
			cout<<"\nAra� modeli: "<<musteri.aracmodel;
			cout<<"\nAra� �retim y�l�: "<<musteri.aracyil;
			cout<<"\nAra� plakas�: "<<musteri.aracplaka;
			cout<<"\nArac�n al�naca�� konum: "<<musteri.alinacakkonum;
			cout<<"\nArac�n b�rak�laca�� konum: "<<musteri.birakilacakkonum;
			cout<<"\nAra� KM'si: "<<musteri.arackm;
			cout<<"\nKira s�resi: "<<musteri.sure;
			cout<<"\nArac�n saatlik �creti: "<<musteri.saatlikfiyat;
			cout<<"\nToplam �cret: "<<musteri.toplamfiyat;
		}
		
	}
	else
	cout<<"\nDosyada hi� kay�t yok"<<endl;
	dosya.close();
	return 0;
}

int musteriara()
{
	bilgi musteri;
	char isim[80];
	bool var;
	ifstream dosya; 
	dosya.open("musteri.dat", ios::binary);
	cout<<"\nKayd�n� bulmak istedi�iniz m��terinin ad�n� giriniz: ";
	cin>>isim;
	dosya.seekg(0, ios::end);
	int kayitsayisi = dosya.tellg()/sizeof(musteri);
	for(int i=0; i<kayitsayisi; i++)
	{
		dosya.seekg(i*sizeof(musteri));
		dosya.read(reinterpret_cast<char*>(&musteri), sizeof(musteri));
		if(strcmp(musteri.ad,isim) == 0)
		{
			cout<<endl<<i+1<<".Kay�tta bulundu"<<endl;
			var=true;
			cout<<endl;
			cout<<"M��terinin";
			cout<<endl;
			cout<<"Ad�: "<<musteri.ad;
			cout<<"\nCinsiyeti: ";
			if(musteri.cinsiyet == 'e' || musteri.cinsiyet == 'e')
			{
				cout<<"Erkek";
			}
			if (musteri.cinsiyet == 'K' || musteri.cinsiyet == 'k')
			{
				cout<<"Kad�n";
			}
			cout<<"\nYa��: "<<musteri.yas;
			cout<<"\nAra� markas�: "<<musteri.aracmarka;
			cout<<"\nAra� modeli: "<<musteri.aracmodel;
			cout<<"\nAra� �retim y�l�: "<<musteri.aracyil;
			cout<<"\nAra� plakas�: "<<musteri.aracplaka;
			cout<<"\nArac�n al�naca�� konum: "<<musteri.alinacakkonum;
			cout<<"\nArac�n b�rak�laca�� konum: "<<musteri.birakilacakkonum;
			cout<<"\nAra� KM'si: "<<musteri.arackm;
			cout<<"\nKira s�resi: "<<musteri.sure;
			cout<<"\nArac�n saatlik �creti: "<<musteri.saatlikfiyat;
			cout<<"\nToplam �cret: "<<musteri.toplamfiyat;
		}
	}
	if(!var)
	cout<<"\nKay�tta bulunamad�"<<endl;
	dosya.close();
}
int personelkayit()
{
	char secim;
	bilgi personel;
  ofstream dosya("personel.dat", ios::binary);
  do
  {
  	cout<<"\nAd: ";
  	cin>>personel.ad;
  	cout<<"Cinsiyet (E/K): ";
  	personel.cinsiyet=getche();
  	cout<<"\nYa�: ";
  	cin>>personel.yas;
  	if(personel.yas<18)
  	{
  		cout<<"Personel kayd� yap�lamaz!";
  		break;
	  }
  	cout<<"\nPersonelin �al��t��� alan: ";
  	cin>>personel.calistigikonum;
	cout<<"\nPersonelin i�e ba�lama y�l�: ";
	cin>>personel.isebaslamayil;
	cout<<endl;
  	cout<<endl;
	dosya.write(reinterpret_cast<char*>(&personel), sizeof(personel));
	cout<<"\nBa�ka kay�t eklemek istiyor musunuz?(E/H)"; secim = getch();
	
	if(secim=='h' || secim == 'H')
	{
		system("cls");
		return 0;
	}
  }
  while(secim =='E' || secim == 'e');
  dosya.close();
}

int personelguncelle()
{
	bilgi personel;
	char isim[80];
	char secim;
	bool var =false;
	
	ifstream dosya;
	dosya.open("personel.dat",ios::binary);
	cout<<"\n\nKayd�n� d�zeltece�iniz personelin ad�n� giriniz: ";
	cin>>isim;
	dosya.seekg(0, ios::end);
	int kayitsayisi = dosya.tellg()/sizeof(personel);
	for(int i=0; i<kayitsayisi; i++)
	{
		dosya.seekg(i*sizeof(personel));
		dosya.read(reinterpret_cast<char*>(&personel), sizeof(personel));
		if(strcmp(personel.ad, isim)==0);
		{
			var=true;
			cout<<endl;
			cout<<"Personelin"<<endl;
			cout<<"Ad�: "<<personel.ad;
			cout<<"\nCinsiyeti: ";
			if(personel.cinsiyet == 'e' || personel.cinsiyet == 'e')
			{
				cout<<"Erkek";
			}
			if (personel.cinsiyet == 'K' || personel.cinsiyet == 'k')
			{
				cout<<"Kad�n";
			}
			cout<<"\nYa��: "<<personel.yas;
			cout<<"\n�al��t��� konum: "<<personel.calistigikonum;
			cout<<"\nPersonelin i�e ba�lama y�l�: "<<personel.isebaslamayil;
			cout<<"D�zeltmek istedi�iniz kay�t bu mu? (E/H): ";
			secim=getche();
			cout<<endl;
			if(secim=='H'||secim=='h')
			{
				bilgi y_personel;
				ofstream y_dosya("yedekpersonel.dat", ios::binary);
				strcpy(y_personel.ad,personel.ad);
				y_personel.yas = personel.yas;
				y_personel.cinsiyet = personel.cinsiyet;
				strcpy(y_personel.calistigikonum,personel.calistigikonum);
				y_personel.isebaslamayil = personel.isebaslamayil;
				y_dosya.write(reinterpret_cast<char*>(&y_personel), sizeof(y_personel));
				y_dosya.close();
			}
			else if(secim =='E' || secim =='e')
			{
				ofstream dosya;
				dosya.open("yedekpersonel.dat", ios::app | ios::binary);
				cout<<"Ad�: ";
				cin>>personel.ad;
			cout<<"\nCinsiyeti (E/K): ";
			personel.cinsiyet = getche();
			cout<<"\nYa��: ";
			cin>>personel.yas;
			cout<<"\n�al��t��� Konum: ";
			cin>>personel.calistigikonum;
			cout<<"\nPersonelin i�e ba�lama y�l�: ";
          	cin>>personel.isebaslamayil;
			dosya.write(reinterpret_cast<char*>(&personel), sizeof(personel));
			dosya.close();
				
			}
			else
			{
				bilgi y_personel;
				ofstream y_dosya("yedekpersonel.dat", ios::binary);
				strcpy(y_personel.ad,personel.ad);
				y_personel.yas = personel.yas;
				y_personel.cinsiyet = personel.cinsiyet;
				strcpy(y_personel.calistigikonum,personel.calistigikonum);
				y_personel.isebaslamayil = personel.isebaslamayil;
				y_dosya.write(reinterpret_cast<char*>(&y_personel), sizeof(y_personel));
				y_dosya.close();
			}
		}
		
	}
	dosya.close();
		if(var)
		{
			remove("personel.dat");
			rename("yedekpersonel.dat","personel.dat");
			cout<<"\nKay�t d�zeltildi"<<endl;
		}
		else
		{
			remove("yedekpersonel.dat");
			cout<<"Kay�t bulunamad�"<<endl;
		}
	getch();
}

int personelsil()
{
	char isim[80];
	char secim =' ';
	bilgi personel;
	bool var=false;
	ifstream dosya;
	dosya.open("personel.dat", ios::binary);
	cout<<"\n\nKayd�n� silece�iniz personelin ad�n� giriniz: ";
	cin>>isim;
	dosya.seekg(0, ios::end);
	int kayitsayisi = dosya.tellg()/sizeof(personel);
	for(int i=0; i<kayitsayisi; i++)
	{
		dosya.seekg(i*sizeof(personel));
		dosya.read(reinterpret_cast<char*>(&personel), sizeof(personel));
		if(strcmp(personel.ad, isim)==0)
		{
			cout<<endl;
			cout<<"Personelin";
			cout<<"\nAd: "<<personel.ad;
			cout<<"\nYa��: "<<personel.yas;
			cout<<"\n�al��t��� Konum: "<<personel.calistigikonum;
			cout<<"\nPersonelin i�e ba�lama y�l�: "<<personel.isebaslamayil;
			cout<<"\n\nSilmek istedi�iniz kay�t bu mu? (E/H): ";
			secim=getch();
			if(secim == 'H' || secim == 'h')
			{
				bilgi y_personel;
				ofstream y_dosya("yedekpersonel.dat", ios::binary);
				strcpy(y_personel.ad,personel.ad);
				y_personel.yas = personel.yas;
				y_personel.cinsiyet = personel.cinsiyet;
				strcpy(y_personel.calistigikonum,personel.calistigikonum);
				y_personel.isebaslamayil = personel.isebaslamayil;
				y_dosya.write(reinterpret_cast<char*>(&y_personel), sizeof(y_personel));
				y_dosya.close();
				
			}
			if(secim == 'e' || secim == 'E')
			{
				var = true;
			}
		}	
		else
		{
			bilgi y_personel;
				ofstream y_dosya("yedekpersonel.dat", ios::binary);
				strcpy(y_personel.ad,personel.ad);
				y_personel.yas = personel.yas;
				y_personel.cinsiyet = personel.cinsiyet;
				strcpy(y_personel.calistigikonum,personel.calistigikonum);
				y_personel.isebaslamayil = personel.isebaslamayil;
				y_dosya.write(reinterpret_cast<char*>(&y_personel), sizeof(y_personel));
				y_dosya.close();
			}	
	}
	dosya.close();
	if(var)
	{
		remove("personel.dat");
		rename("yedekpersonel.dat","personel.dat");
		cout<<"\nKay�t silindi"<<endl;
	}
	else
	{
		remove("yedek.dat");
		cout<<"\nKay�t bulunamad�"<<endl;
	}
}

int personellistele()
{
	bilgi personel;
	ifstream dosya("personel.dat", ios::binary);
	dosya.seekg(0, ios::end);
	int kayitsayisi = dosya.tellg()/sizeof(personel);
	cout<<"\nDosyada "<<kayitsayisi<<" tane kay�tl� personel bulunmaktad�r.\n";
	if(kayitsayisi>0)
	{
		for(int i=0; i<kayitsayisi; i++)
		{
			cout<<endl;
			cout<<i+1<<".personel"<<endl;
			dosya.seekg(i*sizeof(personel));
			dosya.read(reinterpret_cast<char*>(&personel), sizeof(personel));
			cout<<endl;
			cout<<"PERSONELIN:"<<endl;
			cout<<endl;
			cout<<"Ad�: "<<personel.ad;
			cout<<"\nCinsiyeti: ";
			if(personel.cinsiyet == 'e' || personel.cinsiyet == 'e')
			{
				cout<<"Erkek";
			}
			if (personel.cinsiyet == 'K' || personel.cinsiyet == 'k')
			{
				cout<<"Kad�n";
			}
			cout<<"\nYa��: "<<personel.yas;
			cout<<"\n�al��t��� Konum: "<<personel.calistigikonum;
			cout<<"\nPersonelin i�e ba�lama y�l�: "<<personel.isebaslamayil;
		}
		
	}
	else
	cout<<"\nDosyada hi� kay�t yok"<<endl;
	dosya.close();
	return 0;
}

int personelara()
{
	bilgi personel;
	char isim[80];
	bool var;
	ifstream dosya; 
	
	dosya.open("personel.dat", ios::binary);
	cout<<"\n\nKayd�n� bulmak istedi�iniz personelin ad�n� giriniz: ";
	cin>>isim;
	dosya.seekg(0, ios::end);
	int kayitsayisi = dosya.tellg()/sizeof(personel);
	for(int i=0; i<kayitsayisi; i++)
	{
		dosya.seekg(i*sizeof(personel));
		dosya.read(reinterpret_cast<char*>(&personel), sizeof(personel));
		if(strcmp(personel.ad,isim) == 0)
		{
			cout<<endl<<i+1<<".Kay�tta bulundu"<<endl;
			var=true;
			cout<<"Personelin";
			cout<<endl;
			cout<<"Ad�: "<<personel.ad;
			cout<<"\nCinsiyeti: ";
			if(personel.cinsiyet == 'e' || personel.cinsiyet == 'e')
			{
				cout<<"Erkek";
			}
			if (personel.cinsiyet == 'K' || personel.cinsiyet == 'k')
			{
				cout<<"Kad�n";
			}
			cout<<"\nYa��: "<<personel.yas;
			cout<<"\n�al��t��� konum: "<<personel.calistigikonum;
			cout<<"\nPersonelin i�e ba�lama y�l�: "<<personel.isebaslamayil;	
		}
	}
	if(!var)
	cout<<"\nKay�tta bulunamad�"<<endl;
	dosya.close();
}
int main()
{
	setlocale(LC_ALL, "Turkish");
	char anasecim, secim1, secim2;
	cout<<setw(42)<<"B�R ��LEM SE��N�Z"<<endl;

	
	cout<<"\n\nPersonel ��lemleri (P/p): "<< setw(40) << "M��teri ��lemleri (M/m): ";
	anasecim = getch();
	

	switch(anasecim)
	{
		case 'm':{ system("cls");
		cout<<"M��teri kayd� eklemek i�in 'K/k' tu�lay�n�z."<< setw(70) <<"M��teri bilgi g�ncellemesi yapmak i�in 'G/g' tu�lay�n�z."<<endl; 
	    cout<<endl;
	    cout<<"M��teri kayd� silmek i�in 'S/s' tu�lay�n�z."<<setw(68)<<"M��teri kay�tlar�n� listelemek i�in 'L/l' tu�lay�n�z."<<endl;
	    cout<<endl;
	    cout<<endl;
	    cout<<setw(70)<<"M��teri aramak i�in 'A/a' tu�lay�n�z."<<endl;
	    secim1 = getch();
			
			break;
		}
		case 'M':{ system("cls");
		cout<<"M��teri kayd� eklemek i�in 'K/k' tu�lay�n�z."<< setw(70) <<"M��teri bilgi g�ncellemesi yapmak i�in 'G/g' tu�lay�n�z."<<endl; 
	    cout<<endl;
	    cout<<"M��teri kayd� silmek i�in 'S/s' tu�lay�n�z."<<setw(68)<<"M��teri kay�tlar�n� listelemek i�in 'L/l' tu�lay�n�z."<<endl;
	    cout<<endl;
	    cout<<endl;
	    cout<<setw(70)<<"M��teri aramak i�in 'A/a' tu�lay�n�z."<<endl;
	    secim1 = getch();
			
			break;
		}
		case 'p':{
			system("cls");
		cout<<"Personel kayd� eklemek i�in 'K/k' tu�lay�n�z."<< setw(71) <<"Personel bilgi g�ncellemesi yapmak i�in 'G/g' tu�lay�n�z."<<endl; 
	    cout<<endl;
	    cout<<"Personel kayd� silmek i�in 'S/s' tu�lay�n�z."<<setw(69)<<"Personel kay�tlar�n� listelemek i�in 'L/l' tu�lay�n�z."<<endl;
	    cout<<endl;
	    cout<<endl;
	    cout<<setw(71)<<"Personel aramak i�in 'A/a' tu�lay�n�z."<<endl;
	    secim2 = getch();
			break;
		}
		case 'P':{
			system("cls");
		cout<<"Personel kayd� eklemek i�in 'K/k' tu�lay�n�z."<< setw(71) <<"Personel bilgi g�ncellemesi yapmak i�in 'G/g' tu�lay�n�z."<<endl; 
	    cout<<endl;
	    cout<<"Personel kayd� silmek i�in 'S/s' tu�lay�n�z."<<setw(69)<<"Personel kay�tlar�n� listelemek i�in 'L/l' tu�lay�n�z."<<endl;
	    cout<<endl;
	    cout<<endl;
	    cout<<setw(71)<<"Personel aramak i�in 'A/a' tu�lay�n�z."<<endl;
	    secim2 = getch();
			break;
		}
	}

	cout<<endl; cout<<endl;
  	if(anasecim == 'm' || anasecim == 'M')
	  {
	  switch(secim1)
  	{
  		case 'k':{
  			system("cls");
  			cout<<setw(70)<<"M��TER� KAYIT EKLEME EKRANI";
  			musterikayit();
			break;
		  }
		  case 'K':{
		  	system("cls");
  			cout<<setw(70)<<"M��TER� KAYIT EKLEME EKRANI";
  			musterikayit();
			break;
		  }
		  case 's':{
		  	system("cls");
  			cout<<setw(70)<<"M��TER� KAYIT S�LME EKRANI";
  			musterisil();
			break;
		  }
		  case 'S':{
		  	system("cls");
  			cout<<setw(70)<<"M��TER� KAYIT S�LME EKRANI";
  			musterisil();
			break;
		  }
		  case 'g':{
		  	system("cls");
  			cout<<setw(70)<<"M��TER� KAYIT G�NCELLEME EKRANI";
  			musteriguncelle();
			break;
		  }
		  case 'G':{
		  	system("cls");
  			cout<<setw(70)<<"M��TER� KAYIT G�NCELLEME EKRANI";
  			musteriguncelle();
			break;
		  }
		  case 'l':{
		  	system("cls");
  			cout<<setw(70)<<"M��TER� KAYIT L�STELEME EKRANI";
  			musterilistele();
			break;
		  }
		  case 'L':{
		  	system("cls");
  			cout<<setw(70)<<"M��TER� KAYIT L�STELEME EKRANI";
  			musterilistele();
			break;
		  }
		  case 'a':{
		  	system("cls");
		  	cout<<setw(70)<<"M��TER� ARAMA EKRANI";
		  	musteriara();
			break;
		  }
		  case 'A':{
		  	system("cls");
		  	cout<<setw(70)<<"M��TER� ARAMA EKRANI";
		  	musteriara();
			break;
		  }
		  default: cout<<"L�tfen belirtilen karakterlerden birini tu�lay�n�z.";
	  }
	  }
	  if(anasecim == 'p' || anasecim == 'P')
	  {
	  	switch(secim2)
  	{
  		case 'k':{
  			system("cls");
  			cout<<setw(70)<<"PERSONEL KAYIT EKLEME EKRANI";
  			personelkayit();
			break;
		  }
		  case 'K':{
		  	system("cls");
  			cout<<setw(70)<<"PERSONEL KAYIT EKLEME EKRANI";
  			personelkayit();
			break;
		  }
		  case 's':{
		  	system("cls");
  			cout<<setw(70)<<"PERSONEL KAYIT S�LME EKRANI";
  			personelsil();
			break;
		  }
		  case 'S':{
		  	system("cls");
  			cout<<setw(70)<<"PERSONEL KAYIT S�LME EKRANI";
  			personelsil();
			break;
		  }
		  case 'g':{
		  	system("cls");
  			cout<<setw(70)<<"PERSONEL KAYIT G�NCELLEME EKRANI";
  			personelguncelle();
			break;
		  }
		  case 'G':{
		  	system("cls");
  			cout<<setw(70)<<"PERSONEL KAYIT G�NCELLEME EKRANI";
  			personelguncelle();
			break;
		  }
		  case 'l':{
		  	system("cls");
  			cout<<setw(70)<<"PERSONEL KAYIT L�STELEME EKRANI";
  			personellistele();
			break;
		  }
		  case 'L':{
		  	system("cls");
  			cout<<setw(70)<<"PERSONEL KAYIT L�STELEME EKRANI";
  			personellistele();
			break;
		  }
		  case 'a':{
		  	system("cls");
		  	cout<<setw(70)<<"PERSONEL ARAMA EKRANI";
		  	personelara();
			break;
		  }
		  case 'A':{
		  	system("cls");
		  	cout<<setw(70)<<"PERSONEL ARAMA EKRANI";
		  	personelara();
			break;
		  }
		  default: cout<<"L�tfen belirtilen karakterlerden birini tu�lay�n�z.";
	  }
	  }

	return 0;
}
