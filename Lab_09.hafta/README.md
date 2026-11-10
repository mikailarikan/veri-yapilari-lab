# VERİ YAPILARI LABORATUVARI: Dengeli Arama Ağaçları (AVL Tree)

**Amaç:** BST yapısında dengesizliği belirlemek, denge faktörünü hesaplamak ve AVL rotasyonlarını C diliyle uygulamak.

---

## Bölüm 1 - Laboratuvar Soruları

### Soru 1 - AVL Ağacına Ekleme ve Tek Rotasyon
Başlangıçta boş bir BST ağacına sırasıyla `10, 20, 30` sayıları eklenecektir. AVL ağacında her düğümün sol ve sağ alt ağaç yüksekliklerinin farkı en fazla 1 olabilir.

**İstenenler:**
1. Sayıları sırayla BST ağacına ekleyiniz ve her eklemeden sonra kökün denge faktörünü hesaplayınız.
2. Denge faktörü -1, 0, 1 aralığından çıkınca oluşan dengesizliği belirleyip gerekli rotasyonu uygulayınız.
3. C dilinde `createNode`, `insertBST`, `height`, `balanceFactor` ve `rotateLeft` fonksiyonlarını yazınız.
4. Son ağacın inorder ve preorder dolaşım sonuçlarını ekrana yazdırınız.

> **Not:** Bu soruda yalnızca verilen dizinin oluşturduğu RR dengesizliği ele alınacaktır.

**Beklenen Çıktı:**
```text
10 eklendi. BF(kok)=0
20 eklendi. BF(kok)=-1
30 eklendi. BF(kok)=-2
RR dengesizligi: Sol rotasyon!
Kok: 20
Inorder: 10 20 30
Preorder: 20 10 30
```

---

### Soru 2 - AVL Ağacında Dört Rotasyon Durumu
Başlangıçta boş olan dört ayrı AVL ağacına aşağıdaki dizileri ekleyiniz. Her test bağımsız olarak yürütülecektir.

| Test | Ekleme Sırası |
| :--- | :--- |
| **A (LL)** | 30, 20, 10 |
| **B (RR)** | 10, 20, 30 |
| **C (LR)** | 30, 10, 20 |
| **D (RL)** | 10, 30, 20 |

**İstenenler:**
1. Her dizide oluşan dengesizliği LL, RR, LR veya RL olarak sınıflandırınız.
2. C dilinde dört rotasyonu destekleyen genel bir `insertAVL` fonksiyonu yazınız.
3. Her testin sonundaki kök değerini ve preorder dolaşımını ekrana yazdırınız.
