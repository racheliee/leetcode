class Spreadsheet {
public:
    Spreadsheet(int rows) {
        spreadsheet = vector<vector<int>>(rows+1, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        char alpha; int num;
        stringstream ss(cell);
        ss >> alpha >> num;

        spreadsheet[num][alpha-65] = value;
    }
    
    void resetCell(string cell) {
        char alpha; int num;
        stringstream ss(cell);
        ss >> alpha >> num;

        spreadsheet[num][alpha-65] = 0;
    }
    
    int getValue(string formula) {
        char temp; int num1 = -1, num2 = -1;

        stringstream ss(formula);

        while(ss >> temp) {
            if(temp == '=' || temp == '+') continue;

            if(temp >= 65) {
                int num;
                ss >> num;
                if(num1 == -1) num1 = spreadsheet[num][temp-65];
                else num2 = spreadsheet[num][temp-65];
            } else {
                ss.unget();
                if(num1 == -1) ss >> num1;
                else ss >> num2;
            }
        }

        return num1 + num2;
    }

private:
    vector<vector<int>> spreadsheet;
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */