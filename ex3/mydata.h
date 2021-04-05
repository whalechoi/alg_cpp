#pragma once
template<class T>
class mydata
{
private:
	int index;
	T data;
	mydata* next = nullptr;
	mydata(int i, const T& x) {
		this->data = x;
		this->index = i;
	}
public:

	bool empty() {
		if (this->index == -1) {
			return true;
		}
		return false;
	}

	mydata() {
		this->data = NULL;
		this->index = -1;
	}

	~mydata() {
		if (this->next != nullptr) {
			delete this->next;
		}
	}

	// 重载下标运算符，即按号查找
	T& operator[](int i) {
		for (mydata* c = this; c != nullptr; c = c->next) {
			if (c->index == i) {
				return c->data;
			}
		}
		throw("越界访问");
	}

	// 插入到索引i的后面
	void ins(const T& x, int i) {
		if (i < -1) {
			return;
		}
		else {
			for (mydata* c = this; c != nullptr; c = c->next) {
				if (c->index == i) {
					for (mydata* d = c->next; d != nullptr; d = d->next) {
						(d->index)++;
					}
					mydata* temp = new mydata(i + 1, x);
					temp->next = c->next;
					c->next = temp;
				}
			}
		}
	}

	// 删除索引i处元素
	void del(int i) {
		if (i < 0) {
			return;
		}
		for (mydata* c = this; c != nullptr; c = c->next) {
			if (c->index == i - 1) {
				if (c->next->next == nullptr) {
					mydata* temp = c->next;
					c->next = nullptr;
					delete temp;
				}
				else {
					for (mydata* d = c->next->next; d != nullptr; d = d->next) {
						(d->index)--;
					}
					mydata* temp = c->next;
					c->next = c->next->next;
					temp->next = nullptr;
					delete temp;
				}
			}
		}
	}

	// 按值查找
	int find(const T& i) {
		for (mydata* c = this; c != nullptr; c = c->next) {
			if (c->data == i) {
				return c->index;
			}
		}
		return NULL;
	}

};
