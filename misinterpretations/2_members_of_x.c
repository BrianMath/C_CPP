struct s {
	int a;
};

int main() {
	struct s;
	struct s *x;
	struct s {
		int b;
	} y;

	// error: ‘struct s’ has no member named ‘a’
	// x->a = 1;
	x->b = 2;
}

