# Data Structures & Algorithms in C++ — A Pattern-Based Refresher

## The one idea that makes LeetCode tractable

There are tens of thousands of problems on LeetCode, but they are built from a surprisingly small set of **patterns** — maybe 18–20 of them. A "hard" problem is almost never a brand-new idea; it's usually two or three familiar patterns stacked together, or a familiar pattern with a nasty edge case. Once you can look at a problem and think *"this smells like a sliding window"* or *"this is a graph in disguise,"* you've done 80% of the work. The rest is implementation.

So this guide is organized around patterns, not around random problems. For each one you get:

- **When to reach for it** — the recognition cues, which is the skill that actually transfers.
- **Complexity** — what good looks like.
- **A reusable C++ template** — every snippet here compiles under `-std=c++17` and passes its tests.
- **Practice problems**, ordered easy → medium → hard, by their well-known LeetCode names.

Work through it roughly top to bottom; later patterns assume the earlier ones. If you only have limited time, the patterns marked ⭐ are the highest-leverage.

---

## How to use this guide

1. Read a pattern's "when to reach for it" and template.
2. Solve the easy problem in that section **without looking** at a solution. Re-derive the template from scratch.
3. Do one medium. If you're stuck for more than ~20 minutes, read the editorial, understand it, close it, and re-solve from memory the next day.
4. Come back to the hards once the mediums feel automatic.

The goal isn't to finish a list. It's to reach the point where reading a problem statement triggers a pattern in your head within the first minute.

---

## Part 0 — The C++ toolkit you must have at your fingertips

Half of "knowing DSA in C++" is fluency with the STL — knowing which container or `<algorithm>` call removes the boilerplate. These come up constantly:

```cpp
#include <bits/stdc++.h>   // pulls in the whole STL; fine for competitive/interview
using namespace std;

// Containers
unordered_map<int,int> um;     // O(1) avg lookup — the workhorse
unordered_set<int>     us;     // O(1) avg membership
map<int,int>           om;      // ordered, O(log n), iterates sorted
set<int>               os;      // ordered set; lower_bound/upper_bound on it
vector<int>            v;        // dynamic array
deque<int>             dq;       // O(1) push/pop BOTH ends — use for BFS, sliding window
stack<int>             st;       // LIFO
queue<int>             q;        // FIFO

// priority_queue is a MAX-heap by DEFAULT (the opposite of Python's heapq!)
priority_queue<int> maxHeap;                                   // top() = largest
priority_queue<int, vector<int>, greater<int>> minHeap;        // top() = smallest

// <algorithm> essentials
sort(v.begin(), v.end());                       // O(n log n)
sort(v.begin(), v.end(), greater<int>());       // descending
auto it = lower_bound(v.begin(), v.end(), x);   // first >= x   (sorted only)
auto jt = upper_bound(v.begin(), v.end(), x);   // first  > x
int idx = it - v.begin();                        // turn iterator into index
*max_element(v.begin(), v.end());
accumulate(v.begin(), v.end(), 0LL);             // sum (note 0LL to avoid overflow)
reverse(v.begin(), v.end());

// Structured bindings (C++17) — clean tuple/pair/map unpacking
for (auto& [key, val] : um) { /* ... */ }
auto [a, b] = make_pair(1, 2);

// Sentinels & overflow
INT_MAX, INT_MIN, LLONG_MAX;      // from <climits>
// When sums can exceed ~2.1e9, use long long. Overflow is the #1 silent C++ bug here.
```

Two C++ gotchas worth burning into memory before you start:

1. **`priority_queue` is a max-heap by default** — the reverse of most other languages. For a min-heap you must spell out `priority_queue<int, vector<int>, greater<int>>`.
2. **Integer overflow is silent.** `int` tops out around 2.1×10⁹. If a problem's sum/product can exceed that, switch to `long long` *before* it bites you — there's no exception, just a wrong answer.

**Complexity cheat sheet** — the targets you're usually aiming for:

