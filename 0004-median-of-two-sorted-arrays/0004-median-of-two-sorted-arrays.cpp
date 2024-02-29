#include <vector>

class Solution {
public:
 double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
 /*   int m = nums1.size(), n = nums2.size();
    
    // Handle empty arrays
    if (m == 0) return (n % 2 == 0) ? (nums2[n / 2 - 1] + nums2[n / 2]) / 2.0 : nums2[n / 2];
    if (n == 0) return (m % 2 == 0) ? (nums1[m / 2 - 1] + nums1[m / 2]) / 2.0 : nums1[m / 2];

    long total = m + n; // Use long to prevent overflow
    int i = 0, j = 0, count = 0;
    double median1, median2;

    // Traverse both arrays and find the median elements
    while (count <= total / 2) {
      // Get the median element
      if (i != m && (j == n || nums1[i] <= nums2[j])) {
        median1 = nums1[i];
        i++;
      } else {
        median1 = nums2[j];
        j++;
      }

      // Check if we need to find another median (odd total elements)
      if (count == total / 2) {
        break;
      }

      // Get the second median element (if needed)
      if (i != m && (j == n || nums1[i] < nums2[j])) {
        median2 = nums1[i];
        i++;
      } else {
        median2 = nums2[j];
        j++;
      }
      count++;
    }

    // Calculate the final median based on even or odd total elements
    if (total % 2 == 0) {
      return (median1 + median2) / 2.0;
    } else {
      return median2;
    }*/
     
     vector<int> result;
     double final_n;
     for(int i=0;i< (nums1.size());i++)
     {
         result.push_back(nums1[i]);
     }
      for(int i=0;i< (nums2.size());i++)
     {
         result.push_back(nums2[i]);
     }
     sort(result.begin(),result.end());
     
     int total_size = result.size();
        
        if (total_size % 2 != 0) {
            int res = total_size / 2;
            final_n = result[res];
        } else {
            int res = total_size / 2;
            final_n = (result[res - 1] + result[res]) / 2.0;  // Make sure to use 2.0 for correct floating-point division
        }
        
        return final_n;
  }
};
