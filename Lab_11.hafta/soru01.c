
#include <stdio.h>

#define N 6

void matrisOlustur(int matris[N][N], int kenarlar[][2], int kenarSayisi) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matris[i][j] = 0;
        }
    }

    for (int i = 0; i < kenarSayisi; i++) {
        int u = kenarlar[i][0] - 1; //1 çıkarıyoruz çünkü indis haline getirmek için
        int v = kenarlar[i][1] - 1;

        matris[u][v] = 1;// yönsüz olduğu için hem uv hem vu
        matris[v][u] = 1;
    }
}


void matrisYazdir(int matris[N][N]) {

    printf("\nKomsuluk Matrisi:\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }
}


void dereceHesapla(int matris[N][N]) {

    int toplamDerece = 0;

    printf("\nDugum Dereceleri:\n");

    for (int i = 0; i < N; i++) {

        int derece = 0;

        for (int j = 0; j < N; j++) {
            derece += matris[i][j];
        }

        printf("%d. dugum: %d\n", i + 1, derece);

        toplamDerece += derece;
    }

    printf("Grafin genel derecesi (kenar sayisi): %d\n",
           toplamDerece / 2);
}


void bipartiteKontrol(int matris[N][N]) {

    int renk[N];
    int uzaklik[N];
    int kuyruk[N];

    for (int i = 0; i < N; i++) {
        renk[i] = -1;
        uzaklik[i] = -1;
    }

    int bas = 0, son = 0;

    // Başlangıç düğümü 1
    renk[0] = 0;
    uzaklik[0] = 0;

    kuyruk[son++] = 0;

    while (bas < son) {

        int u = kuyruk[bas++];

        for (int v = 0; v < N; v++) {

            if (matris[u][v] == 1) {

                if (renk[v] == -1) {

                    renk[v] = 1 - renk[u];
                    uzaklik[v] = uzaklik[u] + 1;

                    kuyruk[son++] = v;
                }

                else if (renk[v] == renk[u]) {

                    printf("\nGraf Bipartite degildir.\n");
                    return;
                }
            }
        }
    }

    printf("\nDugumlerin 1. dugume uzakliklari:\n");

    for (int i = 0; i < N; i++) {
        printf("%d. dugum: %d\n", i + 1, uzaklik[i]);
    }

    printf("\nRenklendirme:\n");

    for (int i = 0; i < N; i++) {

        if (renk[i] == 0)
            printf("%d. dugum: Mavi\n", i + 1);

        else
            printf("%d. dugum: Kirmizi\n", i + 1);
    }

    printf("\nGraf Bipartite'dir.\n");
}


int main() {

    int kenarlar[8][2] = {
        {1, 2},
        {1, 4},
        {2, 3},
        {3, 4},
        {3, 6},
        {4, 5},
        {5, 6}
    };

    int kenarSayisi = 7;

    int matris[N][N];

    printf("ILK DURUM\n");

    matrisOlustur(matris, kenarlar, kenarSayisi);

    matrisYazdir(matris);

    dereceHesapla(matris);

    bipartiteKontrol(matris);


    printf("\n\n(2,4) KENARI EKLENDIKTEN SONRA\n");

    kenarlar[kenarSayisi][0] = 2;
    kenarlar[kenarSayisi][1] = 4;

    kenarSayisi++;

    matrisOlustur(matris, kenarlar, kenarSayisi);

    matrisYazdir(matris);

    dereceHesapla(matris);

    bipartiteKontrol(matris);

    return 0;
}
