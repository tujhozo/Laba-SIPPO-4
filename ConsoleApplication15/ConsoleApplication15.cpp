#include <iostream>
using namespace std;
struct Tree
{
	int klon;
	Tree* r;
	Tree* l;
	Tree()
	{
		klon = -1;
		r = NULL;
		l = NULL;
	}
};
struct ListElement
{
	int klon;
	ListElement* pointer;
	ListElement()
	{
		klon = -1;
		pointer = NULL;
	}
};

void kp(Tree* y)
{
	if (y != NULL)
	{
		kp(y->l);
		cout << y->klon << " ";
		kp(y->r);
	}

}
void ff(Tree* root, Tree* y)
{
	if (root == NULL || y == NULL) { return; }
	else if (root->l == y) { root->l = NULL; }
	else if (root->r == y) { root->r = NULL; }
	{
		ff(root->l, y);
		ff(root->r, y);
	}
}
void kl(Tree*& y, int x)
{
	if (y == NULL)
	{
		y = new Tree();
		y->klon = x;
	}
	else
		if (y->klon > x)
		{
			kl(y->l, x);
		}
		else
			if (y->klon < x)
			{
				kl(y->r, x);
			}
}

Tree* hh(Tree* y, int x)
{
	Tree* result = NULL;
	if (y == NULL) { result = NULL; }
	else if (y->klon == x) { result = y; }
	else
	{
		result = hh(y->l, x);
		if (result == NULL) { result = hh(y->r, x); }
	}
	return result;
}
void List(ListElement*& first, Tree* y, ListElement*& elem)
{
	if (y)
	{
		List(first, y->l, elem);
		ListElement* p = new ListElement();
		p->klon = y->klon;
		if (elem == NULL)
		{
			first = p;
			elem = p;
		}
		else
		{
			elem->pointer = p;
			elem = p;
		}
		List(first, y->r, elem);
	}
}

void et(ListElement* m) {
	while (m != NULL) {
		cout << m->klon << " ";
		m = m->pointer;
	}
	cout << endl;
}
void R(Tree* y)
{
	if (y != NULL)
	{
		R(y->l);
		R(y->r);
		delete y;
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	Tree* root = NULL;
	ListElement* number = NULL;
	int N = 0, el;
	cout << "Введите количество чисел " << endl;
	cin >> N;
	cout << "Введите числа дерева " << endl;
	for (int i = 0; i < N; i++) {
		cin >> el;
		kl(root, el);
	}
	kp(root);
	cout << endl;
	int v;
	cout << "Введите число для удаления поддерева" << endl;
	cin >> v;
	Tree* y = hh(root, v);
	ff(root, y);
	R(y);
	kp(root);
	cout << endl;
	cout << "Список ";
	ListElement* Nch = NULL;
	List(number, root, Nch);
	et(number);
	return 0;
}
