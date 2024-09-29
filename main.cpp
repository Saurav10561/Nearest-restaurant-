#include <iostream>
#include <vector>
#include "TreeNode.h"

int main() {
    std::vector<Point> restaurants = {
        {2.1, 3.0}, {4.2, 1.5}, {3.3, 3.7}, {5.0, 5.1}, {1.2, 1.8}
    };

    TreeNode kdTree;
    for (const auto& restaurant : restaurants) {
        kdTree.insert(restaurant);
    }

    Point lower_bound = {2.0, 2.0};
    Point upper_bound = {4.5, 4.5};

    std::cout << "Restaurants within the range: " << std::endl;
    auto results = kdTree.rangeQuery(lower_bound, upper_bound);
    for (const auto& res : results) {
        std::cout << "(" << res.x << ", " << res.y << ")" << std::endl;
    }

    return 0;
}
