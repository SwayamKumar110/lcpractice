class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        // Count frequency of each task
        for (char task : tasks) {
            freq[task]++;
        }

        // Max heap: {frequency, task}
        priority_queue<pair<int, char>> pq;

        for (auto i : freq) {
            pq.push({i.second, i.first});
        }

        int time = 0;

        while (!pq.empty()) {
            vector<pair<int, char>> temp;

            for (int i = 0; i <= n; i++) {

                if (!pq.empty()) {
                    auto p = pq.top();
                    pq.pop();

                    int frequency = p.first;
                    char task = p.second;

                    frequency--;

                    if (frequency > 0) {
                        temp.push_back({frequency, task});
                    }

                    time++;
                }
                else {
                    if (temp.empty()) {
                        break;
                    }

                    time++;
                }
            }

            for (auto p : temp) {
                pq.push(p);
            }
        }

        return time;
    }
};