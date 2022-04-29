#include<iostream>
#include<cstdlib>
using namespace std;

int* get_change(int, int);

int main() {
  int num_coins, amount;
  cout << "Enter number of coins and amount: ";
  cin >> num_coins >> amount;
  auto coins = get_change(num_coins, amount);
  int count = 0;
  cout << "Coin\tCount\n";
  for (int i = 1; i <= num_coins; i++) {
    if (coins[i] != 0) {
      cout << i << "\t" << coins[i] << endl;
      count += coins[i];
    }
  }
  cout << "Minimum number of coins: " << count << endl;
  return 0;
}

int* get_change(int num_coins, int amount) {
  int** table = new int*[num_coins + 1];
  for (int i = 0; i <= num_coins; i++) table[i] = new int[amount + 1];

  for (int i = 0; i <= amount; i++) {
    if (i <= num_coins) table[i][0] = 0;
    table[0][i] = 0;
    table[1][i] = i;
  }

  for (int i = 2; i <= num_coins; i++) {
    for (int j = 1; j <= amount; j++) {
      if (i > j) table[i][j] = table[i - 1][j];
      else table[i][j] = min(table[i - 1][j], (j / i) + table[i][j % i]);
    }
  }

  int* coins = new int[num_coins + 1];
  while (amount > 0) {
    int i = num_coins;
    while (i > 0 && table[i][amount] == table[i - 1][amount]) i--;
    coins[i]++;
    amount -= i;
  }
  return coins;
}

