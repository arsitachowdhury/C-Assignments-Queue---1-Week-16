class MyCircularDeque {
public:
    int* a;
    int size, f, r;
    MyCircularDeque(int k) {
        size = k;
        a = new int[size];
        f = -1, r = -1;
    }

    bool insertFront(int value) {
        if ((r + 1) % size == f)
            return false;
        if (f == -1 && r == -1) {
            f++;
            r++;
            a[f] = value;
            return true;
        }
        f--;
        f = (f + size) % size;
        a[f] = value;
        return true;
    }

    bool insertLast(int value) {
        if ((r + 1) % size == f)
            return false;
        if (f == -1 && r == -1) {
            f++;
            r++;
            a[r] = value;
            return true;
        }
        r++;
        r %= size;
        a[r] = value;
        return true;
    }

    bool deleteFront() {
        if (f == -1 && r == -1)
            return false;
        if (f == r) {
            f = -1;
            r = -1;
            return true;
        }
        f++;
        f = f % size;
        return true;
    }

    bool deleteLast() {
        if (f == -1 && r == -1)
            return false;
        if (f == r) {
            f = -1;
            r = -1;
            return true;
        }
        r--;
        r = (r + size) % size;
        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;
        return a[f];
    }

    int getRear() {
        if (isEmpty())
            return -1;
        return a[r];
    }

    bool isEmpty() {
        if (f == -1)
            return true;
        return false;
    }

    bool isFull() {
        if ((r + 1) % size == f)
            return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */