# Veri Yapıları Lab - 3. Hafta Linked List Örnekleri



### Örnek 1: Sıralı Ekleme ve Değere Göre Silme
* **`addOrdered`**: Bağlı listeye yeni düğümü, mevcut sıralamayı bozmayacak şekilde ekler
* **`removeNode`**: Listede aranan değere sahip ilk düğümü bularak siler
* **`count`**: Listedeki mevcut düğüm sayısını döndürür

### Örnek 2: Pozisyona Göre İşlemler
* **`insertAt`**: Belirtilen pozisyona (indis) düğüm ekler. Negatif veya 0 indeks girildiğinde başa, liste boyutunu aşan bir indeks girildiğinde ise sona ekleme yapar.
* **`deleteAt`**: Belirtilen pozisyondaki düğümü siler. Geçersiz indeks girişlerinde işlem yapmaz

### Örnek 3: Ortadaki Düğümü Bulma
* **`findMiddle`**: Yavaş (slow) ve hızlı (fast) işaretçi algoritması kullanarak listenin ortasındaki düğümü tespit eder Çift sayıda eleman olması durumunda ortadaki iki elemandan ikincisini döndürür

### Ortak Yardımcı Fonksiyonlar
* **`printList`**: Listenin mevcut durumunu baştan sona ekrana yazdırır
* **`clear`**: Listedeki tüm düğümleri tek tek gezerek `free()` fonksiyonu ile bellekten temizler ve listeyi sıfırlar
