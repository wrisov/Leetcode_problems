class LFUCache {
public:
    // map(list) : cnt->[{key,val}]
    // hashmap() : key->(cnt,ptr)
    map<int,list<pair<int,int>>> q; // q[cnt]=[{key,val}]
    unordered_map<int,pair<int,list<pair<int,int>>::iterator>> m; // m[key]={cnt,ptr}
    int maxSz, sz;
    
    LFUCache(int capacity) {
        this->maxSz=capacity;
        this->sz=0;
    }
    
    void del(list<pair<int,int>>::iterator ptr, int cnt){
        q[cnt].erase(ptr);
        if (q[cnt].size()==0)
            q.erase(cnt);
    }
    
    void update(int key, int cnt, int val){
        del(m[key].second,cnt);
        q[cnt+1].push_front(make_pair(key,val));
        m[key]=make_pair(cnt+1,q[cnt+1].begin());
    }
    
    int get(int key) {
        if (m.find(key)==m.end())
            return -1;
        int cnt=m[key].first;
        int val=m[key].second->second;
        update(key,cnt,val);
        return val;
    }
    
    void put(int key, int value) {
        if (!maxSz)
            return;
        if (m.find(key)!=m.end()){
            int cnt=m[key].first;
            update(key,cnt,value);
            return;
        }
        sz+=1;
        if (sz>maxSz){
            int k=q.begin()->second.back().first;
            int cnt=q.begin()->first;
            list<pair<int,int>>::iterator it=q[cnt].end();
            it--;
            del(it,cnt);
            m.erase(k);
            sz-=1;
        }
        q[1].push_front(make_pair(key,value));
        m[key]=make_pair(1,q[1].begin());
    }
};