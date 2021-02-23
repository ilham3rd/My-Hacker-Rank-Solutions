/*
Difficulty : Expert
Link : https://www.hackerrank.com/challenges/morgan-and-a-string/problem
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the morganAndString function below.
string morganAndString(string a, string b) {
    string jackString = a;
    string danielString = b;
    string morganString;
    int last_right = 0;
    int sizeJack = jackString.size();
    int sizeDaniel = danielString.size();
    int indexJack = 0;
    int indexDaniel = 0;
    while(1){
        if(indexJack!=sizeJack&&indexDaniel!=sizeDaniel){
            if(jackString[indexJack]<danielString[indexDaniel]){
                morganString.push_back(jackString[indexJack]);
                indexJack++;
                continue;
            }
            else if(jackString[indexJack]>danielString[indexDaniel]){
                morganString.push_back(danielString[indexDaniel]);
                indexDaniel++;
                continue;
            }
            else{
                int temp_indexJack = indexJack;
                int temp_indexDaniel = indexDaniel;
                // morganString.push_back(jackString[indexJack]);
                // indexJack++;
                while(1){
                    if(jackString[temp_indexJack]!=danielString[temp_indexDaniel]){
                        if(jackString[temp_indexJack]<danielString[temp_indexDaniel]){
                            morganString.push_back(jackString[indexJack]);
                            indexJack++;
                            break;
                        }
                        else if(jackString[temp_indexJack]>danielString[temp_indexDaniel]){
                            morganString.push_back(danielString[indexDaniel]);
                            indexDaniel++;
                            break;
                        }
                    }
                    else{
                        temp_indexDaniel++;
                        temp_indexJack++;
                    }
                }
                continue;
            }
        }
        else if(indexJack==sizeJack&&indexDaniel!=sizeDaniel){
            morganString.push_back(danielString[indexDaniel]);
            indexDaniel++;
            continue;
        }
        else if(indexJack!=sizeJack&&indexDaniel==sizeDaniel){
            morganString.push_back(jackString[indexJack]);
            indexJack++;
            continue;
        }
        else if(indexJack==sizeJack&&indexDaniel==sizeDaniel){
            break;
        }
    }


        return morganString;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = morganAndString(a, b);
        // cout<<result<<endl;
        fout << result << "\n";
    }

    fout.close();

    return 0;
}
