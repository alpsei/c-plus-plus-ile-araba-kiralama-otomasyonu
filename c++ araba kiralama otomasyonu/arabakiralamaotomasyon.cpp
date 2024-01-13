/*Ad Soyad: Alper Serin 
  Numara: 2312729001 
  Proje: Araç kiralama otomasyonu */

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
  	cout<<"\nYaþ: ";
  	cin>>musteri.yas;
  	if(musteri.yas<18)
  	{
  		cout<<"Araç kiralamasý yapýlamaz!";
  		return 0;
	  }
	cout<<"Kiralanacak aracýn markasýný giriniz: ";
	cin>>musteri.aracmarka; cout<<endl;
	cout<<"Kiralanacak aracýn modelini giriniz: ";
	cin>>musteri.aracmodel; cout<<endl;
	cout<<"Kiralanacak aracýn üretim yýlýný giriniz: ";
	cin>>musteri.aracyil; cout<<endl;
	cout<<"Kiralanacak aracýn teslim edilmeden önceki km bilgisini giriniz: ";
	cin>>musteri.arackm; cout<<endl;
	cout<<"Kiralanacak aracýn plakasýný giriniz: ";
	cin>>musteri.aracplaka; cout<<endl;
	cout<<"Kiralanacak aracýn teslim verileceði konum bilgisini giriniz: ";
	cin>>musteri.alinacakkonum; cout<<endl;
	cout<<"Kiralanacak aracýn teslim alýnacaðý konum bilgisini giriniz: ";
	cin>>musteri.birakilacakkonum; cout<<endl;
	cout<<"Aracýn ne kadar süre kiralanacaðýný giriniz (saat cinsinden): ";
	cin>>musteri.sure; cout<<endl;
	cout<<"Aracýn saatlik kira ücreti: ";
	cin>>musteri.saatlikfiyat; cout<<endl;
	musteri.toplamfiyat = (musteri.saatlikfiyat * musteri.sure * 0.18) + (musteri.saatlikfiyat * musteri.sure);
	cout<<"Müþterinin ödeyeceði toplam ücret (%18 KDV Dahil): "<<musteri.toplamfiyat;
	
	dosya.write(reinterpret_cast<char*>(&musteri), sizeof(musteri));
	cout<<"\nBaþka kayýt eklemek istiyor musunuz?(E/H)"; secim = getch();
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
	cout<<"\n\nKaydýný düzelteceðiniz müþterinin adýný giriniz: ";
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
			cout<<"Müþteri";
			cout<<"\nAdý: "<<musteri.ad;
			cout<<"\nCinsiyeti: ";
			if(musteri.cinsiyet == 'e' || musteri.cinsiyet == 'e')
			{
				cout<<"Erkek";
			}
			if (musteri.cinsiyet == 'K' || musteri.cinsiyet == 'k')
			{
				cout<<"Kadýn";
			}
			cout<<"\nYaþý: "<<musteri.yas;
			cout<<"\nAraç markasý: "<<musteri.aracmarka;
			cout<<"\nAraç modeli: "<<musteri.aracmodel;
			cout<<"\nAraç üretim yýlý: "<<musteri.aracyil;
			cout<<"\nAraç plakasý: "<<musteri.aracplaka;
			cout<<"\nAracýn alýnacaðý konum: "<<musteri.alinacakkonum;
			cout<<"\nAracýn býrakýlacaðý konum: "<<musteri.birakilacakkonum;
			cout<<"\nAraç KM'si: "<<musteri.arackm;
			cout<<"\nKira süresi: "<<musteri.sure;
			cout<<"\nAracýn saatlik ücreti: "<<musteri.saatlikfiyat;
			cout<<"\nMüþterinin ödeyeceði toplam ücret: "<<musteri.toplamfiyat;
			cout<<"Düzeltmek istediðiniz kayýt bu mu? (E/H): ";
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
				cout<<"Adý: ";
				cin>>musteri.ad;
			cout<<"\nCinsiyeti (E/K): ";
			musteri.cinsiyet = getche();
			cout<<"\nYaþý: ";
			cin>>musteri.yas;
			cout<<"\nAraç markasý: ";
			cin>>musteri.aracmarka;
			cout<<"\nAraç modeli: ";
			cin>>musteri.aracmodel;
			cout<<"\nAraç üretim yýlý: ";
			cin>>musteri.aracyil;
			cout<<"\nAraç plakasý: ";
			cin>>musteri.aracplaka;
			cout<<"\nAracýn alýnacaðý konum: ";
			cin>>musteri.alinacakkonum;
			cout<<"\nAracýn býrakýlacaðý konum: ";
			cin>>musteri.birakilacakkonum;
			cout<<"\nAraç KM'si: ";
			cin>>musteri.arackm;
			cout<<"\nKira süresi: ";
			cin>>musteri.sure;
			cout<<"\nAracýn saatlik ücreti: ";
			cin>>musteri.saatlikfiyat;
			musteri.toplamfiyat = (musteri.saatlikfiyat * musteri.sure * 0.18) + (musteri.saatlikfiyat * musteri.sure);
			cout<<"\nToplam ücret: "<<musteri.toplamfiyat;
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
			cout<<"\nKayýt düzeltildi"<<endl;
		}
		else
		{
			remove("yedek.dat");
			cout<<"Kayýt bulunamadý"<<endl;
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
	cout<<"\n\nKaydýný sileceðiniz müþterinin adýný giriniz: ";
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
			cout<<"Müþterinin";
			cout<<"\nAd: "<<musteri.ad;
			cout<<"\nYaþý: "<<musteri.yas;
			cout<<"\nAraç plakasý: "<<musteri.aracplaka;
			
			cout<<"\n\nSilmek istediðiniz kayýt bu mu? (E/H): ";
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
		cout<<"\nKayýt silindi"<<endl;
	}
	else
	{
		remove("yedek.dat");
		cout<<"\nKayýt bulunamadý"<<endl;
	}
}

int musterilistele()
{
	bilgi musteri;
	ifstream dosya("musteri.dat", ios::binary);
	dosya.seekg(0, ios::end);
	int kayitsayisi = dosya.tellg()/sizeof(musteri);
	cout<<"\nDosyada "<<kayitsayisi<<" tane kayýtlý müþteri bulunmaktadýr.\n";
	if(kayitsayisi>0)
	{
		for(int i=0; i<kayitsayisi; i++)
		{
			cout<<endl;
			cout<<i+1<<".müþteri"<<endl;
			dosya.seekg(i*sizeof(musteri));
			dosya.read(reinterpret_cast<char*>(&musteri), sizeof(musteri));
			cout<<endl;
			cout<<"MÜÞTERÝNÝN:"<<endl;
			cout<<"Adý: "<<musteri.ad;
			cout<<"\nCinsiyeti: ";
			if(musteri.cinsiyet == 'e' || musteri.cinsiyet == 'e')
			{
				cout<<"Erkek";
			}
			if (musteri.cinsiyet == 'K' || musteri.cinsiyet == 'k')
			{
				cout<<"Kadýn";
			}
			cout<<"\nYaþý: "<<musteri.yas;
			cout<<"\nAraç markasý: "<<musteri.aracmarka;
			cout<<"\nAraç modeli: "<<musteri.aracmodel;
			cout<<"\nAraç üretim yýlý: "<<musteri.aracyil;
			cout<<"\nAraç plakasý: "<<musteri.aracplaka;
			cout<<"\nAracýn alýnacaðý konum: "<<musteri.alinacakkonum;
			cout<<"\nAracýn býrakýlacaðý konum: "<<musteri.birakilacakkonum;
			cout<<"\nAraç KM'si: "<<musteri.arackm;
			cout<<"\nKira süresi: "<<musteri.sure;
			cout<<"\nAracýn saatlik ücreti: "<<musteri.saatlikfiyat;
			cout<<"\nToplam ücret: "<<musteri.toplamfiyat;
		}
		
	}
	else
	cout<<"\nDosyada hiç kayýt yok"<<endl;
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
	cout<<"\nKaydýný bulmak istediðiniz müþterinin adýný giriniz: ";
	cin>>isim;
	dosya.seekg(0, ios::end);
	int kayitsayisi = dosya.tellg()/sizeof(musteri);
	for(int i=0; i<kayitsayisi; i++)
	{
		dosya.seekg(i*sizeof(musteri));
		dosya.read(reinterpret_cast<char*>(&musteri), sizeof(musteri));
		if(strcmp(musteri.ad,isim) == 0)
		{
			cout<<endl<<i+1<<".Kayýtta bulundu"<<endl;
			var=true;
			cout<<endl;
			cout<<"Müþterinin";
			cout<<endl;
			cout<<"Adý: "<<musteri.ad;
			cout<<"\nCinsiyeti: ";
			if(musteri.cinsiyet == 'e' || musteri.cinsiyet == 'e')
			{
				cout<<"Erkek";
			}
			if (musteri.cinsiyet == 'K' || musteri.cinsiyet == 'k')
			{
				cout<<"Kadýn";
			}
			cout<<"\nYaþý: "<<musteri.yas;
			cout<<"\nAraç markasý: "<<musteri.aracmarka;
			cout<<"\nAraç modeli: "<<musteri.aracmodel;
			cout<<"\nAraç üretim yýlý: "<<musteri.aracyil;
			cout<<"\nAraç plakasý: "<<musteri.aracplaka;
			cout<<"\nAracýn alýnacaðý konum: "<<musteri.alinacakkonum;
			cout<<"\nAracýn býrakýlacaðý konum: "<<musteri.birakilacakkonum;
			cout<<"\nAraç KM'si: "<<musteri.arackm;
			cout<<"\nKira süresi: "<<musteri.sure;
			cout<<"\nAracýn saatlik ücreti: "<<musteri.saatlikfiyat;
			cout<<"\nToplam ücret: "<<musteri.toplamfiyat;
		}
	}
	if(!var)
	cout<<"\nKayýtta bulunamadý"<<endl;
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
  	cout<<"\nYaþ: ";
  	cin>>personel.yas;
  	if(personel.yas<18)
  	{
  		cout<<"Personel kaydý yapýlamaz!";
  		break;
	  }
  	cout<<"\nPersonelin çalýþtýðý alan: ";
  	cin>>personel.calistigikonum;
	cout<<"\nPersonelin iþe baþlama yýlý: ";
	cin>>personel.isebaslamayil;
	cout<<endl;
  	cout<<endl;
	dosya.write(reinterpret_cast<char*>(&personel), sizeof(personel));
	cout<<"\nBaþka kayýt eklemek istiyor musunuz?(E/H)"; secim = getch();
	
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
	cout<<"\n\nKaydýný düzelteceðiniz personelin adýný giriniz: ";
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
			cout<<"Adý: "<<personel.ad;
			cout<<"\nCinsiyeti: ";
			if(personel.cinsiyet == 'e' || personel.cinsiyet == 'e')
			{
				cout<<"Erkek";
			}
			if (personel.cinsiyet == 'K' || personel.cinsiyet == 'k')
			{
				cout<<"Kadýn";
			}
			cout<<"\nYaþý: "<<personel.yas;
			cout<<"\nÇalýþtýðý konum: "<<personel.calistigikonum;
			cout<<"\nPersonelin iþe baþlama yýlý: "<<personel.isebaslamayil;
			cout<<"Düzeltmek istediðiniz kayýt bu mu? (E/H): ";
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
				cout<<"Adý: ";
				cin>>personel.ad;
			cout<<"\nCinsiyeti (E/K): ";
			personel.cinsiyet = getche();
			cout<<"\nYaþý: ";
			cin>>personel.yas;
			cout<<"\nÇalýþtýðý Konum: ";
			cin>>personel.calistigikonum;
			cout<<"\nPersonelin iþe baþlama yýlý: ";
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
			cout<<"\nKayýt düzeltildi"<<endl;
		}
		else
		{
			remove("yedekpersonel.dat");
			cout<<"Kayýt bulunamadý"<<endl;
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
	cout<<"\n\nKaydýný sileceðiniz personelin adýný giriniz: ";
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
			cout<<"\nYaþý: "<<personel.yas;
			cout<<"\nÇalýþtýðý Konum: "<<personel.calistigikonum;
			cout<<"\nPersonelin iþe baþlama yýlý: "<<personel.isebaslamayil;
			cout<<"\n\nSilmek istediðiniz kayýt bu mu? (E/H): ";
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
		cout<<"\nKayýt silindi"<<endl;
	}
	else
	{
		remove("yedek.dat");
		cout<<"\nKayýt bulunamadý"<<endl;
	}
}

