#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define N 4


/*
Klavyeden -1 girilene kadar verilen tek sayýlarý tek baðlý doðrusal bir listenin baþýna, verilen çift
sayýlarý ise listenin sonuna ekleyen programý yazýnýz.
*/

struct dugum{
    int veriler;
    struct dugum * next;
};


struct dugum *bas;
struct dugum *gecici;

void basaekle(int sayi)
{
    struct dugum *eklenecekler;
    eklenecekler=(struct dugum*)malloc(sizeof(struct dugum));
    eklenecekler->veriler=sayi;
    eklenecekler->next=bas;
    bas=eklenecekler;
}

void sonaekle(int sayi)
{
    struct dugum *eklenecek;
    eklenecek=(struct dugum *)malloc(sizeof(struct dugum));
    eklenecek->veriler=sayi;
    eklenecek->next=NULL;
    if(bas == NULL)
    {
        bas=eklenecek;
    }
    else
    {
        gecici=bas;
        while(gecici->next!=NULL)
        {
            gecici=gecici->next;
        }
        gecici->next=eklenecek;
    }

}

void yazdir()
{
    gecici=bas;
    while(gecici->next != NULL)
    {
        printf("%d  \n",gecici->veriler);
        gecici=gecici->next;
    }
    printf("%d",gecici->veriler);
}

int main()
{

int sayi;
while(sayi!=-1)
{
    printf("\nbir sayi giriniz : ");
    scanf("%d",&sayi);

    if(sayi%2==1)
    {
        sonaekle(sayi);
    }
    else
    {
        basaekle(sayi);
    }


}

yazdir();



    return 0;
}



