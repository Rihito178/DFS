#include<iostream>
#include<queue>
#include<vector>

namespace
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> myQueue;// 小さい順に取り出す優先順位付きキュー
	std::queue<int> ituQueue;// FIFOキュー
}

//BFSに使う構造体
struct Node 
{
	int cost;
};

//優先順位をつける
bool operator>(const Node& a, const Node& b)
{
	return a.cost > b.cost;
}



int main() 
{
	ituQueue.push(10); 
	ituQueue.push(3);
	ituQueue.push(5);
	ituQueue.push(8);
	ituQueue.push(2);

	// ITU QueueはFIFOなので、入れた順番に出てくる
	for(int i=0; i<5; i++)
	{
		int val = ituQueue.front(); 
		ituQueue.pop(); 
		std::cout << "Pop"<< val << std::endl;

	}

	std::cout << "------------------" << std::endl;
	myQueue.push(10);
	myQueue.push(3);
	myQueue.push(5);
	myQueue.push(8);
	myQueue.push(2);

	// Priority Queueは優先順位付きキューなので、小さい順に出てくる
	for (int i = 0; i < 5; i++)
	{
		int val = myQueue.top();
		myQueue.pop();
		std::cout << "Pop" << val << std::endl;

	}

	//ここから下にBFSを書く

	const int N = 5;// ノードの数

	//段階のカウンター
	int neighbors[N][3] = 
	{
		   {1, 2, -1},
		   {0, 3, -1},
		   {0, 3, -1},
		   {1, 2, 4},
		   {3, -1, -1}
	};

	bool visited[N] = { false, false, false, false, false };//通ったかを記録する配列
	std::queue<int> q;

	int start = 0;
	visited[start] = true;//上のvisitedを開始する
	q.push(start);

	//BFSのループ
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		std::cout << "BFS: " << cur << std::endl;

		//カウンターを回す
		for (int i = 0; i < 3; ++i)
		{
			int nxt = neighbors[cur][i];
			if (nxt == -1) break;
			if (!visited[nxt])
			{
				visited[nxt] = true;
				q.push(nxt);
			}
		}
	}
	return 0;
}







