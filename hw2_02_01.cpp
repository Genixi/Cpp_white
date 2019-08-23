bool IsPalindrom(string word) {
	int l = word.size();
	for (int i=0; i < l; ++i) {
		if (word[i] != word[l - i - 1]) {
			return false;
		}
	}
	return true;
}