| Structure / operation | Average | Notes |
|---|---|---|
| `unordered_map` / `unordered_set` op | O(1) | The workhorse. "Trade space for time?" → usually this. |
| `map` / `set` op | O(log n) | Use when you need *sorted* order or `lower_bound`. |
| `vector[i]` index | O(1) | |
| `vector::push_back` / `pop_back` | O(1) amortized | |
| `vector::insert/erase` at front | O(n) | Use `deque` for two-ended work. |
| `sort` | O(n log n) | Introsort. |
| `lower_bound`/`upper_bound` | O(log n) | On a sorted range only. |
| heap push / pop | O(log n) | |

When you finish a solution, ask: *is this the best achievable complexity, or did I leave an obvious factor on the table?* That question alone separates accepted-but-slow from clean.

---

# Part 1 — Foundational patterns (start here)

## 1. Hashing / frequency counting ⭐

**When to reach for it:** "Have I seen this before?", counting occurrences, grouping things, "two elements that sum/relate to X", deduplication. Whenever you catch yourself writing a nested loop to find a matching pair, an `unordered_map` probably collapses it to one pass.

**Complexity:** O(n) time, O(n) space — the classic time-for-space trade.

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> seen;                 // value -> index
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (seen.count(target - nums[i]))        // O(1) lookup, the whole trick
            return {seen[target - nums[i]], i};
        seen[nums[i]] = i;
    }
    return {};
}
```

For frequency counts, `unordered_map<T,int>` with `++freq[x]` is the C++ equivalent of Python's `Counter`.

**Practice**
- Easy: Two Sum · Contains Duplicate · Valid Anagram
- Medium: Group Anagrams · Top K Frequent Elements · Subarray Sum Equals K · Longest Consecutive Sequence
- Hard: First Missing Positive (in-place hashing, O(1) space)

---

## 2. Two pointers ⭐

**When to reach for it:** the array/string is **sorted** (or can be), and you're looking for a pair/triplet, comparing from both ends, or partitioning in place. Also for "remove/move elements in place" with a read-pointer and a write-pointer.

**Complexity:** O(n) after any sort, O(1) extra space.

```cpp
vector<int> twoSumSorted(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int s = nums[lo] + nums[hi];
        if (s == target) return {lo, hi};
        else if (s < target) ++lo;     // need bigger sum -> move left up
        else --hi;                     // need smaller sum -> move right down
    }
    return {};
}
```

The "3Sum" idea is just: fix one element, two-pointer the rest. Most multi-sum and "container" problems are this.

**Practice**
- Easy: Valid Palindrome · Two Sum II (Sorted) · Move Zeroes
- Medium: 3Sum · Container With Most Water · Sort Colors (Dutch flag)
- Hard: Trapping Rain Water · 4Sum

---

## 3. Sliding window ⭐

**When to reach for it:** "longest / shortest / max / min **contiguous** subarray or substring satisfying a condition." The phrase *contiguous* + *optimize over a window* is the giveaway. It's two pointers where the window expands on the right and contracts on the left.

**Complexity:** O(n) — each element enters and leaves the window once.

Longest substring without repeats:

```cpp
int lengthOfLongestSubstring(const string& s) {
    unordered_map<char,int> last;        // char -> last index seen
    int left = 0, best = 0;
    for (int right = 0; right < (int)s.size(); ++right) {
        char ch = s[right];
        if (last.count(ch) && last[ch] >= left)
            left = last[ch] + 1;         // jump left past the duplicate
        last[ch] = right;
        best = max(best, right - left + 1);
    }
    return best;
}
```

The expand-then-shrink template (shortest subarray with sum ≥ target) — memorize this shape:

```cpp
int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, total = 0, best = INT_MAX;
    for (int right = 0; right < (int)nums.size(); ++right) {
        total += nums[right];                 // 1. expand window
        while (total >= target) {             // 2. shrink while valid
            best = min(best, right - left + 1);
            total -= nums[left++];
        }
    }
    return best == INT_MAX ? 0 : best;
}
```

**Practice**
- Easy: Maximum Average Subarray I
- Medium: Longest Substring Without Repeating Characters · Longest Repeating Character Replacement · Permutation in String · Max Consecutive Ones III
- Hard: Minimum Window Substring · Sliding Window Maximum (pairs with a monotonic `deque`)

---

## 4. Prefix sums

**When to reach for it:** repeated "sum/count of a range [i, j]" queries, or "number of subarrays that sum to k." Precompute running totals so any range answer is a single subtraction. Combine with a hash map to count subarrays.

**Complexity:** O(n) build, O(1) per range query.

```cpp
int subarraySum(vector<int>& nums, int k) {
    int count = 0, prefix = 0;
    unordered_map<int,int> seen{{0, 1}};       // empty prefix
    for (int x : nums) {
        prefix += x;
        if (seen.count(prefix - k))            // earlier prefixes giving a k-sum window
            count += seen[prefix - k];
        ++seen[prefix];
    }
    return count;
}
```

**Practice**
- Easy: Running Sum of 1d Array · Range Sum Query (Immutable)
- Medium: Subarray Sum Equals K · Product of Array Except Self · Continuous Subarray Sum
- Hard: Subarrays with K Different Integers · Maximum Sum of 3 Non-Overlapping Subarrays

---

## 5. Fast & slow pointers (Floyd's)

**When to reach for it:** linked-list cycle detection, finding the middle, or any "is there a loop in this sequence" question (including number sequences like Happy Number). Two pointers moving at different speeds.

**Complexity:** O(n) time, O(1) space.

```cpp
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;     // they meet -> cycle exists
    }
    return false;
}
```

**Practice**
- Easy: Linked List Cycle · Middle of the Linked List · Happy Number
- Medium: Linked List Cycle II (find the entry node) · Find the Duplicate Number (array as implicit linked list)
- Hard: combine with reversal in problems like Reorder List

---

## 6. Binary search ⭐

**When to reach for it:** a **sorted** array — but also, more powerfully, any problem where you can phrase "is `x` feasible?" as a monotonic yes/no, then binary-search the *answer* itself. "Minimum capacity / speed / size such that condition holds" is almost always binary-search-on-answer.

**Complexity:** O(log n), or O(n log range) for the answer-search variant.

A note for C++: prefer `lo + (hi - lo) / 2` over `(lo + hi) / 2` — the latter can overflow `int` when both are large. And remember `lower_bound` / `upper_bound` already give you a clean binary search over a sorted container.

Classic:

```cpp
int binarySearch(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
```

Binary search on the answer — the high-value template (find the smallest feasible value):

```cpp
int smallestFeasible(int lo, int hi, function<bool(int)> feasible) {
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (feasible(mid)) hi = mid;       // mid works -> answer is mid or smaller
        else lo = mid + 1;
    }
    return lo;
}
```

**Practice**
- Easy: Binary Search · First Bad Version · Search Insert Position
- Medium: Search in Rotated Sorted Array · Find Peak Element · Koko Eating Bananas · Find Minimum in Rotated Sorted Array
- Hard: Median of Two Sorted Arrays · Split Array Largest Sum · Capacity to Ship Packages Within D Days

---

## 7. Stack & monotonic stack

**When to reach for it:** matching pairs (parentheses), "undo/most-recent" logic, and especially **"next/previous greater/smaller element"** — that last family screams *monotonic stack*. If you're scanning and want, for each element, the nearest bigger one to its left or right, this is it.

**Complexity:** O(n) — each element is pushed and popped at most once.

```cpp
vector<int> nextGreater(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;                              // indices; values decreasing
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            res[st.top()] = nums[i];            // nums[i] is next-greater for popped
            st.pop();
        }
        st.push(i);
    }
    return res;
}
```

**Practice**
- Easy: Valid Parentheses · Min Stack · Baseball Game
- Medium: Daily Temperatures · Next Greater Element II · Evaluate Reverse Polish Notation · Asteroid Collision
- Hard: Largest Rectangle in Histogram · Trapping Rain Water (stack version) · Maximal Rectangle

---

## 8. Intervals

**When to reach for it:** the input is a list of `[start, end]` ranges and you need to merge, count overlaps, insert, or schedule. The reflex move is **sort by start** (sometimes by end), then sweep once. C++ sorts `vector<vector<int>>` lexicographically by default, so a plain `sort` already orders by start.

**Complexity:** O(n log n) sort, O(n) sweep.

```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());           // by start (lexicographic)
    vector<vector<int>> merged;
    for (auto& iv : intervals) {
        if (!merged.empty() && iv[0] <= merged.back()[1])   // overlaps last kept
            merged.back()[1] = max(merged.back()[1], iv[1]);
        else
            merged.push_back(iv);
    }
    return merged;
}
```

**Practice**
- Easy: Meeting Rooms
- Medium: Merge Intervals · Insert Interval · Non-overlapping Intervals · Meeting Rooms II (heap or sweep line)
- Hard: Employee Free Time · Data Stream as Disjoint Intervals

---

# Part 2 — Linked structures & trees

## 9. Linked list manipulation

**When to reach for it:** anything with `ListNode*`. The core skills are pointer reversal and the "dummy head" trick that removes edge cases when the head itself might change. Draw the pointers on paper — almost every bug here is an ordering mistake in the reassignment.

**Complexity:** O(n), O(1) space.

```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* nxt = head->next;   // save next before clobbering
        head->next = prev;            // reverse the link
        prev = head;                  // advance both
        head = nxt;
    }
    return prev;                      // new head
}

