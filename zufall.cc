#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

static int I=2;

double zufall(int a,int c,int m){

  I=(a*I+c)%m;
  return (double)I/(double)m;
  
}

void verteilung(int a,int c,int m,int n){
  
  int Kreis=0;
  double p=M_PI/4;
  double v= p*(1-p)*n;
  
  for (int u=0; u<n ; ++u){
  if ( pow(zufall(a,c,m),2) + pow(zufall(a,c,m),2) <1) {Kreis++;}
  }
  
  cout << p*n << " " << v << " " << Kreis << " " << (double)Kreis/(double)n*4 << " " << 4*sqrt(v)/n << endl;
  
  return;

}

int main(){

vector<int> n{100,10000,100000,1000000};

for (int d : n){
  verteilung( 5, 3, 16,d);
  verteilung( 205, 29573, 1339968,d);
}

}
