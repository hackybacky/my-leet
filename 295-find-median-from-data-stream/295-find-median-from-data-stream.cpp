#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
//u can find count of element equal to or smaller by using pl and find_by_order({ele,1e18})
 
class MedianFinder {
public:
    ordered_set<pair<double,double>>o;
    int i;
    MedianFinder() {
        i=0;
    }
    
    void addNum(int num) {
        o.insert({num*1.0,i++});
    }
    
    double findMedian() {
       int sz = i;
        
        if(sz%2==1){
            
            auto it = *(o.find_by_order(sz/2));
            return it.first;
        }
        auto it =*(o.find_by_order(sz/2));
        auto it2=*(o.find_by_order((sz-1)/2));
        
        return (it.first*1.0+it2.first*1.0)/2*1.0;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */