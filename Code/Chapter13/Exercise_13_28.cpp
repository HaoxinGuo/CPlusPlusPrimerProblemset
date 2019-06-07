//练习13-28
#include <iostream>

#include <string>

using namespace std;

class TreeNode {
public:
		//构造函数
	TreeNode() {};
	TreeNode(const TreeNode&) {};
	TreeNode operator=(const TreeNode &rh) {
		value = rh.value;
		count = rh.count;	
		left = rh.left;
		right = rh.right;
	}
private:
	string value;
	int count;
	TreeNode *left;	
	TreeNode *right;
};


class BinStrTree{
public:
	
private:
	TreeNode *root;
};

int main()
{
	return 0;
}


