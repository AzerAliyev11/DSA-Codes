//minimum range query segment tree implementation

#include <iostream>
#include <vector>

typedef std::vector<int>& arr;

void construct_tree(arr data, arr segmentTree, int low, int high, int pos) {
    if(low == high) {
        segmentTree[pos] = data[low];
        return;
    }

    int mid = (low + high) / 2;
    construct_tree(data, segmentTree, low, mid, 2*pos + 1);
    construct_tree(data, segmentTree, mid + 1, high, 2*pos + 2);
    segmentTree[pos] = std::min(segmentTree[pos*2 + 1], segmentTree[pos*2 + 2]);
}

int range_querry(arr segmentTree, int qlow, int qhigh, int low, int high, int pos) {
    //total overlap
    if(qlow <= low && qhigh >= high) {
        return segmentTree[pos];
    }

    //no overlap
    if(qlow > high || qhigh < low) {
        return INT_MAX;
    }

    //partial overlap
    int mid = (low + high) / 2;
    return std::min(range_querry(segmentTree, qlow, qhigh, low, mid, pos*2+1),
                    range_querry(segmentTree, qlow, qhigh, mid+1, high, pos*2 + 2));
}

int main() {
    std::vector<int> data;
    data.push_back(0);
    data.push_back(-1);
    data.push_back(3);
    data.push_back(4);

    int n = data.size();

    std::vector<int> segmentTree(4 * n, INT_MAX);
    construct_tree(data, segmentTree, 0, n-1, 0);

    std::cout<<range_querry(segmentTree, 0, 3, 0, n-1, 0)<<std::endl;
}