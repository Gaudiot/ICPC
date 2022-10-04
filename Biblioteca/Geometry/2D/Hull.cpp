vector<PT> half_hull(vector<PT> &points, int l, int r, int d) {
    vector<PT> hull;
    for (int i = l; i != r; i += d) {
        int size = hull.size();
        while (size > 1 && !right_turn(hull[size - 1] - hull[size - 2], points[i] - hull[size - 2]))
            hull.pop_back(), size--;

        hull.push_back(points[i]);
    }

    return hull;
}

vector<PT> convex_hull(vector<PT> &points) {
    int n = points.size();
    sort(points.begin(), points.end());

    vector<PT> hull = half_hull(points, 0, n, 1);
    vector<PT> lower = half_hull(points, n - 1, -1, -1);

    for (int i = 1; i < (int) lower.size() - 1; i++)
        hull.push_back(lower[i]);

    return hull;
}