#include<iostream>
#include<queue>

namespace
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> myQueue;// 小さい順に取り出す優先順位付きキュー
	std::queue<int> ituQueue;// FIFOキュー
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

	return 0;
}