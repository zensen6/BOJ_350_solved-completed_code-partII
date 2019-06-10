#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<queue>

using namespace std;

int check[201][201][201] = { false };

bool isempty(int X) {

	if (X == 0) return true;
	else return false;
}

bool ans[201] = { false };

void bfs(int A, int B, int C, int x, int y, int z) {

	queue< tuple<int, int, int> > q;
	q.push(make_tuple(x, y, z));
	check[x][y][z] = true;
	ans[C] = true;
	while (!q.empty()) {

		tuple<int, int, int> t1 = q.front();
		x = get<0>(t1);
		y = get<1>(t1);
		z = get<2>(t1);
		q.pop();
			// A->B
		if (!isempty(x)) {
			if (x + y >= B) {

				if (!check[x - (B - y)][B][z]) {
					q.push(make_tuple(x - (B - y), B, z));
					check[x - (B - y)][B][z] = true;
					//		cout << "A->B:" << B - y << '\n';
					//		cout << x - (B - y) << ' ' << B << ' ' << z << '\n';
					if (x - (B - y) == 0) {

						ans[z] = true;

					}
				}

			}
			else {

				if (!check[0][x + y][z]) {
					q.push(make_tuple(0, x + y, z));
					check[0][x + y][z] = true;
					//		cout << "A->B:" << y << '\n';
					//		cout <<0 << ' ' << x+y << ' ' << z << '\n';
					ans[z] = true;

				}

			}

			// A->C

			if (x + z >= C) {

				if (!check[x - (C - z)][y][C]) {
					q.push(make_tuple(x - (C - z), y, C));
					check[x - (C - z)][y][C] = true;
					//		cout << "A->C:" << C - z << '\n';
					//		cout << x - (C - z) << ' ' << y << ' ' << C << '\n';
					if (x - (C - z) == 0) {

						ans[C] = true;

					}
				}

			}
			else {

				if (!check[0][y][x + z]) {
					q.push(make_tuple(0, y, x + z));
					check[0][y][x + z] = true;
					//		cout << "A->C:" << x << '\n';
					//		cout << 0 << ' ' << y << ' ' << x+z << '\n';

					ans[x + z] = true;


				}

			}


		}
			//B->A
		if (!isempty(y)) {
			if (y + x >= A) {

				if (!check[A][y - (A - x)][z]) {
					q.push(make_tuple(A, y - (A - x), z));
					check[A][y - (A - x)][z] = true;
					//			cout << "B->A:" << A - x << '\n';
					//			cout << A << ' ' << y-(A-x) << ' ' << z << '\n';
				}

			}
			else {

				if (!check[x + y][0][z]) {
					q.push(make_tuple(x + y, 0, z));
					check[x + y][0][z] = true;
					//					cout << "B->A:" << y << '\n';
					//					cout << x + y << ' ' << 0 << ' ' << z << '\n';
					if (x + y == 0) {
						ans[z] = true;
					}


				}

			}
			//B->C
			if (y + z >= C) {

				if (!check[x][y - (C - z)][C]) {
					q.push(make_tuple(x, y - (C - z), C));
					check[x][y - (C - z)][C] = true;
					//				cout << "B->C:" << C-z << '\n';
					//				cout << x  << ' ' << y-(C-z)<< ' ' << C << '\n';
					if (x == 0) {
						ans[C] = true;
					}

				}

			}
			else {

				if (!check[x][0][y + z]) {
					q.push(make_tuple(x, 0, y + z));
					check[x][0][y + z] = true;
					//	cout << "B->C:" << y << '\n';
					//	cout << x  << ' ' << 0 << ' ' << y+z << '\n';
					if (x == 0) {

						ans[y + z] = true;

					}
				}

			}
		}
			//C->A
		if(!isempty(z)){
			if (z + x >= A) {

				if (!check[A][y][z - (A - x)]) {

					q.push(make_tuple(A, y, z - (A - x)));
					check[A][y][z - (A - x)] = true;
					//	cout << "C->A:" << A-x << '\n';
					//	cout << A << ' ' << y << ' ' << z-(A-x) << '\n';

				}

			}
			else {

				if (!check[x + z][y][0]) {

					q.push(make_tuple(x + z, y, 0));
					check[x + z][y][0] = true;
					//	cout << "C->A:" << z << '\n';
					//	cout << x +z << ' ' << y << ' ' << 0 << '\n';
					if (x + z == 0) {

						ans[0] = true;

					}


				}

			}
			//C->B
			if (z + y >= B) {

				if (!check[x][B][z - (B - y)]) {

					q.push(make_tuple(x, B, z - (B - y)));
					check[x][B][z - (B - y)] = true;
					//	cout << "C->B:" << B-y << '\n';
					//	cout << x  << ' ' << B << ' ' << z-(B-y)<< '\n';
					if (x==0) {

						ans[z - (B - y)]=true;

					}
				}
			}
			else {

				if (!check[x][y + z][0]) {

					q.push(make_tuple(x, y + z, 0));
					check[x][y + z][0] = true;
					//	cout << "C->B:" << z << '\n';
					//	cout << x  << ' ' << y+z << ' ' << 0 << '\n';
					if (x == 0) {

						ans[0] = true;

					}

				}
			}

		}

	}

}



int main() {

	int A, B, C;
	cin >> A >> B >> C;
	bfs(A, B, C, 0, 0, C);

	ans[C] = true;
	for (int i = 0; i <= C; i++) {

		if (ans[i]) cout << i << ' ';

	}
	return 0;
}