// Dummy-head pattern — use whenever the result's head might change
ListNode* removePattern(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    ListNode* cur  = head;
    while (cur) {
        // e.g. to delete cur: prev->next = cur->next; (don't advance prev)
        prev = cur;
        cur  = cur->next;
    }
    return dummy.next;
}
```

**Practice**
- Easy: Reverse Linked List · Merge Two Sorted Lists · Remove Duplicates from Sorted List
- Medium: Add Two Numbers · Remove Nth Node From End · Reorder List · LRU Cache (`list` + `unordered_map`, or hand-rolled)
- Hard: Merge k Sorted Lists (heap) · Reverse Nodes in k-Group · Copy List with Random Pointer

---

## 10. Tree traversals (DFS & BFS) ⭐

**When to reach for it:** any binary tree. **DFS (recursion)** for "compute something about subtrees / paths." **BFS (queue)** for "level by level" or shortest depth. The mental model: most tree problems are *"what do I need from my children to answer for myself?"* — that's a post-order DFS.

**Complexity:** O(n) nodes; recursion depth O(h) where h is height.

```cpp
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// DFS — depth, path sums, validation, etc.
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// BFS — level-order, the queue template
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();                 // fix the level size up front
        vector<int> level;
        for (int i = 0; i < sz; ++i) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
        res.push_back(level);
    }
    return res;
}
```

**Practice**
- Easy: Maximum Depth · Invert Binary Tree · Same Tree · Symmetric Tree
- Medium: Level Order Traversal · Right Side View · Lowest Common Ancestor · Construct Tree from Preorder/Inorder · Path Sum II
- Hard: Binary Tree Maximum Path Sum · Serialize and Deserialize Binary Tree · Recover BST

---

## 11. Binary search trees (BST)

**When to reach for it:** the tree is a BST (left < node < right). The superpower is that an **in-order traversal yields sorted order**, and you can prune half the tree at each step. Validation and "kth smallest" lean on these two facts.

For the bounds in validation, use `long` (or `LLONG_MIN`/`LLONG_MAX`) so node values equal to `INT_MIN`/`INT_MAX` don't produce a false negative.

```cpp
bool validate(TreeNode* node, long low, long high) {
    if (!node) return true;
    if (node->val <= low || node->val >= high) return false;   // must fit its range
    return validate(node->left,  low, node->val)
        && validate(node->right, node->val, high);
}
bool isValidBST(TreeNode* root) {
    return validate(root, LONG_MIN, LONG_MAX);
}
```

**Practice**
- Easy: Search in a BST · Range Sum of BST
- Medium: Validate BST · Kth Smallest Element in a BST · Lowest Common Ancestor of a BST · Delete Node in a BST
- Hard: Recover Binary Search Tree · Count of Smaller Numbers After Self (BST / BIT)

---

## 12. Tries (prefix trees)

**When to reach for it:** word dictionaries, prefix matching, autocomplete, or "find all words on a board." Whenever the problem is fundamentally about shared string prefixes, a trie beats repeated string scans.

```cpp
struct TrieNode {
    TrieNode* children[26] = {};     // or unordered_map<char,TrieNode*> for big alphabets
    bool isEnd = false;
};

