vector<int> Reversed(const vector<int>& v) {
	vector<int> res;
	int len = v.size();

	for (int i = 0; i < len; ++i) {
		res.push_back(v[len - i - 1]);
	}
	return res;
}