#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

int main(){

    string date, numS;
    float num;
    fstream file1, file2;
    file1.open("temperature.txt", ios::in);
    file2.open("average.txt", ios::out);

    while (file1 >> date) {
      float res = 0;
      for (int i = 1; i <= 24; i++) {
        file1 >> numS;
        res += stof(numS);;
      }
      res /= 24.0;
      file2 << date << " " << setprecision(1) << fixed << res << endl;
    }

    file1.close();
    file2.close();
}