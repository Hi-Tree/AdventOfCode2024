#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void reader(vector<int>& column1, unordered_map<int,int>& column2_map){
    std::ifstream file("input.txt");
    int val1, val2;

    while (file >> val1 >> val2) { 
        column1.push_back(val1);
        if(column2_map.find(val2) != column2_map.end()){
            column2_map[val2] = column2_map[val2]+1;
        }
        else{
            column2_map[val2] = 1;
        }
    }
    file.close();
}

int calculator(vector<int>& column1, unordered_map<int,int> column2_map, long& count, int pos){//mmmmhhhmmmmmm
    if(pos == column1.size()){
        return count;
    }
    if(column2_map.find(column1[pos]) != column2_map.end()){
        count +=  (column2_map[column1[pos]]*column1[pos]);
    }
    return calculator(column1, column2_map, count, pos+=1);
}

int main(){
    vector<int> column1;
    unordered_map<int,int> column2_map;
    long count = 0;
    reader(column1, column2_map);
    calculator(column1, column2_map, count, 0);
    cout<<count<<endl;
}
