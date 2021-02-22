/*
Difficulty : Medium
Link : https://www.hackerrank.com/challenges/extra-long-factorials/problem
*/

#include <bits/stdc++.h>

using namespace std;


vector<int> perkalian(vector <int> atas, vector <int> bawah){
     int n_bawah=bawah.size();
    vector <vector<int>> total_vector_jumlahan;
    for(int i = bawah.size()-1;i>=0;i--){
        vector <int> vector_jumlah;
        int tambahan = 0;
        for(int j = atas.size()-1;j>=0;j--){
            
            int satuan = (bawah[i]*atas[j]+tambahan)/10;
            int sisa = (bawah[i]*atas[j]+tambahan)%10;
            vector_jumlah.insert(vector_jumlah.begin(),sisa);
            tambahan = satuan;
            if(j==0&&satuan>0){
                vector_jumlah.insert(vector_jumlah.begin(),satuan);
            }
        }
        total_vector_jumlahan.push_back(vector_jumlah);
    }

    int firstZero;
    int lastZero=0;
    int x = total_vector_jumlahan.size()-1;

    if(total_vector_jumlahan.size()<total_vector_jumlahan[x].size()){
        firstZero = total_vector_jumlahan.size();
    }
    else{
        firstZero = total_vector_jumlahan.size()-1;
    }
    
    int size_total_vector =atas.size();
    for(int i=0; i<total_vector_jumlahan.size();i++){
        int size_vector = total_vector_jumlahan[i].size();
        int a;
        if(size_vector>size_total_vector){
            a=firstZero-1;
        }
        else{
            a=firstZero;
        }
        for(int k=0;k<a;k++){
            total_vector_jumlahan[i].insert(total_vector_jumlahan[i].begin(),0);
            }
        for(int k=0;k<lastZero;k++){
            total_vector_jumlahan[1].push_back(0);
        }
        firstZero--;
        lastZero++;
    }

    int sisa=0;
    vector <int> total_sum;
    int max = total_vector_jumlahan[0].size()-1;
    
//     cout<<"Atas"<<endl;
//     for(int i=0;i<atas.size();i++){
//         cout<<atas[i];
//     }

//     cout<<endl<<endl;
    
//     cout<<"Bawah"<<endl;
//     for(int i=0;i<bawah.size();i++){
//         cout<<bawah[i];
//     }

// cout<<endl;
    
//     cout<<endl<<"Jumlahan"<<endl;
//     for(int i=0;i<total_vector_jumlahan.size();i++){
//         for(int j=0;j<total_vector_jumlahan[i].size();j++){
//             cout<<total_vector_jumlahan[i][j];
//         }
//         cout<<endl;

//     }
//     cout<<endl;


    for(int i=max;i>=0;i--){
        int sumTemp=0;
        for(int k=0;k<total_vector_jumlahan.size();k++){
            sumTemp = sumTemp+total_vector_jumlahan[k][i];
        }
        int satuan = (sumTemp+sisa)%10;
        total_sum.insert(total_sum.begin(),satuan);
        sisa = (sumTemp+sisa)/10;
        if(i==0&&sisa>0){
            total_sum.insert(total_sum.begin(),sisa);
        }
        
    }

    //     cout<<endl;
    // cout<<"Result"<<endl;
    //     for(int i = 0; i<total_sum.size();i++){
    //     cout<<total_sum[i];
    // }
    // cout<<endl;
    // cout<<"---------------------"<<endl;
    return total_sum;
}

vector <int> int_to_vec(int x){
    vector <int> num;
    if(x<10){
        num.push_back(x);
    }
    else if(x<100){
        num.push_back(x/10);
        num.push_back(x%10);
    }
    else if(x=100){
        num.push_back(1);
        num.push_back(0);
        num.push_back(0);
    }
    return num;

}

void extraLongFactorials(int n) {
    vector <int> result;


    result.push_back(1);
    for(int i =1;i<=n;i++){
        vector <int> num;
        num = int_to_vec(i);
        result = perkalian(result,num);
    }
    int x;
    for(int i=0;i<result.size();i++){
        if(result[i]!=0){
            x=i;
            break;
        }
    }
    for(int i=x;i<result.size();i++){
        cout<<result[i];

    }

}


int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    extraLongFactorials(n);

    return 0;
}
