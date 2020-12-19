#include"BigNumbers.h"



ostream& operator<<(ostream& o, const Int& a) {
	if (a.nega) { o << '-'; }
	size_t len = a.data.size();
	for (size_t i = len - 1; i != 4294967295; i++) {
		cout << a.data[i];
	}
	return o;
}

istream& operator>>(istream& input, Int& a) {
	if (input.peek() == '-') { a.nega = 0;input.get(); }
	int i = 0;int temp;char temp2;
	while (input.peek() >= '0' && input.peek() <= '9') {
		cin.get() >> temp2;
		if (temp2 >= '0' && temp2 <= '9') {}
	}


	int temp = 0;
	for (int j = 0;j < i;j++, i--) {
		a.data[i] ^= a.data[j];
		a.data[j] ^= a.data[i];
		a.data[i] ^= a.data[j];
	}
	return input;
}
//string& operator>>(const string source, Int& target) {
//	target.data.clear();
//	string::const_iterator init = source.begin();
//	if (*init == '-') {
//		target.nega = 1;
//		init++;
//	}
//	string::const_iterator fin = source.end();
//	fin--;
//	string::iterator temp;
//	int i;
//	if (fin == init) {
//		target.data.push_back(*fin - '0');
//	}
//	else {
//		int TempSect = 0;
//		while (fin >= init) {
//			for (i = 0;i < 31 && fin != init;i++) {
//				for (temp = init;temp != fin;temp++) {
//					*(temp + 1) += CarryOver(*temp);
//				}
//				TempSect += CarryOver(*temp) << i;
//				while (*init == '0') { init++; }
//			}
//			target.data.push_back(TempSect);
//
//		}
//	}
//
//}

Int& Int::operator+(Int& bb) {
	Int Temp(*this);
	if (bb.nega) {
		if (this->nega) {
			int sz = min(this->data.size(), bb.data.size());
			for (int i = 0;i < sz;++i) {
				Temp.data[i] += bb.data[i];
			}
			sz = max(this->data.size(), bb.data.size());
			for (int i = 0;i < sz - 1;++i) {
				if (Temp.data[i] >> 31) {
					Temp.data[i + 1]++;
					Temp.data[i] &= ~(1 << 31);
				}
			}
			if (Temp.data[sz] >> 31) {
				Temp.data.push_back(1);
				Temp.data[sz] &= ~(1 << 31);
			}
			return Temp;
		}
		else {
			Temp.nega = 1;
			if (bb < Temp) {
				int sz = min(this->data.size(), bb.data.size());
				Temp = bb;
				for (int i = 0;i < sz;++i) {
					Temp.data[i] -= this->data[i];
				}
				sz = max(this->data.size(), bb.data.size());
				for (int i = 0;i < sz;++i) {
					if (Temp.data[i] >> 31) {
						Temp.data[i + 1]--;
						Temp.data[i] &= ~(1 << 31);
					}
				}
				auto iter = Temp.data.end() - 1, init = Temp.data.begin();
				while ((!*iter) && iter != init) {
					--iter;
				}
				Temp.data.erase(iter + 1, Temp.data.end());
				return Temp;
			}
			else {
				Temp.nega = 0;
				int sz = min(this->data.size(), bb.data.size());
				for (int i = 0;i < sz;++i) {
					Temp.data[i] -= bb.data[i];
				}
				sz = max(this->data.size(), bb.data.size());
				for (int i = 0;i < sz;++i) {
					if (Temp.data[i] >> 31) {
						Temp.data[i + 1]--;
						Temp.data[i] &= ~(1 << 31);
					}
				}
				auto iter = Temp.data.end() - 1, init = Temp.data.begin();
				while ((!*iter) && iter != init) {
					--iter;
				}
				if (iter + 1 != Temp.data.end()) {
					Temp.data.erase(iter + 1, Temp.data.end());
				}
				return Temp;
			}
		}
	}
	else {
		if (this->nega) {
			Temp.nega=0;
			if (bb > Temp) {
				int sz = min(this->data.size(), bb.data.size());
				Temp = bb;
				for (int i = 0;i < sz;++i) {
					Temp.data[i] -= this->data[i];
				}
				sz = max(this->data.size(), bb.data.size());
				for (int i = 0;i < sz;++i) {
					if (Temp.data[i] >> 31) {
						Temp.data[i + 1]--;
						Temp.data[i] &= ~(1 << 31);
					}
				}
				auto iter = Temp.data.end() - 1, init = Temp.data.begin();
				while ((!*iter) && iter != init) {
					--iter;
				}
				Temp.data.erase(iter + 1, Temp.data.end());
				return Temp;
			}
			else {
				Temp.nega = 1;
				int sz = min(this->data.size(), bb.data.size());
				for (int i = 0;i < sz;++i) {
					Temp.data[i] -= bb.data[i];
				}
				sz = max(this->data.size(), bb.data.size());
				for (int i = 0;i < sz;++i) {
					if (Temp.data[i] >> 31) {
						Temp.data[i + 1]--;
						Temp.data[i] &= ~(1 << 31);
					}
				}
				auto iter = Temp.data.end() - 1, init = Temp.data.begin();
				while ((!*iter) && iter != init) {
					--iter;
				}
				Temp.data.erase(iter + 1, Temp.data.end());
				return Temp;
			}
		}
		else {
			int sz = min(this->data.size(), bb.data.size());
			for (int i = 0;i < sz;++i) {
				Temp.data[i] += bb.data[i];
			}
			sz = max(this->data.size(), bb.data.size());
			for (int i = 0;i < sz - 1;++i) {
				if (Temp.data[i] >> 31) {
					Temp.data[i + 1]++;
					Temp.data[i] &= ~(1 << 31);
				}
			}
			if (Temp.data[sz - 1] >> 31) {
				Temp.data.push_back(1);
				Temp.data[sz - 1] &= ~(1 << 31);
			}
			return Temp;
		}
	}
}

