class Solution {
public:
    string simplifyPath(string path) {
        stack<string> directories;
        stringstream ss(path);
        string token;

        while(getline(ss, token, '/')){
            if(token == ".."){
                if(!directories.empty())
                    directories.pop();
            } else if (token == "." || token.empty()) {
                continue;
            } else{
                directories.push(token);
            }
        }
        
        string res = "";
        while(!directories.empty()){
            res = "/" + directories.top() + res; // prepend
            directories.pop();
        }

        return res.empty() ? "/" : res;
    }
};