// #include <algorithm>
// #include <climits>
//
// #include <climits>
// #include <cstring>
// #include <iostream>
// #include <unordered_map>
//
// using namespace std;
// int findmax(int *arr, int m) {
//   int max = arr[0];
//   for (int i = 0; i < m; i++) {
//     if (arr[i] > max) {
//       max = arr[i];
//     }
//   }
//   return max;
// }
// int minim(int *arr, int n) {
//   int min = arr[0];
//   for (int i = 0; i < n; i++) {
//     if (arr[i] < min) {
//       min = arr[i];
//     }
//   }
//   return min;
// }
// int findpairs(int *arr, int n, int m) {
//   int max = findmax(arr, m);
//   int now = arr[0];
//   int res[n];
//   memset(res, 0, n);
//   int j = 0;
//   while (j < m) {
//     for (int i = 0; i < arr[j]; i++) {
//       int p = minim(res, n);
//       res[p]++;
//       j++;
//     }
//   }
//   int count = 0;
//   for (int i = 0; i < n; i++) {
//     if (res[i] == m) {
//       count++;
//     }
//   }
//   return count;
// }
// int main() {
//   int t;
//   cin >> t;
//
//   while (t--) {
//     int n, m;
//     cin >> n >> m;
//     int arr[m];
//     for (int i = 0; i < m; i++) {
//       cin >> arr[i];
//     }
//     int max = findmax(arr, m);
//     if (max > n) {
//       cout << 0 << endl;
//     }
//     if (max < n) {
//       cout << findpairs(arr, n, m) << endl;
//     }
//   }
//   return 0;
// }
#include <iostream>
#include <string>

using namespace std;

bool ispalindrome(string s, int n) {
  string temp = "";
  for (int i = n - 1; i >= 0; i--) {
    temp += s[i];
  }
  if (temp == s) {
    return true;
  } else {
    return false;
  }
}
// bool ispalindrome(string s, int n) {
//   for (int i = 0; i < n / 2; i++) {
//     if (s[i] != s[n - 1 - i]) {
//       return false;
//     }
//   }
//   return true;
// }

string palindromechech(string temp, int n) {
  string s;
  if (ispalindrome(temp, n)) {
    return "yes"; // Add return statement here
  } else {
    for (int i = 1; i < n; i++) {
      string s = temp;
      s.erase(i - 1, 3);
      if (ispalindrome(s, n - 3)) {
        return "yes";
      }
    }
  }
  return "no";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string res;
    cin >> n;
    string s;
    cin >> s;
    cout << palindromechech(s, n) << endl;
  }
  return 0;
}
