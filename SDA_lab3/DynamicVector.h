#pragma once

template <typename T>
class DynamicVector
{
private:
	int size;
	int cap;
	T* elems;
	//Relation* relation(TComp*, TComp*);
	//Relation* r;

public:
	DynamicVector(int cap = 4);

	DynamicVector(const DynamicVector& dv);

	void add(T e);

	void insert(T el, int pos);

	void remove(int pos);

	int getSize() const { return this->size; }


	T& getElem(int pos) const { return this->elems[pos]; }

	T& operator[](int pos) { return this->elems[pos]; }

	DynamicVector& operator + (T el);
	
	~DynamicVector();
private:
	void resize();
};

template <typename T>

DynamicVector<T>::DynamicVector(int cap)
{
	this->size = 0;
	this->cap = cap;
	this->elems = new T[this->cap];
}

template<typename T>
DynamicVector<T>::DynamicVector(const DynamicVector & dv)
{
	this->cap = dv.cap;
	this->size = dv.size;
	this->elems = new T[this->cap];
	for (int i = 0; i < dv.size; i++)
	{
		this->elems[i] = dv.elems[i];
	}
}

template <typename T>
void DynamicVector<T>::add(T e) {
	if (this->size == this->cap)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

template<typename T>
void DynamicVector<T>::insert(T e, int pos)
{
	//this->cap += 1;
	if (this->cap == this->size) {
		this->resize();
	}
	//T* new_elems = new T[this->cap];
	//T* new_elems_right = new T[this->cap];
	int i = 0;

	for (i = this->size; i >= pos+1; i--) {
		this->elems[i] = this->elems[i - 1];
	}
	this->elems[pos] = e;

	//for (int j = pos + 1; j <= this->size; j++) {
	//	//new_elems[j] = this->elems[j - 1];
	//	new_elems[j] = this->elems[j - 1];
	//}
	this->size++;
}

template<typename T>
void DynamicVector<T>::remove(int pos)
{
	for (int i = pos + 1; i < this->size; i++) {
		this->elems[i - 1] = this->elems[i];
	}
	this->size--;
}


template<typename T>
DynamicVector<T>& DynamicVector<T>::operator+(T el)
{
	this->add(el);
	return *this;
}

template<typename T>
inline DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}


template<typename T>
void DynamicVector<T>::resize()
{
	this->cap *= 2;
	T* new_elems = new T[this->cap];

	for (int i = 0; i < this->size; i++) {
		new_elems[i] = this->elems[i];
	}
	delete[] this->elems;
	this->elems = new_elems;
}

