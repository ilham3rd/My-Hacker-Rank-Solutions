//https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    vector <int> rank_player;
    int rank = 1;
    int last;
    int last_value;
    for(int i=0;i<ranked.size();i++){
        if(ranked[i]>player[0] && ranked[i]!=ranked[i+1]){
            last = i;
            rank++;
            last_value=ranked[i];
        }
    }
    rank_player.push_back(rank);
    cout<<last;
    for(int j=1;j<player.size();j++){
        if(rank==1){
            rank_player.push_back(1);
            continue;
        }
        int p=0;
        for(int k=last;k>=0;k--){
            // cout<<"Player Value "<<player[j]<<endl;
            // cout<<"Ranked Value "<<ranked[k]<<endl;
            // cout<<"Rank Pos "<<rank<<endl;

            if(ranked[k]!=ranked[k-1]){
                cout<<"1"<<endl;
                // last_value=ranked[k];
                cout<<ranked[k]<<" "<<player[j]<<endl;
                if(ranked[k]>player[j]){
                    // cout<<"PUSH"<<endl;
                    rank_player.push_back(rank);
                    last=k;
                    break;
                }
                else if(ranked[k]<=player[j]){
                    rank--;
                    // cout<<"MIN"<<endl;
                   if(rank==1){
                       rank_player.push_back(rank);
                   }
                }
            }
        }
    }
    return rank_player;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ranked_count_temp;
    getline(cin, ranked_count_temp);

    int ranked_count = stoi(ltrim(rtrim(ranked_count_temp)));

    string ranked_temp_temp;
    getline(cin, ranked_temp_temp);

    vector<string> ranked_temp = split(rtrim(ranked_temp_temp));

    vector<int> ranked(ranked_count);

    for (int i = 0; i < ranked_count; i++) {
        int ranked_item = stoi(ranked_temp[i]);

        ranked[i] = ranked_item;
    }

    string player_count_temp;
    getline(cin, player_count_temp);

    int player_count = stoi(ltrim(rtrim(player_count_temp)));

    string player_temp_temp;
    getline(cin, player_temp_temp);

    vector<string> player_temp = split(rtrim(player_temp_temp));

    vector<int> player(player_count);

    for (int i = 0; i < player_count; i++) {
        int player_item = stoi(player_temp[i]);

        player[i] = player_item;
    }

    vector<int> result = climbingLeaderboard(ranked, player);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
