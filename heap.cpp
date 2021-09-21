#include<bits/stdc++.h>
using namespace std;

class heap{
    vector<int>v;
    bool minHeap;
    bool compare(int a,int b){
        if(minHeap)
            return a<b;
        else
            return a>b;
    }


    void heapify(int idx){
        int left = 2*idx;
        int right = 2*idx+1;
        int last = v.size()-1;
        int min_idx = idx;

        if(left <= last && compare(v[left],v[idx]))
            min_idx = left
        if(right <= last && compare(v[right],v[min_idx]))
            min_idx = right;
        
        if(min_idx!=idx){
            swap(v[idx],v[min_idx]);
            heapify(min_idx);
        }
    }
    public:
    heap(int default_size = 10, bool type = true){
        v.reserve(default_size);
        v.push_back(-1);
        minHeap = type;
    }
    void push(int d){

        v.push_back(d);
        int idx = v.size()-1;
        int parent = idx/2;
        // till if min heap 
        while(idx>1 && compare(v[idx],v[parent])){
            swap(v[idx],v[parent]);
            idx = parent;
            parent = parent/2;
        }
    }
    int top(){
        return v[1];
    }
    void pop(){
        // swap first and last element
        int last = v.size()-1;
        swap(v[1],v[last]);
        v.pop_back();
        heapify(1);
    }
};

int main(){
    heap h(10,true);

    for(int i = 0; i < 10; i++){
        int n; cin >> n;
        h.push(n);
    }
    while(!h.empty()){
        cout<< h.top() <<" ";
        h.pop();
    }
    return 0;
}