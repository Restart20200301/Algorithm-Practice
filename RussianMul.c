int RussianMul(int m, int n) {
	int res = 0;
	while (m) {
		if (m & 0x01) res += n;
		n <<= 1;
		m >>= 1;
	}
	return res;
}
