#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {

    int N = 0, T = 0; // N = people in queue, T = time until bank closes
    vector<pair<int, int>>people(N);
    vector <bool> timeUsed(100, false); // To know if time has been used
    scanf("%d %d", &N, &T);
    int M = 0, L = 0; // M = money, L = time till person leaves
    pair<int, int> person;
    
    for(int i = 0; i < N; i++){
    
        scanf("%d %d", &M, &L);
        person.first = M;
        person.second = L;
        people.push_back(person);
        
    }
    
    sort(people.rbegin(), people.rend()); // Sort in descending order
    
    int cashMoney = 0;

    for(int i = 0; i < T && i < N; i++){
        
        if(timeUsed[people[i].second]){ // Time has been used
        
            for(int j = people[i].second; j >= 0; j--){
            
                if(!timeUsed[j]){ // Find time that customer can come which hasen't been used
                
                    timeUsed[j] = true;
                    cashMoney += people[i].first;
                    break;
                
                } else if(j == 0){ // If we get to end then we didn't add any time, so we have one more minute free
                
                    T++;
                
                }
                
            }
        
        } else { // Time hasen't been used
            
            timeUsed[people[i].second] = true; // Marked as used
            cashMoney += people[i].first;
        
        }

    }
    
    printf("%d", cashMoney);
    
    return 0;

}
