#include<iostream>
#include<queue>
#include<utility>
#include<vector>
using namespace std;


typedef pair<int, int> pi;

struct cmp {
    constexpr bool operator()(
        pi const& a, pi const& b
    ) const noexcept {
        return a.first > b.first;
    }
};

int main() {
    priority_queue<pi,vector<pi>, cmp> pq;
    pq.push(make_pair(0, 2));
    pq.push(make_pair(4, 1));
    pq.push(make_pair(3, 3));
    pq.push(make_pair(3, 2));

    while(!pq.empty()) {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}