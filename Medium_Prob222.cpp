/* Given a list of numbers, create an algorithm that arranges them in order to form the largest possible integer. 
For example, given [10, 7, 76, 415], you should return 77641510.*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/* Given an absolute pathname that may have . or .. as part of it, return the shortest standardized path.

For example, given "/usr/bin/../bin/./scripts/../", return "/usr/bin/". */

string getShortestStandardizePath(string path) {
    vector<string> pathPart ;
    int partBegin = 0;
    for (int i=0; i<path.size(); i++) {
        if (path[i] == '/') {
            if (i != partBegin) {
                pathPart.push_back(path.substr(partBegin,i-partBegin));
            }
            partBegin = i+1;
        }
    }

    vector<string> absolutePath;
    for (const string &part : pathPart) {
        if (part == "..") {
            if (!absolutePath.empty()) {
                absolutePath.pop_back();
            }
        } else if (part != ".") {
            absolutePath.push_back(part);
        }
    }

    string standardizedPath;
    for (const string &part : absolutePath) {
        standardizedPath += "/" + part;
    }

    if (standardizedPath.empty()) {
        return "/";
    }

    return standardizedPath;
}

int main(int argc, char *argv[])
{
    cout << getShortestStandardizePath("/usr/bin/../bin/./scripts/../") << endl;
}