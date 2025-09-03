class Solution {
public:
    struct Ratio {
        double diff;
        double ratio;
        int pass;
        int total;
    };

    struct CompareRatio {
        bool operator()(const Ratio& a, const Ratio& b) const {
            return a.diff < b.diff;
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Ratio, vector<Ratio>, CompareRatio> pq;

        for(const auto& c: classes) {
            double ratio = (double)c[0]/(double)c[1];
            pq.push({(double)(c[0]+1)/(double)(c[1]+1) - ratio, ratio, c[0], c[1]});
        }

        while(extraStudents--) {
            auto curr = pq.top();
            pq.pop();
            ++curr.pass;
            ++curr.total;
            curr.ratio = (double)curr.pass / (double)curr.total;
            curr.diff = (double)(curr.pass+1) / (double)(curr.total+1) - curr.ratio;
            pq.push(curr);
        }

        double acc = 0.0;
        while(!pq.empty()) {
            acc += pq.top().ratio;
            pq.pop();
        }

        return acc / (double)classes.size();
    }
};

// Brute Force
// class Solution {
// public:
//     double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
//         int len = classes.size();
//         vector<double> ratios(len);

//         for (int i = 0; i < len; ++i)
//             ratios[i] = (double)classes[i][0] / (double)classes[i][1];

//         while (extraStudents) {
//             double max_diff = 0.0, max_ratio = 0.0;
//             int max_idx = 0;
//             for (int i = 0; i < len; ++i) {
//                 double new_ratio =
//                     (double)(classes[i][0] + 1) / (double)(classes[i][1] +
//                     1);
//                 if (new_ratio - ratios[i] > max_diff) {
//                     max_idx = i;
//                     max_ratio = new_ratio;
//                     max_diff = new_ratio - ratios[i];
//                 }
//             }

//             cout << max_idx << endl;
//             ++classes[max_idx][0];
//             ++classes[max_idx][1];
//             ratios[max_idx] = max_ratio;
//             --extraStudents;
//         }

//         return (double)(accumulate(ratios.begin(), ratios.end(), 0.0) / len);
//     }
// };