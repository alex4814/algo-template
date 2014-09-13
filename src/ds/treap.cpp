#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define FOR(i,s,t) for (int i = s; i < t; ++i)
#define MEM(s,v) memset(s, v, sizeof(s))

#define EPS 1e-8
#define _N 100005
#define _M 105
#define PI acos(-1.0)


struct Node {
	Node *ch[2];
	int key;
	int aux;
	int cnt;
	Node () {}
	Node (int key, int aux) : key(key), aux(aux) {
		ch[0] = ch[1] = NULL, cnt = 1;
	}
	bool operator < (const Node& rhs) const {
		return aux < rhs.aux;
	}
	int cmp(int x) const {
		if (x == key) return -1;
		return x < key ? 0 : 1;
	}
	void maintain() {
		cnt = 1;
		if (ch[0] != NULL) { cnt += ch[0]->cnt; }
		if (ch[1] != NULL) { cnt += ch[1]->cnt; }
	}
}*root;

Node node[_N];

void rotate(Node *&p, int d)
{
	Node *k = p->ch[d ^ 1];
	p->ch[d ^ 1] = k->ch[d]; k->ch[d] = p;
	p->maintain(); k->maintain(); p = k;
}

void insert(Node *&p, int x, int aux)
{
	if (p == NULL) {
		//p = new Node(x, aux);
		p = &node[n_cnt++];
		p->key = x, p->aux = aux, p->cnt = 1;
		p->ch[0] = p->ch[1] = NULL;
	} else {
		int d = (x < p->key ? 0 : 1);	//可能有相同的点
		insert(p->ch[d], x, aux);
		if (p->ch[d]->aux > p->aux) {
			rotate(p, d ^ 1);
		}
	}
	p->maintain();
}

/*
void print(Node *p)
{
	putchar('(');
	if (p->ch[0] != NULL) print(p->ch[0]);
	printf("%s/%d", p->key.c_str(), p->aux);
	if (p->ch[1] != NULL) print(p->ch[1]);
	putchar(')');
}
*/
void print(Node *p)
{
}

int main() 
{
	int key, aux;
	scanf("%d", &n);
	FOR (i, 0, n) {
		scanf("%d%d", &key, &aux);
		insert(root, key, aux);
	}
	printf("YES\n");
	print(p);
}
