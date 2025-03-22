#include "KeyValue.cpp"

int main(){
    KeyValue<int, string> kv;
    kv.set(1, "Alice");
    kv.set(2, "Bob");
    kv.set(3, "Charlie");
    kv.display(1); // Output: "Alice"
    kv.display(2); // Output: "Bob"
    kv.display(3); // Output: "Charlie"

    kv.set(1.2, "Ben");
    return 0;
}