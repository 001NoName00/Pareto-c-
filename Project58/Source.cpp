#include <iostream>
#include <vector>

struct Point {
    int x;
    int y;
};

std::vector<Point> paretoSet(const std::vector<Point>& points) {
    std::vector<Point> paretoSetPoints;

    for (const auto& p : points) {
        bool isPareto = true;
        for (const auto& q : points) {
            if (p.x < q.x && p.y < q.y) {
                isPareto = false;
                break;
            }
        }
        if (isPareto) {
            paretoSetPoints.push_back(p);
        }
    }

    return paretoSetPoints;
}

int main() {
    std::vector<Point> pointsM = { {3, 6}, {2, 8}, {5, 4}, {7, 3}, {4, 5} };
    std::vector<Point> pointsN = { {1, 7}, {6, 2}, {3, 5}, {8, 4}, {5, 6} };

    std::vector<Point> paretoSetPointsM = paretoSet(pointsM);
    std::vector<Point> paretoSetPointsN = paretoSet(pointsN);

    std::cout << "Pareto Set Points for M:\n";
    for (const auto& point : paretoSetPointsM) {
        std::cout << "(" << point.x << ", " << point.y << ")\n";
    }

    std::cout << "\nPareto Set Points for N:\n";
    for (const auto& point : paretoSetPointsN) {
        std::cout << "(" << point.x << ", " << point.y << ")\n";
    }

    return 0;
}
