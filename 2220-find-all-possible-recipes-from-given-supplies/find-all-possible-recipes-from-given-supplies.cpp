class Solution {
public:
    bool dfs(string food, const unordered_map<string, vector<string>>& adj,
             unordered_set<string>& supply_set,
             unordered_map<string, int>& visited) {

        if (supply_set.find(food) != supply_set.end())
            return true;
        else {
            if (adj.find(food) ==
                adj.end()) // not in supply or recipes; impossible
                return false;
        }

        if (visited[food] == 2)
            return true; // visited

        if (visited[food] == 1)
            return false; // cycle

        visited[food] = 1;

        for (auto ingred : adj.at(food)) {

            if (!dfs(ingred, adj, supply_set, visited))
                return false;
        }

        visited[food] = 2;
        supply_set.insert(food);
        return true;
    }

    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_set<string> supply_set =
            unordered_set(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> adj;
        vector<string> pos_recipes;
        unordered_map<string, int> visited;

        int len = ingredients.size();
        for (int i = 0; i < len; ++i) {
            adj[recipes[i]] = ingredients[i];
        }

        for (string food : recipes) {
            if (supply_set.find(food) != supply_set.end()) {
                pos_recipes.push_back(food);
                continue;
            }
            if (dfs(food, adj, supply_set, visited))
                pos_recipes.push_back(food);
        }

        return pos_recipes;
    }
};