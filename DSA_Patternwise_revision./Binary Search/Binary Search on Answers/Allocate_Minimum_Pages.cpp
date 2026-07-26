/*
    Problem: Allocate Minimum Pages
    Pattern: Binary Search on Answers

    Approach:
    1. If the number of students is greater than the number of books, return -1.
    2. The minimum possible answer is the maximum pages in a single book.
    3. The maximum possible answer is the sum of all pages.
    4. Apply Binary Search on this range of possible maximum pages.
    5. For each candidate value:
       - Allocate books sequentially to students.
       - If adding a book exceeds the current limit, assign it to a new student.
       - Count the number of students required.
    6. If all books can be allocated using at most k students, store the
       current value as a potential answer and search for a smaller one.
    7. Otherwise, search for a larger value.
    8. Return the minimum possible maximum pages assigned to any student.

    Key Insight:
    As the allowed maximum pages per student increases, the number of students
    required never increases. This monotonic property enables Binary Search
    on the answer space.

    Time Complexity: O(n × log(sum(arr)))
    Space Complexity: O(1)
*/

class Solution {
public:
    bool possible(long long mid, vector<int>& arr, int k) {
        long long sum = 0;
        int count = 1;

        for (int i = 0; i < arr.size(); i++) {
            if (sum + arr[i] <= mid) {
                sum += arr[i];
            } else {
                count++;
                sum = arr[i];

                if (count > k)
                    return false;
            }
        }

        return true;
    }

    int findPages(vector<int>& arr, int k) {
        if (k > arr.size())
            return -1;

        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (possible(mid, arr, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};
