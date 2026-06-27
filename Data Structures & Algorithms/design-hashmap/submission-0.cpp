class MyHashMap {
private:
    // A large prime number to reduce collision probability
    static const int BUCKET_SIZE = 1009; 
    std::vector<std::list<std::pair<int, int>>> table;

    // Hash function to map key to a bucket index
    int _hash(int key) {
        return key % BUCKET_SIZE;
    }

public:
    MyHashMap() {
        table.resize(BUCKET_SIZE);
    }
    
    // Inserts a (key, value) pair. If the key already exists, update the value.
    void put(int key, int value) {
        int idx = _hash(key);
        for (auto& pair : table[idx]) {
            if (pair.first == key) {
                pair.second = value; // Key exists, update value
                return;
            }
        }
        // Key doesn't exist, insert new pair
        table[idx].push_back({key, value});
    }
    
    // Returns the value to which the specified key is mapped, or -1 if no mapping exists
    int get(int key) {
        int idx = _hash(key);
        for (const auto& pair : table[idx]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return -1;
    }
    
    // Removes the mapping for the specified key if it exists
    void remove(int key) {
        int idx = _hash(key);
        auto& bucket = table[idx];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */