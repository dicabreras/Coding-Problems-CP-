#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <typeinfo>

using namespace std;

int main()
{
    int num_data, pos_k_score, k_score, players_next_round=0;

    string data;
    string string_scores;
    string num, scores_num;
    vector<int> scores;
    

    getline(cin, data); 
    stringstream scores_string(data);
    getline(scores_string, scores_num, ' ');
    num_data = stoi(scores_num);
    getline(scores_string, scores_num, ' ');
    pos_k_score = stoi(scores_num);
    
    getline(cin, string_scores);
    stringstream name_string(string_scores);

    while(getline(name_string, num, ' ')){
        scores.push_back(stoi(num));
    }
    k_score = scores[pos_k_score-1];

    for(int score: scores){
        if (score >=k_score && score >0){
            players_next_round++;
        } 
    }
    cout<<players_next_round;
   
    return 0;
}