Int& Int::operator+(Int& bb) {
	Int Temp(*this);
	if (bb.nega) {
		if (this->nega) {
			Temp.nega = 0;
			if (bb < Temp) {
				int sz = min(this->data.size(), bb.data.size());
				Temp = bb;
				for (int i = 0;i < sz;++i) {
					Temp.data[i] -= this->data[i];
				}
				sz = max(this->data.size(), bb.data.size());
				for (int i = 0;i < sz;++i) {
					if (Temp.data[i] >> 31) {
						Temp.data[i + 1]--;
						Temp.data[i] &= ~(1 << 31);
					}
				}
				auto iter = Temp.data.end() - 1, init = Temp.data.begin();
				while ((!*iter) && iter != init) {
					--iter;
				}
				Temp.data.erase(iter + 1, Temp.data.end());
				return Temp;
			}
			else {
				int sz = min(this->data.size(), bb.data.size());
				Temp = ;
				for (int i = 0;i < sz;++i) {
					Temp.data[i] -= bb.data[i];
				}
				sz = max(this->data.size(), bb.data.size());
				for (int i = 0;i < sz;++i) {
					if (Temp.data[i] >> 31) {
						Temp.data[i + 1]--;
						Temp.data[i] &= ~(1 << 31);
					}
				}
				auto iter = Temp.data.end() - 1, init = Temp.data.begin();
				while ((!*iter) && iter != init) {
					--iter;
				}
				Temp.data.erase(iter + 1, Temp.data.end());
				return Temp;
			}
		}
		else {
			int sz = min(this->data.size(), bb.data.size());
			for (int i = 0;i < sz;++i) {
				Temp.data[i] += bb.data[i];
			}
			sz = max(this->data.size(), bb.data.size());
			for (int i = 0;i < sz - 1;++i) {
				if (Temp.data[i] >> 31) {
					Temp.data[i + 1]++;
					Temp.data[i] &= ~(1 << 31);
				}
			}
			if (Temp.data[sz] >> 31) {
				Temp.data.push_back(1);
				Temp.data[sz] &= ~(1 << 31);
			}
			return Temp;
			
		}
	}
	else {
		if (this->nega) {
			Temp.nega = 1;
			if (bb < Temp) {
				int sz = min(this->data.size(), bb.data.size());
				Temp = bb;
				for (int i = 0;i < sz;++i) {
					Temp.data[i] -= this->data[i];
				}
				sz = max(this->data.size(), bb.data.size());
				for (int i = 0;i < sz;++i) {
					if (Temp.data[i] >> 31) {
						Temp.data[i + 1]--;
						Temp.data[i] &= ~(1 << 31);
					}
				}
				auto iter = Temp.data.end() - 1, init = Temp.data.begin();
				while ((!*iter) && iter != init) {
					--iter;
				}
				Temp.data.erase(iter + 1, Temp.data.end());
				return Temp;
			}
			else {
				int sz = min(this->data.size(), bb.data.size());
				Temp = bb;
				for (int i = 0;i < sz;++i) {
					Temp.data[i] -= bb.data[i];
				}
				sz = max(this->data.size(), bb.data.size());
				for (int i = 0;i < sz;++i) {
					if (Temp.data[i] >> 31) {
						Temp.data[i + 1]--;
						Temp.data[i] &= ~(1 << 31);
					}
				}
				auto iter = Temp.data.end() - 1, init = Temp.data.begin();
				while ((!*iter) && iter != init) {
					--iter;
				}
				Temp.data.erase(iter + 1, Temp.data.end());
				return Temp;
			}
		}
		else {
			int sz = min(this->data.size(), bb.data.size());
			for (int i = 0;i < sz;++i) {
				Temp.data[i] += bb.data[i];
			}
			sz = max(this->data.size(), bb.data.size());
			for (int i = 0;i < sz - 1;++i) {
				if (Temp.data[i] >> 31) {
					Temp.data[i + 1]++;
					Temp.data[i] &= ~(1 << 31);
				}
			}
			if (Temp.data[sz - 1] >> 31) {
				Temp.data.push_back(1);
				Temp.data[sz - 1] &= ~(1 << 31);
			}
			return Temp;
		}
	}
}

