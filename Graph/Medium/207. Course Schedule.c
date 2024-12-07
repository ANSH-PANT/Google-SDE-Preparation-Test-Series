/*
Time Complexity: O(numCourses + prerequisitesSize)
Space Complexity: O(numCourses * PREREQ_MAX)
*/

#define PREREQ_MAX (13)
bool loops(int idx, int cmap[][PREREQ_MAX], int cpr[], int* visited) {
    if (visited[idx] > 0)
        return true;
    if (visited[idx] == 0) {
        visited[idx] = 1;
        for (int i = 0; i < cpr[idx]; i++) {
            if (loops(cmap[idx][i], cmap, cpr, visited)) {
                return true;
            }
        }
        visited[idx] = -1;
    }
    return false;
}
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize,
               int* prerequisitesColSize) {
    int cmap[2001][PREREQ_MAX];
    int cpr[2001] = {0};
    int visited[2001] = {0};
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];
        cmap[course][cpr[course]++] = prereq;
    }
    for (int i = 0; i < numCourses; i++) {
        if (loops(i, cmap, cpr, &visited)) {
            return false;
        }
    }
    return true;
}
