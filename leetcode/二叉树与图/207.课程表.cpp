/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 * 思路1：深度优先搜索，看有没有环
 *
 * 思路2：
 * 宽度优先搜索，将入度为0的点添加至队列。当完成一个顶点的搜索（从队列取出），
 * 它指向的所有顶点入度都减1， 若此时某顶点入度为0则添加至队列，若完成宽度搜索后，
 * 所有的点入度都为0，则图无环，否则有环
 */
struct GraphNode {
    int label;
    vector<GraphNode*> neighbors;
    GraphNode(int x) : label(x) {};
};


// 思路1
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<GraphNode*> graph;
        vector<int> visit;
        for (int i = 0; i < numCourses; i++) {
            graph.push_back(new GraphNode(i));
            visit.push_back(-1);
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            GraphNode* begin = graph[prerequisites[i][1]];
            GraphNode* end = graph[prerequisites[i][0]];
            begin->neighbors.push_back(end);
        }
        for (int i = 0; i < graph.size(); i++) {
            if (visit[i] == -1 && !DFS_graph(graph[i], visit)) {
                return false;
            }
        }
        for (int i = 0; i < numCourses; i++) {
            delete graph[i];
        }
        return true;
    }
private:
    bool DFS_graph(GraphNode* node, vector<int>& visit) {
        visit[node->label] = 0;
        for (int i = 0; i < node->neighbors.size(); i++) {
            if (visit[node->neighbors[i]->label] == -1) {
                if (DFS_graph(node->neighbors[i], visit) == 0) {
                    return false;
                }
            } else if (visit[node->neighbors[i]->label] == 0) {  // 有环
                return false;
            }
        }
        visit[node->label] = 1;
        return true;
    }
};


// 思路2：
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<GraphNode*> graph;
        vector<int> degree;
        
        for (int i = 0; i < numCourses; i++) {
            degree.push_back(0);
            graph.push_back(new GraphNode(i));
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            GraphNode* begin = graph[prerequisites[i][1]];
            GraphNode* end = graph[prerequisites[i][0]];
            begin->neighbors.push_back(end);
            degree[prerequisites[i][0]]++;
        }
        queue<GraphNode*> Q;
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) {
                Q.push(graph[i]);
            }
        }
        while (!Q.empty()) {
            GraphNode* node = Q.front();
            Q.pop();
            for (int i = 0; i < node->neighbors.size(); i++) {
                degree[node->neighbors[i]->label]--;
                if (degree[node->neighbors[i]->label] == 0) {
                    Q.push(node->neighbors[i]);
                }
            }
        }
        for (int i = 0; i < graph.size(); i++) {
            delete graph[i];
        }
        for (int i = 0; i < degree.size(); i++) {
            if (degree[i]) {
                return false;
            }
        }
        return true;
    } 
};
