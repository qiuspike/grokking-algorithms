#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;
using std::queue;
using std::cout;
using std::endl;

bool person_is_seller(string name) {
    return name[name.length() - 1] == 'm';
}

bool bfs(string name, unordered_map<string, vector<string> > &graph) {
    queue<string> search_queue;
    unordered_set<string> searched;

    for (auto e : graph[name])
        search_queue.push(e);
    while (!search_queue.empty()) {
        string person = search_queue.front();
        search_queue.pop();
        if (searched.find(person) != searched.end())
            continue;
        if (person_is_seller(person)) {
            cout << person << " is a mango seller!" << endl;
            return true;
        }
        else {
            searched.insert(person);
            for (auto e : graph[person])
                search_queue.push(e);
        }
    }
    return false;
}


int main() {

    unordered_map<string, vector<string> > graph;
    vector<string> you, bob, alice, claire, anuj, peggy, jonny, thom;
    you.push_back("bob");
    you.push_back("alice");
    you.push_back("claire");
    bob.push_back("anuj");
    bob.push_back("peggy");
    alice.push_back("peggy");
    claire.push_back("thom");
    claire.push_back("jonny");
    graph["you"] = you;
    graph["bob"] = bob;
    graph["alice"] = alice;
    graph["claire"] = claire;
    graph["anuj"] = anuj;
    graph["peggy"] = peggy;
    graph["jonny"] = jonny;
    graph["thom"] = thom;

    bfs("you", graph);
    
    return 0;
}