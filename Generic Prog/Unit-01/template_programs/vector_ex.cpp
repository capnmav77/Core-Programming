template <typename T>
struct vector
{
	vector();
	size_t size() const;
	size_t capacity() const;
	bool empty() const;
	void clear();
	void resize(size_t const size);
	void push_back(T value);
	void pop_back();
	T at(size_t const index) const;
	T operator[](size_t const index) const;
	private:  // The structure in C++ may have private data members.
		  // But no function can be a part of either private 
		  // or public specifier.
		T* data_;
		size_t size_;
		size_t capacity_;
};

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
}