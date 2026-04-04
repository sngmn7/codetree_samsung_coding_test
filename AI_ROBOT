#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Robot {
    int id, r, c;
};

int N, K, L;
int A[34][34]; //먼지 물건 지도
int B[34][34]; //로봇 지도
vector<Robot> robots;

int dx[] ={0, -1, 0, 1};
int dy[] ={-1, 0, 1, 0};
int sx[5] = {0, -1, 0, 1, 0};
int sy[5] = {-1, 0, 1, 0, 0};

bool inRange(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

void moveRobot(Robot& rb){
    if (A[rb.r][rb.c] > 0) return;
    
    queue<pair<int, int>> q;
    vector<vector<int>> dist(N, vector<int>(N, -1));

    q.push({rb.r, rb.c});
    dist[rb.r][rb.c] = 0;

    int bestDist = -1;
    pair <int, int> bestCell = {-1, -1};

    while (!q.empty()){
        auto [r,c] = q.front(); q.pop();

        if (bestDist != -1 && dist[r][c] > bestDist) break;
        for (int d = 0; d < 4; d++){
            int nr = r + dx[d]; int nc = c + dy[d];

            if (!inRange(nr, nc)) continue;
            if (dist[nr][nc] != -1) continue;
            if (A[nr][nc] < 0) continue;
            if (B[nr][nc] != -1) continue;

            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr,nc});

            if (A[nr][nc] > 0){
                if (bestDist == -1 || bestDist == dist[nr][nc]) {
                    if (bestDist == -1) {
                        bestDist = dist[nr][nc];
                        bestCell = {nr, nc};
                    } else {
                        // 행 작은 순 -> 열 작은 순 (min 함수로 한 방에 해결)
                        bestCell = min(bestCell, make_pair(nr, nc));
                    }
                }
            }

        }       
    }
    if (bestDist != -1) {
        B[rb.r][rb.c] = -1;       // 예전 자리 비우기
        rb.r = bestCell.first;    // 좌표 갱신
        rb.c = bestCell.second;
        B[rb.r][rb.c] = rb.id;    // 새 자리에 내 ID 찍기
    }

}

void cleanRobot(Robot& rb){
    int maxDust = -1;
    int bestNo = -1;

    for (int no = 0; no < 4; no++){
        int currentSum = 0;

        for (int k=0; k < 5; k++){
            if (k < 4 && k == no) continue;

            int nr = rb.r + sx[k];
            int nc = rb.c + sy[k];

            if (inRange(nr, nc) && A[nr][nc] > 0){
                currentSum += min(A[nr][nc], 20);
            }
        }

        if (currentSum > maxDust){
            maxDust = currentSum;
            bestNo = no;
        }
    }

    if (bestNo != -1) {
        for (int k = 0; k < 5; k++) {
            if (k < 4 && k == bestNo) continue; // 선택한 방향의 반대(제외할 방향)는 건너뜀
            int nr = rb.r + sx[k];
            int nc = rb.c + sy[k];
            if (inRange(nr, nc) && A[nr][nc] > 0) {
                A[nr][nc] -= 20;
                if (A[nr][nc] < 0) A[nr][nc] = 0; // 먼지는 0보다 작아질 수 없음
            }
        }
    }
}

void diffuseDust() {
    // 1. 확산될 먼지량을 저장할 임시 배열 (N x N)
    vector<vector<int>> tempA(N, vector<int>(N, 0));

    // 2. 먼저 모든 먼지 격자에 5씩 추가 (먼저 수행해야 확산 합계에 반영됨)
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (A[r][c] > 0) {
                A[r][c] += 5;
            }
        }
    }

    // 3. 확산량 계산 (이미 +5가 된 A 지도를 기준으로 스캔)
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            // 깨끗한 칸(0)이 주변(A > 0)에서 먼지를 빨아들임
            if (A[r][c] == 0) { 
                int nearSum = 0;
                for (int d = 0; d < 4; d++) {
                    int nr = r + dx[d], nc = c + dy[d];
                    if (inRange(nr, nc) && A[nr][nc] > 0) {
                        nearSum += A[nr][nc];
                    }
                }
                tempA[r][c] = nearSum / 10;
            }
        }
    }

    // 4. 지도 업데이트 (기존 값에 '더하기')
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (tempA[r][c] > 0) {
                A[r][c] += tempA[r][c]; // 대입(=)이 아니라 더하기(+=)!!
            }
        }
    }
}

int main() {
    cin >> N >> K >> L;

    for(int i = 0; i<N; i++){
        for (int j = 0; j < N; j++){
            cin >> A[i][j];
            B[i][j] = -1;
        }
    }

    for (int i = 0; i < K ; i++){
        int r, c;
        cin >> r >> c;

        robots.push_back({i, r-1, c-1});
        B[r-1][c-1] = i;
    }

    for (int t = 0; t < L; t++){
        for (int i = 0; i < K; i++){
            moveRobot(robots[i]);
        }

        for(int i = 0; i < K; i++){
            cleanRobot(robots[i]);
        }

        diffuseDust();

        long long total = 0;
        for (int r = 0; r<N; r++){
            for (int c = 0; c<N; c++){
                if(A[r][c] > 0){
                    total += A[r][c];
                }
            }
        }

        cout << total << "\n";
    }

    return 0;
}
//test
