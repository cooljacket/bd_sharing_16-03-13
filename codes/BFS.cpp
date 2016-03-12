#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

const int Size = 10;

struct Point
{
	int x, y;
	Point(){}
	Point(int a, int b): x(a), y(b) {}
	
	bool operator < (const Point& b) const {
		if (x != b.x)
			return x < b.x;
		return y < b.y;
	}
};

Point dir[8] = {
	Point(-2, -1), Point(-2, 1), Point(2, 1), Point(2, -1),
	Point(-1, -2), Point(-1, 2), Point(1, 2), Point(1, -2)
};

inline bool equal(const Point& a, const Point& b){
	if(a.x == b.x && a.y == b.y)
		return true;
	return false;
}

inline Point add(const Point& a, const Point& b){
	return Point(a.x + b.x, a.y + b.y);
}

bool valid(const Point& p, const map<Point, int>& m){
	if(p.x <= 0 || p.x > Size)
		return false;
	if(p.y <= 0 || p.y > Size)
		return false;
	if(m.find(p) != m.end())
		return false;
	return true;
}

void display(const vector<Point>& v, map<Point, int>& m, const Point& beg, const Point& now){
	if (equal(now, beg))
		cout << beg.x << ' ' << beg.y << endl;
	else {
		display(v, m, beg, v[m[now]]);
		cout << now.x << ' ' << now.y << endl;
	}
}

void go(const Point& beg, const Point& end) {
	queue<Point> q;
	vector<Point> v;
	map<Point, int> m;
	q.push(beg);

	while (!q.empty()) {
		Point now = q.front();
		v.push_back(now);
		q.pop();

		if(equal(now, end)){
			cout << "Success!" << endl;
			display(v, m, beg, end);
			return ;
		}
		for(int i = 0; i < 8; ++i){
			Point nextOne = add(now, dir[i]);
			if(valid(nextOne, m)){
				q.push(nextOne);
				m[nextOne] = v.size() - 1;
			}
		}
	}

	cout << "Failed, no way to go!!!" << endl;	
}

int main(){
	Point beg, end;
	cin >> beg.x >> beg.y >> end.x >> end.y;
	go(beg, end);

	return 0;
}