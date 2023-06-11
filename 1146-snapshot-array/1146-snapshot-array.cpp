class SnapshotArray {
public:
    unordered_map<int , map<int , int>> mp;
    int sp = 0;
    SnapshotArray(int length) {
    
    }
    
    void set(int index, int val) {
        mp[index][sp] = val;    
    }
    
    int snap() {
        sp++;
        return sp - 1;
    }
    
    int get(int index, int snap_id) {
        
        auto it = mp[index].upper_bound(snap_id);
        if( it == mp[index].begin() )return 0;
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */