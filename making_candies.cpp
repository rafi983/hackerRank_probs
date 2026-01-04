#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;


long long minimumPasses(long long m, long long w, long long p, long long n) {
    long long passes = 0;
    long long candies = 0;
    long long answer = numeric_limits<long long>::max();

    while (true) {
        // Calculate production, handling overflow
        long long prod;
        if (m > 0 && w > numeric_limits<long long>::max() / m) {
             prod = numeric_limits<long long>::max();
        } else {
             prod = m * w;
        }

        // Calculate passes needed to finish with current rate
        long long remaining = max(0LL, n - candies);
        long long steps_to_finish;
        if (prod >= remaining) {
            steps_to_finish = (remaining > 0) ? 1 : 0;
        } else {
            steps_to_finish = (remaining + prod - 1) / prod;
        }

        if (answer == numeric_limits<long long>::max() || passes + steps_to_finish < answer) {
            answer = passes + steps_to_finish;
        }

        if (candies >= n) {
            break;
        }

        // If we can't buy anything, fast forward
        if (candies < p) {
            long long needed = p - candies;
            long long steps_to_wait;
            if (prod >= needed) {
                steps_to_wait = 1;
            } else {
                steps_to_wait = (needed + prod - 1) / prod;
            }

            // Optimization: if waiting to buy takes longer than just finishing, stop.
            if (passes + steps_to_wait >= answer) {
                break;
            }

            passes += steps_to_wait;
            candies += steps_to_wait * prod;
            continue;
        }

        // Buy upgrades
        long long can_buy = candies / p;
        candies %= p;

        if (m > w) swap(m, w);
        long long diff = w - m;

        if (can_buy <= diff) {
            m += can_buy;
        } else {
            can_buy -= diff;
            m += diff; // Now m == w
            m += can_buy / 2;
            w += can_buy - (can_buy / 2);
        }

        passes++;
        // Production for the next pass
        if (m > 0 && w > numeric_limits<long long>::max() / m) {
             candies = numeric_limits<long long>::max();
        } else {
             candies += m * w;
        }
    }

    return answer;
}

int main() {
    long long m, w, p, n;
    if (cin >> m >> w >> p >> n) {
        cout << minimumPasses(m, w, p, n) << endl;
    }
    return 0;
}
