struct s {
	int a;
};

int main() {
	struct s dummy;
	struct s *x;
	struct s {
		int b;
	} y;

	x->a = 1;
	// error: ‘struct s’ has no member named ‘b’
	// x->b = 2;
}

