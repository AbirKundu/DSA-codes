#include <stdio.h>
#include <stdlib.h>

struct Q {
    int* items;
    int f, r, s;
};

struct Q* createQ(int cap) {
    struct Q* q = (struct Q*)malloc(sizeof(struct Q));
    q->s = cap;
    q->f = q->r = -1;
    q->items = (int*)malloc(sizeof(int) * cap);
    return q;
}

int isFull(struct Q* q) {
    return (q->r == q->s - 1);
}

int isEmpty(struct Q* q) {
    return (q->f == -1);
}

void enqueue(struct Q* q, int item) {
    if (isFull(q))
        return;

    if (isEmpty(q))
        q->f = 0;

    q->items[++q->r] = item;
}

int dequeue(struct Q* q) {
    if (isEmpty(q))
        return -1;

    int item = q->items[q->f];
    if (q->f == q->r)
        q->f = q->r = -1;
    else
        q->f++;

    return item;
}

struct S {
    struct Q* q1;
    struct Q* q2;
};

struct S* createS() {
    struct S* s = (struct S*)malloc(sizeof(struct S));
    s->q1 = createQ(100);
    s->q2 = createQ(100);
    return s;
}

void push(struct S* s, int item) {
    enqueue(s->q1, item);
}

int pop(struct S* s) {
    if (isEmpty(s->q1))
        return -1;

    while (!isEmpty(s->q1)) {
        if (s->q1->f == s->q1->r)
            break;

        enqueue(s->q2, dequeue(s->q1));
    }

    int popped = dequeue(s->q1);

    struct Q* temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;

    return popped;
}

int main() {
    struct S* s = createS();

    push(s, 1);
    push(s, 2);
    push(s, 3);

    printf("Popped element: %d\n", pop(s));

    push(s, 4);
    push(s, 5);

    printf("Popped element: %d\n", pop(s));

    return 0;
}
