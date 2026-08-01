// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

bool isValidN(int n) {
 if (n <= 0) {
  return false;
 } else {
    return true;
 }
}

void readNumbers(double numbers [], int n) {
  for ( int i =0; i < n ; i++)
  {
   cout << "Enter number" << i + 1 << ": ";
   cin >> numbers[i] ;
  }
}

double computeSum(double numbers[], int n) {
  double total = 0;
  for (int i=0 ; i < n ; i++) {
     total += numbers[i];
  }
    return total;
}

double computeAverage(double sum, int n) {
  return sum/n;
}

double computeMax( double numbers[], int n){
  double max = numbers[0];
  for (int i=1 ; i < n; ++i){
    if (numbers[i] > max){
      max =numbers[i];
    }
  }
  return max;
}

double computeMin( double numbers[], int n){
  double min = numbers[0];
  for (int i=1 ; i < n; ++i){
    if (numbers[i] < min){
      min =numbers[i];
    }
  }
  return min;
}

int main(){
  int n;
  cout << "How many numbers?: " <<endl;
  cin >> n ;

  if (!isValidN(n)){
      cout << "Error message here" << endl;
      return 1;
  }
  double numbers[100];
  readNumbers(numbers,n);
  double sum =  computeSum(numbers,n);
  double average = computeAverage(sum,n);
  double maximum = computeMax(numbers,n);
  double minimum = computeMin(numbers,n);

  cout << "Sum: " << sum << endl;
  cout << "Average: " << average << endl;
  cout << "Max: " << maximum << endl;
  cout << "Min: " << minimum << endl;

 return 0;
}



