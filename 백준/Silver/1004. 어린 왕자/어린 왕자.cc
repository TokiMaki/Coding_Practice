#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


int main() {
	class Coord {
	public:
		int x, y;
	};
	class Planet {
	public:
		int x, y, r;
	};
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	int n;
	cin >> T;

	Coord start, end;
	vector<Planet> planets;

	for (int i = 0; i < T; ++i) {
		cin >> start.x >> start.y >> end.x >> end.y;
		cin >> n;
		int count = 0;
		for (int i = 0; i < n; ++i) {
			Planet tmp;
			cin >> tmp.x >> tmp.y >> tmp.r;
			planets.emplace_back(tmp);
		}
		for (Planet planet : planets) {
			double startd = sqrt(pow((planet.x - start.x), 2) + pow((planet.y - start.y), 2));
			double endd = sqrt(pow((planet.x - end.x), 2) + pow((planet.y - end.y), 2));
			if (startd < planet.r && endd < planet.r) {
				continue;
			}
			else if (startd < planet.r || endd < planet.r) {
				count++;
			}
		}
		cout << count << "\n";
		planets.clear();
	}
}