struct Trie {
    TrieNode* root = new TrieNode();

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int c = ch - 'a';
            if (!node->children[c]) node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isEnd = true;
    }

    bool search(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int c = ch - 'a';
            if (!node->children[c]) return false;
            node = node->children[c];
        }
        return node->isEnd;
    }
};
```

**Practice**
- Medium: Implement Trie · Design Add and Search Words (`.` wildcard) · Replace Words
- Hard: Word Search II (trie + DFS backtracking on a grid) · Stream of Characters

---

# Part 3 — Heaps & graphs

## 13. Heaps / top-K ⭐

**When to reach for it:** "K largest / smallest / closest / most frequent," a running median, or repeatedly grabbing the current min/max (Dijkstra, merging k lists, scheduling). If you ever think "I need the best element right now, again and again," that's a heap.

**Complexity:** O(n log k) for top-K with a size-k heap — better than O(n log n) sorting when k is small.

Remember the C++ default: `priority_queue<int>` is a **max**-heap. For "k largest," keep a **min**-heap of size k and evict the smallest.

```cpp
vector<int> kLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;   // min-heap of the k largest
    for (int x : nums) {
        pq.push(x);
        if ((int)pq.size() > k) pq.pop();                // evict the smallest
    }
    vector<int> res;                                     // pq.top() is the kth largest
    while (!pq.empty()) { res.push_back(pq.top()); pq.pop(); }
    return res;
}

