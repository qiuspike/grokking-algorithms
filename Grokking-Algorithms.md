### Chapter 1 Introduction to Algorithms

算法是一系列为了完成一个特定任务的指令。

#### Binary search

binary search: 二分搜索是一个输入是已排序元素的快捷搜索算法，时间复杂度为O(logN)。

使用二分搜索是，每次guess中间那个元素，同时eliminate一半元素。

其实现如下：

```c
int binary_search(int* arr, int len, int item) {
    int low = 0, high = len - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < item)
            low = mid + 1;
        else if (arr[mid] > item)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

```

#### Big O notation

Big O 比较**操作(operations)**的数量，它告诉算法operations随输入的数据量大增加的函数关系。而不是以秒计算的时间。即，Algorithm的速度不是以秒来衡量的，而是用operations的增长数量来衡量的。

Big O 确立的是最差情况的操作数量，也就是算法的worst-case。比如:

> 在长度为N的数组arr中用简单搜索search item，最好的情况可能第一个数就是要找的数，但在最坏的情况下需要遍历整个数组，直到最后一个数才能找到item，因而其**时间复杂度(algorithm times)**是O(N)。



### Chapter 2 Selection Sort

#### Arrays and linked lists

数组和链表是两种基本的数据结构，以它们为基础，可以复合和扩展出许多复杂的数据结构。

数组是内存中一块连续的内存，可以随机访问；而链表在内存中地址不连续，在每一个节点中存有下一个节点的地址，只能顺序访问。以下是数组和链表的读取、插入、删除操作的时间复杂度：

