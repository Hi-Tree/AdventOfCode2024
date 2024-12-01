#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void reader(vector<int>& column1, vector<int>& column2){
    std::ifstream file("input.txt");
    int val1, val2;

    while (file >> val1 >> val2) { 
        column1.push_back(val1);
        column2.push_back(val2);
    }

    file.close();
}

int calculator(vector<int>& column1, vector<int>& column2, int& count, int pos){
    if(pos == column1.size()){
        return count;
    }
    
    count += abs(column1[pos]-column2[pos]);
    cout<<pos<<"|"<<column1[pos]<<"|"<<column2[pos]<<"|"<<abs(column1[pos]-column2[pos])<<"|"<<count<<endl;
    return calculator(column1, column2, count, pos+=1);
}


int main(){
    int count = 0;
    vector<int> column1, column2;
    reader(column1,column2);
    std::sort(column1.begin(),column1.end());
    std::sort(column2.begin(),column2.end());
    calculator(column1,column2, count,0);
    cout<<count<<endl;
}