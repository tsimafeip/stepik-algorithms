#include <iostream>
#include <algorithm>
#include <vector>

typedef std::pair <int, int> Segment;

std::vector <int> get_covering_set(std::vector <Segment> segments) {
    std::vector <int> result;

    // sorting segments by the right end
    std::sort(segments.begin(), segments.end(),
            [](auto &left, auto &right) {return left.second < right.second;});

    for (auto & segment : segments) {
        // this condition checks if we have already added the dot that 'covers' current segment.
        if (!result.empty() && result.back() >= segment.first)
            continue;

        result.push_back(segment.second);
    }

    return result;
}

int main() {
    int segments_count;
    std::cin >> segments_count;
    std::vector <Segment> segments(segments_count);
    for (int i = 0; i < segments_count; i++) {
        std::cin >> segments[i].first >> segments[i].second;
    }

    std::vector <int> points = get_covering_set(segments);
    std::cout << points.size() << std::endl;
    for (int point : points) {
        std::cout << point << " ";
    }
}