![Screen Shot 2018-07-26 at 4.56.00 PM](https://raw.githubusercontent.com/qiuyi116/assets/master/Screen%20Shot%202018-07-26%20at%204.56.00%20PM.png)

 综上，数组适合几乎没有插入和删除和需要随机访问的场景；链表适合要频繁进行插入删除，不要随机访问的场景。

#### Selection sort

选择排序，第一次选择数组中最大一个元素，放到数组第一个位置，第二次选次大，放到第二个位置，以此类推。代码如下：

```c
void selection_sort(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[j] > arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

```



### Chapter 3 Recursion

#### Recursion

用递归（Recursion）解决问题，我们要找到其

*  **Base Case**：递归停止，直接返回
*  **Recursive Case**：调用自身解决问题

然后就可以写出递归函数。

如：

```python
def countdown(i):
    print i
    if i <= 0:	# <------- Base case
        return
    else:		# <------- Recursive case
        countdown(i-1)

```

#### The stack

**call stack**，也就是程序调用栈。每一个程序都有其独有的栈，用来跟踪程序的调用和执行。函数的局部变量(也可以在寄存器)、函数调用的返回地址等信息都在栈上存储。

当你在一个函数调用另一个函数时，调用方函数暂停在一个**部分完成的(partially completed)**状态；当被调用函数执行完返回时，调用方函数从暂停的地方继续往后执行。



### Chapter 4 Quicksort

#### Divide & conquer

**Divide & Conquer(D&C)**，即**分治策略**是一种重要的解决问题的思想，即将问题分解成小块儿，然后分别处理，通常和递归结合使用。

对数组使用D&C并递归解决问题时，其base case往往是空数组或者只有一个元素的数组。

如，用递归对一个数组求和：

```c
int recursive_sum(int* arr, int len) {
    if (len == 0) return 0;
    //if (len == 1) return arr[0];
    return arr[0] + recursive_sum(&arr[1], len - 1);
}

```

#### Quicksort

**快排（quick sort）**正是用到了分治策略，并使用递归实现。空数组和只有一个元素的数组是其**base case**，即：

```python
def quicksort(arr):
    if len(arr) < 2:
        return arr

```

快排的步骤如下：

1.  选取一个pivot。
2.  划分(partition)数组；将数组划分为两个子数组，分别由比pivot小的元素和不小于pivot的元素构成。
3.  对子数组递归调用quicksort。

影响快排的关键因素是pivot的选取。最差的情况可能会是O(n^2)。但只要**随机选取pivot**，其平均时间是O(nlogn)。

**划分(partition)**是快排关键的一步，它将一个数组划分为两个子数组和pivot自身。通常，在实现中会在原址上进行划分，划分完后pivot将处于两个子数组中间，并返回其位置。

C的快排实现如下：

```c

int partition(int* arr, int low, int high) {
    int pivot = arr[low]; //TODO
    int i = low, j = high;
    while (i < j) {
        while (arr[j] >= pivot && i < j)
            j--;
        arr[i] = arr[j];
        while (arr[i] < pivot && i < j)
            i++;
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    return i;
}

void recursive_sort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        recursive_sort(arr, low, pi - 1);
        recursive_sort(arr, pi + 1, high);
    }
}

void quicksort(int* arr, int len) {
    recursive_sort(arr, 0, len - 1);
}

```

#### Big O notation revisited

O(n)的真正意义是，c * n，其中c是固定**常数***，指的是当前算法花费的固定时间。这个常数通常被忽略，因为对于不同的Big O times，常数不重要。但有时，这个常数can make a difference。快排在实践上比归并快的原因是，其常数比归并小。



### Chapter 5 Hash Tables

##### Hash functions

Hash函数的要求：

* 一致性(consistent)；对同一个word，每次的mapping结果要一样。
* 对于不同的word，mapping的结果应该不同。

哈希表由键(keys)和值(values)构成，哈希表通过哈希函数将keys maps to values。

哈希表用数组存储数据。各种编程语言都有哈希表的实现，它们被称为hash maps, maps, dictionaries and associative arrays。

#### Use cases

- 创建由A到B到映射
- 查询
- 对一组数据去重
- 提供cache

#### Collisions

**collision**，两个keys通过哈希函数被分配了同一个slot。

解决冲突的方法有多种，常用的有线性探测，二次探测，开链。

**开链**，如果多个keys映射到同一个slot，那么在那个slot创建一个链表。

#### Performance

![](https://raw.githubusercontent.com/qiuyi116/assets/master/Screen%20Shot%202018-07-26%20at%2011.32.29%20PM.png)

在没有冲突的情况下，无论哈希表多大，对哈希表的读取、插入、删除都是常数时间。而避免collisions，有两个途径：

* A low load factor
* A good hash function

当load factor过大时(大于0.7)，需要**resizing**哈希表，即重新分配更大的空间(往往是当前空间的两倍)，将原有数据重新hash后存储过去。



### Chapter 6 Breadth-First Search

#### Graph

图(Graph)是一系列连接关系的模型，用来模型化不同事物之间的连接关系。图由节点(nodes)和边(edges)组成。与一个节点直接相连的其他节点称为这个节点的邻居(neighbors)。

**树(tree)**是一种特殊类型的图，它没有向回指的边。

寻找从图中一节点到另一节点到最短路径的问题被称为**最短路径问题(shortest-path problem)**，解决这类问题的算法叫做**广度优先搜索(breadth-first search)**。

#### Breath-first search

BFS可以用来解决两类图的问题：

* 从节点A到节点B存在路径吗？
* 从节点A到节点B的最短路径是什么？

BFS同时解决这两个问题，如果用BFS找到了路径，那么这个路径就是最短路径。

BSF的时间复杂度是O(V+E)，其中V是节点数，E是边数。

以下是书上P105页的一个例子及BFS的实现：

<img src="https://raw.githubusercontent.com/qiuyi116/assets/master/Screen%20Shot%202018-07-27%20at%2011.35.05%20AM.png">

* 

这是一个**有向图(directed graph)**，描述了you的朋友关系。现在要按照一定的限制规则找到距离you最近的那个人。限制规则如下：

```python
def person_is_seller(name):
    return name[-1] == 'm'

```

首先，将图关系，有程序语言描述：

```python
graph = {}
graph[“you”] = [“alice”, “bob”, “claire”]
graph[“bob”] = [“anuj”, “peggy”]
graph[“alice”] = [“peggy”]
graph[“claire”] = [“thom”, “jonny”]
graph[“anuj”] = []
graph[“peggy”] = []
graph[“thom”] = []
graph[“jonny”] = []

```

最后，实现BFS：

```python
def search(name):
    search_queue = deque()
    search_queue += graph[name]
    searched = []
    while search_queue:
        person = search_queue.popleft()
        if person in searched:
            continue
        if person_is_seller(person):
            print person + “ is a mango seller!” return True
        else:
            search_queue += graph[person]
            searched.append(person)
    return False

```



### Chapter 7 Dijkstra's Algorithm

 Dijkstra算法有四个步骤：

1. 找到cheapest的节点。
2. 检查是否有到该节点的邻居的cheaper的路径，如果有，更新到邻居节点的costs。
3. 重复上述步骤，直到对图中所有节点都做了上述操作。
4. 计算最终路径。

在使用Dijkstra算法时，每条边上都有一个数字，叫做**权重(weight)**。带有权重的图叫有权图(weighted graph)；没有权重的图叫无权图(unweighted grap)。

计算无权图的最短路径，用BFS；计算有权图的最短路径，用Dijkstra‘s algorithm。

Dijkstra's algorithm 只能在**有向无环图(directed acyclic graphs, DAGs)**使用。

Dijkstra's algorithm 在有**negative-weight edges**时不能使用，这时应该用Bellman-Ford algorithm。

对于P131页的例子，对图的数据模型化和准备如下：

```python
graph = {}

start = {}
start["a"] = 6
start["b"] = 2
graph["start"] = start

a = {}
a["fin"] = 1
graph["a"] = a

b = {}
b["a"] = 3
b["fin"] = 5
graph["b"] = b

fin = {}
graph["fin"] = fin

costs = {}
costs["a"] = 6
costs["b"] = 2
costs["fin"] = float("inf")

parents = {}
parents["a"] = "start"
parents["b"] = "start"
parents["fin"] = None

processed = []

```

算法实现如下：

```python
def find_lowest_cost_node(costs):
    lowest_cost = float("inf")
    lowest_cost_node = None
    for node in costs:
        if costs[node] < lowest_cost and node not in processed:
            lowest_cost = costs[node]
            lowest_cost_node = node
    return lowest_cost_node

node = find_lowest_cost_node(costs)
while node is not None:
    cost = costs[node]
    neighbors = graph[node]
    for n in neighbors.keys():
        new_cost = cost + neighbors[n]
        if new_cost < costs[n]:
            costs[n] = new_cost
            parents[n] = node
    processed.append(node)
    node = find_lowest_cost_node(costs)

```



### Chapter 8 Greedy Algorithms

**贪心算法(greedy algorithm)**，在每一步选择局部最优，最终得到全局最优的结果。

对于**教室调度问题(the classroom sheduling problem)**，贪心算法可以得到最优结果。

对于**背包问题(the knapsack problem)、集合覆盖问题(the set-covering problem)**，贪心算法不能得到最优结果，它只能近似得到次优的结果。

#### The set-covering problem

书上，P146在多个州架设电台的例子。

贪心算法实现的**approximation algorithm**:

1. 选择可以覆盖最多未覆盖州的station。
2. 重复直到所有州都被覆盖。

代码如下：

```python
states_needed = set(["mt", "wa", "or", "id", "nv", "ut", "ca", "za"])

stations = {}
stations["kone"] = set(["id", "nv", "ut"])
stations["ktwo"] = set(["wa", "id", "mt"])
stations["kthree"] = set(["or", "nv", "ca"])
stations["kfour"] = set(["nv", "ut"])
stations["kfive"] = set(["ca", "az"])

final_stations = set()

while states_needed:
    best_station = None
    states_covered = set()
    for station, states in stations.items():
        covered = states_needed & states
        if len(covered) > len(states_covered):
            best_station = station
            states_covered = covered
    states_needed = states_needed - states_covered
    final_stations.add(best_station)

```

#### NP-complete problems

The traveling-salesperson problem and the set-covering problem都是NP-complete problem。你得计算所有可能的solution然后从中选择最优(smallest/shortest)的一个。但是可能的solution数量庞大、无法计算。

因此，NP完全性问题指的是一些著名的难以解决的问题。我们可以试着用贪心算法去寻求次优解来解决这些问题。

如果我们能识别出一个问题是NP完全问题，那么就可以用approximation算法去解决而不用徒劳地去寻求完美的解决问题。

以下是辨别一个问题是否是NP-complete的一些giveaways:

* 你的算法在有少量items运行得很快，但对于更多items却运行得相当慢。
* 类似“X的全部组合”的问题。
* 由于不能将问题划分为更小的子问题，而必须计算所有可能的版本。
* 问题涉及到一个序列(sequence)（sequence of cities, like traveling salesperson），并且难以解决。
* 问题涉及到一个集合(set)（like set of radio stations），并且难以解决。
* 问题可以被重述为the set-covering problem or the traveling-salesperson problem。



### Chapter 9 Dynamic Programming

**动态规划(dynamic programming)**，把问题分割成子问题来解决，然后在它们组合成起来。































