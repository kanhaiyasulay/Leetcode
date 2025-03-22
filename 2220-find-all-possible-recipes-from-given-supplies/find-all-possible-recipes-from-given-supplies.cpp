class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) 
    {
        vector<string> result;

        unordered_set<string> st;
        for(auto it:supplies ) st.insert(it);

        int over = recipes.size();
        int undone = 0;
        while(true)
        {
            over = recipes.size();
            over -= result.size();
            undone = 0;
            for(int i=0; i<recipes.size(); i++)
            {
                if(recipes[i] == "@") continue;
                bool canBeMade = true;
                for(int j=0; j<ingredients[i].size(); j++)
                {
                    if(st.find(ingredients[i][j]) == st.end())
                    {
                        canBeMade = false;
                        undone++;
                        break;
                    }
                }
                if(canBeMade) 
                {
                    result.push_back(recipes[i]);
                    st.insert(recipes[i]);
                    recipes[i] = "@";
                }
            }

            if(undone == over) break;
        }

        return result;
    }
};