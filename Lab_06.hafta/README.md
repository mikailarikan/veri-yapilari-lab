# VERİ YAPILARI LABORATUVARI
**Konu:** İkili Arama Ağaçları (Binary Search Tree - BST) | **Programlama dili:** C

## BÖLÜM A - LABORATUVAR SORULARI
Bu bölümde yalnızca sorular bulunmaktadır. Çözümler belgenin sonraki bölümündedir.

---

### Soru 1 - BST oluşturma ve Inorder dolaşma
C dilinde bir ikili arama ağacı oluşturunuz. Tam sayı değerlerini ağaca ekleyen `insert()` fonksiyonunu ve ağacın elemanlarını küçükten büyüğe yazdıran `inorder()` fonksiyonunu yazınız.

Programa sırasıyla 40, 20, 60, 10, 30, 50, 70 değerlerini ekleyiniz. Aynı değer tekrar verilirse yeni düğüm oluşturmayınız.

**Beklenen çıktı:** Inorder: 10 20 30 40 50 60 70  
**İpucu:** BST'de küçük değerler sola, büyük değerler sağa yerleştirilir. Inorder sırası: sol → kök → sağ.

<p style="color: #2563eb; font-size: 16px; font-weight: bold; margin-top: 12px;">
📌 Çözüm kodu soru01.c dosyasında mevcuttur.
</p>

---

### Soru 2 - BST üzerinde arama ve minimum bulma
Birinci soruda oluşturduğunuz ağacı kullanarak iki fonksiyon yazınız:
* `search()`: Verilen değerin ağaçta bulunup bulunmadığını kontrol etsin (bulunduysa 1, bulunamadıysa 0).
* `findMin()`: Ağaçtaki en küçük değeri döndürsün. Fonksiyonun boş olmayan bir ağaçla çağrıldığını varsayınız.

Ağaçta 30 ve 90 değerlerini aratınız; ardından en küçük elemanı yazdırınız.

**Beklenen çıktı:**  
30 agacta bulundu.  
90 agacta bulunamadi.  
En kucuk eleman: 10  

**Not:** İkinci soruda ilk sorudaki `Node` yapısını ve `insert()` fonksiyonunu yeniden yazmanıza gerek yoktur. Soru 1'deki `main()` fonksiyonunu aşağıdakiyle değiştiriniz:

```c
int main() {
    Node *root = NULL;
    int numbers[] = {40, 20, 60, 10, 30, 50, 70};

    for (int i = 0; i < 7; i++)
        root = insert(root, numbers[i]);

    if (search(root, 30))
        printf("30 agacta bulundu.\n");
    else
        printf("30 agacta bulunamadi.\n");

    if (search(root, 90))
        printf("90 agacta bulundu.\n");
    else
        printf("90 agacta bulunamadi.\n");

    if (root != NULL)
        printf("En kucuk eleman: %d\n", findMin(root));

    return 0;
}
```

**Açıklama:** `search()` yalnızca karşılaştırmanın işaret ettiği dalda arama yapar. `findMin()` ise en soldaki düğüme ulaşır.

<p style="color: #2563eb; font-size: 16px; font-weight: bold; margin-top: 12px;">
📌 Çözüm kodu soru02.c dosyasında mevcuttur.
</p>

---

### Kısa değerlendirme soruları

* **25 değeri eklenirse hangi düğümün altına yerleşir?** <span style="color: #16a34a; font-weight: bold;">— Cevap: 30 düğümünün sol kısmına gider.</span>

* **Inorder fonksiyonunda printf() ilk satıra taşınırsa hangi dolaşma elde edilir?** <span style="color: #16a34a; font-weight: bold;">— Cevap: İlk satıra taşındığında işlem sırası "Kök -> Sol -> Sağ" şeklinde değişeceği için elde edilen dolaşma Preorder dolaşmadır.</span>

* **findMin() içinde left yerine right takip edilirse hangi değer bulunur?** <span style="color: #16a34a; font-weight: bold;">— Cevap: left yerine right işaretçisi sürekli takip edildiğinde ağacın en sağ ucuna ulaşılır ve bu işlem ağaçtaki en büyük değeri (maksimum) bulur.</span>
