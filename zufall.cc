#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

static int I = 2;
static ofstream pi("pi.txt");

double zufall(int a, int c, int m) {

  I = (a * I + c) % m;
  return (double)I / (double)m;
}

void verteilung(int a, int c, int m, int n) {

  int Kreis = 0;
  double p = M_PI / 4;
  double v = p * (1 - p) * n;

  for (int u = 0; u < n; ++u) {
    if (pow(zufall(a, c, m), 2) + pow(zufall(a, c, m), 2) < 1) {
      Kreis++;
    }
  }

  cout << setw(3) << a << " |" 
       << setw(6) << c << " |" 
       << setw(8) << m << " |"
       << setw(8) << n << " |" 
       << setw(8) << p * n << " |" 
       << setw(8) << v << " |" 
       << setw(7) << Kreis << " |" 
       << setw(8) << (double)Kreis / (double)n * 4 << " |" 
       << setw(11) << 4 * sqrt(v) / n << endl;

  pi   << setw(3) << a << " |" 
       << setw(6) << c << " |" 
       << setw(8) << m << " |"
       << setw(8) << n << " |" 
       << setw(8) << p * n << " |" 
       << setw(8) << v << " |"
       << setw(7) << Kreis << " |" 
       << setw(8) << (double)Kreis / (double)n * 4 << " |" 
       << setw(11) << 4 * sqrt(v) / n << endl;

  return;
}

int main() {

  vector<int> n{100, 10000, 100000, 1000000};

  cout << setw(3) << "a" << " |" 
       << setw(6) << "c" << " |" 
       << setw(8) << "m" << " |" 
       << setw(8) << "N" << " |" 
       << setw(12) << "E[N\u1d62\u2099]" << " |" 
       << setw(12) << "V[N\u1d62\u2099]" << " |" 
       << setw(11) << "N\u1d62\u2099" << " |" 
       << setw(9) << "\u03c0" << " |" 
       << setw(12) << "\u03c3"
       << "\n-----------------------------------------------------------------------------------\n";

  pi   << setw(3) << "a" << " |" 
       << setw(6) << "c" << " |" 
       << setw(8) << "m" << " |" 
       << setw(8) << "N" << " |" 
       << setw(12) << "E[N\u1d62\u2099]" << " |" 
       << setw(13) << "V[N\u1d62\u2099]" << " |" 
       << setw(11) << "N\u1d62\u2099" << " |" 
       << setw(9) << "\u03c0" << " |" 
       << setw(12) << "\u03c3"
       << "\n-----------------------------------------------------------------------------------\n";

  for (int d : n) {
    verteilung(5, 3, 16, d);
    verteilung(205, 29573, 139968, d);
  }

  pi.close();
}