#include <iostream>
#include <string>
using namespace std;
struct btnode {
	int data;
	struct btnode* lchild;
	struct btnode* rchild;
};
void create_btree(btnode*& T) {
	T = new btnode;
	int a;
	cin >> a;
	if (a == -1) {
		T = NULL;
	}
	else {
		T->data = a;
		create_btree(T->lchild);
		create_btree(T->rchild);
	}
}
//btree to string
void btree_to_string(const btnode* T, string& s) {
	if (T == NULL) {
		s += "#_";
	}
	else {
		s += "q_";//q可以换位任意字符
		btree_to_string(T->lchild, s);
		btree_to_string(T->rchild, s);
	}
}

int main()
{
	btnode* T1, * T2;
	string s1, s2;
	create_btree(T1);
	create_btree(T2);
	btree_to_string(T1, s1);
	btree_to_string(T2, s2);
	if (s1.find(s2) != -1) {
		cout << "同构！";
	}
	else {
		cout << "不同构";
	}
	return 0;
}