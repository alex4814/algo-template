struct Node {
	string key;
	int aux;
	int parent, ch[2];
}treap[_N];

bool cmp(Node a, Node b)
{
	return a.key < b.key;
}

void init(int n)
{
	FOR (i, 0, n) { treap[i].parent = treap[i].ch[0] = treap[i].ch[1] = -1; }
}

int stack[_N];
int build(int n)
{
	int sp = -1;
	FOR (i, 0, n) {
		int k = sp;
		while (k >= 0 && treap[ stack[k] ].aux < treap[i].aux) { --k; } 
		if (k != -1) {
			treap[i].parent = stack[k];
			treap[ stack[k] ].ch[1] = i;
		}
		if (k < sp) {
			treap[ stack[k + 1] ].parent = i;
			treap[i].ch[0] = stack[k + 1];
		}
		stack[sp = ++k] = i;
	}
	treap[ stack[0] ].parent = -1;
	return stack[0];
}
