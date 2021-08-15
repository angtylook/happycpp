#include <iostream>
#include <queue>

class RecentCounter {
public:
    RecentCounter() {}

    int ping(int t) {
        q_.push(t);
        while (!q_.empty()) {
            if (t - q_.front() > 3000)
                q_.pop();
            else {
                break;
            }
        }
        return static_cast<int>(q_.size());
    }

private:
    std::queue<int> q_;
};

int main() {
    RecentCounter rc;
    for (int i : {1, 100, 3001, 3002}) {
        std::cout << rc.ping(i) << std::endl;
    }
    return 0;
}