inline bool CarryOver(char& in) {
	if ((in - '0') % 2) {
		in = (in - '0') / 2 + '0';
		return 1;
	}
	else {
		in = (in - '0') / 2 + '0';
		return 0;
	}
}


bool Int::operator<(Int& bb) {
	if (this->nega) {
		if (bb.nega) {
			if (this->data.size() > bb.data.size()) { return 1; }
			else {
				if (this->data.size() == bb.data.size()) {
					return *(this->data.end() - 1) > * (bb.data.end() - 1);
				}
				else { return 0; }
			}
		}
		else { return 1; }
	}
	else {
		if (bb.nega) { return 0; }
		else {
			if (this->data.size() < bb.data.size()) { return 1; }
			else {
				if (this->data.size() == bb.data.size()) {
					return *(this->data.end() - 1) < *(bb.data.end() - 1);
				}
				else { return 0; }
			}
		}
	}
}

bool Int::operator>(Int& bb) {
	if (this->nega) {
		if (bb.nega) {
			if (this->data.size() > bb.data.size()) { return 0; }
			else {
				if (this->data.size() == bb.data.size()) {
					return *(this->data.end() - 1) < *(bb.data.end() - 1);
				}
				else { return 1; }
			}
		}
		else { return 0; }
	}
	else {
		if (bb.nega) { return 1; }
		else {
			if (this->data.size() < bb.data.size()) { return 0; }
			else {
				if (this->data.size() == bb.data.size()) {
					return *(this->data.end() - 1) > * (bb.data.end() - 1);
				}
				else { return 1; }
			}
		}
	}
}

bool Int::operator==(Int& bb) {
	if (this->nega == bb.nega) {
		return this->data == bb.data;
	}
	else { return 0; }
}