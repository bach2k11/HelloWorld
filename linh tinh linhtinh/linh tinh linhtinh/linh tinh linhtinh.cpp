#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int n, m;
char a[1001][1001];
bool visited[1001][1001];
int d[1001][1001]; //luu so buoc di tu o bat dau
pair<int, int> parent[1001][1001]; //lưu thông tin về đỉnh cha của mỗi ô

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

//bool bfs(int i, int j) {
//    queue<pair<int, int>> q;
//    q.push({ i, j });
//    d[i][j] = 0;
//    visited[i][j] = true;
//    while (!q.empty()) {
//        pair<int, int> top = q.front(); q.pop();
//        for (int k = 0; k < 4; k++) {
//            int i1 = top.first + dx[k];
//            int j1 = top.second + dy[k];
//            if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1] != 'x' && !visited[i1][j1]) {
//                cout << i1 << ' ' << j1 << endl;
//                d[i1][j1] = d[top.first][top.second] + 1;
//                parent[i1][j1] = top; // Lưu thông tin về đỉnh cha của ô (i1, j1)
//                if (a[i1][j1] == 'B') return true;
//                q.push({ i1, j1 });
//                visited[i1][j1] = true;
//            }
//        }
//    }
//    return false;
//}

bool bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i, j });
	d[i][j] = 0;
	visited[i][j] = true;
	while (!q.empty()) {
		pair<int, int> top = q.front(); q.pop();
		cout << "Diem hien tai: (" << top.first << ", " << top.second << ")\n";
		for (int k = 0; k < 4; k++) {
			int i1 = top.first + dx[k];
			int j1 = top.second + dy[k];
			if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1] != 'x' && !visited[i1][j1]) {
				d[i1][j1] = d[top.first][top.second] + 1;
				parent[i1][j1] = top; // Lưu thông tin về đỉnh cha của ô (i1, j1)
				if (a[i1][j1] == 'B') return true;
				q.push({ i1, j1 });
				visited[i1][j1] = true;
			}
		}
		// Hiển thị ma trận sau mỗi bước di chuyển của BFS
		cout << "Ma tran sau buoc di:\n";
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				cout << a[x][y] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return false;
}


void TracePath(pair<int, int> destination) {
	pair<int, int> current = destination;
	while (a[current.first][current.second] != 'A') {
		a[current.first][current.second] = 'K'; // Đánh dấu đường đi bằng kí tự 'K'
		current = parent[current.first][current.second];
	}
}

void Path() {
	cout << "ma tran ? * ? :";
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = 'o';
		}
	}
	int x1, x2, y1, y2;
	cout << "nhap toa do 2 dinh lam rao"; cin >> x1 >> x2 >> y1 >> y2;
	a[x1][y1] = a[x2][y2] = 'x';
	int x, y, z, t;
	cout << "toa do nguon: "; cin >> x >> y;
	cout << "toa do dich: ";  cin >> z >> t;
	a[x][y] = 'A';
	a[z][t] = 'B';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	memset(visited, false, sizeof(visited));
	if (bfs(x, y)) {
		TracePath({ z, t }); // Truy vết đường đi từ điểm đích
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	// Hiển thị ma trận sau khi truy vết
	cout << "Ma tran sau khi truy vet:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	Path();
	return 0;
}
