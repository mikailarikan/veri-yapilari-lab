#include <stdio.h>
#include <ctype.h>

#define N 6
#define INF 999999

char dugumler[N] = {'A', 'B', 'C', 'D', 'E', 'F'};

void dijkstra(int graph[N][N], int kok, int known[N], int dist[N], int path[N]) {
    for (int i = 0; i < N; i++) {
        known[i] = 0;
        dist[i] = INF;
        path[i] = -1;
    }

    dist[kok] = 0;

    for (int adim = 0; adim < N; adim++) {
        int min = INF;
        int u = -1;

        for (int i = 0; i < N; i++) {
            if (!known[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break;

        known[u] = 1;

        for (int v = 0; v < N; v++) {
            if (!known[v] && graph[u][v] > 0 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                path[v] = u;
            }
        }
    }
}

void tabloYazdir(int kok, int known[N], int dist[N], int path[N]) {
    printf("\n--- Dijkstra Tablosu (Kok: %c) ---\n", dugumler[kok]);
    printf("Dugum\tKnown\tDistance\tPath\n");
    for (int i = 0; i < N; i++) {
        printf("%c\t%d\t%d\t\t%c\n",
               dugumler[i],
               known[i],
               dist[i],
               (path[i] == -1) ? '-' : dugumler[path[i]]);
    }
}

void rotaYazdir(int path[N], int hedef) {
    int yol[N];
    int sayac = 0;
    int mevcut = hedef;

    while (mevcut != -1) {
        yol[sayac++] = mevcut;
        mevcut = path[mevcut];
    }

    for (int i = sayac - 1; i >= 0; i--) {
        printf("%c", dugumler[yol[i]]);
        if (i > 0) printf("->");
    }
}

int main() {
    int graph[N][N] = {

        {  0, 7, 5, 0, 0, 1 }, 
        {  7, 0, 1, 1, 3, 0 }, 
        {  5, 1, 0, 2, 1, 0 }, 
        {  0, 1, 2, 0, 0, 7 }, 
        {  0, 3, 1, 0, 0, 2 }, 
        {  1, 0, 0, 7, 2, 0 }  
    };

    int known[N], dist[N], path[N];

   
    char secim;
    int kok = -1;
    printf("Kok dugumu giriniz (A-F): ");
    scanf(" %c", &secim);
    secim = toupper(secim); 

    for (int i = 0; i < N; i++) {
        if (dugumler[i] == secim) {
            kok = i;
            break;
        }
    }

    if (kok == -1) {
        printf("Gecersiz dugum! Varsayilan olarak A secildi.\n");
        kok = 0;
    }

    dijkstra(graph, kok, known, dist, path);
    tabloYazdir(kok, known, dist, path);

    //Kök A iken B ve D düğümlerine en düşük maliyetli rotalar
    dijkstra(graph, 0, known, dist, path);
    printf("\n--- Kok A Icin Rota Ciktisi ---\n");

    printf("A -> B Rotasi: ");
    rotaYazdir(path, 1);
    printf(" (Toplam Maliyet: %d)\n", dist[1]);

    printf("A -> D Rotasi: ");
    rotaYazdir(path, 3);
    printf(" (Toplam Maliyet: %d)\n", dist[3]);

    // 3. Görev: Tüm düğümler için toplam maliyet ve en merkezi düğüm tespiti
    printf("\n--- Merkezi Dugum Analizi ---\n");
    int toplamMaliyetler[N];
    int minToplam = INF;

    for (int i = 0; i < N; i++) {
        dijkstra(graph, i, known, dist, path);
        int toplam = 0;
        for (int j = 0; j < N; j++) {
            toplam += dist[j];
        }
        toplamMaliyetler[i] = toplam;
        printf("Kok %c -> Toplam Maliyet: %d\n", dugumler[i], toplam);

        if (toplam < minToplam) {
            minToplam = toplam;
        }
    }

    printf("\nEn Merkezi Dugumler (Min Maliyet = %d): ", minToplam);
    for (int i = 0; i < N; i++) {
        if (toplamMaliyetler[i] == minToplam) {
            printf("%c ", dugumler[i]);
        }
    }
    printf("\n");

    return 0;
}