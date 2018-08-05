
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

print costs
