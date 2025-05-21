// Queue.java

public class Queue<T> {
    private static final int MAX_CAPACITY = 20;
    private final T[] data;
    private int head, tail;

    // Ctor queue (kosong) dengan alokasi kapasitas maksimum
    public Queue() {
        this.data = (T[]) new Object[MAX_CAPACITY];
        this.head = 0;
        this.tail = 0;
    }

    // Ctor queue terisi dari array dengan alokasi kapasitas maksimum.
    // Copy array dari indeks ke-0 hingga terakhir (data.length)
    // Boleh dilakukan secara copy reference object (bukan reference array)
    public Queue(T[] input) {
        this.data = (T[]) new Object[MAX_CAPACITY];
        this.head = 0;
        this.tail = input.length;
        System.arraycopy(input, 0, this.data, 0, input.length);
    }

    // Mengintip element paling depan pada queue.
    // Jika queue kosong, return null
    public T peek() { 
        if (size() == 0) return null;
        return data[head];
    }

    // Mengeluarkan elemen paling depan dari queue.
    // Jika queue kosong, return null
    public T pop() { 
        if (size() == 0) return null;
        return data[head++];
    }

    // Menambahkan elemen ke dalam queue.
    // Prekondisi: tail < MAX_CAPACITY - 2 (tidak perlu divalidasi)
    public void push(T o) { 
        data[tail++] = o;
    }

    // Menghitung panjang queue.
    public int size() { 
        return tail - head;
    }

    // Getter attribute
    public T[] getData() {
        return data;
     }
    public int getHead() { 
        return head;
    }
    public int getTail() { 
        return tail;
    }
}