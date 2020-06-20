#include<stdio.h>		//standart k�t�phanemizi ekledik.
#include<conio.h>		
#include<locale.h> 		//t�rk�e karakter kullan�m� i�in ekledik.	
float toplam=10;			//kasadaki toplam paray� ifade eder.
void liste(void);			
float urunsecimi(void);
float paragirisi(void);
float kasa(float ,float );
void paraiade(void);
void arizabildirme(void);
void admin(void);
void uyari(void);
main()
{
	setlocale(LC_ALL, "Turkish"); 
	float girilenpara,urunfiyati,paraustu;
	int sifre=1234,sifregiris,input;		//adminlik giri�i i�in kullan�calak �ifreyi 1234 olarak belirledim
	printf("Admin i�lemleri i�in 1'e, di�er i�lemler i�in 2'ye bas�n�z.");
	scanf("%d",&input);
	if(input==1)
	{
		printf("�ifreyi giriniz:\n");
		scanf("%d",&sifregiris);		//�ifre do�ru girilirse admin fonksityonuna ge�i� yap�l�yor.
		if(sifre==sifregiris)
		admin();
	}
	else		
	{
		liste();		//liste fonksiyonuyla otomattaki �r�nlerin listesini sunuyoruz.
		girilenpara=paragirisi();		//paragirisi fonksiyonuyla kullan�c�dan paray� al�yoruz ve bir de�i�kene at�yoruz.
		urunfiyati=urunsecimi();	//urunsecimi fonksiyonuyla kullan�c� istedi�i urunu seciyor ve o urunun fiiyat�n� ana fonksiyonumuzdaki de�i�kene at�yor.
		paraustu=kasa(urunfiyati,girilenpara);		//kasa �nceki iki de�i�kenin fark�n� geri d�nd�r�p varsa para�st�n� belirliyor.
		if(girilenpara<urunfiyati)		//�denen para �r�n fiyat�ndan k���k ise uyar� verilip paraiade fonksiyonu �a��r�l�r.
		{
			printf("Girdi�iniz para yetersizdir.\n");
			paraiade();
		}
		else if(girilenpara==urunfiyati)
		printf("�r�n�n�z haz�rlan�yor l�tfen bekleyiniz.");		//e�itse �r�n� kullan�c�ya verir para �st� vermez.
		else
		printf("Para �st�n�z %.2fTL kadard�r. �r�n�n�z haz�rlan�yor...",paraustu);	//fazlaysa para �st� verir.
	}
	getch();
}
void liste(void)
{
	int i;
	char yiyecek[5][20]={"Kek","Sandvi�","Bisk�vi","�ikolata",'\0'};	//yiyecekleri iki boyutlu dizide tan�mdad�k.
	float yiyecekFiyatlar[]={1.0,3.50,2.25,1.75};	//yiyecekfiyatlar�n� tek boyutlu dizide tan�mlad�k.
	float *p1=yiyecekFiyatlar;		//fiyatlar� daha rahat kullanmak i�in pointera atad�m.
	char soguk_icecek[6][20]={"Kola","Fanta","�cetea","Sprite","Limonlu soda",'\0'};//ayn� i�lemleri di�er �r�nler i�in de yap�yoruz.
	float soguk_icecekFiyatlar[5]={4.0,3.50,3.75,3.00,2.00};
	float *p2=soguk_icecekFiyatlar;
	char sicak_icecek[6][20]={"�ay","T�rk kahvesi","Latte","Espresso","S�cak �ikolata",'\0'};
	float sicak_icecekFiyatlar[5]={1.50,2.50,2.00,2.75,3.00};
	float *p3=sicak_icecekFiyatlar;
	printf("--1)Y�YECEKLER--: \n");
	for(i=0; i<4; i++)
	{
		printf("%d-%s %.2fTL\n",i+1,yiyecek[i],*(p1+i));	//yiyecekleri ve fiyatlar�n� ekrana bast�r�r.
	}
	printf("\n--2)SO�UK ��ECEKLER--: \n");
	for(i=0; i<5; i++)
	{
		printf("%d-%s %.2fTL\n",i+1,soguk_icecek[i],*(p2+i));	//i�ecekleri ve fiyatlar�n� ekrana bast�r�r.
	}
	printf("\n--3)SICAK ��ECEKLER--: \n");
	for(i=0; i<5; i++)
	{
		printf("%d-%s %.2fTL\n",i+1,sicak_icecek[i],*(p3+i));
	}
}
float urunsecimi(void)	//lisgte fonksiyonun ba�lang�c�nda kulland���m�z i�lemleri uygulay�p se�memiz gereken �r�n� belirliyoruz sadece.
{
	int i,kategori,siranu;
	char yiyecek[5][20]={"Kek","Sandvi�","Bisk�vi","�ikolata",'\0'};
	float yiyecekFiyatlar[]={1.0,3.50,2.25,1.75};
	float *p1=yiyecekFiyatlar;
	char soguk_icecek[6][20]={"Kola","Fanta","�cetea","Sprite","Limonlu soda",'\0'};
	float soguk_icecekFiyatlar[5]={4.0,3.50,3.75,3.00,2.00};
	float *p2=soguk_icecekFiyatlar;
	char sicak_icecek[6][20]={"�ay","T�rk kahvesi","Latte","Espresso","S�cak �ikolata",'\0'};
	float sicak_icecekFiyatlar[5]={1.50,2.50,2.00,2.75,3.00};
	float *p3=sicak_icecekFiyatlar;
	printf("\nSe�mek istedi�iniz �r�n�n kategori numaras�n� giriniz:\n");
	scanf("%d",&kategori);//�r�nleri yiyecek-so�uk i�ecek-s�cak i�ecek olarak kategorilere ay�rm��t�k.
	if(kategori>3)
	uyari();		//kullan�c� farkl� bir kategori girerse uyar� verir.
	printf("Se�mek istedi�iniz �r�n�n numaras�n� giriniz:\n");
	scanf("%d",&siranu);
	if(siranu>5)
	uyari();		//kullan�c� farkl� bir s�ra numaras� girerse uyar� verir.
	switch(kategori){
		case 1: return *(p1+siranu-1);break;
		case 2: return *(p2+siranu-1);break;//switch case ile kullan�c�dan al�nan verilerle istenilen �r�n�n fiyat� return kullan�larak ana fonksiyona g�nderilir
		case 3: return *(p3+siranu-1);break;
	}
}
float paragirisi(void)
{
	float para;
	printf("Paran�z� giriniz(Sadece 5kr-10kr-25kr-50kr-1TL):\n");		//bu fonksiyonda kullan�c�dan para al�n�r ve return ile ana fonksiyona g�nderilir.
	scanf("%f",&para);
	return para;
}
float kasa(float urunfiyati,float girilenpara)
{
	toplam+=urunfiyati;					//kasada giren ��kan para hesaplan�r ve para �stleri ana fonksiyona bildirilir.
	return girilenpara-urunfiyati;
}
void paraiade(void)
{
	printf("Girdi�iniz para geri verliyor...\n");		//ERROR durumlar�nda kullan�c� paras� geri verilir.
}
void arizabildirme(void)
{
	printf("Makine ar�zal�d�r. Hassasiyetiniz i�in te�ekk�r ederiz.");	//ar�za durumlar�nda kullan�c�ya bilgi verir.
}
void admin(void)
{
	printf("\nkasada %.2fTL para bulunmaktadir.\n",toplam);	//�ifre ile girilen adminlik fonksiyonu ksadaki paray� �ekebilir �r�n fiyatlar�n� de�i�tirebilir.
}
void uyari(void)
{
	printf("ERROR!!!");	//ERROR mesaj� yay�nlar.
}
