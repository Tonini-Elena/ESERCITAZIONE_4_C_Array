#include <iostream>
#include <iomanip>
#include "utils.hpp"

using namespace std;

int main() {
    double S;
    size_t n;
    double* w = nullptr;
    double* r = nullptr;

   ImportVectors("data.txt", S, n, w, r);

   double rate = weightedAverage(n, w, r);
   double V = ReturnRate(S, rate);

  cout << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
  cout << "v1 = " << ArrayToString(n, w) << endl;
  cout << "v2 = " << ArrayToString(n, r) << endl;
  cout << "Rate of Return of the portfolio: " << fixed << setprecision(4) << rate << endl;
  cout << "V: " << fixed << setprecision(2) << V << endl;

  ExportResult("result.txt", n, w, r, S, rate, V);

  delete[] w;
  delete[] r;

    
  return 0;
}