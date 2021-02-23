/*
Difficulty : Medium
Link : https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int reverseNum(int n){
    int num = n;
    int reverseNum=0;
    int pengkali = 0;
    bool state=false;
    for(int x=6;x>=0;x--){
        int div = pow(10,x);
        if(num/div>0){
            state=true;
            reverseNum = reverseNum + (num/div)*(pow(10,pengkali));
            num = num -((num/div)*div);
            
        }
        if(state==true){
            pengkali++;
        }
        
    }
    // cout<<reverseNum;
    return reverseNum;
}


int beautifulDays(int i, int j, int k) {
    int beautifulDay=0;
    for(int index = i; index<=j; index++){
        if(abs(index - reverseNum(index))%k==0){
            beautifulDay++;
        }
    }
    return beautifulDay;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ijk_temp;
    getline(cin, ijk_temp);

    vector<string> ijk = split_string(ijk_temp);

    int i = stoi(ijk[0]);

    int j = stoi(ijk[1]);

    int k = stoi(ijk[2]);

    int result = beautifulDays(i, j, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
