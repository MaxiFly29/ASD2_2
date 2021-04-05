#pragma once

template <class T>
class BST {
public:
	virtual void insert(T value) = 0;
	virtual bool contains(T value) const = 0;
	virtual void erase(T value) = 0;
	virtual size_t size() const = 0;
	virtual void clear() = 0;
	virtual T sum() const = 0;
};