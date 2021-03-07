/* ------------------------------------------------------------------|
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*  dfs
*
*	执行用时：136 ms, 在所有 C++ 提交中击败了81.70%的用户
*	内存消耗：74 MB, 在所有 C++ 提交中击败了60.07%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

int n;
vector<vector<bool>> f;
vector<vector<string>> res;
vector<string> tmp;

void dfs(int index,string &s) {
    if (index == n) {
        res.emplace_back(tmp);
        return;
    }

    for (int j = index; j < n; j++) {
        if (f[index][j]) {
            tmp.emplace_back(s.substr(index, j + 1 - index));
            dfs(j + 1, s);
            tmp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    n = s.size();
    f.resize(n, vector<bool>(n, true));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
        }
    }
    dfs(0, s);
    return res;
}