// For pairs, the heap orders by .first then .second:
// priority_queue<pair<int,int>> maxByFirst;
```

**Practice**
- Easy: Kth Largest Element in a Stream · Last Stone Weight
- Medium: Top K Frequent Elements · Kth Largest Element in an Array · K Closest Points to Origin · Task Scheduler · Merge k Sorted Lists
- Hard: Find Median from Data Stream (two heaps) · Sliding Window Median · IPO

---

## 14. Graphs (BFS / DFS / topological sort) ⭐

**When to reach for it:** explicit graphs, but also **grids** (each cell is a node, neighbors are up/down/left/right), dependency/prerequisite problems (topological sort), and "shortest steps in an unweighted setting" (BFS gives shortest path for free). A huge fraction of "hard" problems are graphs wearing a costume.

**Complexity:** O(V + E).

```cpp
// Grid BFS — shortest path / flood fill template
int gridBFS(vector<vector<char>>& grid, pair<int,int> start) {
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<bool>> seen(rows, vector<bool>(cols, false));
    queue<pair<int,int>> q;
    q.push(start);
    seen[start.first][start.second] = true;
    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int steps = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            auto [r, c] = q.front(); q.pop();
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols
                        && !seen[nr][nc] && grid[nr][nc] != '#') {
                    seen[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        ++steps;
    }
    return steps;
}

