#include "TreeNode.h"

TreeNode::TreeNode() : root(nullptr) {}

TreeNode::Node* TreeNode::insert(Node* node, Point point, unsigned depth) {
    if (node == nullptr) return new Node(point);

    unsigned current_dim = depth % 2; // alternating between x and y dimensions

    if ((current_dim == 0 && point.x < node->point.x) || (current_dim == 1 && point.y < node->point.y))
        node->left = insert(node->left, point, depth + 1);
    else
        node->right = insert(node->right, point, depth + 1);

    return node;
}

void TreeNode::insert(Point point) {
    root = insert(root, point, 0);
}

void TreeNode::rangeSearch(Node* node, Point lower_bound, Point upper_bound, unsigned depth, std::vector<Point>& result) {
    if (node == nullptr) return;

    // Check if the point lies within the bounding box
    if (node->point.x >= lower_bound.x && node->point.x <= upper_bound.x &&
        node->point.y >= lower_bound.y && node->point.y <= upper_bound.y) {
        result.push_back(node->point);
    }

    unsigned current_dim = depth % 2;

    if ((current_dim == 0 && lower_bound.x < node->point.x) || (current_dim == 1 && lower_bound.y < node->point.y))
        rangeSearch(node->left, lower_bound, upper_bound, depth + 1, result);

    if ((current_dim == 0 && upper_bound.x >= node->point.x) || (current_dim == 1 && upper_bound.y >= node->point.y))
        rangeSearch(node->right, lower_bound, upper_bound, depth + 1, result);
}

std::vector<Point> TreeNode::rangeQuery(Point lower_bound, Point upper_bound) {
    std::vector<Point> result;
    rangeSearch(root, lower_bound, upper_bound, 0, result);
    return result;
}
