#ifndef TREENODE_H
#define TREENODE_H

#include <vector>

struct Point {
    double x, y;
    Point(double x_val = 0, double y_val = 0) : x(x_val), y(y_val) {}
};

class TreeNode {
private:
    struct Node {
        Point point;
        Node* left;
        Node* right;
        Node(Point p) : point(p), left(nullptr), right(nullptr) {}
    };

    Node* root;
    Node* insert(Node* node, Point point, unsigned depth);
    void rangeSearch(Node* node, Point lower_bound, Point upper_bound, unsigned depth, std::vector<Point>& result);

public:
    TreeNode();
    void insert(Point point);
    std::vector<Point> rangeQuery(Point lower_bound, Point upper_bound);
};

#endif // TREENODE_H
