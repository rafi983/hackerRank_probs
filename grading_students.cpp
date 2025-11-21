#include <iostream>
#include <vector>

using namespace std;

vector<int> gradingStudents(const vector<int> &grades) {
    vector<int> finalGrades;
    finalGrades.reserve(grades.size());

    for (int grade : grades) {
        if (grade < 38) {
            finalGrades.push_back(grade);
            continue;
        }

        int nextMultipleOfFive = ((grade / 5) + 1) * 5;
        if (nextMultipleOfFive - grade < 3) {
            finalGrades.push_back(nextMultipleOfFive);
        } else {
            finalGrades.push_back(grade);
        }
    }

    return finalGrades;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    vector<int> grades(n);
    for (int &grade : grades) {
        cin >> grade;
    }

    const vector<int> rounded = gradingStudents(grades);
    for (int grade : rounded) {
        cout << grade << '\n';
    }

    return 0;
}

