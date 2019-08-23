bool IsPalindrom(string word) {
	int l = word.size();
	if (word == " ") {
		return true;
	}
	for (int i=0; i < l; ++i) {
		if (word[i] != word[l - i - 1]) {
			return false;
		}
	}
	return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> words_updt;
	for(auto w : words) {
		if((IsPalindrom(w)) && (w.size() >= minLength)) {
			words_updt.push_back(w);
		}
	}
	return words_updt;
}
