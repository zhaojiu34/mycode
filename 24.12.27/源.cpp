#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

  
      vector<int> FindNumsAppearOnce(vector<int>& array) {
          // write code here
          vector<int>v1;
          sort(array.begin(), array.end());
          unordered_map<int, bool>unmp;
          for (int i = 0; i < array.size(); i++) {
              if (unmp[array[i]] == true) unmp[array[i]] = false;
              else unmp[array[i]] = true;
          }
          for (int i = 0; i < array.size(); i++) {
              if (unmp[array[i]] == true) v1.push_back(array[i]);
          }
          return v1;
      }
