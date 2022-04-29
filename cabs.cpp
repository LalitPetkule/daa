/*
N-Cabs Problem
----
  Given starting and finishing of n passengers,
  find the minimum number of taxis required to pick up all the passengers.

  Sample Input:
        A B C D E
    ST  1 2 3 4 5
    FT  3 3 7 5 7

  Output:
    2

  Pseudocode:
    1. Sort the passenger list by finishing time.
    2. Initialize a taxi counter to 0, and minimum taxi finishing time to 0
    3. Iterate through the list of passengers
      - If passengers start time is less than the minimum taxi finishing time,
        increment the taxi counter
      - Else if current passenger's finishing time is greater than or equal to the minimum taxi finishing time,
        just change the timings for the minimum taxi
    4. Return the taxi counter

  Algorithm:
    sort(passengers) according to finish times
    taxi_count = 1, min_ft = 0

    for (int i through 1 to n -1) {
      if (passengers[i].start_time >= passengers[min_ft].ft ){
        min_ft++;
      } else {
        taxi_count++
      }
    }
    return taxi_count;
*/

#include<iostream>
#include<algorithm>

using namespace std;

struct passenger {
  int start_time;
  int finish_time;
};

bool compare_by_ft(const passenger&, const passenger&);
int minimum_cabs(passenger[], int);

int main(int argc, char* argv[]) {
  int n;
  cout << "Enter number of passengers: ";
  cin >> n;
  passenger passengers[n];
  for (int i = 0; i < n; i++) {
    cout << "Enter start time and finish time for passenger " << i + 1 << ": ";
    cin >> passengers[i].start_time >> passengers[i].finish_time;
  }
  int min_cabs = minimum_cabs(passengers, n);

  cout << "Minimum Cabs required: " << min_cabs << endl;
}

// Sort the passengers according to finish time
bool compare_by_finishtime(const passenger& a, const passenger& b) {
  if (a.finish_time == b.finish_time) return a.start_time < b.start_time;
  return a.finish_time < b.finish_time;
}

int minimum_cabs(passenger passengers[], int num_passengers) {
  sort(passengers, passengers + num_passengers, compare_by_finishtime);
  int min_finishtime_cab = 0; int taxi_count = 1; // Assuming 1st cab is already occupied by the first passenger
  for (int i = 1; i < num_passengers; i++) {
    if (passengers[i].start_time >= passengers[min_finishtime_cab].finish_time) min_finishtime_cab++;
    else taxi_count++;
  }
  return taxi_count;
}
