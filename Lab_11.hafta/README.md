# Hafta 11 - Graf Özellikleri, İki Parçalı (Bipartite) Graflar ve Dijkstra Algoritması

## Soru 1: Graf Dereceleri ve İki Parçalı (Bipartite) Graf Kontrolü

Verilen 6 düğümlü yönsüz graf ($V = \{1, 2, 3, 4, 5, 6\}$) ve kenar kümesi:

$$E = \{(1, 2), (1, 4), (2, 3), (3, 4), (3, 6), (4, 5), (5, 6)\}$$

### Görevler
1. **Komşuluk Matrisi:** Verilen grafı $6 \times 6$ boyutunda bir komşuluk matrisi ile modelleyiniz.
2. **Derece Hesaplama:** Her bir düğümün derecesini ve grafın genel derecesini (toplam kenar sayısını) hesaplayınız.
3. **Bipartite (İki Parçalı) Kontrolü:** `1` numaralı düğümden başlayarak BFS tabanlı uzaklık / renklendirme (tek-çift parite) yöntemiyle grafın iki parçalı (Bipartite) olup olmadığını kontrol ediniz. İki parçalı ise düğümleri iki ayrı kümeye ($U$ ve $V$) ayırarak gösteriniz.
4. **Dinamik Test:** Grafa `(2, 4)` kenarını ekleyiniz. Güncel komşuluk matrisini, düğüm derecelerini, grafın genel derecesini ve Bipartite durumunu yeniden analiz ediniz.

---

## Soru 2: Ağırlıklı Grafta Dijkstra En Kısa Yol Algoritması

Aşağıdaki kenar ağırlıklarına sahip 6 düğümlü (`A, B, C, D, E, F`) yönsüz ve ağırlıklı bir lojistik ağı verilmiştir:

| Kenar | Maliyet (Ağırlık) |
| :---: | :---: |
| A - B | 7 |
| A - C | 5 |
| A - F | 1 |
| B - C | 1 |
| B - D | 1 |
| B - E | 3 |
| C - D | 2 |
| C - E | 1 |
| D - F | 7 |
| E - F | 2 |

### Görevler
1. **Dijkstra Tablosu:** Kullanıcıdan alınan kök düğüm için Dijkstra algoritmasını çalıştırarak her düğümün `Known`, `Distance` ve `Path` değerlerini tablo halinde yazdırınız.
2. **Rota Çıkarma (Backtracking):** Kök düğüm `A` seçildiğinde, `B` ve `D` düğümlerine giden en düşük maliyetli rotaları tersten okuma yöntemiyle belirleyip toplam maliyetleriyle birlikte yazdırınız.
3. **Merkezi Düğüm Analizi:** Algoritmayı `A`'dan `F`'ye kadar tüm düğümleri sırayla kök kabul ederek çalıştırınız. Her kök için diğer tüm düğümlere ulaşmanın toplam en kısa yol maliyetini hesaplayarak ağın en merkezi düğümünü (ana aktarma merkezini) tespit ediniz.
