#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// RFC 9213'e göre Request Yapısı
typedef struct {
    int id;
    char url[100];
    int priority; // u=0 (En yüksek), u=7 (En düşük)
} Request;

typedef struct {
    Request *data;
    int size;
    int capacity;
} PriorityQueue;

// Fonksiyon Prototipleri
PriorityQueue* create_queue(int initial_capacity);
void insert_request(PriorityQueue *pq, Request req);
Request extract_min(PriorityQueue *pq);
void heapify_up(PriorityQueue *pq, int index);
void heapify_down(PriorityQueue *pq, int index);
void free_queue(PriorityQueue *pq);

#endif
