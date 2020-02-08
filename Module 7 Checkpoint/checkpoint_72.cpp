#include <iostream>
using namespace std;

int main() {
  string original, key, ans;
  char res[5000];
  getline(cin, original);
  cin >> key >> ans;

  int i = 0, a = 0;
  while (a < original.length()){
    if(key == original.substr(a, key.length())) {
      a += key.length();
      int c = 0;
      for (int j = 0; j < ans.length(); j++) {
        res[i++] = ans[j];
      }
    }

    else {
      res[i] = original[a];
      i++;
      a++;
    }
  }


  cout<<res;

}