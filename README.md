# RFC 9213 Uyumlu, Modüler API Gateway İstek Zamanlayıcısı

Bu proje, **Kırklareli Üniversitesi Yazılım Mühendisliği** Veri Yapıları ve Algoritmalar dersi kapsamında geliştirilmiştir. Projenin amacı, **RFC 9213 (Extensible HTTP Priorities)** standartlarını kullanarak, gelen HTTP isteklerini bir öncelikli kuyruk (Priority Queue) yapısında simüle eden bir API Gateway zamanlayıcısı oluşturmaktır.

## 🚀 Proje Özellikleri

* **RFC 9213 Uyumluluğu:** İstek öncelikleri `u` (Urgency) parametresine göre (`u=0` en yüksek, `u=7` en düşük) işlenir.
* **Min-Heap Algoritması:** Öncelikli kuyruk yapısı, performans ve verimlilik için Min-Heap veri yapısı kullanılarak implemente edilmiştir.
* **Modüler Mimari:** Kod yapısı C dilinin sunduğu header (`.h`) ve source (`.c`) ayrımına uygun olarak tasarlanmıştır.
* **Dinamik Bellek Yönetimi:** Sabit dizi boyutları yerine `malloc` ve `realloc` kullanılarak esnek bir bellek yönetimi sağlanmıştır.

## 🏗️ Yazılım Mimarisi

Sistem üç temel katmandan oluşmaktadır:

1.  **`priority_queue.h` (Interface):** Veri yapıları (Request, PriorityQueue) ve fonksiyon prototiplerini içeren arayüz dosyası.
2.  **`priority_queue.c` (Implementation):** `heapify_up`, `heapify_down`, `insert` ve `extract_min` gibi çekirdek algoritmaların bulunduğu uygulama dosyası.
3.  **`main.c` (Controller):** RFC Parser fonksiyonunu içeren ve sistemin demo senaryolarını yürüten ana giriş noktası.

## 📊 Neden Min-Heap?

API Gateway gibi yüksek trafikli sistemlerde sıradan bir dizi (array) kullanmak, en öncelikli elemanı bulmak için her seferinde $O(n)$ zaman karmaşıklığına yol açar. Min-Heap kullanımı sayesinde:
* **Ekleme (Insertion):** $O(\log n)$
* **En Öncelikliyi Çıkarma (Extract Min):** $O(\log n)$
* **En Öncelikliyi Bulma:** $O(1)$

Bu performans değerleri, sistemin yoğun yük altında stabil kalmasını sağlar.

## 🛠️ Kurulum ve Çalıştırma

Projeyi yerel makinenizde çalıştırmak için aşağıdaki adımları izleyebilirsiniz:

1.  Depoyu klonlayın veya dosyaları indirin.
2.  Bir C derleyicisi (GCC vb.) kullanarak dosyaları derleyin:
    ```bash
    gcc main.c priority_queue.c -o gateway
    ```
3.  Uygulamayı çalıştırın:
    ```bash
    ./gateway
    ```

## 👨‍💻 Geliştirici
* **Samed** - Yazılım Mühendisliği Öğrencisi, Kırklareli Üniversitesi
