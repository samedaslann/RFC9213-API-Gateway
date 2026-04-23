#include "priority_queue.h"

// Basit RFC 9213 Parser: "u=X" formatındaki stringi tam sayıya çevirir
int parse_rfc_priority(const char *header) {
    int priority = 7; // Varsayılan en düşük öncelik
    char *ptr = strstr(header, "u=");
    if (ptr) {
        priority = ptr[2] - '0';
    }
    return priority;
}

int main() {
    PriorityQueue *api_gateway = create_queue(5);

    // Senaryo: Farklı önceliklerde HTTP istekleri geliyor
    char *headers[] = {"u=3", "u=0", "u=5", "u=1", "u=0"};
    char *urls[] = {"/index", "/admin", "/images", "/api/data", "/login"};

    printf("--- Istekler Gateway'e Aliniyor ---\n");
    for (int i = 0; i < 5; i++) {
        Request req;
        req.id = i + 100;
        strcpy(req.url, urls[i]);
        req.priority = parse_rfc_priority(headers[i]);
        
        printf("Alindi: ID:%d | URL:%-10s | Oncelik:%d (Header: %s)\n", 
               req.id, req.url, req.priority, headers[i]);
        insert_request(api_gateway, req);
    }

    printf("\n--- Min-Heap Calistiriliyor (Zamanlayici) ---\n");
    while (api_gateway->size > 0) {
        Request processed = extract_min(api_gateway);
        printf("Islemde: ID:%d | URL:%-10s | Oncelik:%d\n", 
               processed.id, processed.url, processed.priority);
    }

    free_queue(api_gateway);
    return 0;
}
