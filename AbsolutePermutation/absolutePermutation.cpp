#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'absolutePermutation' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 */

vector<int> absolutePermutation(int n, int k) 
{
    vector<int> absPList;								//initial num generation and vector for results
    std::unordered_map<int, int> absMap;				//map to keep track of indexes with their values
    bool noPerm = false;								
    
    for (int i = 1; i <= n; i++)						//fill array with sorted nums from 1 to n
    {
        absPList.push_back(i);
    }
    
    int index = 0;
    
    for(int i : absPList)
    {
        
        if(i <= k)
        {
            index = i + k;
         
        }
        else if (i > k)									// i += k = |index|, but we prefer the lowest num first
        {
            index = i - k;
            
            if(absMap.count(index) != 0)				//if lower num is taken
            {
                index = i+k;
                
                if (absMap.count(index) !=0)			//if both are taken
                {
                    noPerm = true;
                    break;
                }
            }
            
        }
        
        absMap.insert(std::make_pair(index, i));
    }
    
    absPList.clear();
    
    if (!noPerm)
    {
        for (int i = 1; i <= n; i++)					//go through map in ascending order 
        {
            
            if(absMap.count(i) == 0)					//prevent out of range 
            {
            
                noPerm = true;
                break;
            }
            else
            {
                //std::cout << "index at : " + to_string(absMap.at(i)) << endl;
                absPList.push_back(absMap.at(i));
            }
        }
    }
    
    if (noPerm)
    {
        return vector<int>(1, -1);
    }
    else
    {
        return absPList;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int k = stoi(first_multiple_input[1]);

        vector<int> result = absolutePermutation(n, k);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

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
