#include<iostream>
#include<algorithm>

using namespace std;

int get_median(int arr[], int n);
int kth_smallest(int arr[], int left, int right, int k);
void quicksort(int arr[], int left, int right);
int split(int[], int, int, int);

int main(int argc, char* argv[]) {
  int n;
  std::cout << "Enter number of random elements to generate: ";
  cin >> n;
  std::cout << "Generating " << n << " random elements...\n";

  int arr[n];
  for (int i = 0; i < n; i++) arr[i] = (rand() + 1000) % 1000;
  for (int i = 0; i < n; i++) cout<<arr[i] << " ";
  cout<<endl;

  quicksort(arr, 0, n - 1);

  cout<<"After sorting: ";
  for (int i = 0; i < n; i++) cout<<arr[i] << " ";
  return 0;
}

int split(int arr[], int low, int high, int pivot) {
  auto i = low - 1;
  for (auto j = low; j <= high; j++) {
    if(arr[j] <= pivot) {
      i++;
      std::swap(arr[i], arr[j]);
    }
  }
  for (auto j = low; j <= high; j++) {
    if (arr[j] == pivot) {
      std::swap(arr[i], arr[j]);
      break;
    }
  }
  return i;
}

int kth_smallest(int arr[], int left, int right, int k) {
  int n = right - left + 1;
  if (n <= 5) {
    sort(arr + left, arr + right + 1);
    return left + k - 1;  // Return index of kth smallest element
  }
  int length = (n + 4) / 5;
  int medians[length];

  for (auto i = 0; i < length; i++) {
    auto left_index = left + i * 5;
    auto right_index = min(left + (i + 1) * 5 - 1, right);
    medians[i] = get_median(arr + left_index, right_index - left_index + 1);
  }
  int final_median = (length == 1) ? medians[0] : medians[kth_smallest(medians, 0, length - 1, (length) / 2)];

  int pivot = split(arr, left, right, final_median);

  int kth_index = left + k - 1;
  if (pivot == kth_index) return pivot;
  else if(pivot < kth_index) return kth_smallest(arr, pivot + 1, right, kth_index - pivot);
  return kth_smallest(arr, left, pivot - 1, k);
}

void quicksort(int arr[], int left, int right) {
  if (right <= left) return;
  int pos = kth_smallest(arr, left, right, (right - left + 1) / 2);
  quicksort(arr, left, pos - 1);
  quicksort(arr, pos + 1, right);
}

int get_median(int arr[], int n) {
  sort(arr, arr + n);
  return arr[n / 2];
}
