class Solution {
public:
    long long findSmallest(vector<int>& nums1, vector<int>& nums2, long long midProduct) {
        long long productCount = 0;
        int n = nums2.size();

        for (int i = 0; i < nums1.size(); i++) {
            int num = nums1[i];

            if (num == 0) {
                if (midProduct >= 0)
                    productCount += n;
                continue;
            }

            if (num > 0) {
                int l = 0, r = n - 1, m = -1;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    long long product = 1LL * num * nums2[mid];
                    if (product <= midProduct) {
                        m = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                productCount += (m + 1);
            } else {
                int l = 0, r = n - 1, m = n;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    long long product = 1LL * num * nums2[mid];
                    if (product <= midProduct) {
                        m = mid;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                productCount += (n - m);
            }
        }
        return productCount;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        long long l = -1e10, r = 1e10;
        long long result = 0;

        while (l <= r) {
            long long midProduct = l + (r - l) / 2;
            long long countSmallest = findSmallest(nums1, nums2, midProduct);
            if (countSmallest >= k) {
                result = midProduct;
                r = midProduct - 1;
            } else {
                l = midProduct + 1;
            }
        }

        return result;
    }
};
