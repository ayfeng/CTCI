#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void printMatrix(vector<vector<int> > matrix) {
    for (vector<vector<int> >::iterator i = matrix.begin(); i != matrix.end(); ++i) {
        for (vector<int>::iterator j = i->begin(); j != i->end(); ++j) {
            cout << *j << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix;
    set<int> zero_rows, zero_columns;
    for (int i = 0; i != rows; ++i) {
        vector<int> vectorRow;
        for (int j = 0; j != cols; ++j) {
            int temp;
            cin >> temp;

            if (temp == 0) {
                zero_rows.insert(i);
                zero_columns.insert(j);
            }
            vectorRow.push_back(temp);
        }
        matrix.push_back(vectorRow);
    }

    printMatrix(matrix);

    for (set<int>::iterator it = zero_rows.begin(); it != zero_rows.end(); ++it) {
        fill((matrix.begin()+(*it))->begin(), (matrix.begin()+(*it))->end(), 0);
    }

    for (set<int>::iterator it = zero_columns.begin(); it != zero_columns.end(); ++it) {
        for (int i = 0; i != cols; ++i) {
            cout << *((matrix.begin()+(*it))->begin()+i) << endl;
            matrix[i][*it] = 0;
        }
    }

    printMatrix(matrix);
    
}

void printMatrix(vector<vector<int> > matrix);
