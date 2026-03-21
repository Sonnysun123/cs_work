#include <iostream>
#include <string>
#include <vector>
using namespace std;
void solve()
{
    vector<int> position;
    position.push_back(0);
    vector<string> result;
    int width, height; cin >> width >> height;
    string line;
    getline(cin >> ws, line);
    /*finding all the indexes of space in the string*/
    for (unsigned int i = 0; i < line.size(); i++) 
    {
        if (line[i] == ' '){
            position.push_back(i);
        } 
    }
    //split the sentence to words by spaces.
    //add the first word
    position.push_back(line.size());
    vector<string> words;
    words.push_back(line.substr(0, position[1]));
    for (unsigned int i = 1; i < position.size() - 1; i++) {
        int startIndex = position.at(i) + 1;
        int endIndex = position.at(i + 1);
        int strLength = endIndex - startIndex;
        string temp = line.substr(startIndex, strLength);
        words.push_back(temp);

    }
    //add the last word
    position.push_back(position[position.size() - 1]);
   

    int heightCount = 0;
    int i = 0;
    while (heightCount < height) {
    if (i >= (int)words.size()) break;
    string temp = words[i];
    if ((int)temp.length() > width) {
        cout << "WILL NOT FIT" << endl;
        return;
    }
    while (true) {
        if (i + 1 >= (int)words.size()) break;
        if ((int)temp.length() + 1 + (int)words[i + 1].length() > width) break;
        temp += " " + words[i + 1];
        i++;
    }

    result.push_back(temp);
    heightCount++;
    i++;
}

if (i < (int)words.size()) {
    cout << "WILL NOT FIT" << endl;
    return;
}

for (string s : result) {
    cout << s << endl;
}
}
int main(){
    int tc; cin >> tc;
    while(tc--){
        solve();
    }
}