// Topological sort (Kahn's) — ordering with dependencies; detects cycles
vector<int> topoSort(int n, vector<pair<int,int>>& edges) {   // u -> v means u before v
    vector<int> indeg(n, 0);
    vector<vector<int>> adj(n);
    for (auto& [u, v] : edges) { adj[u].push_back(v); ++indeg[v]; }
    queue<int> q;
    for (int i = 0; i < n; ++i) if (indeg[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        order.push_back(node);
        for (int nei : adj[node])
            if (--indeg[nei] == 0) q.push(nei);
    }
    return (int)order.size() == n ? order : vector<int>{};    // empty => cycle
}
```

For **weighted shortest paths**, it's Dijkstra: a `priority_queue` (min-heap of `{dist, node}`) plus the BFS skeleton, popping the closest node each time.

**Practice**
- Easy: Flood Fill · Find the Town Judge
- Medium: Number of Islands · Clone Graph · Course Schedule (I & II) · Rotting Oranges · Pacific Atlantic Water Flow · Word Ladder
- Hard: Network Delay Time (Dijkstra) · Alien Dictionary (topo sort) · Word Ladder II · Swim in Rising Water · Cheapest Flights Within K Stops

---

## 15. Union-Find (Disjoint Set Union)

**When to reach for it:** "are these two things connected?", counting connected components, detecting cycles in an *undirected* graph, or incrementally merging groups. When the problem is about grouping/connectivity and edges arrive over time, DSU is cleaner than re-running BFS.

**Complexity:** ~O(1) per operation (inverse Ackermann) with path compression + union by rank.

```cpp
struct DSU {
    vector<int> parent, rnk;
    DSU(int n) : parent(n), rnk(n, 0) {
        iota(parent.begin(), parent.end(), 0);   // parent[i] = i
    }
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];        // path compression
            x = parent[x];
        }
        return x;
    }
    bool unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return false;               // already joined (cycle if undirected)
        if (rnk[ra] < rnk[rb]) swap(ra, rb);
        parent[rb] = ra;
        if (rnk[ra] == rnk[rb]) ++rnk[ra];
        return true;
    }
};
```

**Practice**
- Medium: Number of Provinces · Redundant Connection · Accounts Merge · Number of Connected Components
- Hard: Number of Islands II · Smallest String With Swaps · Most Stones Removed

---

# Part 4 — The hard stuff

## 16. Backtracking ⭐

**When to reach for it:** "generate **all** combinations / permutations / subsets," constraint-satisfaction (N-Queens, Sudoku), or partition problems. The signature is *build a candidate incrementally, and undo the last choice at a dead end*. The universal shape is: choose → explore → un-choose. In C++ pass the path by reference and `push_back` / `pop_back` around the recursive call.

**Complexity:** exponential by nature (you're enumerating a search tree); pruning is what makes it pass.

```cpp
void backtrack(int start, vector<int>& nums,
               vector<int>& path, vector<vector<int>>& res) {
    res.push_back(path);                       // every node is a valid subset
    for (int i = start; i < (int)nums.size(); ++i) {
        path.push_back(nums[i]);               // choose
        backtrack(i + 1, nums, path, res);     // explore
        path.pop_back();                       // un-choose  <-- the heart of it
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    backtrack(0, nums, path, res);
    return res;
}
```

The same skeleton solves permutations (track a `used[]` array), combinations (advance `start`), and grid word-search (recurse on neighbors, mark/unmark visited).

**Practice**
- Medium: Subsets (I & II) · Permutations (I & II) · Combination Sum (I & II) · Letter Combinations of a Phone Number · Palindrome Partitioning · Generate Parentheses · Word Search
- Hard: N-Queens · Sudoku Solver · Word Search II · Expression Add Operators

---

## 17. Dynamic programming ⭐ (the big one)

**When to reach for it:** "count the number of ways," "min/max cost to do X," or "is it possible to reach a target" — **and** the problem has *overlapping subproblems* (the same sub-question recurs) plus *optimal substructure* (the answer is built from answers to smaller versions). The honest test: if your recursive brute force re-computes the same arguments, memoize it — that *is* DP.

The two ways to write any DP:

1. **Top-down (memoized recursion):** write the natural recursion, then cache results in a `vector`/`unordered_map` keyed by the state. Easiest to derive. (C++ has no `@cache`; you maintain the memo table by hand.)
2. **Bottom-up (tabulation):** fill a table from base cases up. Often faster and lets you shrink space.

Start top-down to find the recurrence, then convert to bottom-up if you need the speed/space.

### 17a. 1-D DP — decisions along a line

```cpp
int rob(vector<int>& nums) {                 // House Robber: can't take adjacent
    int prev = 0, cur = 0;                   // only last two states matter -> O(1) space
    for (int x : nums) {
        int take = max(cur, prev + x);       // skip x, or take x + best-before-prev
        prev = cur;
        cur = take;
    }
    return cur;
}
```
*Family:* Climbing Stairs, House Robber I/II, Min Cost Climbing Stairs, Decode Ways, Word Break.

### 17b. Grid DP — paths and costs on a 2-D board

```cpp
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) dp[i][j] = grid[i][j];
            else if (i == 0)      dp[i][j] = dp[i][j-1] + grid[i][j];   // only from left
            else if (j == 0)      dp[i][j] = dp[i-1][j] + grid[i][j];   // only from above
            else                  dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    return dp[m-1][n-1];
}
```
*Family:* Unique Paths I/II, Minimum Path Sum, Maximal Square, Dungeon Game.

### 17c. Knapsack — pick items under a budget

```cpp
int knapsack(vector<int>& w, vector<int>& v, int cap) {   // 0/1: each item once
    vector<int> dp(cap + 1, 0);
    for (int i = 0; i < (int)w.size(); ++i)
        for (int c = cap; c >= w[i]; --c)                 // iterate capacity DOWN for 0/1
            dp[c] = max(dp[c], dp[c - w[i]] + v[i]);
    return dp[cap];
}
// For "unbounded" (reuse items), iterate capacity UPWARD instead.
```
*Family:* Partition Equal Subset Sum, Target Sum, Coin Change I/II, Combination Sum IV.

### 17d. Subsequence DP — LIS and friends

```cpp
int lengthOfLIS(vector<int>& nums) {          // Longest Increasing Subsequence, O(n log n)
    vector<int> tails;                        // tails[i] = smallest tail of an inc. seq of length i+1
    for (int x : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);   // x extends the longest run
        else *it = x;                                // x improves a length-(i+1) run
    }
    return tails.size();
}
```
*Family:* LIS, Russian Doll Envelopes, Maximum Length of Pair Chain.

### 17e. String / two-sequence DP — a 2-D grid over two strings

```cpp
int editDistance(const string& a, const string& b) {     // insert/delete/replace
    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; ++i) dp[i][0] = i;            // delete all of a
    for (int j = 0; j <= n; ++j) dp[0][j] = j;            // insert all of b
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = (a[i-1] == b[j-1])
                ? dp[i-1][j-1]                            // match, free
                : 1 + min({dp[i-1][j],     // delete
                           dp[i][j-1],     // insert
                           dp[i-1][j-1]}); // replace
    return dp[m][n];
}
```
*Family:* Longest Common Subsequence, Edit Distance, Distinct Subsequences, Regular Expression / Wildcard Matching, Interleaving String.

**Practice (by difficulty across all DP families)**
- Easy: Climbing Stairs · Min Cost Climbing Stairs · Fibonacci
- Medium: House Robber I/II · Coin Change · Longest Increasing Subsequence · Word Break · Unique Paths · Longest Palindromic Substring · Maximal Square · Partition Equal Subset Sum · Longest Common Subsequence · Decode Ways
- Hard: Edit Distance · Regular Expression Matching · Burst Balloons (interval DP) · Best Time to Buy/Sell Stock IV · Longest Valid Parentheses · Distinct Subsequences

DP is the pattern that most rewards *volume*. The recurrences start to rhyme after about 20 problems.

---

## 18. Greedy

**When to reach for it:** "maximize/minimize" where a locally optimal choice provably leads to a global optimum — often after sorting. The danger is that greedy *looks* applicable far more often than it *is*; the discipline is to convince yourself (or find a counterexample) that the local choice never needs to be undone. When greedy fails, the fallback is usually DP.

```cpp
bool canJump(vector<int>& nums) {            // can you reach the last index?
    int farthest = 0;
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (i > farthest) return false;      // stuck — can't even reach here
        farthest = max(farthest, i + nums[i]);
    }
    return true;
}
```

**Practice**
- Easy: Best Time to Buy and Sell Stock · Assign Cookies
- Medium: Jump Game I/II · Gas Station · Partition Labels · Task Scheduler · Non-overlapping Intervals
- Hard: Candy · Minimum Number of Refueling Stops · Create Maximum Number

---

## 19. Bit manipulation

**When to reach for it:** problems about parity, "find the unique/missing number," subsets-as-bitmasks, or when O(1) space matters. C++ gives you cheap helpers: `__builtin_popcount(x)` counts set bits, `__builtin_clz(x)` counts leading zeros. Useful tricks: XOR cancels pairs (`a ^ a == 0`), `x & (x-1)` drops the lowest set bit, `x & -x` isolates it.

```cpp
int singleNumber(vector<int>& nums) {        // every element appears twice except one
    int result = 0;
    for (int x : nums) result ^= x;          // pairs cancel; the loner survives
    return result;
}

