class MyHashSet {
private:
    int num_buckets;
    std::vector<std::list<int>> buckets;

    // Hash function to map key to a bucket index
    int hash(int key) {
        return key % num_buckets;
    }

public:
    MyHashSet() {
        num_buckets = 1009; // A prime number to reduce collisions
        buckets.resize(num_buckets);
    }
    
    void add(int key) {
        int i = hash(key);
        // Only add if it doesn't already exist
        if (!contains(key)) {
            buckets[i].push_back(key);
        }
    }
    
    void remove(int key) {
        int i = hash(key);
        // Find the key in the linked list and remove it
        auto& bucket = buckets[i];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == key) {
                bucket.erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int i = hash(key);
        // Search for the key in the bucket
        for (int val : buckets[i]) {
            if (val == key) {
                return true;
            }
        }
        return false;
    }
};