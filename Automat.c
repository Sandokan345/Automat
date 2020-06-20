#include<stdio.h>		//standart kütüphanemizi ekledik.
#include<conio.h>		
#include<locale.h> 		//türkçe karakter kullanýmý için ekledik.	
float toplam=10;			//kasadaki toplam parayý ifade eder.
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
	int sifre=1234,sifregiris,input;		//adminlik giriþi için kullanýcalak þifreyi 1234 olarak belirledim
	printf("Admin iþlemleri için 1'e, diðer iþlemler için 2'ye basýnýz.");
	scanf("%d",&input);
	if(input==1)
	{
		printf("Þifreyi giriniz:\n");
		scanf("%d",&sifregiris);		//þifre doðru girilirse admin fonksityonuna geçiþ yapýlýyor.
		if(sifre==sifregiris)
		admin();
	}
	else		
	{
		liste();		//liste fonksiyonuyla otomattaki ürünlerin listesini sunuyoruz.
		girilenpara=paragirisi();		//paragirisi fonksiyonuyla kullanýcýdan parayý alýyoruz ve bir deðiþkene atýyoruz.
		urunfiyati=urunsecimi();	//urunsecimi fonksiyonuyla kullanýcý istediði urunu seciyor ve o urunun fiiyatýný ana fonksiyonumuzdaki deðiþkene atýyor.
		paraustu=kasa(urunfiyati,girilenpara);		//kasa önceki iki deðiþkenin farkýný geri döndürüp varsa paraüstünü belirliyor.
		if(girilenpara<urunfiyati)		//ödenen para ürün fiyatýndan küçük ise uyarý verilip paraiade fonksiyonu çaðýrýlýr.
		{
			printf("Girdiðiniz para yetersizdir.\n");
			paraiade();
		}
		else if(girilenpara==urunfiyati)
		printf("Ürününüz hazýrlanýyor lütfen bekleyiniz.");		//eþitse ürünü kullanýcýya verir para üstü vermez.
		else
		printf("Para üstünüz %.2fTL kadardýr. Ürününüz hazýrlanýyor...",paraustu);	//fazlaysa para üstü verir.
	}
	getch();
}
void liste(void)
{
	int i;
	char yiyecek[5][20]={"Kek","Sandviç","Bisküvi","Çikolata",'\0'};	//yiyecekleri iki boyutlu dizide tanýmdadýk.
	float yiyecekFiyatlar[]={1.0,3.50,2.25,1.75};	//yiyecekfiyatlarýný tek boyutlu dizide tanýmladýk.
	float *p1=yiyecekFiyatlar;		//fiyatlarý daha rahat kullanmak için pointera atadým.
	char soguk_icecek[6][20]={"Kola","Fanta","Ýcetea","Sprite","Limonlu soda",'\0'};//ayný iþlemleri diðer ürünler için de yapýyoruz.
	float soguk_icecekFiyatlar[5]={4.0,3.50,3.75,3.00,2.00};
	float *p2=soguk_icecekFiyatlar;
	char sicak_icecek[6][20]={"Çay","Türk kahvesi","Latte","Espresso","Sýcak çikolata",'\0'};
	float sicak_icecekFiyatlar[5]={1.50,2.50,2.00,2.75,3.00};
	float *p3=sicak_icecekFiyatlar;
	printf("--1)YÝYECEKLER--: \n");
	for(i=0; i<4; i++)
	{
		printf("%d-%s %.2fTL\n",i+1,yiyecek[i],*(p1+i));	//yiyecekleri ve fiyatlarýný ekrana bastýrýr.
	}
	printf("\n--2)SOÐUK ÝÇECEKLER--: \n");
	for(i=0; i<5; i++)
	{
		printf("%d-%s %.2fTL\n",i+1,soguk_icecek[i],*(p2+i));	//içecekleri ve fiyatlarýný ekrana bastýrýr.
	}
	printf("\n--3)SICAK ÝÇECEKLER--: \n");
	for(i=0; i<5; i++)
	{
		printf("%d-%s %.2fTL\n",i+1,sicak_icecek[i],*(p3+i));
	}
}
float urunsecimi(void)	//lisgte fonksiyonun baþlangýcýnda kullandýðýmýz iþlemleri uygulayýp seçmemiz gereken ürünü belirliyoruz sadece.
{
	int i,kategori,siranu;
	char yiyecek[5][20]={"Kek","Sandviç","Bisküvi","Çikolata",'\0'};
	float yiyecekFiyatlar[]={1.0,3.50,2.25,1.75};
	float *p1=yiyecekFiyatlar;
	char soguk_icecek[6][20]={"Kola","Fanta","Ýcetea","Sprite","Limonlu soda",'\0'};
	float soguk_icecekFiyatlar[5]={4.0,3.50,3.75,3.00,2.00};
	float *p2=soguk_icecekFiyatlar;
	char sicak_icecek[6][20]={"Çay","Türk kahvesi","Latte","Espresso","Sýcak çikolata",'\0'};
	float sicak_icecekFiyatlar[5]={1.50,2.50,2.00,2.75,3.00};
	float *p3=sicak_icecekFiyatlar;
	printf("\nSeçmek istediðiniz ürünün kategori numarasýný giriniz:\n");
	scanf("%d",&kategori);//ürünleri yiyecek-soðuk içecek-sýcak içecek olarak kategorilere ayýrmýþtýk.
	if(kategori>3)
	uyari();		//kullanýcý farklý bir kategori girerse uyarý verir.
	printf("Seçmek istediðiniz ürünün numarasýný giriniz:\n");
	scanf("%d",&siranu);
	if(siranu>5)
	uyari();		//kullanýcý farklý bir sýra numarasý girerse uyarý verir.
	switch(kategori){
		case 1: return *(p1+siranu-1);break;
		case 2: return *(p2+siranu-1);break;//switch case ile kullanýcýdan alýnan verilerle istenilen ürünün fiyatý return kullanýlarak ana fonksiyona gönderilir
		case 3: return *(p3+siranu-1);break;
	}
}
float paragirisi(void)
{
	float para;
	printf("Paranýzý giriniz(Sadece 5kr-10kr-25kr-50kr-1TL):\n");		//bu fonksiyonda kullanýcýdan para alýnýr ve return ile ana fonksiyona gönderilir.
	scanf("%f",&para);
	return para;
}
float kasa(float urunfiyati,float girilenpara)
{
	toplam+=urunfiyati;					//kasada giren çýkan para hesaplanýr ve para üstleri ana fonksiyona bildirilir.
	return girilenpara-urunfiyati;
}
void paraiade(void)
{
	printf("Girdiðiniz para geri verliyor...\n");		//ERROR durumlarýnda kullanýcý parasý geri verilir.
}
void arizabildirme(void)
{
	printf("Makine arýzalýdýr. Hassasiyetiniz için teþekkür ederiz.");	//arýza durumlarýnda kullanýcýya bilgi verir.
}
void admin(void)
{
	printf("\nkasada %.2fTL para bulunmaktadir.\n",toplam);	//þifre ile girilen adminlik fonksiyonu ksadaki parayý çekebilir ürün fiyatlarýný deðiþtirebilir.
}
void uyari(void)
{
	printf("ERROR!!!");	//ERROR mesajý yayýnlar.
}
