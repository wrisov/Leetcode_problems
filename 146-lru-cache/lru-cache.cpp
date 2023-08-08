class LRUCache {
 int cache_capacity;                                         // Cache capacity
    list<int> keys;                                             // list of keys
    unordered_map<int, pair<int, list<int>::iterator>> mp;      // Hash of key as integer and value as pair with value and position in the list using iterator
public:
    LRUCache(int capacity) {
        cache_capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!= mp.end())                    //  First we have to check if he key is present in the map
        {                                              // If yes
            keys.erase(mp[key].second);               // Remove the key from that location where, location is taken from map value pair
            keys.push_front(key);                     // Then add the key to the front of the list.
            mp[key].second = keys.begin();   // and set the location of key in the map value pair
            return mp[key].first;               // return the value of the key
        }
        else
        {
            return -1;   // If not found return -1
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!= mp.end())   // If key found then we simply need to remove the key location from the map and shift it to front.
        {
            keys.erase(mp[key].second);
        }
        else  // else, we need to check the capacity of the cache, if capacity is full remove the last key in the key list.
        {
            if(keys.size() == cache_capacity)
            {
                mp.erase(keys.back());
                keys.pop_back();
            }
        }
        keys.push_front(key);
        mp[key] = {value, keys.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */