# Veri Yapıları Lab 4.Hafta: Bağlı Liste, Stack ve Queue Soruları

---

### Soru 1: Müzik Çalar (Çift Bağlı Liste)

Şarkı ekleyip silebilen, ileri/geri şarkı geçişi yapabilen bir müzik çalar uygulaması yazın. Amaç, `prev` ve `next` pointer'larının dinamik şekilde yönetimini kavramaktır.

- Şarkıyı listenin sonuna ekleme fonksiyonu -> `addSongToEnd(Song** head, char* name)`
- Şarkı silme fonksiyonu -> `removeSong(Song** head, char* name)`
- Sonraki şarkıya geçme -> `playNext(Song** current)`
- Önceki şarkıya geçme -> `playPrevious(Song** current)`
- Çalma listesini gösterme -> `displayPlaylist(Song* head)`
- Kullanıcı seçimleriyle listeyi yöneten bir menü oluşturun.

İpucu: Şarkı silerken `prev` ve `next` bağlantılarını düzgün güncelleyin. Liste boşken "Liste boş" uyarısı verin.

Kod iskeleti:

```c
typedef struct Song {
    char name[50];
    struct Song* next;
    struct Song* prev;
} Song;

// Fonksiyon imzaları:
void addSongToEnd(Song** head, char* name);
void removeSong(Song** head, char* name);
void playNext(Song** current);
void playPrevious(Song** current);
void displayPlaylist(Song* head);
```

---

### Soru 2: Undo (Geri Alma) Özelliği Simülasyonu (Stack)

Stack kullanarak bir geri alma özelliği simüle edin.

- `add <kelime>` komutuyla girilen kelime stack'e eklenir -> `pushWord()`
- `undo` komutuyla son eklenen kelime geri alınır (pop) -> `popWord()`
- `show` komutuyla şu ana kadar eklenen kelimeler gösterilir -> `showWords()`

Beklenen örnek kullanım:

```
> add Merhaba
> add Dünya
> show   -> Merhaba Dünya
> undo
> show   -> Merhaba
```

Kod iskeleti:

```c
typedef struct Word {
    char text[50];
    struct Word* next;
} Word;

void pushWord(Word** top, char* text);
void popWord(Word** top);
void showWords(Word* top);
```

---

### Soru 3: Yazıcı Kuyruğu (Queue)

Bir yazıcının işlem sırasını taklit eden uygulama yazın. Her eklenen dosya kuyruğa alınır, "Yazdır" komutuyla sıradaki iş kuyruktan çıkarılır.

- Kuyruğa dosya ekleme fonksiyonu -> `enqueuePrintJob(Queue* q, char* fileName)`
- Sıradaki işi yazdırma fonksiyonu -> `processNextJob(Queue* q)`
- Kuyruğu gösterme fonksiyonu -> `showQueue(Queue q)`
- Menü: 1) Yeni dosya ekle, 2) Yazdır, 3) Kuyruğu göster

İpucu: Kuyruk boşken yazdırma işlemi yapılmamalıdır. FIFO (ilk giren ilk çıkar) mantığına dikkat edin.

Kod iskeleti:

```c
typedef struct PrintJob {
    char fileName[50];
    struct PrintJob* next;
} PrintJob;

typedef struct Queue {
    PrintJob* front;
    PrintJob* rear;
} Queue;

void enqueuePrintJob(Queue* q, char* fileName);
void processNextJob(Queue* q);
void showQueue(Queue q);
```
