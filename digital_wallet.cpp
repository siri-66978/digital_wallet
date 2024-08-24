#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
struct User {
    int userID;
    int balance;
};
bool compareByBalance(const User& a, const User& b) {
    if (a.balance == b.balance) {
        return a.userID < b.userID;
    }
    return a.balance < b.balance;
}
int main() {
    int n;
    cin >> n;
    map<int, int> userBalances;
    for (int i = 0; i < n; ++i) {
        int userID, balance;
        cin >> userID >> balance;
        userBalances[userID] = balance;
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int from_userID, to_userID, amount;
        cin >> from_userID >> to_userID >> amount;
        if (userBalances[from_userID] >= amount) {
            userBalances[from_userID] -= amount;
            userBalances[to_userID] += amount;
            cout << "Success" << endl;
        } else {
            cout << "Failure" << endl;
        }
    }
        cout<<"\n";
    vector<User> users;
    for (const auto& entry : userBalances) {
        users.push_back(User{entry.first, entry.second});
    }
    sort(users.begin(), users.end(), compareByBalance);
    for (const auto& user : users) {
        cout<<user.userID << " " << user.balance<< endl;
    }
    return 0;
}
