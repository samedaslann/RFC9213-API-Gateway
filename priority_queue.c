#include "priority_queue.h"

PriorityQueue* create_queue(int initial_capacity) {
    PriorityQueue *pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->data = (Request*)malloc(initial_capacity * sizeof(Request));
    pq->size = 0;
    pq->capacity = initial_capacity;
    return pq;
}

void swap(Request *a, Request *b) {
    Request temp = *a;
    *a = *b;
    *b = temp;
}

void insert_request(PriorityQueue *pq, Request req) {
    // Dinamik Bellek Yönetimi (realloc)
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->data = (Request*)realloc(pq->data, pq->capacity * sizeof(Request));
    }
    pq->data[pq->size] = req;
    heapify_up(pq, pq->size);
    pq->size++;
}

void heapify_up(PriorityQueue *pq, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && pq->data[index].priority < pq->data[parent].priority) {
        swap(&pq->data[index], &pq->data[parent]);
        heapify_up(pq, parent);
    }
}

Request extract_min(PriorityQueue *pq) {
    if (pq->size <= 0) {
        Request empty = {-1, "", 999};
        return empty;
    }
    Request root = pq->data[0];
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;
    heapify_down(pq, 0);
    return root;
}

void heapify_down(PriorityQueue *pq, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->data[left].priority < pq->data[smallest].priority)
        smallest = left;
    if (right < pq->size && pq->data[right].priority < pq->data[smallest].priority)
        smallest = right;

    if (smallest != index) {
        swap(&pq->data[index], &pq->data[smallest]);
        heapify_down(pq, smallest);
    }
}

void free_queue(PriorityQueue *pq) {
    free(pq->data);
    free(pq);
}
