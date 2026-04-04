#include <iostream>

using namespace std;

int n;
char dir[100];
int dist[100];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int x,y = 0;
int nx;
int ny;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dir[i] >> dist[i];
    }

    for (int i = 0; i < n; i++){
        if(dir[i] == 'N'){
            for(int j = 0; j < dist[i]; j++){
                nx += dx[1];
            }
        }
        else if(dir[i] == 'S'){
            for(int j = 0; j < dist[i]; j++){
                nx += dx[0];
            }
        }
        else if(dir[i] == 'E'){
            for(int j = 0; j < dist[i]; j++){
                ny += dy[2];
            }
        }
        else if(dir[i] == 'W'){
            for(int j = 0; j < dist[i]; j++){
                ny += dy[3];
            }
        }

    }

    cout << ny<< " " << nx << "\n";

    return 0;
}