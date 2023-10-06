#include <iostream>
#include <vector>
#include <algorithm>

struct Shop {
    int start;
    int end;
};

bool sortByClosingTime(const Shop& a, const Shop& b) {
    return a.end < b.end;
}

int maxShopsToVisit(std::vector<Shop>& shops, int k) {
    int n = shops.size();
    
    // Sort the shops by closing times
    std::sort(shops.begin(), shops.end(), sortByClosingTime);

    int visited = 1; // First shop is always visited
    int prevShop = 0; // Index of the last visited shop
    
    for (int i = 1; i < n; i++) {
        if (shops[i].start > shops[prevShop].end) {
            visited++;
            prevShop = i;
        }
        if (visited == k) {
            break; // All persons have visited a shop
        }
    }

    return visited;
}

int main() {
    int N = 5; // Number of shops
    int K = 3; // Number of people

    std::vector<Shop> shops = {{1, 3}, {2, 5}, {3, 7}, {5, 8}, {6, 9}};
    
    int maxShops = maxShopsToVisit(shops, K);
    std::cout << "Maximum number of shops that can be visited: " << maxShops << std::endl;

    return 0;
}