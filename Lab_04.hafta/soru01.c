#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct tanımı
typedef struct Song {
    char name[50];
    struct Song* next;
    struct Song* prev;
} Song;

//fonksiyon imzaları
void addSongToEnd(Song** head, char* name);
void removeSong(Song** head, char* name);
void playNext(Song** current);
void playPrevious(Song** current);
void displayPlaylist(Song* head);

int main() {
    Song* playlist = NULL;      //Çalma listesinin başını tutan pointer
    Song* currentSong = NULL;   //Şuan hangi şarkı çalıyoru gösteren pointer
    int choice;
    char name[50];

    while (1) {
        printf("\n---MUZIK CALAR MENU---\n");
        printf("1. Sarki Ekle\n");
        printf("2. Sarki Sil\n");
        printf("3. Sonraki Sarkiyi Cal\n");
        printf("4. Onceki Sarkiyi Cal\n");
        printf("5. Calma Listesini Goster\n");
        printf("6. Su An Calan Sarkiyi Goster\n");
        printf("0. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Eklenecek sarki adi: ");
                scanf(" %49[^\n]", name); //Regex pattern'i ile enter görene kadar yazılanı al diyoruz(boşluklu isim de gelebilir)
                addSongToEnd(&playlist, name);
                
                // Eğer eklenen ilk şarkı ise otmatik onu çalmaya başla
                if (currentSong == NULL) {
                    currentSong = playlist;
                }
                printf("Sarki listeye eklendi.\n");
                break;
                
            case 2:
                printf("Silinecek sarki adi: ");
                scanf(" %49[^\n]", name);
                
                // Eğer silinecek şarkı şu an çalan şarkıysa, currentSong'u güncelleyelim
                if (currentSong != NULL && strcmp(currentSong->name, name) == 0) //strcmp eşit olduğunda 0 döndüreceğinden 0'a eşit miyi kontrol ediyoruz.
                {
                    if (currentSong->next != NULL) {
                        currentSong = currentSong->next;
                    } else {
                        currentSong = currentSong->prev; 
                    }
                }
                removeSong(&playlist, name);
                break;
                
            case 3:
                playNext(&currentSong);
                break;
                
            case 4:
                playPrevious(&currentSong);
                break;
                
            case 5:
                displayPlaylist(playlist);
                break;
                
            case 6:
                if (currentSong != NULL) {
                    printf("Su an caliyor: %s\n", currentSong->name);
                } else {
                    printf("Su an calan bir sarki yok veya liste bos.\n");
                }
                break;
                
            case 0:
                printf("Cikis yapildi.\n");
                return 0;
                
            default:
                printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
        }
    }
    return 0;
}


void addSongToEnd(Song** head, char* name) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->name, name);//name içerisindeki yazanı newSong name'ine atamak için strcpy
    newSong->next = NULL;
    newSong->prev = NULL;

    if (*head == NULL) {
        *head = newSong;
        return;
    }

    Song* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newSong;
    newSong->prev = temp;
}


void removeSong(Song** head, char* name) {
    if (*head == NULL) {
        printf("Liste bos!\n");
        return;
    }

    Song* temp = *head;

    // Silinecek şarkıyı bulmak için listeyi dolaş
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        temp = temp->next;
    }

    // Şarkı bulunamazsa
    if (temp == NULL) {
        printf("Sarki bulunamadi!\n");
        return;
    }

    // Şarkı listenin ilk başındaysa
    if (temp == *head) {
        *head = temp->next;
    }

    // Şarkının sonrasında bir düğüm varsa onun prev bağlantısını güncelle
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // Şarkının öncesinde bir düğüm varsa onun next bağlantısını güncelle
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp); 
    printf("Sarki silindi.\n");
}


void playNext(Song** current) {
    if (*current == NULL) {
        printf("Liste bos veya sarki secili degil.\n");
        return;
    }
    
    if ((*current)->next != NULL) {
        *current = (*current)->next;
        printf("Su an caliyor: %s\n", (*current)->name);
    } else {
        printf("Son sarkidasiniz, sonraki sarki yok.\n");
    }
}


void playPrevious(Song** current) {
    if (*current == NULL) {
        printf("Liste bos veya sarki secili degil.\n");
        return;
    }
    
    if ((*current)->prev != NULL) {
        *current = (*current)->prev;
        printf("Su an caliyor: %s\n", (*current)->name);
    } else {
        printf("Ilk sarkidasiniz, onceki sarki yok.\n");
    }
}


void displayPlaylist(Song* head) {

    if (head == NULL) {
        printf("Liste bos.\n");
        return;
    }
    
    printf("\n--- Calma Listesi ---\n");
    Song* temp = head;
    while (temp != NULL) {
        printf("- %s\n", temp->name);
        temp = temp->next;
    }
    printf("---------------------\n");
}