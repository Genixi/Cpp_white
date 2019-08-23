void Reverse(vector<int>& v) {
	int len;
	if (v.size() % 2 == 0) {
		len = v.size() / 2;
	} else {
		len = v.size() / 2 + 1;
	}

	int temp;
	for (int i = 0; i < len; ++i) {
		temp = v[i];
		v[i] = v[v.size() - i - 1];
		v[v.size() - i - 1] = temp;
	}
}