int personellistele()
{
	bilgi personel;
	ifstream dosya("personel.dat", ios::binary);
	dosya.seekg(0, ios::end);
	int kayitsayisi = dosya.tellg()/sizeof(personel);
	cout<<"\nDosyada "<<kayitsayisi<<" tane kayýtlý personel bulunmaktadýr.\n";
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
			cout<<"Adý: "<<personel.ad;
			cout<<"\nCinsiyeti: ";
			if(personel.cinsiyet == 'e' || personel.cinsiyet == 'e')
			{
				cout<<"Erkek";
			}
			if (personel.cinsiyet == 'K' || personel.cinsiyet == 'k')
			{
				cout<<"Kadýn";
			}
			cout<<"\nYaþý: "<<personel.yas;
			cout<<"\nÇalýþtýðý Konum: "<<personel.calistigikonum;
			cout<<"\nPersonelin iþe baþlama yýlý: "<<personel.isebaslamayil;
		}
		
	}
	else
	cout<<"\nDosyada hiç kayýt yok"<<endl;
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
	cout<<"\n\nKaydýný bulmak istediðiniz personelin adýný giriniz: ";
	cin>>isim;
	dosya.seekg(0, ios::end);
	int kayitsayisi = dosya.tellg()/sizeof(personel);
	for(int i=0; i<kayitsayisi; i++)
	{
		dosya.seekg(i*sizeof(personel));
		dosya.read(reinterpret_cast<char*>(&personel), sizeof(personel));
		if(strcmp(personel.ad,isim) == 0)
		{
			cout<<endl<<i+1<<".Kayýtta bulundu"<<endl;
			var=true;
			cout<<"Personelin";
			cout<<endl;
			cout<<"Adý: "<<personel.ad;
			cout<<"\nCinsiyeti: ";
			if(personel.cinsiyet == 'e' || personel.cinsiyet == 'e')
			{
				cout<<"Erkek";
			}
			if (personel.cinsiyet == 'K' || personel.cinsiyet == 'k')
			{
				cout<<"Kadýn";
			}
			cout<<"\nYaþý: "<<personel.yas;
			cout<<"\nÇalýþtýðý konum: "<<personel.calistigikonum;
			cout<<"\nPersonelin iþe baþlama yýlý: "<<personel.isebaslamayil;	
		}
	}
	if(!var)
	cout<<"\nKayýtta bulunamadý"<<endl;
	dosya.close();
}
int main()
{
	setlocale(LC_ALL, "Turkish");
	char anasecim, secim1, secim2;
	cout<<setw(42)<<"BÝR ÝÞLEM SEÇÝNÝZ"<<endl;

	
	cout<<"\n\nPersonel Ýþlemleri (P/p): "<< setw(40) << "Müþteri Ýþlemleri (M/m): ";
	anasecim = getch();
	

	switch(anasecim)
	{
		case 'm':{ system("cls");
		cout<<"Müþteri kaydý eklemek için 'K/k' tuþlayýnýz."<< setw(70) <<"Müþteri bilgi güncellemesi yapmak için 'G/g' tuþlayýnýz."<<endl; 
	    cout<<endl;
	    cout<<"Müþteri kaydý silmek için 'S/s' tuþlayýnýz."<<setw(68)<<"Müþteri kayýtlarýný listelemek için 'L/l' tuþlayýnýz."<<endl;
	    cout<<endl;
	    cout<<endl;
	    cout<<setw(70)<<"Müþteri aramak için 'A/a' tuþlayýnýz."<<endl;
	    secim1 = getch();
			
			break;
		}
		case 'M':{ system("cls");
		cout<<"Müþteri kaydý eklemek için 'K/k' tuþlayýnýz."<< setw(70) <<"Müþteri bilgi güncellemesi yapmak için 'G/g' tuþlayýnýz."<<endl; 
	    cout<<endl;
	    cout<<"Müþteri kaydý silmek için 'S/s' tuþlayýnýz."<<setw(68)<<"Müþteri kayýtlarýný listelemek için 'L/l' tuþlayýnýz."<<endl;
	    cout<<endl;
	    cout<<endl;
	    cout<<setw(70)<<"Müþteri aramak için 'A/a' tuþlayýnýz."<<endl;
	    secim1 = getch();
			
			break;
		}
		case 'p':{
			system("cls");
		cout<<"Personel kaydý eklemek için 'K/k' tuþlayýnýz."<< setw(71) <<"Personel bilgi güncellemesi yapmak için 'G/g' tuþlayýnýz."<<endl; 
	    cout<<endl;
	    cout<<"Personel kaydý silmek için 'S/s' tuþlayýnýz."<<setw(69)<<"Personel kayýtlarýný listelemek için 'L/l' tuþlayýnýz."<<endl;
	    cout<<endl;
	    cout<<endl;
	    cout<<setw(71)<<"Personel aramak için 'A/a' tuþlayýnýz."<<endl;
	    secim2 = getch();
			break;
		}
		case 'P':{
			system("cls");
		cout<<"Personel kaydý eklemek için 'K/k' tuþlayýnýz."<< setw(71) <<"Personel bilgi güncellemesi yapmak için 'G/g' tuþlayýnýz."<<endl; 
	    cout<<endl;
	    cout<<"Personel kaydý silmek için 'S/s' tuþlayýnýz."<<setw(69)<<"Personel kayýtlarýný listelemek için 'L/l' tuþlayýnýz."<<endl;
	    cout<<endl;
	    cout<<endl;
	    cout<<setw(71)<<"Personel aramak için 'A/a' tuþlayýnýz."<<endl;
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
  			cout<<setw(70)<<"MÜÞTERÝ KAYIT EKLEME EKRANI";
  			musterikayit();
			break;
		  }
		  case 'K':{
		  	system("cls");
  			cout<<setw(70)<<"MÜÞTERÝ KAYIT EKLEME EKRANI";
  			musterikayit();
			break;
		  }
		  case 's':{
		  	system("cls");
  			cout<<setw(70)<<"MÜÞTERÝ KAYIT SÝLME EKRANI";
  			musterisil();
			break;
		  }
		  case 'S':{
		  	system("cls");
  			cout<<setw(70)<<"MÜÞTERÝ KAYIT SÝLME EKRANI";
  			musterisil();
			break;
		  }
		  case 'g':{
		  	system("cls");
  			cout<<setw(70)<<"MÜÞTERÝ KAYIT GÜNCELLEME EKRANI";
  			musteriguncelle();
			break;
		  }
		  case 'G':{
		  	system("cls");
  			cout<<setw(70)<<"MÜÞTERÝ KAYIT GÜNCELLEME EKRANI";
  			musteriguncelle();
			break;
		  }
		  case 'l':{
		  	system("cls");
  			cout<<setw(70)<<"MÜÞTERÝ KAYIT LÝSTELEME EKRANI";
  			musterilistele();
			break;
		  }
		  case 'L':{
		  	system("cls");
  			cout<<setw(70)<<"MÜÞTERÝ KAYIT LÝSTELEME EKRANI";
  			musterilistele();
			break;
		  }
		  case 'a':{
		  	system("cls");
		  	cout<<setw(70)<<"MÜÞTERÝ ARAMA EKRANI";
		  	musteriara();
			break;
		  }
		  case 'A':{
		  	system("cls");
		  	cout<<setw(70)<<"MÜÞTERÝ ARAMA EKRANI";
		  	musteriara();
			break;
		  }
		  default: cout<<"Lütfen belirtilen karakterlerden birini tuþlayýnýz.";
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
  			cout<<setw(70)<<"PERSONEL KAYIT SÝLME EKRANI";
  			personelsil();
			break;
		  }
		  case 'S':{
		  	system("cls");
  			cout<<setw(70)<<"PERSONEL KAYIT SÝLME EKRANI";
  			personelsil();
			break;
		  }
		  case 'g':{
		  	system("cls");
  			cout<<setw(70)<<"PERSONEL KAYIT GÜNCELLEME EKRANI";
  			personelguncelle();
			break;
		  }
		  case 'G':{
		  	system("cls");
  			cout<<setw(70)<<"PERSONEL KAYIT GÜNCELLEME EKRANI";
  			personelguncelle();
			break;
		  }
		  case 'l':{
		  	system("cls");
  			cout<<setw(70)<<"PERSONEL KAYIT LÝSTELEME EKRANI";
  			personellistele();
			break;
		  }
		  case 'L':{
		  	system("cls");
  			cout<<setw(70)<<"PERSONEL KAYIT LÝSTELEME EKRANI";
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
		  default: cout<<"Lütfen belirtilen karakterlerden birini tuþlayýnýz.";
	  }
	  }

	return 0;
}