int countBits(int x) {
    int count = 0;
    while (x) { x &= x - 1; ++count; }        // clears lowest set bit each loop
    return count;
    // or just: return __builtin_popcount(x);
}
```

**Practice**
- Easy: Single Number · Number of 1 Bits · Missing Number · Reverse Bits
- Medium: Single Number II/III · Sum of Two Integers (no `+`) · Subsets (via bitmask) · Counting Bits
- Hard: Maximum XOR of Two Numbers (bitwise trie) · bitmask DP (e.g. Shortest Path Visiting All Nodes)

---

# A suggested order of attack

If you want a concrete path rather than picking around, this ordering builds cleanly:

1. **Week 1 — fundamentals:** Hashing, Two Pointers, Sliding Window, Prefix Sums, Binary Search. These show up *inside* later problems, so make them automatic.
2. **Week 2 — linear structures:** Stack/Monotonic Stack, Linked Lists, Intervals, Heaps.
3. **Week 3 — trees & graphs:** Tree DFS/BFS, BST, Tries, then Graphs (BFS/DFS/topo sort) and Union-Find. This is where most "hard" problems live.
4. **Week 4 — the heavy hitters:** Backtracking, then Dynamic Programming (give DP the most time — it's the single largest source of mediums *and* hards), with Greedy and Bit Manipulation rounding it out.

Do ~3 problems per pattern before moving on: one easy to lock the template, two mediums to stress it. Circle back to hards once the whole map feels familiar.

---

# How to actually attack an unfamiliar problem

A repeatable 5-minute process before you write any code:

1. **Restate it** in your own words and nail down the exact input/output and constraints. The constraints leak the intended complexity: `n ≤ 20` whispers *backtracking/bitmask*; `n ≤ 10^5` rules out O(n²) and points at O(n log n); `n ≤ 10^9` means *math or binary search on the answer*, not iteration. Constraints near 10⁹ are also your cue to reach for `long long`.
2. **Pattern-match.** Run down the cues: contiguous + optimize → sliding window; sorted or "find a pair" → two pointers/binary search; "all combinations" → backtracking; "number of ways / min cost" → DP; connectivity → graph/DSU; "kth / top / running min" → heap.
3. **Brute force first**, out loud. State its complexity. This is your fallback and often the seed of the optimal (memoize it, or replace the inner scan with a hash map / monotonic stack).
4. **Optimize the bottleneck**, not the whole thing — which single operation is too slow, and which container makes it O(1) or O(log n)?
5. **Edge cases before submitting:** empty input, one element, all-equal, negatives, duplicates, **overflow** (the C++-specific one — does any sum/product exceed `int`?), the head/root being the thing that changes.

When you get one wrong, don't just read the fix — note *which cue you missed* in step 2. Over time that error log is worth more than the solutions themselves; it's literally retraining your pattern recognition.

Good luck — every template here compiles under `-std=c++17` and passes its tests, so a solid drill is to close this file and reproduce each one from scratch. If you can regenerate the template, you understand the pattern.
