sort()

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {40, 10, 30, 20};

    sort(v.begin(), v.end());  // ascending

    for (int x : v) cout << x << " ";
}
///////////////////////////////////////////////////////
find()

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40};

    auto it = find(v.begin(), v.end(), 30);

    if (it != v.end())
        cout << "Found";
    else
        cout << "Not Found";
}

///////////////////////////////////////////////////////
reverse()
  
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4};

    reverse(v.begin(), v.end());  // 4 3 2 1

    for (int x : v) cout << x << " ";
}

///////////////////////////////////////////////////////
remove() (VERY IMPORTANT ⚠️)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 20, 40};

    auto it = remove(v.begin(), v.end(), 20);

    v.erase(it, v.end());  // actual deletion

    for (int x : v) cout << x << " ";
}

Output: 10 30 40

///////////////////////////////////////////////////////
vector (Dynamic Array)
  
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};

    v.push_back(40);

    for (int x : v)
        cout << x << " "; //10 20 30 40
}

//////////////////////////////////////////////////
map (Sorted Key-Value)

#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m;

    m[101] = "Error";
    m[102] = "Warning";

    for (auto p : m)
        cout << p.first << " " << p.second << endl; //101 error & 102 warning
}

//////////////////////////////////////////////////
unordered_map (Hash Table)

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> um;

    um[1] = "Active";
    um[2] = "Inactive";

    cout << um[1]; //active
}

//////////////////////////////////////////////////
set (Unique Sorted)

#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    s.insert(30);
    s.insert(10);
    s.insert(30); // ignored  10,30

    for (int x : s)
        cout << x << " ";
}

//////////////////////////////////////////////////
queue (FIFO)

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);

    cout << q.front() << endl; //20

    q.pop();
}

//////////////////////////////////////////////////
priority_queue (Heap)

#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(10);
    pq.push(50);
    pq.push(20);

    cout << pq.top(); // highest 50
}


////////////////////////////////////////////////////////
que : Difference between map and unordered_map?

MAP:
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m;

    m[3] = "C";
    m[1] = "A";
    m[2] = "B";

    for (auto x : m)
        cout << x.first << " ";    // 1 2 3
}

unordered_map:

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> um;

    um[3] = "C";
    um[1] = "A";
    um[2] = "B";

    for (auto x : um)
        cout << x.first << " "; // 3 1 2
}
