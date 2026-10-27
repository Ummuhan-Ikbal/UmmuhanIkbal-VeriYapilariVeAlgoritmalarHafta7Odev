#include <stdio.h>

#include <stdlib.h>

typedef struct Dugum {

    int veri;

    struct Dugum *sol;

    struct Dugum *sag;

} Dugum;

// Yeni dugum olusturuyoruz

Dugum* yeniDugum(int veri) {

    Dugum *yeni = malloc(sizeof(Dugum));

    if (yeni == NULL) {

        printf("Bellek hatasi!\n");

        exit(1);

    }

    yeni->veri = veri;

    yeni->sol = NULL;

    yeni->sag = NULL;

    return yeni;

}

// BST'ye eleman ekleme

Dugum* ekle(Dugum *kok, int veri) {

    if (kok == NULL)

        return yeniDugum(veri);

    if (veri < kok->veri)

        kok->sol = ekle(kok->sol, veri);

    else if (veri > kok->veri)

        kok->sag = ekle(kok->sag, veri);

    return kok;

}

// Hazineyi rekursif arama

int ara(Dugum *kok, int hedef) {

    if (kok == NULL)

        return 0;

    printf("%d dugumu ziyaret edildi.\n", kok->veri);

    if (kok->veri == hedef)

        return 1;

    if (hedef < kok->veri)

        return ara(kok->sol, hedef);

    return ara(kok->sag, hedef);

}

// Agacin yuksekligini hesaplama

int yukseklik(Dugum *kok) {

    if (kok == NULL)

        return 0;

    int sol = yukseklik(kok->sol);

    int sag = yukseklik(kok->sag);

    return 1 + (sol > sag ? sol : sag);

}

// Belleği temizleme

void temizle(Dugum *kok) {

    if (kok == NULL)

        return;

    temizle(kok->sol);

    temizle(kok->sag);

    free(kok);

}

int main(void)
{
    Dugum *kok = NULL;

    int sayilar[] = {50, 30, 70, 20, 40, 60, 80};

    int n = sizeof(sayilar) / sizeof(sayilar[0]);

    for (int i = 0; i < n; i++)

        kok = ekle(kok, sayilar[i]);

    int hedef;

    printf("Hazine sayisini gir: ");

    scanf("%d", &hedef);

    if (ara(kok, hedef))

        printf("Hazine bulundu!\n");

    else

        printf("Bosuna kazdin!\n");

    printf("Agac yuksekligi: %d\n", yukseklik(kok));

    printf("En kotu durumda ziyaret edilecek dugum: %d\n",yukseklik(kok));
    temizle(kok);
    return 0;
}