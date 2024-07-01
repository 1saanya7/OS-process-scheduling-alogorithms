#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "Enter total number of resources: ";
    int num_resources;
    cin >> num_resources;

    cout << "Enter instance of each resource: ";
    vector<int> resource(num_resources);
    for (int i = 0; i < num_resources; i++) {
        cin >> resource[i];
    }

    cout << "Enter number of processes: ";
    int num_process;
    cin >> num_process;

    cout << "Enter the allocation matrix:\n";
    vector<vector<int> > allocation(num_process, vector<int>(num_resources));
    for (int i = 0; i < num_process; i++) {
        for (int j = 0; j < num_resources; j++) {
            cin >> allocation[i][j];
        }
    }

    cout << "Enter the maximum requirement matrix:\n";
    vector<vector<int> > max_req(num_process, vector<int>(num_resources));
    for (int i = 0; i < num_process; i++) {
        for (int j = 0; j < num_resources; j++) {
            cin >> max_req[i][j];
        }
    }

    cout << "All required inputs are taken.\n";

    vector<vector<int> > remaining_req(num_process, vector<int>(num_resources));
    for (int i = 0; i < num_process; i++) {
        for (int j = 0; j < num_resources; j++) {
            remaining_req[i][j] = max_req[i][j] - allocation[i][j];
        }
    }

    cout << "We have got our remaining requirement matrix.\n";

    // Initialization
    vector<int> available1(num_resources, 0);
    for (int i = 0; i < num_resources; i++) {
        int sum = 0;
        for (int j = 0; j < num_process; j++) {
            sum += allocation[j][i];
        }
        available1[i] = resource[i] - sum;
    }

    vector<int> safe_state;
    int count1 = 0;
    int count2 = 0;
    vector<bool> flag(num_process, false);

    while (count1 < num_process) {
        if (count2 == num_process && safe_state.empty()) {
            cout << "Safe state does not exist\n";
            exit(0);
        }

        for (int i = 0; i < num_process; i++) {
            if (!flag[i]) {
                int m = 0;
                for (int j = 0; j < num_resources; j++) {
                    if (remaining_req[i][j] <= available1[j]) {
                        m++;
                    }
                }
                if (m == num_resources) {
                    count1++;
                    flag[i] = true;
                    for (int l = 0; l < num_resources; l++) {
                        available1[l] = allocation[i][l] + available1[l];
                        remaining_req[i][l] = 0;
                    }
                    safe_state.push_back(i + 1);
                }
            } else {
                continue;
            }
        }
        count2++;
    }

    cout << "Safe State: ";
    for(int k=0;k<safe_state.size();k++){
    	cout<<safe_state[k];
	}
    cout << endl;

    return 0;
}
